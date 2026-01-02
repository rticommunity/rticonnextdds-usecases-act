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

################################################################################
# SYSTEM PARAMETERS
################################################################################
# This is the default system_params.sh file for the ACT use case.
# Location: params/system_params.sh
#
# These parameters are shared across all nodes in the system.
# Paths are relative to this file's location (params/).
################################################################################

# XML Files
export NDDS_QOS_PROFILES=""

# WAN QoS (relative path from params/ to config/qos/)
NDDS_QOS_PROFILES+="../config/qos/wan_qos_lib.xml;"

# LAN QoS
NDDS_QOS_PROFILES+="../config/qos/lan_qos_lib.xml;"

# Remote Admin QoS
NDDS_QOS_PROFILES+="../config/qos/remoteadmin_qos_lib.xml;"

# Routing Service file (relative path from params/ to config/routing/)
NDDS_QOS_PROFILES+="../config/routing/routing_service_config.xml"

echo "
-----------------------------XML PROFILES---------------------------------------
NDDS_QOS_PROFILES = $NDDS_QOS_PROFILES
-----------------------------XML PROFILES---------------------------------------"


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

echo "
-----------------------------WAN PARAMETERS-------------------------------------
WAN_TTL = $WAN_TTL
WAN_LATENCY_SEC = $WAN_LATENCY_SEC Seconds
WAN_TIMEOUT_SEC = $WAN_TIMEOUT_SEC Seconds
WAN_HB_PERIOD_SEC = $WAN_HB_PERIOD_SEC Seconds
WAN_HB_RETRIES = $WAN_HB_RETRIES
WAN_MAX_BLOCKING_SEC = $WAN_MAX_BLOCKING_SEC Seconds

-----------------------------WAN PARAMETERS-------------------------------------"

################################################################################
#                                 DATA CHANNELS                                #
################################################################################

# Comma separated, no spaces, NULL if empty 

# Platform Event Topics that are Aperiodic and need samples resent if dropped
export PLATFORM_EVENTS_CHANNEL=PlatformCommandAck,ContactReport

# Platform Status Topics that will be published by default such as Position/high level status
# Downsampled to 1 HZ
export PLATFORM_PRIMARY_STATUS_1HZ_CHANNEL=PlatformStatus

# Platform Status Topics to be enabled dynamically, FULL rate
export PLATFORM_FULL_STATUS_CHANNEL=NULL

# Platform topics to be shared within the Team
export PLATFORM_TEAM_COMMS_CHANNEL=PlatformData

# Controller Topics such as ContactReports etc. resent if dropped
export CONTROLLER_EVENTS_CHANNEL=NULL

# Controller Commands filtered by destination
export CONTROLLER_COMMANDS_CHANNEL=C2Command

# Message field to filter on for Commands Destination
export C2_COMMAND_FILTER_FIELD=msg.destination

# Value to use as Filter- In this case unique identifier of Router Name
export C2_COMMAND_FILTER_MATCH=$ROUTER_NAME

echo "
-----------------------------DATA CHANNELS--------------------------------------
PLATFORM_EVENTS_CHANNEL = $PLATFORM_EVENTS_CHANNEL
PLATFORM_FULL_STATUS_CHANNEL = $PLATFORM_FULL_STATUS_CHANNEL
PLATFORM_PRIMARY_STATUS_1HZ_CHANNEL = $PLATFORM_PRIMARY_STATUS_1HZ_CHANNEL
PLATFORM_TEAM_COMMS_CHANNEL = $PLATFORM_TEAM_COMMS_CHANNEL
CONTROLLER_EVENTS_CHANNEL = $CONTROLLER_EVENTS_CHANNEL
CONTROLLER_COMMANDS_CHANNEL = $CONTROLLER_COMMANDS_CHANNEL
C2_COMMAND_FILTER_FIELD = $C2_COMMAND_FILTER_FIELD
C2_COMMAND_FILTER_MATCH = $C2_COMMAND_FILTER_MATCH
-----------------------------DATA CHANNELS--------------------------------------"

################################################################################