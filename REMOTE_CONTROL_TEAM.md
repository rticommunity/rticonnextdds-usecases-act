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

**Note:** Team assignments affect platform-to-platform communication only. All platforms can still communicate with Control nodes regardless of team assignment. This is because each routing service uses separate DDS Domain Participants: one for platform-to-Control communication (which has no partition restrictions and communicates by default) and one for platform-to-platform (TEAM) communication (which uses partition-based isolation). The RemoteAdmin tool only modifies the partition on the TEAM participant, leaving Control communication completely unaffected.

**Important:** On startup, each platform initializes its Team participant with a unique partition identifier (e.g., "Platform_30", "Platform_31"). PLATFORM_TEAM_CHANNEL sessions are enabled by default, but platforms won't discover each other because they have different partitions. When assigned to a team, the partition is updated to the team name (e.g., "A", "B", "C"), enabling platforms in the same team to discover each other and communicate. The Control participant remains unchanged and continues normal platform-to-Control communication throughout this process.

## Scenario

In this example, we will:

1. Start two platform simulators (Platform_30 and Platform_31)
2. Start their corresponding routing services (both initially with unique partition identifiers: "Platform_30" and "Platform_31")
3. Verify platforms are isolated from each other (cannot communicate via PLATFORM_TEAM_CHANNEL)
4. Use RemoteAdmin to assign both platforms to team "A" (changing partitions from unique identifiers to shared team name)
5. Verify platforms can now communicate with each other via PLATFORM_TEAM_CHANNEL
6. Note that Control communication remains unaffected throughout (Control receives data from both platforms at all times)

## Architecture

### Initial State (Unique Partition Identifiers on Startup)

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
│   Router    │     X     │   Router    │           │   Router     │
│ (Partition: │◄─────────►│ (Partition: │           │              │
│ Platform_30)│  ISOLATED │ Platform_31)│           │              │
└──────┬──────┘  P2P      └──────┬──────┘           └──────┬───────┘
       │         Blocked         │                         │
       │                         │                         │
       └────────────────┬────────┴─────────────────────────┘
                        │ WAN Domain 200
              All platforms communicate with Control
              Platforms isolated from each other (unique partitions)
```

### After Team Assignment (Both Platforms → Team A)

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
│ (Partition: │  P2P Comms│ (Partition: │           │              │
│    Team A)  │  Enabled  │    Team A)  │           │              │
└──────┬──────┘           └──────┬──────┘           └──────┬───────┘
       │                         │                         │
       │                         │                         │
       └────────────────┬────────┴─────────────────────────┘
                        │ WAN Domain 200
              Both platforms communicate with Control
              Platform_30 ✓ Platform_31 (same team A - P2P enabled)
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
./start_platform_sim.sh --id 30
```

You should see output indicating the simulator is publishing `PlatformData`:

```
Publishing PlatformData with Session ID 0
Publishing PlatformData with Session ID 1
...
```

### Terminal 2: Start Platform_30 Router

```bash
cd scripts
./start_platform_router.sh --id 30
```

The routing service will start and bridge Platform_30's platform domain to the WAN domain. Look for:

```
RTI Routing Service started
```

### Terminal 3: Start Platform_31 Simulator

```bash
cd scripts
./start_platform_sim.sh --id 31
```

Similar output as Platform_30, publishing session data.

### Terminal 4: Start Platform_31 Router

```bash
cd scripts
./start_platform_router.sh --id 31
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

### Verify Initial Isolation

Before making any changes, note that Platform_30 and Platform_31 are isolated from each other (different unique partitions: "Platform_30" and "Platform_31"). However, Control receives data from both platforms because the Control participant has no partition restrictions.

### Terminal 7: Assign Both Platforms to Team A

Now use RemoteAdmin to assign both platforms to team "A":

**Assign Platform_30 to team A:**
```bash
cd tools/remote_admin
./send_remote_cmd.sh -n Platform_30 -t A
```

**Assign Platform_31 to team A:**
```bash
./send_remote_cmd.sh -n Platform_31 -t A
```

Expected output for each command:

```
=============================================================
Remote Admin - RTI Routing Service Controller
=============================================================
Using system parameters from: rticonnextdds-usecases-act/params
Exported NDDS_QOS_PROFILES: rticonnextdds-usecases-act/config/qos/remoteadmin_qos_lib.xml
=============================================================

Waiting for a matching replier...
Sending Remote TEAM UPDATE: 
resource_identifier: /routing_services/platform/domain_routes/dr/participants/team_wan
Partition XML being sent:
<participant><domain_participant_qos><partition><name><element>A</element></name></partition></domain_participant_qos></participant>

Command returned: OK
```

### Verify Team Member Communication

With both platforms now assigned to team "A", they can discover each other and exchange data via the PLATFORM_TEAM_CHANNEL.

**Important**: Control continues to receive data from both platforms throughout all team assignments. Team partitions only affect platform-to-platform communication via PLATFORM_TEAM_CHANNEL.

### Optional: Separate Platforms Into Different Teams

To demonstrate team isolation, you can assign platforms to different teams:

```bash
cd tools/remote_admin
./send_remote_cmd.sh -n Platform_30 -t A
./send_remote_cmd.sh -n Platform_31 -t B
```

Now Platform_30 (team A) and Platform_31 (team B) cannot communicate with each other via PLATFORM_TEAM_CHANNEL, but both still communicate with Control.

## What's Happening Behind the Scenes

When you run `./send_remote_cmd.sh -n Platform_30 -t A`:

1. **RemoteAdmin constructs a resource identifier**:
   ```
   /routing_services/Platform_30/domain_routes/dr/participants/platform_wan
   ```
   This targets the WAN participant responsible for TEAM (platform-to-platform) communication, not the participant used for Control communication.

2. **Creates an XML QoS update** to set the partition:
   ```xml
   <participant>
     <domain_participant_qos>
       <partition>
         <name>
           <element>A</element>
         </name>
       </partition>
     </domain_participant_qos>
   </participant>
   ```

3. **Sends a CommandRequest** on the admin domain (100) to Platform_30's routing service

4. **Platform_30 router updates** its WAN Team participant's QoS to use partition "A"

5. **DDS enforces matching**: Platforms with the same partition can now discover each other and communicate via PLATFORM_TEAM_CHANNEL

## Key Observations

- **Team isolation affects PLATFORM_TEAM_CHANNEL only**: Platform-to-platform communication is isolated by team assignment
- **Control communication unaffected**: All platforms can communicate with Control regardless of team assignment
- **Unique partitions on startup**: Platforms initialize with unique partition identifiers (e.g., "Platform_30") to prevent unintended team communication
- **Team assignment changes partition**: Assigning to a team updates the partition to the team name (e.g., "A", "B", "C")
- **Team changes are immediate**: As soon as the partition change is applied, platform-to-platform isolation takes effect
- **No restart required**: The routing service remains running during the reconfiguration

## Cleanup

To stop all processes, press `Ctrl+C` in each terminal:

1. Terminal 1: Platform_30 simulator
2. Terminal 2: Platform_30 router
3. Terminal 3: Platform_31 simulator
4. Terminal 4: Platform_31 router
5. Terminal 5: Control_20 simulator
6. Terminal 6: Control_20 router

## Related Examples

- **REMOTE_ENABLE_DETAIL_STATUS.md**: Enable on-demand high-bandwidth telemetry
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
