# ACT Production Deployment Guide

This guide provides step-by-step instructions for deploying the ACT (Autonomous Collaborative Teaming) architecture in a production environment.

**Important**: This guide is for **production deployments only**. If you're learning the system, see the [Examples README](../examples/README.md) instead.

---

## Table of Contents

1. [Prerequisites](#prerequisites)
2. [Understanding the Architecture](#understanding-the-architecture)
3. [Deployment Structure](#deployment-structure)
4. [Step-by-Step Deployment](#step-by-step-deployment)
5. [Configuration Reference](#configuration-reference)
6. [RemoteAdmin Tool Setup](#remoteadmin-tool-setup)
7. [Running Your Deployment](#running-your-deployment)
8. [Monitoring and Verification](#monitoring-and-verification)
9. [Troubleshooting](#troubleshooting)
10. [Best Practices](#best-practices)

---

## Prerequisites

### Required
- **RTI Connext DDS 7.3.0 or later** installed
- **`NDDSHOME` environment variable** set to your RTI Connext installation directory
- Basic understanding of DDS concepts (domains, topics, QoS)
- Your data types defined (IDL files)

### Recommended
- Familiarity with RTI Routing Service
- Understanding of your network topology (LAN/WAN characteristics)
- Experience running the [example walkthroughs](../examples/) first

### Verify Prerequisites
```bash
# Check RTI Connext installation
echo $NDDSHOME
ls $NDDSHOME/bin/rtiroutingservice

# Check version
$NDDSHOME/bin/rtiroutingservice -version
```

---

## Understanding the Architecture

Before deploying, you should understand the key architectural concepts including network segmentation, QoS profiles, data channels, and routing patterns.

**📚 For comprehensive architectural details, see:** [Technical Details](../TECHNICAL_DETAILS.md)

Key concepts covered in the Technical Details:
- **Network Architecture**: Domain segmentation, port allocation, and routing service operation
- **QoS Profiles**: RELIABLE vs BEST_EFFORT delivery patterns
- **WAN Tuning**: High-latency network configuration
- **Data Channels**: Topic routing and content filtering

**Quick Summary**:
- **Platform Domains** (10-19): Vehicle/platform local networks
- **WAN Domain** (3): Wide area network bridging all nodes  
- **C2 Domains** (20-29): Command & control station networks
- **Admin Domain** (100): Remote administration control plane

---

## Deployment Structure

### Recommended Directory Layout

Create a **separate deployment directory** (not inside this repository):

```
my_act_deployment/
├── config/                          # Copy from repository
│   ├── qos/
│   │   ├── lan_qos_lib.xml         # LAN QoS profiles
│   │   ├── wan_qos_lib.xml         # WAN QoS profiles
│   │   └── remoteadmin_qos_lib.xml # RemoteAdmin QoS
│   └── routing/
│       └── routing_service_config.xml
├── params/
│   └── system_params.sh            # System-wide configuration
└── nodes/
    ├── platform_10/                # Each node gets a folder
    │   ├── node_params.sh          # Node-specific config
    │   ├── start_router.sh         # Start routing service
    │   └── start_app.sh            # Start your application
    ├── platform_11/
    │   └── ...
    └── c2_20/
        └── ...
```

**Why this structure?**
- Centralizes shared configuration (`config/`, `params/`)
- Isolates node-specific files (`nodes/`)
- Makes it easy to add new nodes
- Keeps deployment separate from repository updates

---

## Step-by-Step Deployment

### Step 1: Create Deployment Directory

```bash
# Create your deployment root
mkdir -p my_act_deployment
cd my_act_deployment

# Create structure
mkdir -p config params nodes
```

### Step 2: Copy Configuration Files

```bash
# Copy the entire config folder from the repository
cp -r <path_to_repo>/config/* config/

# Verify files copied
ls config/qos/
ls config/routing/
```

This includes:
- **QoS profiles** for LAN/WAN communication
- **Routing service configuration** for all node types

### Step 3: Create System Parameters

The system parameters file contains settings shared by **all nodes**.

```bash
# Copy template
cp <path_to_repo>/templates/params/system_params.template.sh params/system_params.sh

# Edit the file
vim params/system_params.sh
```

**Key Configuration Areas:**

#### A. Update File Paths
Since `system_params.sh` is now in `params/`, update paths:
```bash
# Change from:
NDDS_QOS_PROFILES="../../config/qos/..."

# To:
NDDS_QOS_PROFILES="../config/qos/remoteadmin_qos_lib.xml:"
NDDS_QOS_PROFILES+="../config/qos/lan_qos_lib.xml:"
NDDS_QOS_PROFILES+="../config/qos/wan_qos_lib.xml:"
NDDS_QOS_PROFILES+="../config/routing/routing_service_config.xml"
```

#### B. Configure WAN Parameters
Adjust based on your network characteristics:
```bash
# For Satellite Link (example)
export WAN_TTL=6                    # Multicast time-to-live
export WAN_LATENCY_SEC=1.5          # Round-trip time (seconds)
export WAN_TIMEOUT_SEC=300          # Node unreachable timeout

# For Low-Latency Radio Mesh (example)
export WAN_TTL=6 (TTL depends on your network settings)
export WAN_LATENCY_SEC=0.5
export WAN_TIMEOUT_SEC=120
```

#### C. Define Data Channels
Specify which topics use which routes and QoS patterns:
```bash
# Events: RELIABLE delivery, critical data
export PLATFORM_EVENT_CHANNEL=PlatformCommandAck,ContactReport,CriticalAlert
export C2_EVENT_CHANNEL=MissionUpdate,NewTarget

# Status: BEST_EFFORT delivery, periodic updates
export PLATFORM_STATUS_10SEC_CHANNEL=PlatformStatus,Telemetry

# Platform-to-Platform: Direct communication between platforms
export PLATFORM_TO_PLATFORM_CHANNEL=PlatformData,SharedSensor

# Filtered Commands: Content filtering for targeted delivery
export C2_COMMAND_FILTER_CHANNEL=C2Command
export C2_COMMAND_FILTER_FIELD=msg.destination
export C2_COMMAND_FILTER_MATCH=$ROUTER_NAME  # Only accept commands for this node
```

**Note**: Replace these example topic names with your actual data types.

### Step 4: Add Your First Node (Platform)

Let's add Platform-10 as an example:

#### 4.1: Create Node Directory
```bash
mkdir -p nodes/platform_10
```

#### 4.2: Create Node Parameters
```bash
cp <path_to_repo>/templates/params/node_params.template.sh nodes/platform_10/node_params.sh

# Edit nodes/platform_10/node_params.sh
vim nodes/platform_10/node_params.sh
```

Replace placeholders:
```bash
# Change:
TYPE="{{NODE_TYPE}}"
export DOMAIN_ID={{DOMAIN_ID}}
export ROUTER_NAME="{{NODE_NAME}}"

# To:
TYPE="platform"                  # "platform" or "c2"
export DOMAIN_ID=10              # Unique domain per node
export ROUTER_NAME="USV_10"      # Descriptive name
```

#### 4.3: Create Router Start Script
```bash
cp <path_to_repo>/templates/scripts/start_node_router.template.sh nodes/platform_10/start_router.sh

# Edit nodes/platform_10/start_router.sh
vim nodes/platform_10/start_router.sh
```

Update paths:
```bash
# Change:
source {{PARAM_FILE}}

# To:
source ./node_params.sh

# Change system_params.sh path:
source ../../params/system_params.sh
```

Make executable:
```bash
chmod +x nodes/platform_10/start_router.sh
```

#### 4.4: Create Application Start Script
```bash
cp <path_to_repo>/templates/scripts/start_node.template.sh nodes/platform_10/start_app.sh

# Edit nodes/platform_10/start_app.sh
vim nodes/platform_10/start_app.sh
```

**Customize the application section** with your actual application:
```bash
################################################################################
#                        SYSTEM-SPECIFIC PROCESSES                              #
################################################################################

# Example: Start your C++ application
./my_platform_app &
APP_PID=$!

# Example: Start Python application
# python3 platform_control.py &
# APP_PID=$!

# Example: Multiple processes
# ./sensor_driver &
# ./autopilot &
# python3 mission_planner.py &

echo "Application started with PID: $APP_PID"
```

Make executable:
```bash
chmod +x nodes/platform_10/start_app.sh
```

### Step 5: Add Additional Nodes

Repeat Step 4 for each additional node:

#### For Another Platform (Platform-11):
```bash
mkdir -p nodes/platform_11
# Copy and edit files with:
#   TYPE="platform"
#   DOMAIN_ID=11
#   ROUTER_NAME="USV_11"
```

#### For a C2 Station (C2-20):
```bash
mkdir -p nodes/c2_20
# Copy and edit files with:
#   TYPE="c2"
#   DOMAIN_ID=20
#   ROUTER_NAME="C2_20"
```

**Domain ID Guidelines:**
- Platforms: Any unique domain. Generally same Domain ID for all Platforms. 
- C2 Stations: Any unique domain. Generally same Domain ID for all Platforms. 
- WAN: Current Default is 3. Recommend not using 0.
- Admin: 100 (for RemoteAdmin)

### Step 6: Define Your Data Types

Create IDL files for your custom data types:

```bash
# Example: my_act_deployment/types/my_types.idl
mkdir -p types
```

```idl
// types/my_types.idl
module MyTypes {
    struct PlatformStatus {
        string<100> source;
        double latitude;
        double longitude;
        float speed;
        // ... your fields
    };

    struct C2Command {
        string<100> destination;
        long command_type;
        // ... your fields
    };
};
```

Generate type support:
```bash
cd types
rtiddsgen -language C++11 -platform x64Linux4gcc7.3.0 my_types.idl
```

Update your application code to use these types.

---

## Configuration Reference

### Node Types

Set `TYPE` in `node_params.sh`:

| Type | Description | Domain | Routing Config |
|------|-------------|--------------|----------------|
| `platform` | Vehicle/UAV/USV | 10 | Platform routes |
| `c2` | Command station | 20 | C2 routes |

### Data Channel Types

Defined in `system_params.sh`:

| Channel | QoS | Use Case | Example Topics |
|---------|-----|----------|----------------|
| PLATFORM_EVENT_CHANNEL | RELIABLE | Critical aperiodic data | Acks, Alerts, Reports |
| PLATFORM_STATUS_*_CHANNEL | BEST_EFFORT | Periodic status | Telemetry, Position |
| C2_EVENT_CHANNEL | RELIABLE | Critical commands | Missions, Targets |
| C2_COMMAND_FILTER_CHANNEL | RELIABLE + Filtered | Targeted commands | Direct commands |
| PLATFORM_TO_PLATFORM_CHANNEL | RELIABLE/BEST_EFFORT | P2P communication | Shared data |

### WAN Tuning Parameters

| Parameter | Description | Satellite Example | Radio Mesh Example |
|-----------|-------------|-------------------|-------------------|
| WAN_LATENCY_SEC | Round-trip time | 1.5 | 0.2 |
| WAN_TIMEOUT_SEC | Unreachable timeout | 300 | 60 |
| WAN_TTL | Multicast hops | 6 | 4 |

**Auto-calculated values** (don't modify):
- `WAN_HB_PERIOD_SEC` = 2 × WAN_LATENCY_SEC
- `WAN_HB_RETRIES` = WAN_TIMEOUT_SEC / WAN_HB_PERIOD_SEC
- `WAN_MAX_BLOCKING_SEC` = 10 × WAN_LATENCY_SEC

---

## Running Your Deployment

### Startup Sequence

**1. Start All Routing Services First**
```bash
# Platform-10
cd nodes/platform_10
./start_router.sh &

# Platform-11
cd ../platform_11
./start_router.sh &

# C2-20
cd ../c2_20
./start_router.sh &
```

**2. Wait for Discovery** (< couple seconds)
Routing services could need time to discover each other on WAN domain.

**3. Start Applications**
```bash
# Platform-10 application
cd nodes/platform_10
./start_app.sh &

# Platform-11 application
cd ../platform_11
./start_app.sh &

# C2-20 application
cd ../c2_20
./start_app.sh &
```


### Running on Multiple Machines

For distributed deployment:

1. **Install on each node**:
   ```bash
   # Copy deployment folder to each machine
   scp -r my_act_deployment user@platform10:/opt/act/
   ```

2. **Start router and app on each machine**:
   ```bash
   # On platform-10 machine:
   cd /opt/act/my_act_deployment/nodes/platform_10
   ./start_router.sh
   ./start_app.sh
   ```

3. **Ensure network connectivity**:
   - All routers must reach WAN domain (multicast or unicast)
   - Configure `NDDS_DISCOVERY_PEERS` if needed for WAN

---

## Monitoring and Verification

### Check Routing Service Logs

Look for successful discovery:
```
Session <session_name> ENABLED
Route <route_name> ENABLED
```

Look for participant matching:
```
DomainParticipant matched remote participant
```

### Use RTI Tools

**RTI Admin Console:**
```bash
$NDDSHOME/bin/rtiadminconsole
```
- View all participants on WAN domain (0)
- Check routing service status
- Monitor data flow


### Verify Data Flow

**Expected Behavior:**
1. Routing services discover each other (WAN domain 0)
2. Applications discover local routers (LAN domains)
3. Data flows: App → Router → WAN → Router → App
4. Content filtering works (commands only to intended recipients)


---

## Troubleshooting

### Router Won't Start

**Problem**: `rtiroutingservice` command not found
```bash
# Solution: Set NDDSHOME
export NDDSHOME=/path/to/rti_connext_dds-7.3.0
export PATH=$NDDSHOME/bin:$PATH
```

**Problem**: "Cannot load QoS profile"
```bash
# Solution: Check NDDS_QOS_PROFILES in system_params.sh
echo $NDDS_QOS_PROFILES
# Verify files exist at those paths
```

**Problem**: "Configuration name not found"
```bash
# Solution: Check TYPE in node_params.sh matches routing config
# Must be "platform" or "c2"
```


### Content Filtering Not Working

**Problem**: Platform receives commands meant for other platforms

**Solution**: Verify content filter configuration
```bash
# In system_params.sh:
export C2_COMMAND_FILTER_CHANNEL="C2Command"     # Topic name
export C2_COMMAND_FILTER_FIELD="msg.destination" # Field in the data type
export C2_COMMAND_FILTER_MATCH=$ROUTER_NAME      # Should match node name

# Ensure your C2Command type has a 'destination' field
# Commands must set destination to the target platform name
```

### RemoteAdmin "No matching replier found"

**Problem**: RemoteAdmin can't connect to routing service

**Checklist:**
- [ ] Routing service running?
- [ ] Application name matches? (Check `-appName` in router script vs `-n` in RemoteAdmin)
- [ ] Both using admin domain 100?
- [ ] NDDS_QOS_PROFILES set correctly?

```bash
# Verify router was started with -appName
ps aux | grep rtiroutingservice

# Should see: rtiroutingservice -appName Platform-10 ...

# RemoteAdmin must use same name:
./remote_admin.sh -n Platform-10 -t platform --p2p true
```


## Best Practices

### Development Workflow
1. ✅ **Test with examples first** - Understand architecture before deploying
2. ✅ **Start small** - Deploy 1 platform + 1 C2, then scale
3. ✅ **Version control your deployment** - Track configuration changes
4. ✅ **Document your channels** - Maintain a list of topics and their routing
5. ✅ **Test incrementally** - Add one node at a time

### Configuration Management
1. ✅ **Keep deployment separate from repo** - Use templates, don't copy examples
2. ✅ **Single system_params.sh** - All nodes share one configuration
3. ✅ **Unique node names** - Use clear, descriptive names (USV_10, C2_20, etc.)
4. ✅ **Unique domain IDs** - Never reuse domain IDs across nodes
5. ✅ **Document customizations** - Note any changes to QoS profiles

### Network Configuration
1. ✅ **Measure WAN latency** - Use actual network measurements for tuning
2. ✅ **Test WAN failover** - Verify timeout settings handle link loss
3. ✅ **Use multicast when possible** - Enables automatic discovery
4. ✅ **Configure NDDS_DISCOVERY_PEERS** - For unicast-only networks


---

## Next Steps

### After Initial Deployment

1. **Run example walkthroughs** to understand features:
   - [QUICKSTART.md](../examples/QUICKSTART.md)
   - [MULTI_PLATFORM.md](../examples/MULTI_PLATFORM.md)
   - [REMOTE_ENABLE_P2P.md](../examples/REMOTE_ENABLE_P2P.md)
   - [REMOTE_CONTROL_GROUP.md](../examples/REMOTE_CONTROL_GROUP.md)

2. **Customize data channels** for your use case

3. **Integrate your applications** with DDS APIs

4. **Test failure scenarios**:
   - WAN link loss
   - Node failures
   - High latency conditions

5. **Optimize performance** based on measurements

### Additional Resources

- **Main README**: [../README.md](../README.md) - Architecture overview
- **RemoteAdmin README**: [../tools/remote_admin/README.md](../tools/remote_admin/README.md) - Tool details
- **RTI Documentation**: RTI Connext DDS User's Manual
- **RTI Community**: https://community.rti.com/

---

## Support

For issues or questions:
1. Check [Troubleshooting](#troubleshooting) section above
2. Review [example walkthroughs](../examples/)
3. Consult RTI Connext DDS documentation
4. Contact RTI Support

---

**Document Version**: 1.0  
**Last Updated**: December 2024  
**Applies To**: RTI Connext DDS 7.3.0+
