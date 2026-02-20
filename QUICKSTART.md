# ACT Quickstart Example

This is a minimal example demonstrating the ACT (Autonomous Collaborative Teaming) system with **1 Platform** and **1 Control Station**.

## Overview

This example launches:
- **Platform 30 (Platform_30)**: A simulated platform node
- **Control Station 20 (Control_20)**: A command and control station

Each node requires both a **routing service** (bridges domains) and a **simulator** (generates/processes data).

## Prerequisites

- [RTI Connext DDS Professional 7.3.0+](https://community.rti.com/static/documentation/developers/get-started/) (free license available immediately)
- Python 3 with RTI Connext DDS Python API ([setup guide](https://community.rti.com/static/documentation/developers/get-started/pip-install.html#section-pip-install))
- RTI Routing Service
- `NDDSHOME` environment variable set
- `RTI_LICENSE_FILE` environment variable set

## Quick Start

Open **4 terminals** and run the following commands from the repository root:

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

### Terminal 3: Control-20 Router
```bash
cd scripts
./start_control_router.sh --id 20
```

### Terminal 4: Control-20 Simulator
```bash
cd scripts
./start_control_sim.sh --id 20
```

## What's Happening?

1. **Platform 30 Router**: Bridges Platform LAN (domain 30) ↔ WAN (domain 200) ↔ Control LAN (domain 20)
2. **Platform 30 Simulator**: Publishes status updates, receives commands from Control
3. **Control-20 Router**: Bridges Control LAN (domain 20) ↔ WAN (domain 200) ↔ Platform LAN (domain 30)
4. **Control-20 Simulator**: Receives platform status, sends commands to platforms

## Expected Output

**Platform Simulator** will show:
- Publishing `PlatformStatus` messages periodically
- Receiving `ControlCommand` messages from Control-20
- Sending `PlatformCommandAck` acknowledgments

**Control Simulator** will show:
- Receiving `PlatformStatus` from Platform_30
- Sending `ControlCommand` to Platform_30
- Receiving `PlatformCommandAck` from Platform_30

## Monitoring with RTI Tools

You can monitor the system using RTI Admin Console:

```bash
# From repository root
# Admin Console can use config/qos/rti_admin_console_qos_lib.xml for UDPv6
rtiadminconsole
```

## Next Steps

- Review scripts in `scripts/` and parameters in `params/`
- Try the [Multi-Platform](MULTI_PLATFORM.md) example
- Use [RemoteAdmin](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext-dds_professional/services/routing_service/remote_admin.html) ([local tool docs](tools/remote_admin/README.md)) to control routers at runtime - see [REMOTE_CONTROL_TEAM.md](REMOTE_CONTROL_TEAM.md) and [REMOTE_ENABLE_DETAIL_STATUS.md](REMOTE_ENABLE_DETAIL_STATUS.md) for examples

## Troubleshooting

**Issue**: Scripts fail with "file not found"
- **Solution**: Run scripts from `scripts/` directory

**Issue**: Python import errors
- **Solution**: Verify RTI Connext DDS Python API is installed and `NDDSHOME` is set

---

## Questions or Feedback?

Reach out to us at **services_community@rti.com** - we welcome your questions and feedback!
