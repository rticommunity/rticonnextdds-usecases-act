# Autonomous Collaborative Teaming
**Case + Code**

## System Architecture Document

## 1. Executive Summary
The Autonomous Collaborative Teaming (ACT) Routing System is a middleware infrastructure designed to enable the command, control, and coordination of heterogeneous teams of autonomous systems. 
The architecture facilitates a transition from 1:1 operator-to-platform ratios to 1:N (team) operations. 
It utilizes DDS (Data Distribution Service) and a Routing Service layer to abstract complex networking into logical domains, ensuring interoperability between diverse vendors while managing data flow across bandwidth-constrained Wide Area Networks (WAN).

> **Note:** The requirements, scenarios, and use cases defined in this document are provided as reference examples only and can be modified as needed to target specific use cases. This architecture is intended to highlight various technical options and implementation patterns aligned with autonomous collaborative teaming scenarios.

## 2. Scenarios

This architecture focuses on the DDS implementation of the message routing use case and is aligned with the following scenarios:

### Foundational Control: Single Operator to Heterogeneous Team (1:N)

This scenario facilitates the transition from legacy 1:1 remote piloting to a single operator managing a diverse team of autonomous assets (1:N). The focus is on implementing basic "CRUD" (Create, Read, Update, Delete) functionality that allows an operator to provision heterogeneous robots—such as mixing UAVs with ground vehicles—into a cohesive team and assign missions through a "single pane of glass," abstracting away unique manufacturer interfaces.

### Tactical Teams: Dynamic Autonomous Formations (5 to 12 Platforms)

Designed for tactical operations, this scenario models a team of approximately 8–12 autonomous platforms that dynamically split into smaller task forces, such as a "Green Team" (2 platforms) for scouting or a "Red Team" (4 platforms) for intervention. It relies on peer-to-peer mesh networking to maintain connectivity; if a platform loses line-of-sight with the controller, a peer automatically relays command and status data, ensuring the team remains operational even when partially disconnected.

### Strategic Scale: Large-Scale Swarms and Bandwidth Constraints (32+ Platforms)

This scenario manages formations of 32 to hundreds of attritable platforms operating under severe bandwidth constraints (e.g., 50 kbps jammed radio or 2.5 Mbps satellite links). To prevent network collapse from "discovery storms," the architecture utilizes hierarchical commands sent only to Team Leaders and "Topic Aggregation" to compress dozens of DDS topics into serialized "Command" and "Status" streams.

## 3. Assumed System Topology

### Network Infrastructure & Communication Parameters

- **Network Topology**: A "flat" single subnet is the baseline, though separate subnets or tunnels may be implemented for Wide Area Network (WAN) communication.
- **Transport Protocols**: A variety of transports are utilized, including UDPv4, UDPv6, Shared Memory (SHMEM), and Loopback.
- **Data Transmission**: Unicast is the preferred method for data transmission; multicast is used selectively, generally restricted to within specific functional groups.
- **Bandwidth Allocation**:
  - Control/Status/Video Telemetry: Approximately 2–3 MBps is allocated for this combined data stream.
  - Control/Status Data: A dedicated budget of approximately 100 KBps is maintained for control and status information alone.
- **Physical Links**: Mesh radios are employed for Line-of-Sight (LOS) communication, while satellite links are used for Beyond-Line-of-Sight (BLOS) connectivity.
- **Dynamic Discovery**: Platforms and Control stations are dynamically changing, being added/removed based on changing conditions and can't be hardcoded with IP addresses in discovery lists.

## 4. System Actors & Roles

- **Mission Commander**: The high-level decision-maker responsible for defining mission objectives and "CRUD" (Create, Read, Update, Delete) operations for Team groupings.
- **System Operator**: The "human-in-the-loop" monitoring the Single Pane of Glass (SPOG) who manages exceptions and approves high-consequence actions (e.g., weapons release).
- **Control Node**: The hardware/software entity (Ashore, Afloat, or Airborne) that publishes commands and subscribes to aggregated status updates. This hosts a RTI Routing Service to aggregate/filter/route Topics as needed.
- **Platform Nodes**: The autonomous unit (UxV) hosting the autonomy engine, sensors, and a local RTI Routing Service.
- **Leader**: Within a Team, the Platform designated to receive commands from Control and relay them to Team members as appropriate.
- **Follower**: Within a Team, the Platform designated to receive relayed commands from the Leader Platform.
- **Team**: A Platform that has been designated as a member of the logical mission-centric grouping of Platforms.
- **Integrator**: The developer responsible for integrating Platforms/Controllers and ensuring third-party payloads comply with standard data models (e.g., UMAA).
- **Network Architect**: The technical specialist responsible for designing the network topology, configuring Quality of Service (QoS) for bandwidth prioritization, managing Discovery mechanisms (e.g., Unicast vs. Multicast), and ensuring the system adheres to low-bandwidth/high-latency constraints (DDIL environments).


## 5. User Stories

### Category A: Operational Command & Control

**Focus**: Managing the Team from the Controller Node.

| ID | Actor | User Story | Scenario |
| --- | --- | --- | --- |
| US-A1 | Mission Commander | As a Commander, I want to dynamically create, update, and disband Teams (CRUD) during a mission, so that I can re-task assets to new objectives without restarting the system or hard-coding network addresses. | 2, 3 |
| US-A2 | System Operator | As an Operator, I want to view the status of heterogeneous assets (e.g., air and ground) on a single unified interface, so that I do not have to monitor individual proprietary laptops for each vendor. | 1, 2, 3 |
| US-A3 | System Operator | As an Operator, I want to transfer control of a Team from a Shore Controller to a Mobile Controller, so that the Team can extend its operational range beyond the horizon of the shore station. | 2, 3 |
| US-A4 | Mission Commander | As a Commander, I want to issue a single high-level command to a Team leader, so that the Team members can coordinate details peer-to-peer without saturating the long-haul WAN_DOMAIN link. | 3 |

### Category B: Autonomy & Collaborative Teaming

**Focus**: Platform-to-Platform interaction in the field.

| ID | Actor | User Story | Scenario |
| --- | --- | --- | --- |
| US-B1 | Platform (Leader) | As a Leader, I want follower Platforms to autonomously track my path and speed, so that we can execute missions with minimal human intervention (Leader-Follower). | 2, 3 |
| US-B2 | Platform (Leader) | As a Leader, I want to receive commands via Satellite (BLOS) and re-transmit a subset as necessary to my Team via local Mesh radio (LOS), so that Platforms without satellite uplinks still receive orders. | 2, 3 |
| US-B3 | Platform (Team) | As a Team Member, I want to detect when a peer Platform has been destroyed or disabled, so that the remaining team can recalculate the mission plan to cover the gap. | 2, 3 |
| US-B4 | Platform (Team) | As a Team Member, I want to receive position/contact reports/mission status from only other Team Members so that I can coordinate mission completion as necessary. | 2, 3 |

### Category C: Infrastructure, Resilience & Networking

**Focus**: Keeping the system alive in "Hellscape" environments.

| ID | Actor | User Story | Scenario |
| --- | --- | --- | --- |
| US-C1 | Network Architect | As an Architect, I want to prioritize "Command" and "Hazard" data over "Health Logs" when bandwidth drops to 50 kbps, so that critical control is maintained even when the link is jammed. | 1, 2, 3 |
| US-C2 | Network Architect | As an Architect, I want to prevent 100 Platforms from simultaneously broadcasting "Discovery" packets when the mission starts, so that the network does not collapse under a "discovery storm." | 3 |
| US-C3 | Integrator | As an Integrator, I want to write autonomy software against a standardized data model (UMAA), so that my code works on both "Vendor A" and "Vendor B" platforms without modification. | 1, 2, 3 |
| US-C4 | Integrator | As an Integrator, I want to isolate high-bandwidth sensor traffic to the local Platform, so that raw video or LiDAR data never accidentally routes to the WAN_DOMAIN and impacts bandwidth. | 1, 2, 3 |
| US-C5 | Integrator | As an Integrator, I want to isolate mission management/UI internal traffic to the local Controller, so that unnecessary traffic doesn't route to the WAN_DOMAIN and impact bandwidth. | 1, 2, 3 |
| US-C6 | Platform (Team) | As a Team Member, I want to automatically relay messages from a disconnected Team member back to the Control Node, so that the Team maintains situational awareness even when direct line-of-sight to Control is broken. | 2, 3 |


## 6. System Requirements

### 6.1 Functional Requirements

- **SYS-REQ-01 (Scaling)**: The system shall support the discovery and routing of data for teams scaling to hundreds of Platforms. (US-C2)
- **SYS-REQ-02 (Degraded Comms)**: The system shall maintain Control connectivity over variable bandwidth links ranging from 2.5 Mbps down to 50 Kbps, with latencies up to 1.5 seconds. (US-C1)
- **SYS-REQ-03 (Standardization)**: Infrastructure must be able to support transmission of Standardized Datamodels such as UMAA (Unmanned Autonomy Architecture) to ensure vendor neutrality. (US-A2, US-C3)
- **SYS-REQ-04 (Dynamic Regrouping)**: The system shall allow Controllers to modify the logical grouping of Platforms at runtime using remote administration commands. (US-A1)
- **SYS-REQ-05 (Transport Agnostic)**: The system shall operate seamlessly across mixed physical transports, including Satellite (BLOS), Mesh Radio (LOS), SHMEM, and wired local networks. (US-A2)
- **SYS-REQ-06 (Unicast Priority)**: The system shall utilize Unicast communication for all WAN_DOMAIN data exchange, prioritizing it over multicast or broadcast mechanisms to ensure predictable behavior and avoid network storms on bandwidth-constrained links. Must use Multicast within WAN_DOMAIN for discovery if constrained with Partition QOS or Unicast if in tandem with CDS (US-C2)
- **SYS-REQ-07 (Dynamic Control Handoff)**: The system shall implement a dynamic control transfer mechanism that allows an Operator to seamlessly hand off the command authority of an assigned Team from a Shore Controller to a Mobile/Afloat Controller during mission execution, ensuring continuous command connectivity and extending operational range beyond the line-of-sight of the originating station (US-A3)
- **SYS-REQ-08 (Autonomous Leader-Follower Tracking)**: The system shall implement a peer-to-peer telemetry exchange mechanism within the WAN_DOMAIN (using partition-based Team isolation) that allows follower Platforms to autonomously subscribe to and track the real-time position, heading, and speed of a designated Convoy Leader as well as other Team member Platforms, enabling synchronized formation movement for resupply operations with minimal human intervention (US-B1, US-B4)
- **SYS-REQ-09 (Multi-Transport Command Relay)**: The system shall implement a multi-transport routing mechanism utilizing the Routing Service that allows a designated Relay Node to receive commands via high-latency Satellite links (BLOS) and automatically re-transmit them to Team members via low-latency Mesh radio (LOS) on the WAN_DOMAIN, ensuring that agents lacking direct satellite connectivity receive mission-critical orders (US-B2)
- **SYS-REQ-10 (Peer Loss Detection)**: The system shall implement a decentralized liveliness monitoring mechanism utilizing DDS Liveliness/Deadline QoS policies and Participant Discovery protocols that allows remaining Team Members to automatically detect the cessation of a peer Platform's heartbeats exceeding a configurable lease_duration threshold, triggering a local autonomy event to recalculate mission parameters and redistribute coverage gaps (US-B3)
- **SYS-REQ-11 (Bandwidth-Aware Data Prioritization)**: The system shall implement a traffic shaping and prioritization mechanism utilizing DDS TransportPriority QoS and Asynchronous Flow Controllers within the Routing Service that explicitly assigns higher transmission priority to "Command" and "Hazard" channels over "Health/Status" telemetry, ensuring that mission-critical control messages are successfully transmitted even when network throughput degrades to 50 kbps or lower (US-C1)
- **SYS-REQ-13 (Local Traffic Isolation)**: The system shall implement a domain segregation architecture utilizing a dedicated PLATFORM_DOMAIN/CONTROL_DOMAIN using a Routing Service configured with strict topic allow-lists, ensuring that voluminous raw/high rate data remains logically isolated to the Platform/Control's onboard compute hardware and is never accidentally bridged to the bandwidth-constrained WAN_DOMAIN (US-C4, US-C5)
- **SYS-REQ-14 (Leader-Follower Command Distribution)**: The system shall implement a hierarchical routing mechanism utilizing Content Filtered Topics within the Routing Service to deliver high-level mission objectives exclusively to a designated Team Leader on the WAN_DOMAIN, enabling the leader to autonomously disseminate granular tasking details to follower nodes via the WAN_DOMAIN (constrained by Domain Participant Partition QoS per TEAM), ensuring that high-frequency coordination traffic remains logically isolated to the local mesh network and does not saturate the bandwidth-constrained long-haul WAN_DOMAIN link. (US-A4)
- **SYS-REQ-16 (Gossip-Based State Relay)**: The system shall implement a decentralized data propagation mechanism utilizing a gossip protocol for peer-to-peer message exchange and the Persistence Service for durable message buffering, ensuring that "Command" and "Status" updates from disconnected nodes are stored and automatically relayed through connected peers back to the Control Node (eventual consistency), preserving situational awareness even when direct WAN connectivity is severed (US-C6)


## 7. Derived Technical Requirements (DDS Implementation)

### 7.1 Domain Segmentation Strategy

**REQS:** SYS-REQ-01, SYS-REQ-06, SYS-REQ-13

The architecture must implement a Multi-Tier DDS Domain Model. DDS data is isolated between domains using Topic Routes/Sessions within RTI's Routing Service.

**DTR-01 Platform (PLATFORM_DOMAIN):**
- **Domain ID Range:** 30-100 (e.g., Platform_30 uses domain 30, Platform_31 uses domain 31 if VLAN)
- **Scope:** Strictly local to a single Platform.
- **Traffic:** High-rate sensor data, actuator loops, raw autonomy processing.
- **Transport:** Shared Memory (SHMEM) or UDP Loopback. NO routing to external radios.
- **Discovery:** Multicast

**DTR-02 Control (CONTROL_DOMAIN):**
- **Domain ID Range:** 10-30 (e.g., Control_20 uses domain 20)
- **Scope:** Strictly local to a single Controller.
- **Traffic:** Internal UI microservices, mission management.
- **Transport:** Shared Memory (SHMEM) or UDP Loopback. NO routing to external radios.
- **Discovery:** Multicast
**DTR-03 (WAN_DOMAIN - Wide Area Network):**
- **Domain ID:** 200 (default)
- **Scope:** All wide-area network communication (control-to-platform and platform-to-platform).
- **Traffic:** 
  - Control Participant: Commands (downstream) and Status/Events (upstream) between Controller and Platforms
  - Team Participant: Peer-to-peer coordination, task allocation, position sharing within Teams
- **Transport:** Optimized for WAN (Unicast, TCP/UDP_WAN, UDPv4, UDPv6).
- **Discovery:** Unicast

**Architecture Note:** Each Platform node creates TWO separate Domain Participants on WAN_DOMAIN:
  1. **Control Participant:** Always active for control-to-platform communication. Subscribes to CONTROL_COMMANDS_CHANNEL, publishes PLATFORM_PRIMARY_STATUS_1HZ_CHANNEL and PLATFORM_EVENTS_CHANNEL.
  2. **Team Participant:** Partition-controlled for platform-to-platform team communication. On startup, initialized with the platform's unique identifier (e.g., "Platform_30") as its partition. PLATFORM_TEAM_CHANNEL sessions are enabled by default, but platforms won't discover each other due to unique partition isolation. Upon team assignment, the partition is updated to the team name (e.g., "A", "B", "C") via Remote Administration, enabling discovery and communication with other team members.

This dual-participant approach enables independent lifecycle management: control communication remains operational even when team sessions are disabled, while partition-based isolation ensures Team members only discover and communicate with their assigned teammates.

**DTR-04 (ADMIN_DOMAIN - Remote Administration):**
- **Domain ID:** 100
- **Scope:** Remote administration and monitoring across all nodes.
- **Traffic:** Routing Service remote commands (session enable/disable, partition updates), monitoring telemetry.
- **Transport:** Same as WAN_DOMAIN.
- **Discovery:** Unicast

### 7.2 Data Routing & Traffic Shaping

To meet US-C1 and US-C4:
- **DTR-05 (Content Filtering):** The Controller must utilize Writer-Side Content Filtered Topics (CFT) on the WAN_DOMAIN to ensure commands addressed to "Platform ID 101" are not deserialized by the rest of the team.
- **DTR-06 (Domain Isolation):** The nodes must utilize Topic Routes on each of the domains to ensure message level isolation per Domain.

### 7.3 Discovery Optimization

To meet US-C2:
- **DTR-07 (Discovery Mechanism):** The WAN_DOMAIN shall utilize unicast discovery between Platform and Control nodes possibly utilizing Cloud Discovery Service (CDS) in combination with DNS host names if necessary.
- **DTR-08 (Phased Initialization):** The Routing Service shall implement a Phased Initialization strategy within the WAN_DOMAIN where:
  - **Primary Status Channels (PLATFORM_PRIMARY_STATUS_1HZ_CHANNEL)** are enabled by default on startup, providing baseline telemetry to Control
  - **Detail Status Channels (PLATFORM_DETAIL_STATUS_CHANNEL)** remain disabled by default and can be enabled later by Control via Remote Administration to provide additional high-bandwidth topics when detailed monitoring is required
  - **Team Channels (PLATFORM_TEAM_CHANNEL)** are enabled by default, but platform-to-platform discovery is constrained by unique partition identifiers until Platforms are explicitly assigned to a shared team partition via Remote Administration commands
  
  This approach prevents network saturation from the simultaneous broadcast of hundreds of unassigned endpoints while enabling controlled, on-demand activation of high-fidelity data routes and team collaboration

## 8. Implementation Details

### 8.1 Architecture Diagram Description
The architecture functions as a "Hub-and-Spoke" for control-to-platform communication and a "Mesh" for platform-to-platform team communication, both within the WAN_DOMAIN.

**The Platform Node:**
- **Internal:** Runs Autonomy Containers on PLATFORM_DOMAIN.
- **Gateway:** Hosts a local Routing Service instance.
- **Logic:**
  - **Input:** Subscribes to Select Topics from PLATFORM_DOMAIN, WAN_DOMAIN
  - **Process:** Routes as configured between Domains, applies QoS per "Channel"
  - **Output:** Publishes to Select Topics from PLATFORM_DOMAIN, WAN_DOMAIN
- **Discovery:** Contains list of available Control Nodes host names in initial peers list
- **Remote Administration:** 
  - Used to send "Update Domain Participant Partition" commands to the Platforms Routing Service, logically moving them from "Team A" to "Team B" on the WAN_DOMAIN.
  - Used to send "Enable/Disable Session" commands to the Platforms Routing Service allowing Topic messages to be sent/received within a Team after assignment.

**The Control Node:**
- **Internal:** Runs UI/Mission Management Containers on CONTROL_DOMAIN.
- **Gateway:** Hosts a local Routing Service instance.
- **Logic:**
  - **Input:** Subscribes to Select Topics from CONTROL_DOMAIN, WAN_DOMAIN
  - **Process:** Routes as configured between Domains, applies QoS per "Channel"
  - **Output:** Publishes to Select Topics from CONTROL_DOMAIN WAN_DOMAIN
- **Discovery:** Receives Discovery announcements from Platform nodes
- **Remote Administration:** Used to send "Enable/Disable Session" commands to specific Platforms allowing additional Status topics to be published.

### 8.2 Channels
In the Autonomous Collaborative Teaming (ACT) architecture, a Channel is a logical abstraction layer implemented via the RTI Routing Service that groups multiple distinct DDS Topics into a single configuration entity. This allows the system to apply a unified Quality of Service (QoS) profile and routing logic to a specific group of topics based on their operational intent (e.g., Command vs. Status) and their destination (e.g., Platform vs. Control), without requiring the operator to configure routes for every individual topic.

**Key Characteristics:**

- **Topic Aggregation:** Instead of managing individual routes for dozens of topics (e.g., FuelLevel, BatteryStatus, GPSPosition), an administrator assigns these topics to a specific Channel (e.g., "PLATFORM STATUS") using environment variables. The Routing Service then processes them as a collective stream.
- **Destination-Based Routing:** Channels define the flow of data between specific logical nodes. For example, a "PLATFORM_TEAM_CHANNEL" Channel routes peer-to-peer data between Platforms and applies the STATUS_QOS while a "PLATFORM EVENT" Channel routes data vertically between the Platform and the Control and applies an EVENT_QOS.
- **QoS Abstraction:** Each channel has a pre-defined QoS profile applied to all topics within it. This ensures that critical data is sent reliably while high-volume telemetry is sent BEST_EFFORT, abstracting the complex DDS QoS settings away from the end-user.
**Channel Types and QoS Assignments:**

The ACT architecture defines three primary channel types, each with specific QoS and routing behaviors:

| Channel Name | QoS Profile | Destination / Logic | Topic Examples |
| --- | --- | --- | --- |
| CONTROL_COMMANDS_CHANNEL | EVENT_QOS | Control → Platform<br/>Utilizes Content Filtered Topics to target specific platforms (e.g., target_id = "Platform_30"), preventing the entire team from processing commands meant for a single agent. | ControlCommand<br/>MissionAssignment<br/>ReturnToBase |
| PLATFORM_EVENTS_CHANNEL | EVENT_QOS | Platform → Control<br/>Used for critical alerts that must be delivered but occur infrequently. | ContactReport<br/>HazardDetection<br/>SystemFailure<br/>ControlCommandAck |
| PLATFORM_PRIMARY_STATUS_1HZ_CHANNEL | STATUS_QOS | Platform → Control<br/>Low-bandwidth, always-on status at 1Hz. This is the default status channel enabled at startup. | Fuel<br/>Battery<br/>Heading<br/>Speed<br/>Position (1Hz) |
| PLATFORM_DETAIL_STATUS_CHANNEL | STATUS_QOS | Platform → Control<br/>High-bandwidth, on-demand detailed status. Disabled by default, enabled via remote admin for detailed monitoring. | Full sensor suite<br/>High-rate position<br/>Detailed diagnostics |
| PLATFORM_TEAM_CHANNEL | STATUS_QOS | Platform ↔ Platform<br/>Used for peer-to-peer team coordination data. Disabled by default, enabled via remote admin (TEAM_ENABLE) when platforms are assigned to a team. | Position<br/>TeamStatus<br/>CoordinationData |

**Implementation Mechanism:**

The system uses Environment Variables to dynamically map topics to these channels at runtime. 
For example, a developer can add a new sensor topic to the PLATFORM_STATUS list, and the Routing Service will automatically route it through the PLATFORM_STATUS Channel with "BEST_EFFORT" QoS and direct it to the CONTROL_DOMAIN, without requiring recompilation or complex XML editing

### 8.3 Unicast Discovery
A Centralized Discovery Server (CDS), each with an assigned DNS name, will be used at every Control station. Platforms will be configured with a pre-defined list of these CDS DNS hostnames as their initial peer list.
Startup and Synchronization
Upon startup, Platforms will connect to these CDS instances to receive locators for other Platforms and Control systems currently on the network.
It is likely necessary for all CDS instances to be synchronized with each other.
Adding a New Control Station
When a new Control station comes online:
It will send its locators to its pre-defined initial_peers list, which includes all existing Control/CDS instances.
The other CDS instances will then propagate the new Control station's information to the Platforms, enabling control and handoff capabilities.
Product gap:
Synchronization of CDS instances. 
JIRA: CDS-188: Add support for replication and horizontal scaling


## 9. Workflow

### Dynamic Team Assignment (The "CRUD" Lifecycle):

The workflow transitions a set of autonomous platforms from an "Idle/Unassigned" state into a specific "Team" (e.g., Red Team) to enable peer-to-peer collaboration, and finally dissolves them back to the pool.

#### 1. Phase 1: Initialization & "Light" Discovery

**Operational State:** Platforms (e.g., UxVs) power on and loiter. They must be visible to the Control Station but should not yet discover every other platform's full endpoint database to prevent bandwidth saturation (Discovery Storms).

**DDS Implementation:**

**PLATFORM:** 
- **Routing Service WAN_DOMAIN Participant:**
  - Connects to the Control nodes defined in initial_peers list with DNS hostnames/IP addresses using Unicast Discovery (via static peers or Cloud Discovery Service).
  - Enables routes by default to subscribe to Command topics from Control on the WAN_DOMAIN (CONTROL_COMMANDS_CHANNEL)
  - Publishes low-frequency (1Hz) topics over the PLATFORM_PRIMARY_STATUS_1HZ_CHANNEL on the WAN_DOMAIN
  - Publishes events via PLATFORM_EVENTS_CHANNEL on the WAN_DOMAIN
- **Routing Service WAN_DOMAIN Team Participant:**
  - Initialized with the platform's unique identifier as its Domain Participant Partition (e.g., "Platform_30", "Platform_31").
  - PLATFORM_TEAM_CHANNEL sessions are enabled by default, but platforms won't discover each other due to partition-based isolation (each platform has a unique partition).

**CONTROLLER:**
- **Routing Service WAN_DOMAIN Participant:**
  - Listens for Discovery Announcements from Platforms, responds with locators
  - Enables Routes by default to subscribe to Status Topics from Platforms on the WAN_DOMAIN (PLATFORM_PRIMARY_STATUS_1HZ_CHANNEL, PLATFORM_EVENTS_CHANNEL)
  - Enables Routes by default to publish Command topics on the WAN_DOMAIN (CONTROL_COMMANDS_CHANNEL)

#### 2. Phase 2: The Assignment Trigger (Create/Update)

**Operational State:** The Operator selects specific platforms (e.g., "Platform 7" and "Platform 8") on the "Single Pane of Glass" UI and assigns them to "Red Team".

**DDS Implementation:**

**CONTROLLER:**
- **UI:**
  - **Action:** Sends a command over the TeamAssignCommand Topic assigning the Platform to a specific Team.

#### 3. Phase 3: Dynamic Reconfiguration (Partition Switching)

**Operational State:** The selected platforms logically detach from the general pool and form a secure, isolated network segment.

**DDS Implementation:**

**PLATFORM:**
- **Autonomy:**
  - **Action:** Processes the command from the Controller UI
  - **Action:** Uses Remote Admin commands to update the Domain Participant Partition QoS of the WAN_DOMAIN Team Participant from the unique identifier (e.g., "Platform_30") to the team name (e.g., "A").
- **Routing Service:**
  - **Action:** Receives the Remote Admin commands from the autonomy application
  - **Action:** Updates the DP Partition QoS for the WAN_DOMAIN Team Participant from the unique identifier to the team name (e.g., "A")
  - **Result:** Platforms with the same team partition can now discover each other and exchange data via PLATFORM_TEAM_CHANNEL (sessions already enabled)
  - **Action:** Enables Sessions associated with the PLATFORM_TEAM_CHANNEL

**Result:**
- **Discovery:** This change forces the DDS discovery mechanism to reset connections. Platform 7 and Platform 8 will immediately begin discovering only other participants with the "Red_Team" partition. They will stop communicating with "Unassigned" nodes or "Blue Team" nodes, effectively isolating traffic. They will also begin discovering Topics available per PLATFORM_TEAM_CHANNEL
- **Communications:** The Routing Service enables specific Sessions defined by the PLATFORM_TEAM_CHANNEL. This allows those topic messages to flow across the WAN_DOMAIN.

#### 4. Phase 4: Dissolution (Delete/Return to Pool)

**Operational State:** The mission is complete. The Operator selects "Red Team" and clicks "Disband".

**DDS Implementation:**

**Controller:**
- **UI:**
  - Sends a command over the "TeamAssignCommand" Topic to reset Teams back to defaults.

**Platform:**
- **Autonomy:**
  - Receives commands over "TeamAssignCommand" Topic.
  - Sends a Remote Administration command to Routing Service to reset the Domain Participant PartitionQoS back to "Default" string.
  - Sends a Remote Administration command to disable all Sessions enabling Topics over the PLATFORM_TEAM_CHANNEL.
- **Routing Service:**
  - Receives the Remote Admin commands from the autonomy application
  - Updates the Domain Participant PartitionQoS for the WAN_DOMAIN Participant to reflect "Default"
  - Disables specific Sessions defined by the PLATFORM_TEAM_CHANNEL.

**Result:**
- The Platforms stop discovering each other and return to the "Light" monitoring state on the WAN_DOMAIN, ready for reassignment.

