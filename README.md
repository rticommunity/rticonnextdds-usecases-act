# Autonomous Collaborative Teaming (ACT) - Routing Service Architecture

RTI Routing Service architecture for Autonomous Collaborative Teaming use cases to manage message flow between Platforms (UxV's) and Control stations.

This use case is centered around a Maritime ISR scenario but can be adapted for other collaborative teaming applications.

```mermaid
graph TB
    subgraph Node1["Control Node"]
        subgraph CONTROL["CONTROL_DOMAIN (20)"]
            C_APP[Control Apps]
        end
        RS_C[Routing Service]
        subgraph WAN_C["WAN Participant"]
            WAN_CP[WAN_DOMAIN 200]
        end
        C_APP <--> RS_C
        RS_C <--> WAN_CP
    end
    
    subgraph Node2["Platform Node"]
        subgraph PLATFORM["PLATFORM_DOMAIN (30)"]
            P_APP[Platform Apps]
        end
        RS_P[Routing Service]
        subgraph WAN_P["WAN Participants"]
            WAN_CTRL[Control Participant<br/>Domain 200]
            WAN_TEAM[Team Participant<br/>Domain 200]
        end
        P_APP <--> RS_P
        RS_P --> WAN_CTRL
        RS_P --> WAN_TEAM
    end
    
    subgraph Network["Wide Area Network"]
        WAN_NET[WAN_DOMAIN 200<br/>Hub-Spoke + Mesh]
    end
    
    WAN_CP <-->|Commands & Status| WAN_NET
    WAN_CTRL <-->|Commands & Status| WAN_NET
    WAN_TEAM <-->|Team Coordination| WAN_NET
    
    style CONTROL fill:#fff4e1,stroke:#f57c00,stroke-width:2px,color:#000
    style PLATFORM fill:#e1f5fe,stroke:#01579b,stroke-width:2px,color:#000
    style WAN_C fill:#f1f8e9,stroke:#558b2f,stroke-width:2px,color:#000
    style WAN_P fill:#f1f8e9,stroke:#558b2f,stroke-width:2px,color:#000
    style Network fill:#c8e6c9,stroke:#2e7d32,stroke-width:3px,color:#000
    style RS_C fill:#fff9c4,stroke:#f9a825,stroke-width:2px,color:#000
    style RS_P fill:#fff9c4,stroke:#f9a825,stroke-width:2px,color:#000
```

## Getting Started

### Clone with Submodules

This repository uses git submodules for CMake utilities. Clone with:

```bash
git clone --recurse-submodules https://github.com/rticommunity/rticonnextdds-usecases-act.git
```

Or if you've already cloned without submodules:

```bash
git submodule update --init --recursive
```

## Choose Your Adventure

### Examples

- **[Quick Start](QUICKSTART.md)** - Single platform + Control communication (15 min)
- **[Multi-Platform](MULTI_PLATFORM.md)** - Two platforms with TEAM communication (20 min)
- **[Team Assignment](REMOTE_CONTROL_TEAM.md)** - Multi-tenant logical isolation (20 min)
- **[Enable Detailed Status](REMOTE_ENABLE_DETAIL_STATUS.md)** - On-demand high-bandwidth telemetry (15 min)

### Technical Details

**[TECHNICAL_DETAILS.md](TECHNICAL_DETAILS.md)** - Architecture, QoS patterns, data channels, and configuration details.

---

## Questions or Feedback?

Reach out to us at **services_community@rti.com** - we welcome your questions and feedback!