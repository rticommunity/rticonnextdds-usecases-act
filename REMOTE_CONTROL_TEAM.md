# Remote Control Team Assignment Example

This example demonstrates how to use the RemoteAdmin tool to dynamically assign nodes to different groups (DDS partitions) and verify that team isolation prevents cross-team communication. You'll see how changing a platform's team assignment stops Control from receiving its data.

## Concept

In the ACT architecture, **groups** are implemented using DDS Domain Participant partitions to logically isolate communication between nodes. Only nodes assigned to the same team can exchange data. This is useful for:

- **Mission separation**: Different teams or operations on separate groups
- **Security zones**: Restricting data flow to authorized participants
- **Testing isolation**: Running multiple configurations without interference
- **Dynamic reorganization**: Moving nodes between groups during runtime

The RemoteAdmin tool allows you to change a node's team assignment without restarting the routing service, enabling dynamic reconfiguration.

## Scenario

In this example, we will:

1. Start two platform simulators (Platform_30 and Platform_31)
2. Start their corresponding routing services (both initially in default team)
3. Start a Control simulator that receives data from both platforms
4. Use RemoteAdmin to assign Platform_31 to a different team (team 5)
5. Verify that Control no longer receives data from Platform_31 but still receives from Platform_30

## Architecture

### Initial State (All in Default Team)

```
┌─────────────┐           ┌─────────────┐           ┌─────────────┐
│ Platform_30 │           │ Platform_31 │           │    Control_20    │
│  Simulator  │           │  Simulator  │           │  Simulator  │
└──────┬──────┘           └──────┬──────┘           └──────┬──────┘
       │                         │                         │
       │ LAN Domain 0            │ LAN Domain 1            │ Control Domain 2
       │                         │                         │
┌──────▼──────┐           ┌──────▼──────┐           ┌──────▼──────┐
│ Platform_30 │           │ Platform_31 │           │    Control_20    │
│   Router    │◄──────────┤   Router    │──────────►│   Router    │
│  (default)  │  WAN      │  (default)  │  WAN      │  (default)  │
└─────────────┘  Domain 10└─────────────┘  Domain 10└─────────────┘
      ▲                                                     │
      │                                                     │
      └─────────────────────────────────────────────────────┘
           Control receives data from both Platform_30 and Platform_31
```

### After Team Change (Platform-11 → Team 5)

```
┌─────────────┐           ┌─────────────┐           ┌─────────────┐
│ Platform-10 │           │ Platform-11 │           │    Control-20    │
│  Simulator  │           │  Simulator  │           │  Simulator  │
└──────┬──────┘           └──────┬──────┘           └──────┬──────┘
       │                         │                         │
       │ LAN Domain 0            │ LAN Domain 1            │ Control Domain 2
       │                         │                         │
┌──────▼──────┐           ┌──────▼──────┐           ┌──────▼──────┐
│ Platform-10 │           │ Platform-11 │           │    Control-20    │
│   Router    │     X     │   Router    │     X     │   Router    │
│  (default)  │◄─────────┤│  (team 5) ││──────────►│  (default)  │
└─────────────┘  ISOLATED └─────────────┘  ISOLATED └─────────────┘
      ▲              └──────────┘                          │
      │             Team Mismatch                         │
      └────────────────────────────────────────────────────┘
           Control receives data ONLY from Platform-10
```

## Prerequisites

- RTI Connext DDS 7.3.0 or later ([C++ setup guide](https://community.rti.com/static/documentation/developers/get-started/apt-install.html))
- Python 3 with RTI Connext DDS Python API ([setup guide](https://community.rti.com/static/documentation/developers/get-started/pip-install.html#section-pip-install))
- `NDDSHOME` environment variable set
- `RTI_LICENSE_FILE` environment variable set
- RemoteAdmin tool built (`tools/remote_admin/build/RemoteAdmin`)
- Parameter files in `params/`

## Step-by-Step Walkthrough

### Terminal 1: Start Platform_30 Simulator

```bash
cd scripts
./start_platform10_sim.sh
```

You should see output indicating the simulator is publishing `PlatformData`:

```
Publishing PlatformData with Session ID 0
Publishing PlatformData with Session ID 1
...
```

### Terminal 4: Start Platform_31 Router

```bash
cd scripts
./start_platform10_router.sh
```

The routing service will start and bridge Platform_30's LAN domain to the WAN domain. Look for:

```
RTI Routing Service started
```

### Terminal 3: Start Platform_31 Simulator

```bash
cd scripts
./start_platform11_sim.sh
```

Similar output as Platform_30, publishing session data.

### Terminal 4: Start Platform-11 Router

```bash
cd scripts
./start_platform11_router.sh
```

### Terminal 5: Start Control Simulator

```bash
cd scripts
./start_control_20_sim.sh
```

### Terminal 6: Start Control_20 Router

```bash
cd scripts
./start_control_20_router.sh
```

**Important**: Watch the Control output carefully (Terminal 5). You should see it receiving data from **both** Platform_30 and Platform_31:

```
- Received ContactReport Data: 10 from source: Platform_30 type: Platform
- Received ContactReport Data: 11 from source: Platform_31 type: Platform
...
```

The session IDs will alternate or interleave, showing data from both platforms.

### Terminal 7: Verify Initial State

Before making any changes, confirm Control is receiving from both platforms. Let it run for about 10-15 seconds and observe the session IDs. You should see a mix of session IDs from both simulators.

### Terminal 8: Change Platform_31 Team Assignment

Now use RemoteAdmin to assign Platform_31 to team 5:

```bash
cd tools/remote_admin
./send_remote_cmd.sh -n Platform_31 --type platform -g 5
```

Expected output:

```
=============================================================
Remote Admin - RTI Routing Service Controller
=============================================================
Using system parameters from: rticonnextdds-usecases-act/params
Exported NDDS_QOS_PROFILES: rticonnextdds-usecases-act/config/qos/remoteadmin_qos_lib.xml
=============================================================

Waiting for a matching replier...
Sending Remote TEAM UPDATE: 
resource_identifier: /routing_services/Platform_31/domain_routes/dr/participants/platform_wan
body_text: str://"<participant><domain_participant_qos><partition><name><element>5</element></name></partition></domain_participant_qos></participant>"
application_name: Platform_31
Command returned: OK
```

### Terminal 5 (C2): Verify Team Isolation

Switch back to Terminal 5 where the Control simulator is running. You should now see:

**Before team change:**
```
- Received ContactReport Data: 10 from source: Platform_30 type: Platform
- Received ContactReport Data: 11 from source: Platform_31 type: Platform
```

**After team change:**
```
- Received ContactReport Data: 10 from source: Platform_30 type: Platform
```

Notice that after the team change, you only see ContactReports from Platform_30. Platform_31's data is no longer received because it's in a different team (partition).

### Terminal 8: Reset Platform_31 to Default Partition

To restore communication, reset Platform_31's Domain Participant Partition back to "ALL" (the default):

```bash
cd tools/remote_admin
./send_remote_cmd.sh -n Platform_31 -g ALL --type platform
```

**Note**: The default Domain Participant Partition is "ALL", not an empty string.

### Terminal 5 (C2): Verify Communication Restored

After moving Platform_31 back to the default team, Control should start receiving data from both platforms again:

```
- Received ContactReport Data: 10 from source: Platform_30 type: Platform
- Received ContactReport Data: 11 from source: Platform_31 type: Platform
```

## What's Happening Behind the Scenes

When you run `./send_remote_cmd.sh -n Platform_31 -g 5`:

1. **RemoteAdmin constructs a resource identifier**:
   ```
   /routing_services/Platform_31/domain_routes/dr/participants/platform_wan
   ```

2. **Creates an XML QoS update** to set the partition:
   ```xml
   <participant>
     <domain_participant_qos>
       <partition>
         <name>
           <element>5</element>
         </name>
       </partition>
     </domain_participant_qos>
   </participant>
   ```

3. **Sends a CommandRequest** on the admin domain (100) to Platform-11's routing service

4. **Platform-11 router updates** its WAN participant's QoS to use partition "5"

5. **DDS enforces isolation**: Only participants with matching partitions can communicate

## Key Observations

- **Team isolation is immediate**: As soon as the team change is applied, communication stops
- **No restart required**: The routing service remains running during the reconfiguration
- **Session IDs continue**: Platform_31 keeps publishing, but Control can't receive it
- **Bidirectional isolation**: Platform_31 also can't receive data meant for the default team
- **Default partition is "ALL"**: The default Domain Participant Partition is set to "ALL", not an empty string or "0"

## Advanced: Assign Control to a Team

You can also assign Control to a specific team to create an isolated communication cell:

```bash
cd tools/remote_admin

# Move Platform_30 to team 3 (using ROUTER_NAME from params/platform_10_params.sh)
./send_remote_cmd.sh -n Platform_30 -g 3 --type platform

# Move Control_20 to team 3 (using ROUTER_NAME from params/control_20_params.sh)
./send_remote_cmd.sh -n Control_20 -g 3 --type c2

# Platform_31 stays in default team
```

Now:
- Platform_30 and Control_20 communicate (both in team 3)
- Platform_31 is isolated (in default team)
- To add Platform_31 to the team: `./send_remote_cmd.sh -n Platform_31 -g 3 --type platform`

## Troubleshooting

### Control Still Receiving Data After Team Change

- **Verify the command succeeded**: Check RemoteAdmin output for "Command returned: entity updated OK"
- **Check routing service logs**: Look for partition updates in the router terminal
- **Confirm correct resource name**: Use `-n Platform_31` not `-n platform_11` (case-sensitive)
- **Wait a few seconds**: There may be a small delay for DDS discovery to update

### RemoteAdmin Shows "No matching replier found"

- **Verify routing service is running**: Check Terminal 4 (Platform_31 router)
- **Check application name**: The `-appName Platform_31` in the router must match `-n Platform_31` in RemoteAdmin
- **Verify admin domain**: Both router and RemoteAdmin must use the same admin domain (default: 100)

### Control Not Receiving Any Data

- **Check all routers are running**: Verify Terminals 2 and 4 show active routing services
- **Verify simulators are publishing**: Check Terminals 1 and 3 for "Publishing PlatformData" messages
- **Check Control router**: Ensure `start_control_20_router.sh` is running (if using separate Control router)

## Cleanup

To stop all processes, press `Ctrl+C` in each terminal:

1. Terminal 1: Platform_30 simulator
2. Terminal 2: Platform_30 router
3. Terminal 3: Platform_31 simulator
4. Terminal 4: Platform_31 router
5. Terminal 5: Control_20 simulator
6. Terminal 6: Control_20 router

## Related Examples

- **REMOTE_ENABLE_TEAM.md**: Enable direct platform-to-platform communication
- **QUICKSTART.md**: Basic setup and initial testing
- **MULTI_PLATFORM.md**: Scaling to many platforms

## Summary

This example demonstrates:

✅ Dynamic team assignment using RemoteAdmin  
✅ [DDS Domain Participant Partition](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/users_manual/users_manual/PARTITION_QosPolicy.htm)-based isolation between groups  
✅ Runtime reconfiguration without service restarts  
✅ Verification of team isolation through message observation  
✅ Restoring communication by reassigning groups  

Groups provide a powerful mechanism for organizing and isolating communication in complex distributed systems. Use RemoteAdmin to dynamically manage these assignments as operational requirements change.

---

## Questions or Feedback?

Reach out to us at **services_community@rti.com** - we welcome your questions and feedback!
