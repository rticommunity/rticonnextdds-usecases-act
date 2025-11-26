# Simulation Scripts and Parameters

This folder contains all simulation-related scripts, Python node simulators, and parameter configuration files for the ACT (Autonomous Collaborative Teaming) use case.

Each **node** (platform or C2 station) in the system requires both a routing service and a simulator component.

## Directory Structure

```
sim/
├── params/                        # Parameter configuration files
│   ├── platform_10_params.sh     # Platform 10 (USV_10) configuration
│   ├── platform_11_params.sh     # Platform 11 (USV_11) configuration
│   ├── c2_20_params.sh            # C2 Station 20 configuration
│   └── wan_params.sh              # WAN network parameters
├── python_node/                   # Python node simulator implementations
│   ├── platform_sim.py            # Platform simulator
│   └── c2_sim.py                  # C2 simulator
├── start_platform10_sim.sh        # Launch Platform 10 simulator
├── start_platform10_router.sh     # Launch Platform 10 routing service
├── start_platform11_sim.sh        # Launch Platform 11 simulator
├── start_platform11_router.sh     # Launch Platform 11 routing service
├── start_c2_20_sim.sh             # Launch C2-20 simulator
├── start_c2_20_router.sh          # Launch C2-20 routing service
├── start_node_sim.sh              # Generic node simulator (requires params)
└── README.md                      # This file
```

**Note**: Each node-specific script (e.g., `start_platform10_sim.sh`) sources its parameter file and then runs the appropriate simulator or router.

## Quick Start

### Running Complete Systems (Router + Simulator)

For each node, you need to run both the routing service and the simulator in separate terminals:

**Platform 10 (USV_10):**
```bash
# Terminal 1: Start routing service
cd sim
./start_platform10_router.sh

# Terminal 2: Start simulator
cd sim
./start_platform10_sim.sh
```

**Platform 11 (USV_11):**
```bash
# Terminal 1: Start routing service
cd sim
./start_platform11_router.sh

# Terminal 2: Start simulator
cd sim
./start_platform11_sim.sh
```

**C2 Station 20:**
```bash
# Terminal 1: Start routing service
cd sim
./start_c2_20_router.sh

# Terminal 2: Start simulator
cd sim
./start_c2_20_sim.sh
```

### Running Only Simulators

If routing services are already running, you can run just the simulators:

```bash
# Platform 10 simulator only
cd sim
./start_platform10_sim.sh

# Platform 11 simulator only
cd sim
./start_platform11_sim.sh

# C2-20 simulator only
cd sim
./start_c2_20_sim.sh
```

### Running Only Routers

If you want to run routing services without simulators:

```bash
# Platform 10 router only
cd sim
./start_platform10_router.sh

# Platform 11 router only
cd sim
./start_platform11_router.sh

# C2-20 router only
cd sim
./start_c2_20_router.sh
```

## Parameter Files

### Platform Parameters
- **platform_10_params.sh**: Configures USV_10 on domain 10
- **platform_11_params.sh**: Configures USV_11 on domain 11

Each platform parameter file sets:
- `ROUTER_NAME`: Platform identifier (e.g., USV_10)
- `PLATFORM_DOMAIN`: LAN domain ID
- `DOMAIN_ID`: Same as PLATFORM_DOMAIN
- `DESTINATION`: Target C2 station
- `SESSION_ID`: Unique session identifier
- `LAN_QOS_PROFILE`: QoS profile for LAN communication

### C2 Parameters
- **c2_20_params.sh**: Configures C2_20 station on domain 20

Sets:
- `ROUTER_NAME`: C2 identifier (C2_20)
- `C2_DOMAIN`: LAN domain ID
- `DOMAIN_ID`: Same as C2_DOMAIN
- `DESTINATION`: Target platform (e.g., USV_10)
- `SESSION_ID`: Unique session identifier

### WAN Parameters
- **wan_params.sh**: Network timing and reliability parameters

Configures:
- `WAN_TTL`: Multicast TTL
- `WAN_LATENCY_SEC`: Max WAN link latency
- `WAN_TIMEOUT_SEC`: Timeout for intermittent loss
- Calculated values for heartbeats and retries

## Simulator Scripts

### Platform Simulator (python_node/platform_sim.py)
Simulates a platform/vehicle that:
- Publishes `PlatformStatus` at regular intervals
- Publishes `PlatformData` for P2P communication
- Receives and processes `C2Command` messages
- Sends `PlatformCommandAck` acknowledgments
- Publishes `ContactReport` data

### C2 Simulator (python_node/c2_sim.py)
Simulates a Command & Control station that:
- Receives `PlatformStatus` from platforms
- Sends `C2Command` to specific platforms
- Receives `PlatformCommandAck` acknowledgments
- Receives and processes `ContactReport` data

## Creating New Configurations

To add a new node (e.g., Platform 12):

1. **Create a parameter file** in `params/`:
   ```bash
   cp params/platform_10_params.sh params/platform_12_params.sh
   ```

2. **Edit the parameters**:
   ```bash
   export PLATFORM_DOMAIN=12
   export ROUTER_NAME="USV_12"
   export SESSION_ID=12
   # ... etc
   ```

3. **Create simulator start script**:
   ```bash
   cp start_platform10_sim.sh start_platform12_sim.sh
   ```

4. **Create router start script**:
   ```bash
   cp start_platform10_router.sh start_platform12_router.sh
   ```

5. **Update the source lines** in both new scripts:
   ```bash
   source ./params/platform_12_params.sh
   ```

6. **Make them executable**:
   ```bash
   chmod +x start_platform12_sim.sh start_platform12_router.sh
   ```

## Command-Line Arguments

The Python node simulators accept these arguments:
- `--files`: XML configuration files (QoS and types)
- `--qos_profile`: DDS QoS profile to use
- `--domain_id`: DDS domain ID
- `--source`: Source identifier (simulator name)
- `--destination`: Destination identifier
- `--session`: Session ID
- `--verbosity`: Logging level (0-3)

## Integration with Routing Service

Each node requires two components running simultaneously:

1. **Routing Service** (router scripts): Bridges LAN ↔ WAN ↔ C2 domains
   - Handles data transformation and routing between domains
   - Applies QoS policies and filtering rules
   - Enables remote administration via RemoteAdmin tool

2. **Simulator** (sim scripts): Publishes/subscribes on LAN domains
   - Platform simulators: Generate status updates and process commands
   - C2 simulators: Send commands and receive platform status

### Typical Deployment

A complete system requires:
- 1+ Platform nodes (each needs router + sim)
- 1+ C2 nodes (each needs router + sim)
- RemoteAdmin tool (optional, for dynamic control)

Example 2-platform, 1-C2 deployment (6 terminals):
```
Terminal 1: sim/start_platform10_router.sh
Terminal 2: sim/start_platform10_sim.sh
Terminal 3: sim/start_platform11_router.sh
Terminal 4: sim/start_platform11_sim.sh
Terminal 5: sim/start_c2_20_router.sh
Terminal 6: sim/start_c2_20_sim.sh
```

## Notes

- All scripts must be run from the `sim/` directory
- Python 3 with RTI Connext DDS Python API required
- Parameter files are sourced by start scripts to set environment variables
- XML paths are relative to the `sim/` directory
