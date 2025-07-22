# Overview 
Routing Service architecture for Autonomous Collaborative Teaming use case to  
manage message flow between Platforms and C2(Command and Control) stations.

The system has been separated into 3 domains:
- Platform (Vehicle or Platform network)
- WAN Domain (Communications network i.e. Sat, Mesh Radio)
- C2 Domain (C2 Network- Groundstations etc.)

Routing Service acts as a relay mechanism between the *internal* LAN messaging and  
the *external* WAN Domain.

Performs the following roles:
- Dynamic instantiation of readers/writers based on a regex match filter
- Dynamic application of QoS per *Lanes*
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
- Platforms must be able to receive select topics from C2 with delivery [C2 Events](#c2-events)
- Platforms must be able to receive *only* commands addressed to a destination GUID with delivery [C2 GUID Commands](#guid-commands)
- *Only* any C2 must be able to receive select topics from Platforms with delivery [Platform Events](#platform-events)
- C2 must be able to receive select downsampled topics from Platforms with delivery [Platform Status](#platform-status) 
- Platforms must be able to receive select topics from other Platforms with delivery [Platform to Platform](#platform-to-platform)  
- All Platforms and C2 have automatic discovery of other Platforms and C2 endpoints


## RELIABLE delivery
For data that is sent Aperiodically such as Commands and Events, we want to ensure  
delivery of the message. We do this by applying a resend mechanism that we can adjust  
at the user space level.

After sending a *RELIABLE* message, Connext will send out "heartbeats" either piggybacked  
with another message or separately. A response will be sent back if the expected  
message sequence has been received. If not, another copy will be sent out again.  

For example, in `start_router.sh`, the `*EVENT*` Topic route assigns the `WAN_EVENT_QOS` QoS  
to be used across the WAN.  
Looking at `./router_config/routing_service_config.xml` this is defined in `./qos/act_qos_lib.xml`  
in profile `WAN::event_qos`.

The `event_qos` sets the Reliability QoS to `RELIABLE`. This enables the resend mechanism.  

This allows us to control different data "lanes" behaviour separately as needed.

## BEST_EFFORT delivery
For data that is sent Periodically such as Status updates, we generally aren't  
too concerned if we miss a sample as there will be another one coming along shortly.  

In `start_router.sh`, the `*STATUS*` [Lane](#data-lanes) assigns an appropriate QoS as  
defined in `./qos/act_qos_lib.xml` in profile `WAN::status_qos`.

The `status_qos` sets the Reliability QoS to BEST_EFFORT. This just sends the  
message once and does *NOT* apply any resend mechanism.

This allows us to control different data "lanes" behaviour separately as needed.


## Data "Lanes"
In `./start_router.sh` you will see a section titled "Data Lanes".
These variables are used to move selected topics from the Platform to C2  
and apply the appropriate QoS per Data Pattern such a Status(Periodic, [BEST_EFFORT](#best_effort-delivery))  
and Event(Aperiodic, [RELIABLE](#reliable-delivery)).  

By using these "*Lanes*" in the Start Routing script you can abstract away lower  
level configuration/management and just focus on selecting the right "*Lane*" for your  
Topic to be added into.
REGEX matching is used including wildcards such as * so `*Status` will match with  
all `*Status` topics.  
*NOTE: Comma separated list, no spaces*




## C2 Events
In `start_router.sh`, the `C2_EVENT` [Lane](#data-lanes) can be   
modified to move topic messages(i.e."ContactReport") RELIABLY to *only* Platforms.

QoS applied for this [Lane](#data-lanes) is `event_qos` configured for [RELIABLE](#reliable-delivery)  
reliability with the assumption the data is being sent aperiodically.


### Test:
In `start_router.sh`, ensure the `ContactReport` topic is assigned to the  
`C2_EVENT` [Lane](#data-lanes) .

1. Start Platform-10 sim
- `source ./platform_10.sh`
-  `./start_sim.sh`  

2. Start Platform-10 Routing Service
- `source ./platform_10.sh`
- `./start_router.sh`  

3. Start a second Platform sim (Platform-11)  
*NOTE: This isolates this Platform from the other one similar to a VLAN to  
simulate physical isolation*
- `source ./platform_11.sh`
-  `./start_sim.sh`  

4. Start Platform-11 Routing Service
- `source ./platform_11.sh`
- `./start_router.sh`  

5. Start C2-21 sim
- `source ./c2.21.sh`
-  `./start_sim.sh`  

6. Start a C2-21 Routing Service
- `source ./c2.21.sh`
- `./start_router.sh`  

#### Pass criteria:
- Ensure the `C2_EVENT` topics are *only* received on Platforms from C2 source type


## GUID Commands
In `start_router.sh`, the `C2_COMMAND_GUID_FILTER` [Lanes](#data-lanes can be   
modified to move the "Command" topic messages from the C2 to *only* the addressed PLATFORM.

The QoS applied for this route across the WAN is the `WAN_EVENT_QOS` which sets  
the Reliability QoS to [[RELIABILITY]](#reliable-delivery)

A Content Filter has been applied on the `destination_id` field in  
`routing_service_config.xml` `wan_to_platform` route.

This filters at the *writer* side i.e. only the message to the destined PLATFORM is  
sent and the other PLATFORM's are ignored.

This example is set up so the GUID in `platform_10.sh` match the destination GUID  
of `c2_21.sh`

### Test:
In `start_router.sh`, ensure the `C2Command` topic is assigned to the 
`C2_COMMAND_GUID_FILTER` [Lane](#data-lanes) .

1. Start Platform-10 sim
- `source ./platform_10.sh`
-  `./start_sim.sh`  

2. Start Platform-10 Routing Service
- `source ./platform_10.sh`
- `./start_router.sh`  

3. Start a second Platform sim (Platform-11)  
*NOTE: This isolates this Platform from the other one similar to a VLAN to  
simulate physical isolation*
- `source ./platform_11.sh`
-  `./start_sim.sh`  

4. Start Platform-11 Routing Service
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
In `start_router.sh`, the `PLATFORM_EVENT` [Lane](#data-lanes) can be   
modified to move the desired "Event"(`CommandAck`,`ContactReport` etc.) topics from  
the Platform to *any* C2 station. 

The QoS applied for this route across the WAN is the `WAN_EVENT_QOS` which sets  
the Reliability QoS to [[RELIABILITY]](#reliable-delivery)

As the `ContactReport` Topic is published and subscribed to by both C2 and PLATFORM,  
(see `C2_EVENT`) Partitions have been applied to isolate the data planes.  

This constrains the data flow so Platforms will *only* receive ContactReports  
from other C2 stations and C2 stations will only receive ContactReports from Platforms. 

Partitions can be adjusted with XML as needed.


### Test:
In `start_router.sh`, ensure the `PlatformCommandAck` and `ContactReport` topics  
are assigned to the `PLATFORM_EVENT` [Lane](#data-lanes) .

1. Start Platform-10 sim  
- `source ./platform_10.sh`  
-  `./start_sim.sh`  

2. Start Platform-10 Routing Service  
- `source ./platform_10.sh`  
- `./start_router.sh`  

3. Start a second Platform sim (Platform-11)  
*NOTE: This isolates this Platform from the other one similar to a VLAN to  
simulate physical isolation*  
- `source ./platform_11.sh`  
-  `./start_sim.sh`  

4. Start Platform-11 Routing Service  
- `source ./platform_11.sh`  
- `./start_router.sh`  

5. Start C2-21 sim  
- `source ./c2.21.sh`  
-  `./start_sim.sh`  

6. Start a C2-21 Routing Service  
- `source ./c2.21.sh`  
- `./start_router.sh`  

#### Pass criteria:
- Ensure `PLATFORM_EVENT` topics are *only* received on C2 from PLATFORM source type


## Platform Status
In `start_router.sh`, the `PLATFORM_<RATE>_STATUS` [Lane](#data-lanes) can be   
modified to move the desired status topics from the Platform to *any* C2 station. 

Topics can be downsampled to different rates by using the desired filter.

The QoS applied for this route across the WAN is the `WAN_STATUS_QOS` which sets  
the Reliability QoS to [[BEST_EFFORT]](#best_effort-delivery)

### Test:
In `start_router.sh`, ensure the `PlatformData` topic is assigned to the desired   
`PLATFORM_<RATE>_STATUS` [Lane](#data-lanes) .

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
- C2 will be receiving selected `PLATFORM_<RATE>_STATUS` messages at the  
desired downsampled rate



## Platform to Platform
In `start_router.sh`, the `PLATFORM_TO_PLATFORM` [Lane](#data-lanes) can be   
modified to move topic messages(i.e.`PlatformData`) between *only* Platforms.

QoS applied for this [Lane](#data-lanes)  is `status_qos` i.e. [BEST_EFFORT](#best_effort-delivery)  
reliability with the assumption the data is being sent periodically.

This can be modified in `./routing_service_config.xml` with the `WAN_P2P_QOS` variable.  

### Test:
In `start_router.sh`, ensure the `PlatformData` topic is assigned to the  
`PLATFORM_TO_PLATFORM` [Lane](#data-lanes) .

1. Start Platform-10 sim
- `source ./platform_10.sh`
-  `./start_sim.sh`  

2. Start Platform-10 Routing Service
- `source ./platform_10.sh`
- `./start_router.sh`  

3. Start a second Platform sim (Platform-11)  
*NOTE: This isolates this Platform from the other one similar to a VLAN to  
simulate physical isolation*
- `source ./platform_11.sh`
-  `./start_sim.sh`  

4. Start Platform-11 Routing Service
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

