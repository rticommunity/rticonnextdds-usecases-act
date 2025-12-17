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


# Unique identifier for this node
# - Must be unique across all nodes in the system
# - Used as the routing service -appName (identifies this routing service instance)
# - Used as the -n parameter in send_remote_cmd.sh to address this node for remote admin
# - Used in C2Command messages to address this platform from C2 stations
export ROUTER_NAME="Platform_10"

# Used for Routing Service
export PLATFORM_DOMAIN=10
export TYPE="platform"

# Used for Platform Sim
export LAN_QOS_PROFILE="LAN::domain_participant_qos"
export SESSION_ID=10
export DOMAIN_ID=$PLATFORM_DOMAIN
export DESTINATION="C2_20"

# XML Files for Platform applications
XML_FILES="../config/qos/lan_qos_lib.xml;"
XML_FILES+="../node_sim/datamodel/act_types.xml"
export XML_FILES

echo "
-------------------------------- $ROUTER_NAME CONFIGS: -------------------------
PLATFORM_DOMAIN: $PLATFORM_DOMAIN
TYPE: $TYPE
ROUTER_NAME: $ROUTER_NAME
LAN_QOS_PROFILE: $LAN_QOS_PROFILE
SESSION_ID: $SESSION_ID
DOMAIN_ID: $DOMAIN_ID
XML_FILES: $XML_FILES
DESTINATION: $DESTINATION
-------------------------------- $ROUTER_NAME CONFIGS: -------------------------"