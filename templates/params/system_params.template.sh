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
# SYSTEM PARAMETERS TEMPLATE
################################################################################
# Instructions:
# 1. This template is for creating deployment-specific system parameters
# 2. The repository now includes a default system_params.sh in config/params/
# 3. For deployment, copy and customize:
#    Example: cp config/params/system_params.sh my_deployment/params/system_params.sh
# 4. Update the paths below to point to your config/ folder
#    Example: ../config/qos/ (if params and config are at same level)
# 5. Adjust WAN parameters based on your network characteristics
# 6. Modify DATA CHANNELS to match your application data topics
#
# This file should be shared by all nodes in your deployment.
################################################################################


# XML Files
export NDDS_QOS_PROFILES=""

# UPDATE THESE PATHS based on your deployment structure
# If using config/params/system_params.sh as-is:
#   From config/params/system_params.sh to config/qos/ → ../qos/

# WAN QoS - UPDATE PATH
NDDS_QOS_PROFILES+="UPDATE_PATH_TO/config/qos/wan_qos_lib.xml;"

# LAN QoS - UPDATE PATH
NDDS_QOS_PROFILES+="UPDATE_PATH_TO/config/qos/lan_qos_lib.xml;"

# Remote Admin QoS - UPDATE PATH
NDDS_QOS_PROFILES+="UPDATE_PATH_TO/config/qos/remoteadmin_qos_lib.xml;"

# Routing Service file - UPDATE PATH
NDDS_QOS_PROFILES+="UPDATE_PATH_TO/config/routing/routing_service_config.xml"

echo "
-----------------------------XML PROFILES---------------------------------------
NDDS_QOS_PROFILES = $NDDS_QOS_PROFILES
-----------------------------XML PROFILES---------------------------------------"


################################################################################
#                               WAN PARAMETERS                                 #
################################################################################
# These settings are used throughout the config files to tune WAN behavior
# Adjust based on your network characteristics:
#   - WAN_TTL: Multicast Time-To-Live (hops)
#   - WAN_LATENCY_SEC: Expected round-trip time (seconds)
#   - WAN_TIMEOUT_SEC: Time before declaring node unreachable (seconds)
################################################################################

# Multicast TTL for the WAN network
export WAN_TTL=6

# Max latency of the WAN link (seconds)
export WAN_LATENCY_SEC=1.5

# Timeout for WAN > intermittent loss of comms (seconds)
export WAN_TIMEOUT_SEC=300


#### Calculated from above - DO NOT MODIFY

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
# Define which topics are routed on different channels
# Format: Comma separated topic names, no spaces
# Use "NULL" if no topics on that channel
################################################################################

# Platform event data (infrequent, important)
export PLATFORM_EVENT_CHANNEL=PlatformCommandAck,ContactReport

# Platform status at various rates
export PLATFORM_STATUS_FULL_CHANNEL=NULL
export PLATFORM_STATUS_1SEC_CHANNEL=NULL
export PLATFORM_STATUS_10SEC_CHANNEL=PlatformStatus
export PLATFORM_STATUS_30SEC_CHANNEL=NULL
export PLATFORM_STATUS_60SEC_CHANNEL=NULL

# Platform-to-platform communication
export PLATFORM_TO_PLATFORM_CHANNEL=PlatformData

# C2 event data
export C2_EVENT_CHANNEL=NULL

################################################################################
# C2 COMMAND FILTERING - CONTENT-BASED ROUTING
################################################################################
# These settings enable content-filtered routing so each platform receives
# ONLY the commands addressed specifically to it (not commands for other platforms)
#
# CRITICAL: These field names MUST match your actual message data structure!
#
# C2_COMMAND_FILTER_CHANNEL: Topic name for commands (e.g., "C2Command")
# C2_COMMAND_FILTER_FIELD:   Field path in the message that contains destination
#                            - Must match the actual field name in your IDL/data type
#                            - Examples: "msg.destination", "header.targetNode", "destinationId"
#                            - Use dot notation for nested fields
# C2_COMMAND_FILTER_MATCH:   Value to match against - typically set to $ROUTER_NAME
#                            - Each node will compare incoming commands' destination field
#                              against this value
#                            - Can be set to a specific value or use $ROUTER_NAME variable
#
# Example data structure:
#   struct C2Command {
#     CommandHeader msg;      // Contains: string destination;
#     string commandType;
#     ...
#   };
#   → Use C2_COMMAND_FILTER_FIELD=msg.destination
#
# The filter works by: 
#   - Reading the C2_COMMAND_FILTER_FIELD from each message
#   - Comparing it to C2_COMMAND_FILTER_MATCH
#   - Only routing messages where they match
################################################################################

# C2 command filtering (content-filtered to specific destinations)
export C2_COMMAND_FILTER_CHANNEL=C2Command
export C2_COMMAND_FILTER_FIELD=msg.destination
# UPDATE THIS: Set to the value that should match for this deployment
# Use $ROUTER_NAME to match against the node's router name, or set a specific value
export C2_COMMAND_FILTER_MATCH=$ROUTER_NAME

echo "
-----------------------------DATA CHANNELS--------------------------------------
PLATFORM_EVENT_CHANNEL = $PLATFORM_EVENT_CHANNEL
PLATFORM_STATUS_FULL_CHANNEL = $PLATFORM_STATUS_FULL_CHANNEL
PLATFORM_STATUS_1SEC_CHANNEL = $PLATFORM_STATUS_1SEC_CHANNEL
PLATFORM_STATUS_10SEC_CHANNEL = $PLATFORM_STATUS_10SEC_CHANNEL
PLATFORM_STATUS_30SEC_CHANNEL = $PLATFORM_STATUS_30SEC_CHANNEL
PLATFORM_STATUS_60SEC_CHANNEL = $PLATFORM_STATUS_60SEC_CHANNEL
PLATFORM_TO_PLATFORM_CHANNEL = $PLATFORM_TO_PLATFORM_CHANNEL
C2_EVENT_CHANNEL = $C2_EVENT_CHANNEL
C2_COMMAND_FILTER_CHANNEL = $C2_COMMAND_FILTER_CHANNEL
C2_COMMAND_FILTER_FIELD = $C2_COMMAND_FILTER_FIELD
C2_COMMAND_FILTER_MATCH = $C2_COMMAND_FILTER_MATCH
-----------------------------DATA CHANNELS--------------------------------------"

################################################################################
