# ACT Multi-Platform Example

This example demonstrates a more advanced ACT (Autonomous Collaborative Teaming) deployment with **2 Platforms** and **1 C2 Station**, including **platform-to-platform (P2P)** communication.

## Overview

This example uses the shared scripts from `../node_sim/` to launch:
- **Platform 10 (USV_10)**: First unmanned surface vehicle
- **Platform 11 (USV_11)**: Second unmanned surface vehicle
- **C2 Station 20**: Command and control station

Key features demonstrated:
- Multiple platforms communicating through WAN
- Platform-to-platform (P2P) direct communication
- C2 commanding multiple platforms
- Contact report sharing between platforms

## Prerequisites

- RTI Connext DDS Professional 7.3.0+
- Python 3 with RTI Connext DDS Python API
- RTI Routing Service

## Full Deployment

Open **6 terminals** and run the following commands from the repository root:

### Terminal 1: Platform 10 Router
```bash
cd examples/node_sim
./start_platform10_router.sh
```

### Terminal 2: Platform 10 Simulator
```bash
cd examples/node_sim
./start_platform10_sim.sh
```

### Terminal 3: Platform 11 Router
```bash
cd examples/node_sim
./start_platform11_router.sh
```

### Terminal 4: Platform 11 Simulator
```bash
cd examples/node_sim
./start_platform11_sim.sh
```

### Terminal 5: C2-20 Router
```bash
cd examples/node_sim
./start_c2_20_router.sh
```

### Terminal 6: C2-20 Simulator
```bash
cd examples/node_sim
./start_c2_20_sim.sh
```

## What's Happening?

### Architecture

```
┌─────────────┐         ┌─────────────┐         ┌─────────────┐
│ Platform 10 │         │ Platform 11 │         │    C2-20    │
│  (Domain 10)│◄───────►│  (Domain 11)│◄───────►│  (Domain 20)│
└──────┬──────┘    P2P  └──────┬──────┘    WAN  └──────┬──────┘
       │                        │                        │
       └────────────────────────┴────────────────────────┘
                          WAN Domain 0
```

### Communication Flows

1. **Platform-to-C2 (via WAN)**:
   - Platforms publish `PlatformStatus` → C2 receives
   - C2 sends `C2Command` → Platforms receive
   - Platforms send `PlatformCommandAck` → C2 receives

2. **Platform-to-Platform (P2P)**:
   - Platforms share `PlatformData` directly
   - Platforms exchange `ContactReport` information
   - Collaborative awareness without C2 relay

3. **Multi-Platform Coordination**:
   - C2 monitors status from both platforms
   - C2 can command either platform independently
   - Platforms coordinate autonomously via P2P

## Expected Output

**Platform Simulators** will show:
- Publishing `PlatformStatus` to C2
- Publishing `PlatformData` for P2P
- Receiving `C2Command` from C2-20
- Sending `PlatformCommandAck` to C2-20
- Publishing `ContactReport` data

**C2 Simulator** will show:
- Receiving `PlatformStatus` from both USV_10 and USV_11
- Sending `C2Command` to both platforms
- Receiving `PlatformCommandAck` from both platforms
- Receiving `ContactReport` from both platforms

## Monitoring with RTI Tools

Monitor all three nodes with RTI Admin Console:

```bash
# From repository root
rtiadminconsole
```

You should see:
- Domain 10: USV_10 publications/subscriptions
- Domain 11: USV_11 publications/subscriptions
- Domain 20: C2_20 publications/subscriptions
- Domain 0: WAN routing traffic

## Testing P2P Communication

The P2P communication happens automatically between platforms. To verify:

1. Watch for `PlatformData` messages in the simulator output
2. Both platforms should see each other's data
3. Use RTI Admin Console to monitor domain 10 and 11 directly

## Advanced: Remote Administration

Control routers at runtime using the RemoteAdmin tool:

```bash
cd tools/remote_admin/build
./RemoteAdmin
```

RemoteAdmin allows you to:
- Enable/disable routes dynamically
- Pause/resume data flow
- Monitor routing service status
- Test failover scenarios

## Scaling to More Platforms

To add Platform 12:

1. Copy an existing platform param file:
   ```bash
   cd examples/node_sim/params
   cp platform_10_params.sh platform_12_params.sh
   ```

2. Edit `platform_12_params.sh`:
   - Change `PLATFORM_DOMAIN=12`
   - Change `ROUTER_NAME="USV_12"`
   - Change `SESSION_ID=12`

3. Copy and update start scripts:
   ```bash
   cp start_platform10_router.sh start_platform12_router.sh
   cp start_platform10_sim.sh start_platform12_sim.sh
   # Update both to source platform_12_params.sh
   ```

4. Run the new scripts in two additional terminals

## Configuration Details

All configurations are in `../node_sim/params/`:
- `platform_10_params.sh`: USV_10 on domain 10
- `platform_11_params.sh`: USV_11 on domain 11
- `c2_20_params.sh`: C2_20 on domain 20
- `config/params/system_params.sh`: WAN timing, channel setup and network parameters

QoS profiles are in `../../config/qos/`:
- `lan_qos_lib.xml`: LAN domain QoS
- `wan_qos_lib.xml`: WAN domain QoS
- `remoteadmin_qos_lib.xml`: Remote admin QoS

## Next Steps

- Experiment with stopping/starting individual routers
- Use RemoteAdmin to pause/resume routes
- Monitor with RTI Admin Console or RTI Monitor
- Add more platforms using the scaling instructions
- Modify QoS profiles to test different reliability settings

## Troubleshooting

**Issue**: Platforms can't see each other's P2P data
- **Solution**: Verify routing services are configured for P2P routes
- **Solution**: Check that both platform routers are running

**Issue**: C2 not receiving data from one platform
- **Solution**: Ensure that platform's router is running
- **Solution**: Check domain IDs in parameter files match

**Issue**: High latency or packet loss
- **Solution**: Adjust `config/params/system_params.sh` WAN timing parameters
- **Solution**: Check network connectivity between nodes
