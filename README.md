# Autonomous Collaborative Teaming (ACT) - Routing Service Architecture

RTI Routing Service architecture for Autonomous Collaborative Teaming use cases to manage message flow between Platforms (vehicles/UAVs/USVs) and C2 (Command and Control) stations.

This use case is centered around a Maritime ISR scenario but can be adapted for other collaborative teaming applications.

## Repository Structure

```
rticonnextdds-usecases-act/
├── config/                      # System-wide configuration
│   ├── qos/                    # QoS profiles (LAN, WAN, Remote Admin)
│   └── routing/                # Routing Service configuration
├── examples/                    # Demo implementations for learning
│   ├── QUICKSTART.md           # 1 Platform + 1 C2 walkthrough
│   ├── MULTI_PLATFORM.md       # 2 Platforms + 1 C2 walkthrough
│   └── node_sim/               # Python simulators and demo scripts
├── templates/                   # Starting points for deployment
│   ├── README.md               # Detailed deployment instructions
│   ├── params/                 # Parameter file templates
│   └── scripts/                # Start script templates
├── tools/                       # Utilities
│   └── remote_admin/           # Remote administration tool
└── docs/                        # Documentation and diagrams
```

## Quick Start

### For Learning (Examples)
See the `examples/` folder for demo implementations:
- **QUICKSTART.md**: Simple 1 Platform + 1 C2 setup
- **MULTI_PLATFORM.md**: Advanced 2 Platforms + 1 C2 with P2P communication
- **REMOTE_ENABLE_P2P.md**: Dynamically enable platform-to-platform communication
- **REMOTE_CONTROL_GROUP.md**: Dynamically assign nodes to groups for isolation

### For Deployment (Production)
See the `templates/` folder for deployment templates:
1. Copy `config/` folder to your deployment directory
2. Use templates to create your node configurations
3. Customize for your specific use case

**Important**: Examples are for learning only. For production deployment, use templates to create a separate deployment structure.

## Use Case Requirements:
- Platforms must be able to receive select topics from C2 [C2 Events](#c2-events)
- Platforms must be able to receive *only* commands addressed to a destination [C2 Filtered Commands](#filtered-commands)
- *Only* any C2 must be able to receive select topics from Platforms [Platform Events](#platform-events)
- C2 must be able to receive select *downsampled* topics from Platforms [Platform Status](#platform-status) 
- Platforms must be able to receive select topics from other Platforms [Platform to Platform](#platform-to-platform)  
- All Platforms and C2 have automatic discovery of other Platforms and C2 endpoints

## Network Architecture
The system has been separated into 3 DDS domains:
- Platform (Vehicle or Platform network)
- WAN (Communications network i.e. Sat, Mesh Radio)
- C2 (C2 Network- Groundstations etc.)

Routing Service acts as a relay mechanism between the *internal* LAN and  
the *external* WAN DDS Domain.

This allows For Network level isolation of messaging as DDS Domains isolate  
through unique port range allocation.

## Features
This infrastructure performs the following roles:
- Dynamic instantiation of readers/writers based on regex match filters
- Dynamic application of QoS per data "Channel"
- Network-level segmentation using DDS Domains (LAN vs WAN isolation)
- Content-filtered routing for targeted command delivery
- Routing of selected topics between:
  - Platform → C2
  - C2 → Platform
  - Platform ↔ Platform
- Dynamic discovery of Platforms and C2 systems
- Scalable pub/sub architecture supporting one-to-many/many-to-one communication
- **Runtime reconfiguration** via RemoteAdmin tool for:
  - Enabling/disabling platform-to-platform communication routes
  - Assigning nodes to groups (partitions) for logical isolation
  - Dynamic control without service restarts

## Architecture Overview

### Network Segmentation
The system uses 3 DDS domains for network-level isolation:
- **Platform Domain** (10-19): Vehicle/Platform local network
- **WAN Domain** (0): Wide Area Network (Satellite, Mesh Radio, etc.)
- **C2 Domain** (20-29): Command & Control network

RTI Routing Service acts as a bridge between domains, enabling secure and controlled message flow while maintaining network isolation through unique port ranges.

### QoS Profiles
Two primary QoS patterns are configured in `config/qos/`:
- **Status QoS** (BEST_EFFORT): For periodic data (e.g., status updates)
- **Event QoS** (RELIABLE): For aperiodic critical data (e.g., commands, events)

### Data Channels
Configurable "channels" in `system_params.sh` allow you to:
- Group topics by data pattern (periodic vs aperiodic)
- Apply appropriate QoS policies per channel
- Use regex matching for topic selection
- Control routing behavior without modifying XML files

See the [Data Channels](#data-channels) section below for details.

![ACT Routing Architecture](docs/images/act_routing_arch.jpeg)


## Examples

The `examples/` folder contains hands-on walkthroughs with Python simulators to demonstrate the ACT routing architecture. These are for **learning and testing only** - not for production deployment.

### [QUICKSTART.md](examples/QUICKSTART.md)
**What it demonstrates**: Basic setup with 1 Platform and 1 C2 station

Get started quickly with a simple configuration that shows:
- Platform sending status updates to C2 (periodic data)
- C2 sending commands to Platform (targeted delivery)
- Basic routing service configuration
- Channel-based QoS application

**Best for**: First-time users learning the fundamentals

### [MULTI_PLATFORM.md](examples/MULTI_PLATFORM.md)
**What it demonstrates**: Advanced setup with 2 Platforms and 1 C2 station

Explores multi-platform scenarios including:
- Multiple platforms communicating with C2
- Platform discovery and dynamic routing
- Content filtering for targeted commands
- Scaling considerations

**Best for**: Understanding multi-node deployments

### [REMOTE_ENABLE_P2P.md](examples/REMOTE_ENABLE_P2P.md)
**What it demonstrates**: Dynamic platform-to-platform communication control

Shows runtime reconfiguration capabilities:
- Starting platforms with P2P disabled
- Using RemoteAdmin tool to enable direct platform-to-platform routes
- Verifying bidirectional data flow between platforms
- Dynamic control without service restarts

**Best for**: Learning runtime route management and collaborative platform operations

### [REMOTE_CONTROL_GROUP.md](examples/REMOTE_CONTROL_GROUP.md)
**What it demonstrates**: Dynamic group assignment and isolation

Explores partition-based group isolation with a practical scenario:
- 2 Platforms + 1 C2 initially communicating
- Using RemoteAdmin tool to assign one platform to a different group
- Observing message flow changes in real-time (C2 stops receiving from isolated platform)
- Restoring communication by reassigning groups

**Best for**: Understanding logical isolation, partition-based security, and mission separation patterns

---

## RELIABLE delivery
For aperiodic, critical data (commands, events), RELIABLE QoS ensures message delivery through automatic retransmission.

After sending a RELIABLE message, Connext sends "heartbeats" (piggyback or separate) to verify reception. If acknowledgment isn't received, the message is resent.

**Configuration**: Event channels use `WAN::event_qos` profile (defined in `config/qos/`)
- Reliability: RELIABLE
- Tunable via WAN parameters in `system_params.sh`

**Used by**: `*_EVENT_CHANNEL`, `C2_COMMAND_FILTER_CHANNEL`

## BEST_EFFORT delivery
For periodic, non-critical data (status updates), BEST_EFFORT QoS sends messages once without retransmission. This is acceptable when new data arrives frequently.

**Configuration**: Status channels use `WAN::status_qos` profile (defined in `config/qos/`)
- Reliability: BEST_EFFORT
- Lower overhead, no acknowledgments

**Used by**: `*_STATUS_*_CHANNEL`, `PLATFORM_TO_PLATFORM_CHANNEL`


## Data "Channels"

Data channels provide an abstraction layer for routing configuration. Instead of modifying XML files, you define channels in `system_params.sh` that group topics by their data pattern and apply appropriate QoS policies.

**Channel Configuration** (in `system_params.sh`):
- Comma-separated topic names (no spaces)
- Supports regex matching with wildcards (e.g., `*Status` matches any prefix)
- Use `NULL` for unused channels

**Available Channels:**
- `PLATFORM_EVENT_CHANNEL`: Infrequent, critical platform events (RELIABLE)
- `PLATFORM_STATUS_*_CHANNEL`: Periodic status at various rates (BEST_EFFORT, with downsampling)
- `PLATFORM_TO_PLATFORM_CHANNEL`: Platform-to-platform communication (BEST_EFFORT)
- `C2_EVENT_CHANNEL`: C2 events to platforms (RELIABLE)
- `C2_COMMAND_FILTER_CHANNEL`: Content-filtered commands (RELIABLE, destination-based)

**Content Filtering** (C2 Commands):
The `C2_COMMAND_FILTER_CHANNEL` uses content-based filtering to ensure each platform receives only commands addressed to it:
- `C2_COMMAND_FILTER_FIELD`: Field path in message (e.g., `msg.destination`)
  - **Must match your actual message data structure**
- `C2_COMMAND_FILTER_MATCH`: Value to match (typically `$ROUTER_NAME`)

![ACT Data Channels Logical View](docs/images/act_channels.jpeg)

---

## Deployment

For production deployment:
1. See `templates/README.md` for complete instructions
2. Copy `config/` folder to your deployment
3. Use templates to create node configurations
4. Customize paths, domain IDs, and data channels for your use case

**Do not use the `examples/` folder for production** - it contains demo code with Python simulators for learning purposes only.

---

## Additional Resources

- **Remote Admin Tool**: See `tools/remote_admin/` for runtime configuration capabilities including enabling/disabling P2P routes and assigning nodes to groups
- **Architecture Diagrams**: See `docs/images/` for system architecture visuals
- **QoS Profiles**: See `config/qos/` for LAN, WAN, and Remote Admin QoS configurations
- **Routing Config**: See `config/routing/routing_service_config.xml` for routing rules

For questions or issues, please refer to the RTI Connext DDS documentation or contact RTI support.

