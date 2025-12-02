# Autonomous Collaborative Teaming (ACT) - Routing Service Architecture

RTI Routing Service architecture for Autonomous Collaborative Teaming use cases to manage message flow between Platforms (vehicles/UAVs/USVs) and C2 (Command and Control) stations.

This use case is centered around a Maritime ISR scenario but can be adapted for other collaborative teaming applications.


## Choose your adventure

### 1. 🎓 **Learn the Architecture** → [Examples README](examples/README.md)
Start here if you're new to ACT. Run pre-built examples to understand:
- How routing services bridge domains
- How data flows between platforms and C2 stations
- How to use runtime control features

**Available Examples**:

- **[Basic Data Flow](examples/QUICKSTART.md)** ⭐ (15 min)
  - Single platform + C2 communication
  - Learn domain bridging and content filtering
   
- **[Multi-Platform System](examples/MULTI_PLATFORM.md)** ⭐⭐ (20 min)
  - Two platforms collaborating with C2
  - Learn platform-to-platform communication
   
- **[Dynamic P2P Control](examples/REMOTE_ENABLE_P2P.md)** ⭐⭐⭐ (20 min)
  - Enable/disable routes at runtime
  - Learn RemoteAdmin tool usage
   
- **[Group Assignment](examples/REMOTE_CONTROL_GROUP.md)** ⭐⭐⭐ (20 min)
  - Logical isolation with partitions
  - Learn multi-tenant operations


### 2. 🚀 **Deploy Your System** → [Deployment Guide](templates/DEPLOYMENT.md)
Ready for production? Follow the comprehensive deployment guide:
- Step-by-step deployment instructions
- Configuration reference
- Troubleshooting and best practices
- RemoteAdmin tool setup


### 3. 📚 **Read Technical Details** → [Technical Details](TECHNICAL_DETAILS.md)
Dive deep into the architecture and design:
- Use case requirements and network architecture
- QoS delivery patterns (RELIABLE vs BEST_EFFORT)
- Data channels and content filtering
- Feature overview and configuration details

---

