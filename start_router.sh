#!/bin/bash

# (c) Copyright, Real-Time Innovations, 2025.  All rights reserved.
# RTI grants Licensee a license to use, modify, compile, and create derivative
# works of the software solely for use with RTI Connext DDS. Licensee may
# redistribute copies of the software provided that all such copies are subject
# to this license. The software is provided "as is", with no warranty of any
# type, including any warranty for fitness for any purpose. RTI is under no
# obligation to maintain or support the software. RTI shall not be liable for
# any incidental or consequential damages arising out of the use or inability
# to use the software.



# NOTE: Source a platform/c2 ENV script before running

# Check NDDSHOME variable
if [[ -z "${NDDSHOME}" ]]; then
    echo "Must set the NDDSHOME environment variable "
    exit 1;
fi

# XML Files
export NDDS_QOS_PROFILES=""

# WAN QoS
NDDS_QOS_PROFILES+="./qos/wan_qos_lib.xml;"

# LAN QoS
NDDS_QOS_PROFILES+="./qos/lan_qos_lib.xml;"

# Remote Admin QoS
NDDS_QOS_PROFILES+="./qos/remoteadmin_qos_lib.xml;"

# Routing Service file
NDDS_QOS_PROFILES+="./router_config/routing_service_config.xml"


################################################################################
#                                 VERBOSITY                                    #
################################################################################

# Controls what type of messages are logged.
# <service_level> is the verbosity level for the service logs
# <dds_level> is the verbosity level for the DDS logs. 

# Both can take any of the following values:
# | SILENT      | No messages will be logged. (lowest verbosity) |
# | ERROR       | Log only high-priority error messages. (default) |
# | WARN        | Log warning and error messages. |
# | LOCAL       | Log verbose info, warnings, and errors about local Connext objects. |
# | REMOTE      | Log verbose info, warnings, and errors about remote objects. |

# Format:  <service_level>[:<dds_level>]
# Default: ERROR:ERROR

verbosity=ERROR:ERROR


################################################################################
#                               WAN PARAMETERS                                 #
################################################################################

# These settings are used through the config files to modify parameters as needed

# Multicast TTL for the WAN network
export WAN_TTL=6

# Max latency of the WAN link
export WAN_LATENCY_SEC=1.5 # Seconds

# Timeout for WAN > intermittent loss of comms
export WAN_TIMEOUT_SEC=300 # Seconds




#### Calculated from above

# Set Heartbeat Period to 2X WAN Latency for Reliability Mechanism
export WAN_HB_PERIOD_SEC=$(echo "$WAN_LATENCY_SEC*2" | bc | awk '{print int($1)}')

# Set HB Retries to WAN TIMEOUT/HB PERIOD
# This defines how many unresponsive HB's will be sent out before the Reader is removed
export WAN_HB_RETRIES=$(echo "$WAN_TIMEOUT_SEC/$WAN_HB_PERIOD_SEC" | bc | awk '{print int($1)}')

# Set Max Blocking Time to 10X RTT Time to give enough time for Samples to be received/acknowledged
export WAN_MAX_BLOCKING_SEC=$(echo "$WAN_LATENCY_SEC*10" | bc | awk '{print int($1)}')

################################################################################
#                                 DATA CHANNELS                                #
################################################################################
# CHANNELS are a combination of Topic Routes, QOS, and Partitions
# - Topic Routes automatically generate Readers and Writers per list of Topics
# - This group of Topics is associated per Data Pattern Behavior so the correct QoS is applied
# - Partitions are applied per Channel so as to match ONLY with other C2's, Platforms etc


# Comma separated, no spaces, NULL if empty 
# Can use wildcards such as *Status

export PLATFORM_EVENT_CHANNEL=PlatformCommandAck,ContactReport # PLATFORM -> C2 (Aperiodic- RELIABLE.)

export PLATFORM_STATUS_FULL_CHANNEL=NULL # PLATFORM -> C2 (Periodic- Full Rate- BEST_EFFORT)
export PLATFORM_STATUS_1SEC_CHANNEL=NULL # PLATFORM -> C2 (Periodic- Downsampled to every 1 Sec - BEST_EFFORT)
export PLATFORM_STATUS_10SEC_CHANNEL=PlatformStatus # PLATFORM -> C2 (Periodic- Downsampled to every 10 Secs - BEST_EFFORT)
export PLATFORM_STATUS_30SEC_CHANNEL=NULL # PLATFORM -> C2 (Periodic- Downsampled to every 30 Secs - BEST_EFFORT)
export PLATFORM_STATUS_60SEC_CHANNEL=NULL # PLATFORM -> C2 (Periodic- Downsampled to every 60 Secs - BEST_EFFORT)

export PLATFORM_TO_PLATFORM_CHANNEL=PlatformData # Platform -> Platform (Periodic- Full Rate - BEST_EFFORT)
export C2_EVENT_CHANNEL=NULL # C2 -> Platform (Aperiodic, RELIABLE)


# Use this channel to send commands to ONLY the specific platform based on a field match (GUID etc.) 
# Only use if Command Message Field and Match are set correctly
export C2_COMMAND_FILTER_CHANNEL=C2Command # C2 -> Platform Filtered by field match (Aperiodic, RELIABLE)
export C2_COMMAND_FILTER_FIELD=msg.destination # Specific field within message used for filtering
export C2_COMMAND_FILTER_MATCH=$ROUTER_NAME # Use the Routers Name to only receive messages addressed to it



################################################################################

echo "
------------------------------ROUTER CONFIGS------------------------------------
XML FILES used:  $NDDS_QOS_PROFILES
TYPE: $TYPE
ROUTER_NAME: $ROUTER_NAME
LAN_QOS_PROFILE: $LAN_QOS_PROFILE
SESSION_ID: $SESSION_ID
DOMAIN_ID: $DOMAIN_ID
DESTINATION: $DESTINATION
Logging Verbosity: $verbosity


-------------------------------CHANNELS-----------------------------------------
PLATFORM_EVENT_CHANNEL:  $PLATFORM_EVENT_CHANNEL
PLATFORM_STATUS_FULL_CHANNEL: $PLATFORM_STATUS_FULL_CHANNEL
PLATFORM_STATUS_1SEC_CHANNEL:  $PLATFORM_STATUS_1SEC_CHANNEL
PLATFORM_STATUS_10SEC_CHANNEL:  $PLATFORM_STATUS_10SEC_CHANNEL
PLATFORM_STATUS_30SEC_CHANNEL:  $PLATFORM_STATUS_30SEC_CHANNEL
PLATFORM_STATUS_60SEC_CHANNEL:  $PLATFORM_STATUS_60SEC_CHANNEL
PLATFORM_TO_PLATFORM_CHANNEL:  $PLATFORM_TO_PLATFORM_CHANNEL
C2_EVENT_CHANNEL:  $C2_EVENT_CHANNEL

C2_COMMAND_FILTER_CHANNEL:  $C2_COMMAND_FILTER_CHANNEL
C2_COMMAND_FILTER_FIELD: $C2_COMMAND_FILTER_FIELD
C2_COMMAND_FILTER_MATCH: $C2_COMMAND_FILTER_MATCH

-----------------------------WAN CONFIGS----------------------------------------
WAN_TTL = $WAN_TTL
WAN_LATENCY_SEC = $WAN_LATENCY_SEC Seconds
WAN_TIMEOUT_SEC = $WAN_TIMEOUT_SEC Seconds
WAN_HB_PERIOD_SEC = $WAN_HB_PERIOD_SEC Seconds
WAN_HB_RETRIES = $WAN_HB_RETRIES
WAN_MAX_BLOCKING_SEC = $WAN_MAX_BLOCKING_SEC Seconds

-------------------------------- ROUTER CONFIGS: --------------------------------"


# Run Routing Service
$NDDSHOME/bin/rtiroutingservice -appName $ROUTER_NAME -cfgName $TYPE -verbosity $verbosity