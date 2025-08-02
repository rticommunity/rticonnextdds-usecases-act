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

# Roundtrip Time of the system
export WAN_RTT_SEC=1.5 # Seconds

# Timeout for WAN > intermittent loss of comms
export WAN_TIMEOUT_SEC=300 # Seconds




#### Calculated from above

# Set Heartbeat Period to 2X RTT for Reliability Mechanism
export WAN_HB_PERIOD_SEC=$(echo "$WAN_RTT_SEC*2" | bc | awk '{print int($1)}')

# Set HB Retries to WAN TIMEOUT/HB PERIOD
# This defines how many unresponsive HB's will be sent out before the Reader is removed
export WAN_HB_RETRIES=$(echo "$WAN_TIMEOUT_SEC/$WAN_HB_PERIOD_SEC" | bc | awk '{print int($1)}')

# Set Max Blocking Time to 10X RTT Time to give enough time for Samples to be received/acknowledged
export WAN_MAX_BLOCKING_SEC=$(echo "$WAN_RTT_SEC*10" | bc | awk '{print int($1)}')

################################################################################
#                                 DATA CHANNELS                                #
################################################################################
# CHANNELS are a combination of Topic Routes, QOS, and Partitions
# - Topic Routes automatically generate Readers and Writers per list of Topics
# - This group of Topics is associated per Data Pattern Behavior so the correct QoS is applied
# - Partitions are applied per Channel so as to match ONLY with other C2's, Platforms etc


# Comma separated, no spaces, NULL if empty 
# Can use wildcards such as *Status

export PLATFORM_EVENT_CHANNEL=PlatformCommandAck,ContactReport #PLATFORM -> C2 (Aperiodic- Ensured Delivery CommandAck etc.)

export PLATFORM_STATUS_FULL_CHANNEL=NULL #PLATFORM -> C2 (Periodic- Full Rate)
export PLATFORM_STATUS_1SEC_CHANNEL=NULL #PLATFORM -> C2 (Periodic- Downsampled to every 1 Sec)
export PLATFORM_STATUS_10SEC_CHANNEL=PlatformStatus #PLATFORM -> C2 (Periodic- Downsampled to every 10 Secs)
export PLATFORM_STATUS_30SEC_CHANNEL=NULL #PLATFORM -> C2 (Periodic- Downsampled to every 30 Secs)
export PLATFORM_STATUS_60SEC_CHANNEL=NULL #PLATFORM -> C2 (Periodic- Downsampled to every 60 Secs)

export PLATFORM_TO_PLATFORM_CHANNEL=PlatformData #Platform -> Platform (Periodic- Full Rate)

export C2_COMMAND_FILTER_CHANNEL=C2Command #C2 -> Platform Aperiodic- (Targeted delivery by GUID address)
export C2_EVENT_CHANNEL=ContactReport

################################################################################

echo "
-------------------------------- ROUTER CONFIGS: --------------------------------
XML FILES used:  $NDDS_QOS_PROFILES
PLATFORM_EVENT_CHANNEL:  $PLATFORM_EVENT_CHANNEL
PLATFORM_STATUS_FULL_CHANNEL: $PLATFORM_STATUS_FULL_CHANNEL
PLATFORM_STATUS_1SEC_CHANNEL:  $PLATFORM_STATUS_1SEC_CHANNEL
PLATFORM_STATUS_10SEC_CHANNEL:  $PLATFORM_STATUS_10SEC_CHANNEL
PLATFORM_STATUS_30SEC_CHANNEL:  $PLATFORM_STATUS_30SEC_CHANNEL
PLATFORM_STATUS_60SEC_CHANNEL:  $PLATFORM_STATUS_60SEC_CHANNEL
C2_COMMAND_FILTER_CHANNEL:  $C2_COMMAND_FILTER_CHANNEL
C2_EVENT_CHANNEL:  $C2_EVENT_CHANNEL
PLATFORM_TO_PLATFORM_CHANNEL:  $PLATFORM_TO_PLATFORM_CHANNEL

ROUTER_NAME = $ROUTER_NAME

WAN_TTL = $WAN_TTL
WAN_RTT_SEC = $WAN_RTT_SEC Seconds
WAN_TIMEOUT_SEC = $WAN_TIMEOUT_SEC Seconds
WAN_HB_PERIOD_SEC = $WAN_HB_PERIOD_SEC Seconds
WAN_HB_RETRIES = $WAN_HB_RETRIES
WAN_MAX_BLOCKING_SEC = $WAN_MAX_BLOCKING_SEC Seconds

Logging Verbosity: $verbosity
-------------------------------- ROUTER CONFIGS: --------------------------------"


# Run Routing Service
$NDDSHOME/bin/rtiroutingservice -appName $ROUTER_NAME -cfgName $TYPE -verbosity $verbosity