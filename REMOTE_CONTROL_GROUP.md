# Remote Control Group Assignment Example

This example demonstrates how to use the RemoteAdmin tool to dynamically assign nodes to different groups (DDS partitions) and verify that group isolation prevents cross-group communication. You'll see how changing a platform's group assignment stops C2 from receiving its data.

## Concept

In the ACT architecture, **groups** are implemented using DDS partitions to logically isolate communication between nodes. Only nodes assigned to the same group can exchange data. This is useful for:

- **Mission separation**: Different teams or operations on separate groups
- **Security zones**: Restricting data flow to authorized participants
- **Testing isolation**: Running multiple configurations without interference
- **Dynamic reorganization**: Moving nodes between groups during runtime

The RemoteAdmin tool allows you to change a node's group assignment without restarting the routing service, enabling dynamic reconfiguration.

## Scenario

In this example, we will:

1. Start two platform simulators (Platform-10 and Platform-11)
2. Start their corresponding routing services (both initially in default group)
3. Start a C2 simulator that receives data from both platforms
4. Use RemoteAdmin to assign Platform-11 to a different group (group 5)
5. Verify that C2 no longer receives data from Platform-11 but still receives from Platform-10

## Architecture

### Initial State (All in Default Group)

```
┌─────────────┐           ┌─────────────┐           ┌─────────────┐
│ Platform-10 │           │ Platform-11 │           │    C2-20    │
│  Simulator  │           │  Simulator  │           │  Simulator  │
└──────┬──────┘           └──────┬──────┘           └──────┬──────┘
       │                         │                         │
       │ LAN Domain 0            │ LAN Domain 1            │ C2 Domain 2
       │                         │                         │
┌──────▼──────┐           ┌──────▼──────┐           ┌──────▼──────┐
│ Platform-10 │           │ Platform-11 │           │    C2-20    │
│   Router    │◄──────────┤   Router    │──────────►│   Router    │
│  (default)  │  WAN      │  (default)  │  WAN      │  (default)  │
└─────────────┘  Domain 10└─────────────┘  Domain 10└─────────────┘
      ▲                                                     │
      │                                                     │
      └─────────────────────────────────────────────────────┘
           C2 receives data from both Platform-10 and Platform-11
```

### After Group Change (Platform-11 → Group 5)

```
┌─────────────┐           ┌─────────────┐           ┌─────────────┐
│ Platform-10 │           │ Platform-11 │           │    C2-20    │
│  Simulator  │           │  Simulator  │           │  Simulator  │
└──────┬──────┘           └──────┬──────┘           └──────┬──────┘
       │                         │                         │
       │ LAN Domain 0            │ LAN Domain 1            │ C2 Domain 2
       │                         │                         │
┌──────▼──────┐           ┌──────▼──────┐           ┌──────▼──────┐
│ Platform-10 │           │ Platform-11 │           │    C2-20    │
│   Router    │     X     │   Router    │     X     │   Router    │
│  (default)  │◄─────────┤│  (group 5) ││──────────►│  (default)  │
└─────────────┘  ISOLATED └─────────────┘  ISOLATED └─────────────┘
      ▲              └──────────┘                          │
      │             Group Mismatch                         │
      └────────────────────────────────────────────────────┘
           C2 receives data ONLY from Platform-10
```

## Prerequisites

- RTI Connext DDS 7.3.0 or later ([C++ setup guide](https://community.rti.com/static/documentation/developers/get-started/apt-install.html))
- Python 3 with RTI Connext DDS Python API ([setup guide](https://community.rti.com/static/documentation/developers/get-started/pip-install.html#section-pip-install))
- `NDDSHOME` environment variable set
- `RTI_LICENSE_FILE` environment variable set
- RemoteAdmin tool built (`tools/remote_admin/build/RemoteAdmin`)
- Parameter files in `params/`

## Step-by-Step Walkthrough

### Terminal 1: Start Platform-10 Simulator

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

### Terminal 2: Start Platform-10 Router

```bash
cd scripts
./start_platform10_router.sh
```

The routing service will start and bridge Platform-10's LAN domain to the WAN domain. Look for:

```
RTI Routing Service started
```

### Terminal 3: Start Platform-11 Simulator

```bash
cd scripts
./start_platform11_sim.sh
```

Similar output as Platform-10, publishing session data.

### Terminal 4: Start Platform-11 Router

```bash
cd scripts
./start_platform11_router.sh
```

### Terminal 5: Start C2 Simulator

```bash
cd scripts
./start_c2_20_sim.sh
```

**Important**: Watch the C2 output carefully. You should see it receiving data from **both** Platform-10 and Platform-11:

```
Received PlatformData with Session ID 15 from DDS sample
Received PlatformData with Session ID 27 from DDS sample
...
```

The session IDs will alternate or interleave, showing data from both platforms.

### Terminal 6: Verify Initial State

Before making any changes, confirm C2 is receiving from both platforms. Let it run for about 10-15 seconds and observe the session IDs. You should see a mix of session IDs from both simulators.

### Terminal 7: Change Platform-11 Group Assignment

Now use RemoteAdmin to assign Platform-11 to group 5:

```bash
cd tools/remote_admin
./remote_admin.sh -n Platform-11 -t platform -g 5
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
Sending Remote GROUP UPDATE: 
resource_identifier: /routing_services/Platform-11/domain_routes/dr/participants/platform_wan
body_text: str://"<participant><domain_participant_qos><partition><name><element>5</element></name></partition></domain_participant_qos></participant>"
application_name: Platform-11
Command returned: OK
```

### Terminal 5 (C2): Verify Group Isolation

Switch back to Terminal 5 where the C2 simulator is running. You should now see:

**Before group change:**
```
Received PlatformData with Session ID 15 from DDS sample  ← Platform-10
Received PlatformData with Session ID 27 from DDS sample  ← Platform-11
Received PlatformData with Session ID 16 from DDS sample  ← Platform-10
Received PlatformData with Session ID 28 from DDS sample  ← Platform-11
```

**After group change:**
```
Received PlatformData with Session ID 17 from DDS sample  ← Platform-10
Received PlatformData with Session ID 18 from DDS sample  ← Platform-10
Received PlatformData with Session ID 19 from DDS sample  ← Platform-10
Received PlatformData with Session ID 20 from DDS sample  ← Platform-10
```

Notice that after the group change, you only see session IDs from Platform-10. Platform-11's data is no longer received because it's in a different group (partition).

### Terminal 7: Move Platform-11 Back to Default Group

To restore communication, move Platform-11 back to the default group (empty partition):

```bash
cd tools/remote_admin
./remote_admin.sh -n Platform-11 -t platform -g ""
```

**Note**: Use an empty string `""` or `''` for the default (no partition) group.

### Terminal 5 (C2): Verify Communication Restored

After moving Platform-11 back to the default group, C2 should start receiving data from both platforms again:

```
Received PlatformData with Session ID 45 from DDS sample  ← Platform-10
Received PlatformData with Session ID 31 from DDS sample  ← Platform-11
Received PlatformData with Session ID 46 from DDS sample  ← Platform-10
```

## What's Happening Behind the Scenes

When you run `./remote_admin.sh -n Platform-11 -g 5`:

1. **RemoteAdmin constructs a resource identifier**:
   ```
   /routing_services/Platform-11/domain_routes/dr/participants/platform_wan
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

- **Group isolation is immediate**: As soon as the group change is applied, communication stops
- **No restart required**: The routing service remains running during the reconfiguration
- **Session IDs continue**: Platform-11 keeps publishing, but C2 can't receive it
- **Bidirectional isolation**: Platform-11 also can't receive data meant for the default group
- **Group "0" vs empty**: The default group is an empty partition, not partition "0"

## Advanced: Assign C2 to a Group

You can also assign C2 to a specific group to create an isolated communication cell:

```bash
# Move Platform-10 to group 3
./remote_admin.sh -n Platform-10 -t platform -g 3

# Move C2-20 to group 3
./remote_admin.sh -n C2-20 -t c2 -g 3

# Platform-11 stays in default group
```

Now:
- Platform-10 and C2-20 communicate (both in group 3)
- Platform-11 is isolated (in default group)
- To add Platform-11 to the group: `./remote_admin.sh -n Platform-11 -g 3`

## Troubleshooting

### C2 Still Receiving Data After Group Change

- **Verify the command succeeded**: Check RemoteAdmin output for "Command returned: OK"
- **Check routing service logs**: Look for partition updates in the router terminal
- **Confirm correct resource name**: Use `-n Platform-11` not `-n platform-11` (case-sensitive)
- **Wait a few seconds**: There may be a small delay for DDS discovery to update

### RemoteAdmin Shows "No matching replier found"

- **Verify routing service is running**: Check Terminal 4 (Platform-11 router)
- **Check application name**: The `-appName Platform-11` in the router must match `-n Platform-11` in RemoteAdmin
- **Verify admin domain**: Both router and RemoteAdmin must use the same admin domain (default: 100)

### C2 Not Receiving Any Data

- **Check all routers are running**: Verify Terminals 2 and 4 show active routing services
- **Verify simulators are publishing**: Check Terminals 1 and 3 for "Publishing PlatformData" messages
- **Check C2 router**: Ensure `start_c2_20_router.sh` is running (if using separate C2 router)

## Cleanup

To stop all processes, press `Ctrl+C` in each terminal:

1. Terminal 1: Platform-10 simulator
2. Terminal 2: Platform-10 router
3. Terminal 3: Platform-11 simulator
4. Terminal 4: Platform-11 router
5. Terminal 5: C2-20 simulator

## Related Examples

- **REMOTE_ENABLE_P2P.md**: Enable direct platform-to-platform communication
- **QUICKSTART.md**: Basic setup and initial testing
- **MULTI_PLATFORM.md**: Scaling to many platforms

## Summary

This example demonstrates:

✅ Dynamic group assignment using RemoteAdmin  
✅ DDS partition-based isolation between groups  
✅ Runtime reconfiguration without service restarts  
✅ Verification of group isolation through message observation  
✅ Restoring communication by reassigning groups  

Groups provide a powerful mechanism for organizing and isolating communication in complex distributed systems. Use RemoteAdmin to dynamically manage these assignments as operational requirements change.

---

## Questions or Feedback?

Reach out to us at **services_community@rti.com** - we welcome your questions and feedback!
