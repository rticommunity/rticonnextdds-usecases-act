# Overview 
Routing Service architecture for Autonomous Collaborative Teaming use case to  
manage message flow between Platforms and C2(Command and Control) stations.

This use case is centered around a Maritime ISR scenario but can be adopted for  
other similar needs.

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
- Dynamic instantiation of readers/writers based on a regex match filter per *Channel*.
- Dynamic application of QoS per *Channel*
- Segmentation of traffic at the network layer(using DDS Domains) between LAN and WAN environments
- Routing of selected topics between the following per *Channel*:
  - Platform -> C2
  - C2 -> Platform
  - Platform <-> Platform
- Dynamic discovery of Platforms/C2 systems
- Dynamic pub/sub architecture of one-to-many/many-to-one between C2 and Platforms


## Transports
Currently the transport over the WAN is configured to use Multicast UDPv4 for discovery and unicast UDPv4  
for data flow. This can be changed with XML configuration to use other options such as:
- Unicast UDPv4 for Discovery (IP addresses, DNS Domain names or a [Discovery Service](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/addon_products/cloud_discovery_service/index.html))  
- [TCP](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/users_manual/users_manual/PartTCP.htm)  
- [UDPv6](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/users_manual/users_manual/Setting_Builtin_Transport_Properties_wit.htm#Table_PropertiesForBuiltinUDPv6Transport)  
- [Real Time WAN transport for NAT traversal etc.](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/users_manual/users_manual/PartRealtimeWAN.htm)  


## Network Settings
Connext by default will attempt to use all Network Interfaces provided by the OS.  
However as required, interfaces can be constrained with [allow/deny lists](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/users_manual/users_manual/Setting_Builtin_Transport_Properties_wit.htm#Table_PropertiesBuiltinUDPv4Transport) and [prioritized](https://community.rti.com/kb/how-do-i-restrict-and-prioritize-interfaces-rti-connext-use) using max_interfaces_list.  
Connext also has the ability to [move message fragmentation to the DDS layer](https://community.rti.com/static/documentation/connext-dds/7.5.0/doc/manuals/connext_dds_professional/users_manual/users_manual/LargeData_Fragmentation.htm) in situations where a low MTU size is causing   
excessive IP fragment re-assembly errors.

## Directions
Default configurations are set at the top of `router_config/routing_service_config.xml`  
within the `<configuration_variables>` tag section.

A reference start script `./start_router.sh` has been included to highlight example usage.

All configurations in the Routing Service config file can be overridden using ENV variables.

An end user would only need to modify the high level variables in the start script  
and not even touch the xml file.


The QoS has been setup in `./qos/act_qos_lib.xml` for 2 common patterns of   
- Status (Periodic data)
- Events (Aperiodic data i.e. Commands/ContactReports- "ensure delivery" [RELIABLE](#reliable-delivery))

See Block Diagram below:
![ACT Routing Architecture](/images/act_routing_arch.jpeg)




## RELIABLE delivery
For data that is sent Aperiodically such as Commands and Events, we want to ensure  
delivery of the message.  
We do this by applying a resend mechanism (RELIABILTY QoS: RELIABLE) that we can adjust  
at the user space level.

This allows us to control different data "channels" behaviour separately as needed.

More info see [manual](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/users_manual/users_manual/RELIABILITY_QosPolicy.htm#sending_2410472787_2023245).  

## BEST_EFFORT delivery
For data that is sent Periodically such as Status updates, we generally aren't  
too concerned if we miss a sample as there will be another one coming along shortly.  

For this data pattern we set the Reliability QoS to BEST_EFFORT.  

This allows us to control different data "channels" behaviour separately as needed.

More info see [manual](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/users_manual/users_manual/RELIABILITY_QosPolicy.htm#sending_2410472787_2023245).  


## Data "Channels"
In `./start_router.sh` you will see a section titled "Data Channels".  
These variables are used to move selected topics from the Platform to C2  
and apply the appropriate QoS per Data Pattern such a Status(Periodic, [BEST_EFFORT](#best_effort-delivery))  
and Event(Aperiodic, [RELIABLE](#reliable-delivery)).  

By using these "*Channels*" in the Start Routing script, you can abstract away lower  
level configuration/management and just focus on selecting the right "*Channel*" for your  
Topic to be added into.  
(REGEX matching is used including wildcards so `*Status` will match with any prefix.)    

### Data Channels Logical View
![ACT Data Channels Logical View](/images/act_channels.jpeg)


## C2 Events
In `start_router.sh`, the `C2_EVENT_CHANNEL` [Channel](#data-channels) is used to move topic   
messages(i.e."ContactReport") to *only* Platforms.

QoS applied to this [Channel](#data-channels) is `event_qos` configured for Reliability QoS kind:[RELIABLE](#reliable-delivery)  
with the assumption the data is being sent aperiodically.


### Test:
In `start_router.sh`, ensure the `ContactReport` topic is assigned to the  
`C2_EVENT_CHANNEL` [Channel](#data-channels) .

1. Start Platform-10 sim
- `source ./platform_10.sh`
-  `./start_sim.sh`  

2. Start Platform-10 Routing Service
- `source ./platform_10.sh`
- `./start_router.sh`  

3. Start a second Platform sim (Platform-11) in a different DDS Domain  
*NOTE: This isolates this Platform from the other one similar to a VLAN to  
simulate physical isolation*
- `source ./platform_11.sh`
-  `./start_sim.sh`  

4. Start Platform-11 Routing Service
- `source ./platform_11.sh`
- `./start_router.sh`  

5. Start C2-20 sim
- `source ./c2_20.sh`
-  `./start_sim.sh`  

6. Start a C2-20 Routing Service
- `source ./c2_20.sh`
- `./start_router.sh`  

#### Pass criteria:
- Ensure the `C2_EVENT_CHANNEL` topics are *only* received on Platforms from C2 source type


## Filtered Commands
In `start_router.sh`, the `C2_COMMAND_FILTER_CHANNEL` [Channels](#data-channels) is used to move  
the "Command" topic messages from the C2 to *only* the addressed PLATFORM.

The QoS applied for this route across the WAN is the `WAN_EVENT_QOS` which sets  
the Reliability QoS to kind: [RELIABLE](#reliable-delivery)

A Content Filter has been applied on the `destination` field in  
`routing_service_config.xml` `wan_to_platform` route.

This filters at the *writer* side i.e. only the message to the destined PLATFORM is  
sent and the other PLATFORM's are ignored.

This example is set up so the `ROUTER_NAME` in `platform_10.sh` matches the destination  
of `c2_20.sh`

### Test:
In `start_router.sh`, ensure the `C2Command` topic is assigned to the 
`C2_COMMAND_FILTER_CHANNEL` [Channel](#data-channels) .

1. Start Platform-10 sim
- `source ./platform_10.sh`
-  `./start_sim.sh`  

2. Start Platform-10 Routing Service
- `source ./platform_10.sh`
- `./start_router.sh`  

3. Start a second Platform sim (Platform-11) in a different DDS Domain  
*NOTE: This isolates this Platform from the other one similar to a VLAN to  
simulate physical isolation*
- `source ./platform_11.sh`
-  `./start_sim.sh`  

4. Start Platform-11 Routing Service
- `source ./platform_11.sh`
- `./start_router.sh`  

5. Start C2-20 sim
- `source ./c2_20.sh`
-  `./start_sim.sh`  

6. Start a C2-20 Routing Service
- `source ./c2_20.sh`
- `./start_router.sh`  

#### Pass criteria:
- Commands are *only* being received by Platform-10


## Platform Events
In `start_router.sh`, the `PLATFORM_EVENT_CHANNEL` [Channel](#data-channels) is used to move the  
desired "Event"(`CommandAck`,`ContactReport` etc.) topics from the Platform to *any* C2 station. 

The QoS applied for this route across the WAN is the `WAN_EVENT_QOS` which sets  
the Reliability QoS to kind: [RELIABLE](#reliable-delivery)

As the `ContactReport` Topic is published and subscribed to by both C2 and PLATFORM,  
(see `C2_EVENT_CHANNEL`) Partitions have been applied to isolate the data planes.  

This constrains the data flow so Platforms will *only* receive ContactReports  
from other C2 stations and C2 stations will only receive ContactReports from Platforms. 

Partitions can be adjusted with XML as needed.


### Test:
In `start_router.sh`, ensure the `PlatformCommandAck` and `ContactReport` topics  
are assigned to the `PLATFORM_EVENT_CHANNEL` [Channel](#data-channels) .

1. Start Platform-10 sim  
- `source ./platform_10.sh`  
-  `./start_sim.sh`  

2. Start Platform-10 Routing Service  
- `source ./platform_10.sh`  
- `./start_router.sh`  

3. Start a second Platform sim (Platform-11) in a different DDS Domain  
*NOTE: This isolates this Platform from the other one similar to a VLAN to  
simulate physical isolation*  
- `source ./platform_11.sh`  
-  `./start_sim.sh`  

4. Start Platform-11 Routing Service  
- `source ./platform_11.sh`  
- `./start_router.sh`  

5. Start C2-20 sim  
- `source ./c2_20.sh`  
-  `./start_sim.sh`  

6. Start a C2-20 Routing Service  
- `source ./c2_20.sh`  
- `./start_router.sh`  

#### Pass criteria:
- Ensure `PLATFORM_EVENT_CHANNEL` topics are *only* received on C2 from PLATFORM source type


## Platform Status
In `start_router.sh`, the `PLATFORM_STATUS_<RATE>_CHANNEL` [Channel](#data-channels) is used to move  
the desired status topics from the Platform to *any* C2 station.  

Topics can be downsampled to different rates by using the desired filter.

The QoS applied for this "Channel" across the WAN is the `WAN_STATUS_QOS` which sets  
the Reliability QoS kind to [BEST_EFFORT](#best_effort-delivery)

The Routing Service input reader QoS has a different time-based filter QoS applied per chosen channel  
to downsample the data before it is processed by the Routing Service.

This minimizes resource usage and optimizes overhead/bandwidth usage across the entire message path.

### Test:
In `start_router.sh`, ensure the `PlatformData` topic is assigned to the desired   
`PLATFORM_STATUS_<RATE>_CHANNEL` [Channel](#data-channels) .

1. Start Platform-10 sim  
- `source ./platform_10.sh`  
-  `./start_sim.sh`  

2. Start Platform-10 Routing Service  
- `source ./platform_10.sh`  
- `./start_router.sh`  

3. Start C2-20 sim  
- `source ./c2_20.sh`  
-  `./start_sim.sh`  

4. Start a C2-20 Routing Service  
- `source ./c2_20.sh`  
- `./start_router.sh`  

#### Pass criteria:
- C2 will be receiving selected `PLATFORM_STATUS_<RATE>_CHANNEL` messages at the  
desired downsampled rate



## Platform to Platform
In `start_router.sh`, the `PLATFORM_TO_PLATFORM_CHANNEL` [Channel](#data-channels) is used to move topic  
messages(i.e.`PlatformData`) between *only* Platforms.

QoS applied for this [Channel](#data-channels)  is `status_qos` i.e. Reliability QoS kind:[BEST_EFFORT](#best_effort-delivery)  
with the assumption that the data is being sent periodically.

This can be modified in `./routing_service_config.xml` with the `WAN_P2P_QOS` variable to select an event based behavior pattern if desired.    

### Test:
In `start_router.sh`, ensure the `PlatformData` topic is assigned to the  
`PLATFORM_TO_PLATFORM_CHANNEL` [Channel](#data-channels) .

1. Start Platform-10 sim
- `source ./platform_10.sh`
-  `./start_sim.sh`  

2. Start Platform-10 Routing Service
- `source ./platform_10.sh`
- `./start_router.sh`  

3. Start a second Platform sim (Platform-11) in a different DDS Domain  
*NOTE: This isolates this Platform from the other one similar to a VLAN to  
simulate physical isolation*
- `source ./platform_11.sh`
-  `./start_sim.sh`  

4. Start Platform-11 Routing Service
- `source ./platform_11.sh`
- `./start_router.sh`  

5. Start C2-20 sim
- `source ./c2_20.sh`
-  `./start_sim.sh`  

6. Start a C2-20 Routing Service
- `source ./c2_20.sh`
- `./start_router.sh`  

#### Pass criteria:
- Ensure `PlatformData` topics are *only* received on Platforms

