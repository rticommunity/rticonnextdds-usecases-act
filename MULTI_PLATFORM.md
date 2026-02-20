# ACT Multi-Platform Example

This example demonstrates a more advanced ACT (Autonomous Collaborative Teaming) deployment with **2 Platforms** and **1 Control Station**, including **platform-to-platform (TEAM)** communication.

## Overview

This example launches:
- **Platform 30 (Platform_30)**: First unmanned "Platform"
- **Platform 31 (Platform_31)**: Second unmanned "Platform"
- **Control Station 20**: Command and control station

Key features demonstrated:
- Multiple platforms communicating through WAN
- Platform-to-platform (TEAM) direct communication
- Control commanding multiple platforms
- Contact report sharing between platforms

## Prerequisites

- [RTI Connext DDS Professional 7.3.0+](https://community.rti.com/static/documentation/developers/get-started/) (free license available immediately)
- Python 3 with RTI Connext DDS Python API ([setup guide](https://community.rti.com/static/documentation/developers/get-started/pip-install.html#section-pip-install))
- RTI Routing Service
- `NDDSHOME` environment variable set
- `RTI_LICENSE_FILE` environment variable set

## Full Deployment

Open **6 terminals** and run the following commands from the repository root:

### Terminal 1: Platform 30 Router
```bash
cd scripts
./start_platform_router.sh --id 30
```

### Terminal 2: Platform 30 Simulator
```bash
cd scripts
./start_platform_sim.sh --id 30
```

### Terminal 3: Platform 31 Router
```bash
cd scripts
./start_platform_router.sh --id 31
```

### Terminal 4: Platform 31 Simulator
```bash
cd scripts
./start_platform_sim.sh --id 31
```

### Terminal 5: Control-20 Router
```bash
cd scripts
./start_control_router.sh --id 20
```

### Terminal 6: Control-20 Simulator
```bash
cd scripts
./start_control_sim.sh --id 20
```

## What's Happening?

### Architecture

```
┌──────────────┐         ┌─────────────┐         ┌───────────────┐
│ Platform 30  │         │ Platform 31 │         │    Control-20 │
│  (Domain 30) │◄───────►│  (Domain 31)│◄───────►│  (Domain 20)  │
└──────┬───────┘   TEAM  └──────┬──────┘    WAN  └──────┬────────┘
       │                        │                       │
       └────────────────────────┴───────────────────────┘
                          WAN Domain 200
```

### Communication Flows

1. **Platform-to-Control (via WAN)**:
   - Platforms publish `PlatformStatus` → Control receives
   - Control sends `ControlCommand` → Platforms receive
   - Platforms send `PlatformCommandAck` → Control receives

2. **Platform-to-Platform (TEAM)**:
   - Platforms share `PlatformData` directly
   - Platforms exchange `ContactReport` information
   - Collaborative awareness without Control relay

3. **Multi-Platform Coordination**:
   - Control monitors status from both platforms
   - Control can command either platform independently
   - Platforms coordinate autonomously via TEAM

## Expected Output

**Platform Simulators** will show:
- Publishing `PlatformStatus` to Control
- Publishing `PlatformData` for TEAM
- Receiving `ControlCommand` from Control-20
- Sending `PlatformCommandAck` to Control-20
- Publishing `ContactReport` data

**Control Simulator** will show:
- Receiving `PlatformStatus` from both Platform_30 and Platform_31
- Sending `ControlCommand` to both platforms
- Receiving `PlatformCommandAck` from both platforms
- Receiving `ContactReport` from both platforms

## Monitoring with RTI Tools

Monitor all three nodes with RTI Admin Console:

```bash
# From repository root
rtiadminconsole
```

You should see:
- Domain 30: Platform_30 publications/subscriptions
- Domain 31: Platform_31 publications/subscriptions
- Domain 20: Control_20 publications/subscriptions
- Domain 200: WAN routing traffic

## Testing TEAM Communication

The TEAM communication happens automatically between platforms. To verify:

1. Watch for `PlatformData` messages in the simulator output
2. Both platforms should see each other's data
3. Use RTI Admin Console to monitor domain 30 and 31 directly

## Advanced: Remote Administration

Control routers at runtime using the [RemoteAdmin tool](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/services/routing_service/remote_admin.html):

```bash
cd tools/remote_admin
# Assign Platform_30 to team A
./send_remote_cmd.sh -n Platform_30 -t A

# Assign Platform_31 to team B
./send_remote_cmd.sh -n Platform_31 -t B

# Enable detailed status on Platform_30
./send_remote_cmd.sh -n Platform_30 --detail true
```

RemoteAdmin allows you to:
- Assign platforms to different teams for isolation
- Enable detailed status telemetry on-demand
- Control data flow without restarting services

See [REMOTE_CONTROL_TEAM.md](REMOTE_CONTROL_TEAM.md) and [REMOTE_ENABLE_DETAIL_STATUS.md](REMOTE_ENABLE_DETAIL_STATUS.md) for detailed examples.

## Scaling to More Platforms

Adding additional platforms is trivial. To add Platform 32:

**Terminal 1: Platform 32 Router**
```bash
cd scripts
./start_platform_router.sh --id 32
```

**Terminal 2: Platform 32 Simulator**
```bash
cd scripts
./start_platform_sim.sh --id 32
```

That's it! The scripts automatically:
- Generate `ROUTER_NAME="Platform_32"`
- Set `PLATFORM_DOMAIN=32`
- Set `SESSION_ID=32`
- Configure all other parameters

You can add platforms 30-99 without creating any new files.

## Configuration Details

All configurations are in `params/`:
- `system_params.sh`: WAN timing, channel setup, discovery peers, and network parameters

Node configs are dynamic:
- Platform: `start_platform_sim.sh --id <num>` and `start_platform_router.sh --id <num>` (IDs 30-99)
- Control: `start_control_sim.sh --id <num>` and `start_control_router.sh --id <num>` (IDs 10-29)

QoS profiles are in `config/qos/`:
- `lan_qos_lib.xml`: LAN domain QoS
- `wan_qos_lib.xml`: WAN domain QoS
- `remoteadmin_qos_lib.xml`: Remote admin QoS

## Next Steps

- Experiment with stopping/starting individual routers
- Use RemoteAdmin to pause/resume routes
- Monitor with RTI Admin Console
- Add more platforms using the scaling instructions
- Modify QoS profiles to test different reliability settings

## Troubleshooting

**Issue**: Platforms can't see each other's TEAM data
- **Solution**: Verify routing services are configured for TEAM routes
- **Solution**: Check that both platform routers are running

**Issue**: Control not receiving data from one platform
- **Solution**: Ensure that platform's router is running
- **Solution**: Check domain IDs in parameter files match

**Issue**: High latency or packet loss
- **Solution**: Adjust `params/system_params.sh` WAN timing parameters
- **Solution**: Check network connectivity between nodes

---

## Questions or Feedback?

Reach out to us at **services_community@rti.com** - we welcome your questions and feedback!
