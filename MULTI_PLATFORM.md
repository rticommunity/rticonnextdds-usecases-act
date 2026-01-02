# ACT Multi-Platform Example

This example demonstrates a more advanced ACT (Autonomous Collaborative Teaming) deployment with **2 Platforms** and **1 Control Station**, including **platform-to-platform (TEAM)** communication.

## Overview

This example launches:
- **Platform 10 (Platform_10)**: First unmanned surface vehicle
- **Platform 11 (Platform_11)**: Second unmanned surface vehicle
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

### Terminal 1: Platform 10 Router
```bash
cd scripts
./start_platform10_router.sh
```

### Terminal 2: Platform 10 Simulator
```bash
cd scripts
./start_platform10_sim.sh
```

### Terminal 3: Platform 11 Router
```bash
cd scripts
./start_platform11_router.sh
```

### Terminal 4: Platform 11 Simulator
```bash
cd scripts
./start_platform11_sim.sh
```

### Terminal 5: Control-20 Router
```bash
cd scripts
./start_control_20_router.sh
```

### Terminal 6: Control-20 Simulator
```bash
cd scripts
./start_control_20_sim.sh
```

## What's Happening?

### Architecture

```
┌─────────────┐         ┌─────────────┐         ┌─────────────┐
│ Platform 10 │         │ Platform 11 │         │    Control-20    │
│  (Domain 10)│◄───────►│  (Domain 11)│◄───────►│  (Domain 20)│
└──────┬──────┘    TEAM  └──────┬──────┘    WAN  └──────┬──────┘
       │                        │                        │
       └────────────────────────┴────────────────────────┘
                          WAN Domain 0
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
- Receiving `PlatformStatus` from both Platform_10 and Platform_11
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
- Domain 10: Platform_10 publications/subscriptions
- Domain 11: Platform_11 publications/subscriptions
- Domain 20: Control_20 publications/subscriptions
- Domain 0: WAN routing traffic

## Testing TEAM Communication

The TEAM communication happens automatically between platforms. To verify:

1. Watch for `PlatformData` messages in the simulator output
2. Both platforms should see each other's data
3. Use RTI Admin Console to monitor domain 10 and 11 directly

## Advanced: Remote Administration

Control routers at runtime using the [RemoteAdmin tool](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/services/routing_service/remote_admin.html):

```bash
cd tools/remote_admin
# Enable TEAM on Platform_10
./send_remote_cmd.sh -n Platform_10 --team true

# Assign Platform_11 to team 5
./send_remote_cmd.sh -n Platform_11 --type platform -g 5
```

RemoteAdmin allows you to:
- Enable/disable TEAM routes dynamically
- Assign nodes to different groups for isolation
- Control data flow without restarting services

See [REMOTE_ENABLE_TEAM.md](REMOTE_ENABLE_TEAM.md) and [REMOTE_CONTROL_TEAM.md](REMOTE_CONTROL_TEAM.md) for detailed examples.

## Scaling to More Platforms

To add Platform 12:

1. Copy an existing platform param file:
   ```bash
   cd params
   cp platform_10_params.sh platform_12_params.sh
   ```

2. Edit `platform_12_params.sh`:
   - Change `PLATFORM_DOMAIN=12`
   - Change `ROUTER_NAME="Platform_12"`
   - Change `SESSION_ID=12`

3. Copy and update start scripts:
   ```bash
   cp start_platform10_router.sh start_platform12_router.sh
   cp start_platform10_sim.sh start_platform12_sim.sh
   # Update both to source platform_12_params.sh
   ```

4. Run the new scripts in two additional terminals

## Configuration Details

All configurations are in `params/`:
- `platform_10_params.sh`: Platform_10 on domain 10
- `platform_11_params.sh`: Platform_11 on domain 11
- `control_20_params.sh`: Control_20 on domain 20
- `system_params.sh`: WAN timing, channel setup and network parameters

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
