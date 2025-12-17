# ACT Quickstart Example

This is a minimal example demonstrating the ACT (Autonomous Collaborative Teaming) system with **1 Platform** and **1 C2 Station**.

## Overview

This example launches:
- **Platform 10 (USV_10)**: A simulated unmanned surface vehicle
- **C2 Station 20**: A command and control station

Each node requires both a **routing service** (bridges domains) and a **simulator** (generates/processes data).

## Prerequisites

- [RTI Connext DDS Professional 7.3.0+](https://community.rti.com/static/documentation/developers/get-started/) (free license available immediately)
- Python 3 with RTI Connext DDS Python API ([setup guide](https://community.rti.com/static/documentation/developers/get-started/pip-install.html#section-pip-install))
- RTI Routing Service
- `NDDSHOME` environment variable set
- `RTI_LICENSE_FILE` environment variable set

## Quick Start

Open **4 terminals** and run the following commands from the repository root:

### Terminal 1: Platform 10 Router
```bash
cd start_scripts
./start_platform10_router.sh
```

### Terminal 2: Platform 10 Simulator
```bash
cd start_scripts
./start_platform10_sim.sh
```

### Terminal 3: C2-20 Router
```bash
cd start_scripts
./start_c2_20_router.sh
```

### Terminal 4: C2-20 Simulator
```bash
cd start_scripts
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

You can monitor the system using RTI Admin Console:

```bash
# From repository root
# Admin Console can use config/qos/rti_admin_console_qos_lib.xml for UDPv6
rtiadminconsole
```

## Next Steps

- Review scripts in `start_scripts/` and parameters in `params/`
- Try the [Multi-Platform](MULTI_PLATFORM.md) example
- Use [RemoteAdmin](tools/remote_admin/) to control routers at runtime

## Troubleshooting

**Issue**: Scripts fail with "file not found"
- **Solution**: Run scripts from `start_scripts/` directory

**Issue**: Python import errors
- **Solution**: Verify RTI Connext DDS Python API is installed and `NDDSHOME` is set
