# ACT Examples and Tutorials

This folder contains **example implementations** for learning the ACT (Autonomous Collaborative Teaming) architecture.

⚠️ **Important**: These examples are **for learning only**. For production deployment, see the [Deployment Guide](../templates/DEPLOYMENT.md).

---

## Quick Start

All examples are self-contained and ready to run. Each provides step-by-step instructions.

### Prerequisites
- RTI Connext DDS 7.3.0 or later
- `NDDSHOME` environment variable set

### Available Examples

| Example | Description | Complexity | Time | Link |
|---------|-------------|------------|------|------|
| Basic Data Flow | 1 Platform + 1 C2 | ⭐ Basic | 15 min | [QUICKSTART.md](QUICKSTART.md) |
| Multi-Platform System | 2 Platforms + 1 C2 with P2P | ⭐⭐ Intermediate | 20 min | [MULTI_PLATFORM.md](MULTI_PLATFORM.md) |
| Dynamic P2P Control | Runtime P2P enable/disable | ⭐⭐⭐ Advanced | 20 min | [REMOTE_ENABLE_P2P.md](REMOTE_ENABLE_P2P.md) |
| Group Assignment | Partition-based isolation | ⭐⭐⭐ Advanced | 20 min | [REMOTE_CONTROL_GROUP.md](REMOTE_CONTROL_GROUP.md) |

---

## Example Details

### 1. [QUICKSTART.md](QUICKSTART.md) - Basic Data Flow ⭐

**Use Case**: Single platform communicating with a command station through WAN.

**Scenario**: 
- USV-10 (autonomous surface vehicle) operating in the field
- C2-20 (command and control station) monitoring and controlling the platform
- Communication over satellite or radio WAN link

**What's Demonstrated**:
- ✅ Platform → C2: Status updates (periodic, 10-second intervals)
- ✅ C2 → Platform: Commands (content-filtered by destination)
- ✅ Platform → C2: Command acknowledgments (reliable events)
- ✅ Domain bridging: Platform LAN (domain 10) ↔ WAN (domain 0) ↔ C2 LAN (domain 20)
- ✅ QoS profiles: BEST_EFFORT for status, RELIABLE for commands/acks
- ✅ Content filtering: Platform only receives commands addressed to it

**Architecture**:
```
Platform-10 (Domain 10) <--> Router <--> WAN (Domain 0) <--> Router <--> C2-20 (Domain 20)
```

**What You'll Learn**:
- How routing services bridge DDS domains
- How content filtering targets specific recipients
- Difference between RELIABLE and BEST_EFFORT QoS
- Basic system startup and monitoring

**Best For**: First-time users, understanding core architecture

---

### 2. [MULTI_PLATFORM.md](MULTI_PLATFORM.md) - Multi-Platform System ⭐⭐

**Use Case**: Multiple platforms collaborating and sharing data with each other and C2.

**Scenario**:
- USV-10 and USV-11 (two autonomous vehicles) operating in the same area
- C2-20 monitoring both platforms
- Platforms share sensor data and coordinated maneuvers
- All nodes communicate through WAN infrastructure

**What's Demonstrated**:
- ✅ Multiple platforms (USV-10, USV-11) simultaneously
- ✅ Platform-to-Platform (P2P) communication for collaboration
- ✅ C2 receives data from all platforms
- ✅ Each platform has isolated LAN domain (10, 11)
- ✅ Scalable architecture pattern
- ✅ Automatic discovery of new platforms

**Architecture**:
```
Platform-10 (Domain 10) <--> Router <--\
                                        \
                                         WAN (Domain 0) <--> Router <--> C2-20 (Domain 20)
                                        /
Platform-11 (Domain 11) <--> Router <--/
                    ^                                                          
                    |_________P2P Data (via WAN)_________|
```

**What You'll Learn**:
- Scaling from 1 to N platforms
- Platform-to-platform data routes
- Managing multiple routing services
- Discovery at scale

**Best For**: Understanding how the system scales, collaborative autonomous systems

---

### 3. [REMOTE_ENABLE_P2P.md](REMOTE_ENABLE_P2P.md) - Dynamic P2P Control ⭐⭐⭐

**Use Case**: Dynamically enabling platform-to-platform communication based on operational needs without restarting services.

**Scenario**:
- USV-10 and USV-11 initially operating independently
- Mission update requires coordinated maneuver
- Operator remotely enables P2P communication from C2 station
- Platforms begin sharing tactical data
- After coordination, P2P can be disabled to reduce bandwidth

**What's Demonstrated**:
- ✅ RemoteAdmin tool for runtime control
- ✅ Enabling P2P routes without service restart
- ✅ Disabling P2P routes to conserve bandwidth
- ✅ Remote administration API usage
- ✅ Immediate reconfiguration (no downtime)
- ✅ Admin domain (100) for control plane

**Commands Used**:
```bash
# Enable P2P for Platform-10
./remote_admin.sh -n Platform-10 -t platform --p2p true

# Disable P2P for Platform-10
./remote_admin.sh -n Platform-10 -t platform --p2p false
```

**Architecture**:
```
RemoteAdmin (Domain 100) --[Commands]--> Routing Services
                                              |
                                        [Enable/Disable]
                                              |
                                         P2P Routes
```

**What You'll Learn**:
- Using RemoteAdmin tool for live reconfiguration
- Remote administration request-reply pattern
- Bandwidth management through selective routing
- Operational flexibility without restarts

**Best For**: Operations teams, bandwidth-constrained environments, dynamic mission requirements

---

### 4. [REMOTE_CONTROL_GROUP.md](REMOTE_CONTROL_GROUP.md) - Group Assignment ⭐⭐⭐

**Use Case**: Assigning platforms to logical groups for data isolation and multi-tenant operations.

**Scenario**:
- Multiple platforms operating in the same physical area
- Platform-10 and Platform-11 assigned to different task groups
- C2-20 monitors all platforms but can filter by group
- Group assignment changed dynamically based on mission phase
- Data isolation prevents cross-group information leakage

**What's Demonstrated**:
- ✅ DDS partitions for logical grouping
- ✅ Dynamic group assignment via RemoteAdmin
- ✅ Data isolation between groups
- ✅ Multi-tenant scenarios (different organizations/missions)
- ✅ Group-based data filtering
- ✅ Operational security through isolation

**Commands Used**:
```bash
# Assign Platform-11 to group 5
./remote_admin.sh -n Platform-11 -t platform -g 5

# Assign Platform-11 back to default group (0)
./remote_admin.sh -n Platform-11 -t platform -g 0
```

**Architecture**:
```
Group 0 (default):        Platform-10 <--> C2-20 (receives all)
                          
Group 5 (isolated):       Platform-11 <--> [isolated] <-X-> C2-20 (no data)
```

**What You'll Learn**:
- DDS partitions for data isolation
- Multi-tenant system architecture
- Dynamic partition assignment
- Security through network segmentation
- Coalition operations patterns

**Best For**: Multi-tenant systems, coalition operations, security-sensitive deployments, mission-phase transitions

---

## Learning Path

### Step 1: Understand Basic Architecture
**Start here**: [QUICKSTART.md](QUICKSTART.md)

Run a minimal system with 1 platform and 1 C2 station. Learn:
- How routing services bridge domains
- How data flows Platform → WAN → C2
- Basic QoS profiles (RELIABLE vs BEST_EFFORT)
- Command filtering

**Time**: ~15 minutes

### Step 2: Scale to Multiple Platforms
**Next**: [MULTI_PLATFORM.md](MULTI_PLATFORM.md)

Add a second platform and enable platform-to-platform communication. Learn:
- Managing multiple nodes
- P2P data routes
- Discovery at scale
- Network segmentation benefits

**Time**: ~20 minutes

### Step 3: Dynamic Runtime Control
**Advanced**: [REMOTE_ENABLE_P2P.md](REMOTE_ENABLE_P2P.md)

Control platform-to-platform communication without restarting services. Learn:
- RemoteAdmin tool usage
- Enabling/disabling routes at runtime
- Remote administration API
- Dynamic system reconfiguration

**Time**: ~20 minutes

### Step 4: Logical Isolation with Groups
**Advanced**: [REMOTE_CONTROL_GROUP.md](REMOTE_CONTROL_GROUP.md)

Assign platforms to groups for data isolation. Learn:
- DDS partitions for grouping
- Group-based filtering
- Multi-tenant scenarios
- Dynamic group assignment

**Time**: ~20 minutes

---

## Running Examples

All examples follow the same pattern:

### Basic Steps
1. Open multiple terminal windows (typically 4-6)
2. Navigate to `examples/node_sim/`
3. Run the start scripts in sequence
4. Observe the output
5. Follow the walkthrough instructions

### Example Terminal Layout
```
Terminal 1: Platform-10 Router
Terminal 2: Platform-10 Simulator
Terminal 3: C2-20 Router
Terminal 4: C2-20 Simulator
Terminal 5: (Optional) RemoteAdmin tool
Terminal 6: (Optional) RTI Admin Console
```

### All Scripts Are Ready to Run
No configuration needed - examples use pre-configured parameters.

---

## Example Components

### Simulators (`node_sim/python_node/`)
- **`platform_sim.py`**: Simulates a platform (vehicle/UAV/USV)
  - Publishes: PlatformStatus (periodic), PlatformCommandAck (event)
  - Subscribes: C2Command (filtered by destination)
  
- **`c2_sim.py`**: Simulates a C2 station
  - Publishes: C2Command (targeted to specific platforms)
  - Subscribes: PlatformStatus, PlatformCommandAck

### Start Scripts (`node_sim/`)
- **`start_platform10_router.sh`**: Platform-10 routing service
- **`start_platform10_sim.sh`**: Platform-10 simulator
- **`start_platform11_router.sh`**: Platform-11 routing service
- **`start_platform11_sim.sh`**: Platform-11 simulator
- **`start_c2_20_router.sh`**: C2-20 routing service
- **`start_c2_20_sim.sh`**: C2-20 simulator

### Configuration (`node_sim/params/`)
- Pre-configured parameters for each node
- **Do not modify** - these are for examples only
- For deployment, use templates in `../templates/`

---

## What's Demonstrated

### Data Flow Patterns
- ✅ Platform → C2: Status updates, events, acknowledgments
- ✅ C2 → Platform: Commands (content-filtered by destination)
- ✅ Platform ↔ Platform: Peer-to-peer data sharing
- ✅ Downsampling: 10-second status updates to reduce bandwidth

### QoS Profiles
- ✅ **Event channels**: RELIABLE delivery for critical data
- ✅ **Status channels**: BEST_EFFORT for periodic updates
- ✅ **WAN tuning**: Heartbeat periods, timeouts for high-latency links
- ✅ **Content filtering**: Targeted command delivery

### Routing Features
- ✅ Domain bridging (LAN ↔ WAN ↔ LAN)
- ✅ Dynamic route enabling/disabling
- ✅ Partition-based grouping
- ✅ Automatic discovery across domains
- ✅ Topic-based filtering with regex

### Runtime Control
- ✅ RemoteAdmin tool for live reconfiguration
- ✅ Enable/disable P2P routes without restart
- ✅ Assign nodes to groups dynamically
- ✅ Remote administration domain (100)

---

## Monitoring Tools

### RTI Admin Console
```bash
$NDDSHOME/bin/rtiadminconsole
```
View:
- All DDS participants (routing services, simulators)
- Topic discovery status
- Data reader/writer matching
- Live data samples

### RTI Monitor
```bash
$NDDSHOME/bin/rtimonitor
```
Monitor:
- Real-time throughput
- Latency statistics
- Resource usage
- Discovery events

### Routing Service Logs
Watch terminal output for:
- Session ENABLED/DISABLED
- Route ENABLED/DISABLED
- Participant discovery
- Data flow messages

---

## Common Questions

### Q: Can I modify the examples?
**A**: Yes, for learning purposes. But **do not use modified examples for production**. Use the [templates](../templates/) instead.

### Q: Why are domains hardcoded (10, 11, 20)?
**A**: For simplicity in examples. In production, you choose your own domain IDs.

### Q: Can I add my own data types?
**A**: Yes! See `node_sim/types/act_types.xml` as a reference. Generate type support with `rtiddsgen`.

### Q: Why separate examples from deployment?
**A**: Examples are optimized for learning (hardcoded, simplified). Production needs flexibility, customization, and proper structure.

### Q: Do I need RemoteAdmin for production?
**A**: No, it's optional. But it enables runtime control without service restarts - very useful for operations.

---

## Troubleshooting

### Can't Start Routing Service
```bash
# Check NDDSHOME
echo $NDDSHOME

# Verify rtiroutingservice exists
ls $NDDSHOME/bin/rtiroutingservice
```

### Simulators Can't Connect
- Start routers **before** simulators
- Wait 10 seconds after starting routers
- Check for "matched" messages in router logs

### No Data Flowing
- Verify all terminals are running
- Check routing service logs for errors
- Ensure topic names match (case-sensitive)

### RemoteAdmin Errors
- Rebuild RemoteAdmin if you updated code
- Check that router's `-appName` matches `-n` parameter
- Verify `system_params.sh` is sourced

---

## After Learning Examples

Once you understand the architecture:

1. **Read the [Deployment Guide](../templates/DEPLOYMENT.md)**
2. **Create your own deployment structure** using templates
3. **Define your data types** (IDL files)
4. **Configure data channels** for your use case
5. **Integrate your applications** with DDS

---

## Additional Resources

- **Main README**: [../README.md](../README.md) - Architecture overview
- **Deployment Guide**: [../templates/DEPLOYMENT.md](../templates/DEPLOYMENT.md) - Production setup
- **Template README**: [../templates/README.md](../templates/README.md) - Template usage
- **RemoteAdmin README**: [../tools/remote_admin/README.md](../tools/remote_admin/README.md) - Tool documentation

---

**Remember**: Examples are for **learning only**. For production, use the [Deployment Guide](../templates/DEPLOYMENT.md).
