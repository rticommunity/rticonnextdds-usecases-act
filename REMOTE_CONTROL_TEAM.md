# Remote Control Team Assignment Example

This example demonstrates how to use the RemoteAdmin tool to dynamically assign platforms to different teams (DDS partitions) using letter designations (A, B, C, etc.) to isolate platform-to-platform communication within the PLATFORM_TEAM_CHANNEL.

## Concept

In the ACT architecture, **teams** are implemented using DDS Domain Participant partitions to logically isolate platform-to-platform communication. Platforms assigned to different teams cannot exchange data with each other via the PLATFORM_TEAM_CHANNEL. This is useful for:

- **Mission separation**: Different teams operating independently
- **Security zones**: Restricting platform-to-platform data flow to authorized team members
- **Testing isolation**: Running multiple platform configurations without cross-team interference
- **Dynamic reorganization**: Moving platforms between teams during runtime

For details on the partition mechanism, see [DDS PARTITION QoS Policy](https://community.rti.com/static/documentation/connext-dds/7.3.1/doc/manuals/connext_dds_professional/users_manual/users_manual/PARTITION_QosPolicy.htm?Highlight=partition).

The RemoteAdmin tool allows you to change a platform's team assignment without restarting the routing service, enabling dynamic reconfiguration.

**Note:** Team assignments affect platform-to-platform communication only. All platforms can still communicate with Control nodes regardless of team assignment. This is because each routing service uses separate DDS Domain Participants: one for platform-to-Control communication and one for platform-to-platform (TEAM) communication. The RemoteAdmin tool only modifies the partition on the TEAM participant, leaving Control communication unaffected.

## Scenario

In this example, we will:

1. Start two platform simulators (Platform_30 and Platform_31)
2. Start their corresponding routing services (both initially in default team "ALL")
3. Start a Control simulator that receives data from both platforms
4. Use RemoteAdmin to assign Platform_31 to a different team (team "B")
5. Verify that Platform_30 and Platform_31 can no longer exchange data with each other (platform-to-platform isolation), but both can still communicate with Control

## Architecture

### Initial State (All in Default Team "ALL")

```
┌─────────────┐           ┌─────────────┐           ┌─────────────┐
│ Platform_30 │           │ Platform_31 │           │ Control_20   │
│  Simulator  │           │  Simulator  │           │  Simulator   │
└──────┬──────┘           └──────┬──────┘           └──────┬───────┘
       │                         │                         │
       │ Platform Domain 30      │ Platform Domain 31      │ Control Domain 20
       │                         │                         │
┌──────▼──────┐           ┌──────▼──────┐           ┌──────▼───────┐
│ Platform_30 │           │ Platform_31 │           │  Control_20  │
│   Router    │◄─────────►│   Router    │           │   Router     │
│  (Team ALL) │  P2P Comms│  (Team ALL) │           │  (Team ALL)  │
└──────┬──────┘  via TEAM └──────┬──────┘           └──────┬───────┘
       │         Channel         │                         │
       │                         │                         │
       └────────────────┬────────┴─────────────────────────┘
                        │ WAN Domain 200
              All platforms communicate with Control
              Platforms can communicate with each other (Team ALL)
```

### After Team Change (Platform_31 → Team B)

```
┌─────────────┐           ┌─────────────┐           ┌─────────────┐
│ Platform_30 │           │ Platform_31 │           │ Control_20   │
│  Simulator  │           │  Simulator  │           │  Simulator   │
└──────┬──────┘           └──────┬──────┘           └──────┬───────┘
       │                         │                         │
       │ Platform Domain 30      │ Platform Domain 31      │ Control Domain 20
       │                         │                         │
┌──────▼──────┐           ┌──────▼──────┐           ┌──────▼───────┐
│ Platform_30 │     X     │ Platform_31 │           │  Control_20  │
│   Router    │◄─────────►│   Router    │           │   Router     │
│  (Team ALL) │  ISOLATED │  (Team B)   │           │  (Team ALL)  │
└──────┬──────┘  P2P Only └──────┬──────┘           └──────┬───────┘
       │                         │                         │
       │                         │                         │
       └────────────────┬────────┴─────────────────────────┘
                        │ WAN Domain 200
              Both platforms still communicate with Control
              Platform_30 ✗ Platform_31 (different teams - P2P blocked)
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

Now use RemoteAdmin to assign Platform_31 to team "B":

```bash
cd tools/remote_admin
./send_remote_cmd.sh -n Platform_31 --type platform --team B
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
Partition XML being sent:
<participant><domain_participant_qos><partition><name><element>B</element></name></partition></domain_participant_qos></participant>

Command returned: OK
```

### Terminal 5 (Control_20): Verify Team Isolation

Switch back to Terminal 5 where the Control simulator is running. 

**Important**: Control will still receive data from **both** Platform_30 and Platform_31:

```
- Received ContactReport Data: 10 from source: Platform_30 type: Platform
- Received ContactReport Data: 11 from source: Platform_31 type: Platform
```

**Team isolation affects platform-to-platform communication only.** To verify the team isolation is working, you would need to enable the PLATFORM_TEAM_CHANNEL (see REMOTE_ENABLE_TEAM.md) and observe that platforms in different teams cannot exchange data with each other via that channel.

### Terminal 8: Reset Platform_31 to Default Team

To restore platform-to-platform communication capability, reset Platform_31's Domain Participant Partition back to "ALL" (the default):

```bash
cd tools/remote_admin
./send_remote_cmd.sh -n Platform_31 --team ALL --type platform
```

**Note**: The default Domain Participant Partition is "ALL", not an empty string.

### Verify Platform-to-Platform Communication Restored

After moving Platform_31 back to team "ALL", both platforms are now in the same team and can exchange data via the PLATFORM_TEAM_CHANNEL (when enabled). Control continues to receive data from both platforms regardless of team assignments.

## What's Happening Behind the Scenes

When you run `./send_remote_cmd.sh -n Platform_31 --team B`:

1. **RemoteAdmin constructs a resource identifier**:
   ```
   /routing_services/Platform_31/domain_routes/dr/participants/platform_wan
   ```
   This targets the WAN participant responsible for TEAM (platform-to-platform) communication, not the participant used for Control communication.

2. **Creates an XML QoS update** to set the partition:
   ```xml
   <participant>
     <domain_participant_qos>
       <partition>
         <name>
           <element>B</element>
         </name>
       </partition>
     </domain_participant_qos>
   </participant>
   ```

3. **Sends a CommandRequest** on the admin domain (100) to Platform_31's routing service

4. **Platform_31 router updates** its WAN participant's QoS to use partition "B"

5. **DDS enforces isolation**: Only participants with matching partitions can communicate

## Key Observations

- **Team isolation affects PLATFORM_TEAM_CHANNEL only**: Platform-to-platform communication is isolated by team assignment
- **Control communication unaffected**: All platforms can communicate with Control regardless of team assignment
- **Team changes are immediate**: As soon as the team change is applied, platform-to-platform isolation takes effect
- **No restart required**: The routing service remains running during the reconfiguration
- **Default team is "ALL"**: The default Domain Participant Partition is set to "ALL". Teams can be assigned using letter designations (A, B, C, etc.)

## Advanced: Assign Control to a Team

You can also assign Control to a specific team to create an isolated communication cell:

```bash
cd tools/remote_admin

# Move Platform_30 to team A (using ROUTER_NAME from params/platform_10_params.sh)
./send_remote_cmd.sh -n Platform_30 --team A --type platform

# Move Control_20 to team A (using ROUTER_NAME from params/control_20_params.sh)
./send_remote_cmd.sh -n Control_20 --team A --type control

# Platform_31 stays in default team
```

Now:
- Platform_30 and Control_20 communicate (both in team A)
- Platform_31 is isolated (in default team)
- To add Platform_31 to the team: `./send_remote_cmd.sh -n Platform_31 --team A --type platform`

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
- **REMOTE_ENABLE_FULL_STATUS.md**: Enable on-demand high-bandwidth telemetry
- **QUICKSTART.md**: Basic setup and initial testing
- **MULTI_PLATFORM.md**: Scaling to many platforms

## Summary

This example demonstrates:

✅ Dynamic team assignment using RemoteAdmin  
✅ [DDS Domain Participant Partition](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/users_manual/users_manual/PARTITION_QosPolicy.htm)-based isolation between teams  
✅ Runtime reconfiguration without service restarts  
✅ Verification of team isolation through message observation  
✅ Restoring communication by reassigning teams  

Teams provide a powerful mechanism for organizing and isolating platform-to-platform communication in complex distributed systems. Use RemoteAdmin to dynamically manage these assignments as operational requirements change.

---

## Questions or Feedback?

Reach out to us at **services_community@rti.com** - we welcome your questions and feedback!
