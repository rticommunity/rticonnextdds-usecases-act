# ACT Quickstart Example

This is a minimal example demonstrating the ACT (Autonomous Collaborative Teaming) system with **1 Platform** and **1 C2 Station**.

## Overview

This example uses the shared scripts from `../node_sim/` to launch:
- **Platform 10 (USV_10)**: A simulated unmanned surface vehicle
- **C2 Station 20**: A command and control station

Each node requires both a **routing service** (bridges domains) and a **simulator** (generates/processes data).

## Prerequisites

- RTI Connext DDS Professional 7.3.0+
- Python 3 with RTI Connext DDS Python API
- RTI Routing Service

## Quick Start

Open **4 terminals** and run the following commands from the repository root:

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

### Terminal 3: C2-20 Router
```bash
cd examples/node_sim
./start_c2_20_router.sh
```

### Terminal 4: C2-20 Simulator
```bash
cd examples/node_sim
./start_c2_20_sim.sh
```

## What's Happening?

1. **Platform 10 Router**: Bridges Platform LAN (domain 10) ↔ WAN (domain 0) ↔ C2 LAN (domain 20)
2. **Platform 10 Simulator**: Publishes status updates, receives commands from C2
3. **C2-20 Router**: Bridges C2 LAN (domain 20) ↔ WAN (domain 0) ↔ Platform LAN (domain 10)
4. **C2-20 Simulator**: Receives platform status, sends commands to platforms

## Expected Output

**Platform Simulator** will show:
- Publishing `PlatformStatus` messages periodically
- Receiving `C2Command` messages from C2-20
- Sending `PlatformCommandAck` acknowledgments

**C2 Simulator** will show:
- Receiving `PlatformStatus` from USV_10
- Sending `C2Command` to USV_10
- Receiving `PlatformCommandAck` from USV_10

## Monitoring with RTI Tools

You can monitor the system using RTI Admin Console or RTI Monitor:

```bash
# From repository root
# Admin Console will use config/qos/rti_admin_console_qos_lib.xml
rtiadminconsole
```

## Next Steps

- Review the scripts in `../node_sim/` to understand the configuration
- Check parameter files in `../node_sim/params/` to see domain/QoS settings
- Try the **multi-platform** example for a more advanced scenario
- Use the **RemoteAdmin** tool (`tools/remote_admin/`) to control routers at runtime

## Troubleshooting

**Issue**: Scripts fail with "file not found"
- **Solution**: Make sure to run scripts from `examples/node_sim/` directory

**Issue**: Simulators don't see each other's data
- **Solution**: Ensure both routers are running before starting simulators

**Issue**: Python import errors
- **Solution**: Verify RTI Connext DDS Python API is installed and `NDDSHOME` is set
