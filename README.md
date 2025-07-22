# rticonnextdds-usecases-act

# Overview 
Routing Service architecture for Autonomous Collaborative Teaming use case to  
manage message flow between Platforms and C2(Command and Control) stations.

The system has been separated into 3 domains:
- Platform (Vehicle or Platform network): Domain 1
- WAN Domain (Communications network i.e. Sattellite, Mesh Radio): Domain 2
- C2 Domain (C2 Network- Groundstations etc.): Domain 3

Routing Service acts as a relay mechanism between the *internal* LAN messaging and  
the *external* WAN Domain.

Performs the following roles:
- Dynamic instantiation of readers/writers based on a regex match filter
- Dynamic application of QoS per Routes
- Segmentation of traffic at the logical layer between LAN and WAN environments
- Routing of selected topics between *only*:
  - Platform - C2
  - C2 - Platform
  - Platform - Platform
- Dynamic discovery of Platforms/C2 systems
- Dynamic pub/sub architecture of one-to-many/many-to-one between C2 and Platforms

## Directions
Default configurations are set at the top of `router_config/routing_service_config.xml`  
within the `<configuration_variables>` tag section.

A reference start script `./start_router.sh` has been included to highlight example usage.

All configurations in the Routing Service config file can be overridden using ENV variables.

An end user would only need to modify the high level variables in the start script  
and not even touch the xml file.


The QoS has been setup in `./act_qos_lib.xml` for 2 common patterns of   
- Status (Periodic data without reliability mechanism)
- Events (Aperiodic data i.e. Commands/ContactReports- ensure delivery)

See Included System Block Diagram for more info.


## Use Case:
- Platforms must be able to receive select topics from C2 with [RELIABLE](#reliable-delivery) delivery 
- Platforms must be able to receive select topics from other Platforms with [Best Effort](#best_effort-delivery) delivery [Platform to Platform](#platform-to-platform)
- Platforms must be able to receive *only* commands addressed to a destination GUID with [RELIABLE](#reliable-delivery) delivery[C2 GUID Commands](#guid-commands)
- *Only* any C2 must be able to receive select topics from Platforms with [RELIABLE](#reliable-delivery) delivery [Platform Events](#platform-events)
- C2 must be able to receive select downsampled topics from Platforms with [Best Effort](#best_effort-delivery) delivery [Platform Status](#platform-status) 
- All Platforms and C2 have automatic discovery of other Platforms and C2 endpoints


## RELIABLE delivery
For data that is sent Aperiodically such as Commands and Events, we want to ensure  
delivery of the message. We do this by applying a resend mechanism that we can adjust  
at the user space level.

After sending a *RELIABLE* message, will send out "heartbeats" either piggybacked  
with another message or separately. A response will be sent back if the expected  
message sequence has been received. If not, another copy will be sent out again.  

For example, in `start_router.sh`, the `*EVENT*` Topic variables assign an appropriate QoS as  
defined in `./qos/act_qos_lib.xml` in profile `WAN::event_qos`.

The `event_qos` sets the Reliability QoS to `RELIABLE`. This enables the resend mechanism.  

This allows us to control different data "lanes" behaviour separately as needed.

## BEST_EFFORT delivery
For data that is sent Periodically such as Status updates, we generally aren't  
too concerned if we miss a sample as there will be another one coming along shortly.  

In `start_router.sh`, the `*STATUS*` Topic variables assign an appropriate QoS as  
defined in `./qos/act_qos_lib.xml` in profile `WAN::status_qos`.

The `status_qos` sets the Reliability QoS to BEST_EFFORT. This just sends the  
message once and does *NOT* apply any resend mechanism.

This allows us to control different data "lanes" behaviour separately as needed.



## C2 to Platform
In `start_router.sh`, the `C2_EVENT_TOPICS` ENV variables can be   
modified to move topic messages(i.e."ContactReport") RELIABLY to *only* Platforms.

QoS applied for this "Data Lane" is `event_qos` i.e. RELIABLE reliability with  
the assumption the data is being sent aperiodically.


### Test:
In `start_router.sh`, ensure the `ContactReport` topic is assigned to the 
`C2_EVENT_TOPICS` variable.

1. Start Platform-10 sim
- `source ./platform_10.sh`
-  `./start_sim.sh`  

2. Start Platform-10 Routing Service
- `source ./platform_10.sh`
- `./start_router.sh`  

3. Start a second Platform sim (Platform-11)
*NOTE: This isolates this Platform from the other one similar to a VLAN to simulate physical isolation*
- `source ./platform_11.sh`
-  `./start_sim.sh`  

2. Start Platform-11 Routing Service
- `source ./platform_11.sh`
- `./start_router.sh`  

5. Start C2-21 sim
- `source ./c2.21.sh`
-  `./start_sim.sh`  

6. Start a C2-21 Routing Service
- `source ./c2.21.sh`
- `./start_router.sh`  

#### Pass criteria:
- Ensure `ContactReport` topics are *only* received on Platforms



## Platform to Platform
In `start_router.sh`, the `PLATFORM_TO_PLATFORM_TOPICS` ENV variables can be   
modified to move topic messages(i.e.`PlatformData`) between *only* Platforms.

QoS applied for this "Data Lane" is `status_qos` i.e. BEST_EFFORT reliability with  
the assumption the data is being sent periodically.

This can be modified in `./routing_service_config.xml` with the `WAN_P2P_QOS` variable.  

### Test:
In `start_router.sh`, ensure the `PlatformData` topic is assigned to the 
`PLATFORM_TO_PLATFORM_TOPICS` variable.

1. Start Platform-10 sim
- `source ./platform_10.sh`
-  `./start_sim.sh`  

2. Start Platform-10 Routing Service
- `source ./platform_10.sh`
- `./start_router.sh`  

3. Start a second Platform sim (Platform-11)
*NOTE: This isolates this Platform from the other one similar to a VLAN to simulate physical isolation*
- `source ./platform_11.sh`
-  `./start_sim.sh`  

2. Start Platform-11 Routing Service
- `source ./platform_11.sh`
- `./start_router.sh`  

5. Start C2-21 sim
- `source ./c2.21.sh`
-  `./start_sim.sh`  

6. Start a C2-21 Routing Service
- `source ./c2.21.sh`
- `./start_router.sh`  

#### Pass criteria:
- Ensure `PlatformData` topics are *only* received on Platforms


## GUID Commands
In `start_router.sh`, the `C2_COMMAND_GUID_FILTER_TOPICS` ENV variables can be   
modified to move the "Command" topic messages from the C2 to *only* the addressed PLATFORM.

A Content Filter has been applied on the `destination_id` field in  
`routing_service_config.xml` `wan_to_platform` route.

This filters at the *writer* side i.e. only the message to the destined PLATFORM is  
sent and the other PLATFORM's are ignored.

This example is set up so the GUID in `platform_10.sh` match the destination GUID  
of `c2_21.sh`

### Test:
In `start_router.sh`, ensure the `C2Command` topic is assigned to the 
`C2_COMMAND_GUID_FILTER_TOPICS` variable.

1. Start Platform-10 sim
- `source ./platform_10.sh`
-  `./start_sim.sh`  

2. Start Platform-10 Routing Service
- `source ./platform_10.sh`
- `./start_router.sh`  

3. Start a second Platform sim (Platform-11)
*NOTE: This isolates this Platform from the other one similar to a VLAN to simulate physical isolation*
- `source ./platform_11.sh`
-  `./start_sim.sh`  

2. Start Platform-11 Routing Service
- `source ./platform_11.sh`
- `./start_router.sh`  

5. Start C2-21 sim
- `source ./c2.21.sh`
-  `./start_sim.sh`  

6. Start a C2-21 Routing Service
- `source ./c2.21.sh`
- `./start_router.sh`  

#### Pass criteria:
- Commands are *only* being received by Platform-10


## Platform Events
In `start_router.sh`, the `PLATFORM_EVENT_TOPICS` ENV variables can be   
modified to move the desired "Event"(`CommandAck`,`ContactReport` etc.) topics from  
the Platform to *any* C2 station. 

As the `ContactReport` Topic is published and subscribed to by both C2 and PLATFORM,  
Partitions have been applied to isolate the data planes.  

This constrains the data flow so Platforms will *only* receive ContactReports  
from other C2 stations and C2 stations will only receive ContactReports from Platforms. 

Partitions can be adjusted with XML as needed.


### Test:
In `start_router.sh`, ensure the `PlatformCommandAck` and `ContactReport` topics  
are assigned to the `PLATFORM_EVENT_TOPICS` variable.

1. Start Platform-10 sim  
- `source ./platform_10.sh`  
-  `./start_sim.sh`  

2. Start Platform-10 Routing Service  
- `source ./platform_10.sh`  
- `./start_router.sh`  

3. Start a second Platform sim (Platform-11)  
*NOTE: This isolates this Platform from the other one similar to a VLAN to simulate physical isolation*  
- `source ./platform_11.sh`  
-  `./start_sim.sh`  

2. Start Platform-11 Routing Service  
- `source ./platform_11.sh`  
- `./start_router.sh`  

5. Start C2-21 sim  
- `source ./c2.21.sh`  
-  `./start_sim.sh`  

6. Start a C2-21 Routing Service  
- `source ./c2.21.sh`  
- `./start_router.sh`  

#### Pass criteria:
- C2 will be receiving selected `PLATFORM_EVENT_TOPICS` topic messages from *only* "Platform" source type
- PLATFORM's will be receiving selected `PLATFORM_EVENT_TOPICS` topic messages from *only* "C2" source type


## Platform Status
In `start_router.sh`, the `PLATFORM_<RATE>_STATUS_TOPICS` ENV variables can be   
modified to move the desired status topics from the Platform to *any* C2 station. 

Topics can be downsampled to different rates by using the desired filter.

### Test:
In `start_router.sh`, ensure the `PlatformData` topic is assigned to the desired   
`PLATFORM_<RATE>_STATUS_TOPICS` variable.

1. Start Platform-10 sim  
- `source ./platform_10.sh`  
-  `./start_sim.sh`  

2. Start Platform-10 Routing Service  
- `source ./platform_10.sh`  
- `./start_router.sh`  

3. Start C2-21 sim  
- `source ./c2.21.sh`  
-  `./start_sim.sh`  

4. Start a C2-21 Routing Service  
- `source ./c2.21.sh`  
- `./start_router.sh`  

#### Pass criteria:
- C2 will be receiving selected `PLATFORM_<RATE>_STATUS_TOPICS` messages at the  
desired downsampled rate
