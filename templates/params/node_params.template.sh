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
# NODE PARAMETERS TEMPLATE
################################################################################
# Instructions:
# 1. Copy this file to your node folder
#    Example: cp templates/params/node_params.template.sh my_deployment/nodes/platform_12/node_params.sh
# 2. Replace all {{PLACEHOLDERS}} with actual values
# 3. Choose NODE_TYPE: "platform" or "c2"
# 4. For C2 nodes, update the XML_FILES paths
#
# Example for Platform 12:
#   {{NODE_TYPE}} → platform
#   {{DOMAIN_ID}} → 12
#   {{NODE_NAME}} → USV_12
#
# Example for C2-21:
#   {{NODE_TYPE}} → c2
#   {{DOMAIN_ID}} → 21
#   {{NODE_NAME}} → C2_21
################################################################################

# Node type: "platform" or "c2"
export TYPE="{{NODE_TYPE}}"

# Domain ID for this node (platforms: 10-19, c2: 20-29)
export DOMAIN_ID={{DOMAIN_ID}}

# Node name (e.g., "USV_10", "C2_20")
export ROUTER_NAME="{{NODE_NAME}}"

# LAN QoS Profile
export LAN_QOS_PROFILE="LAN::domain_participant_qos"

# Set domain-specific variable based on type
if [ "$TYPE" = "platform" ]; then
    export PLATFORM_DOMAIN=$DOMAIN_ID
elif [ "$TYPE" = "c2" ]; then
    export C2_DOMAIN=$DOMAIN_ID
    
    # C2 nodes need XML files for types
    # UPDATE THESE PATHS based on your deployment structure
    XML_FILES=""
    # With recommended structure: ../../config/qos/lan_qos_lib.xml
    XML_FILES+="UPDATE_PATH_TO/config/qos/lan_qos_lib.xml;"
    # Example: ./types/act_types.xml if types folder is in node directory
    # Example: ../../shared/types/act_types.xml if types are shared
    XML_FILES+="UPDATE_PATH_TO/types/act_types.xml"
    export XML_FILES
fi

echo "
-------------------------------- $ROUTER_NAME CONFIGS: -------------------------
TYPE: $TYPE
DOMAIN_ID: $DOMAIN_ID
ROUTER_NAME: $ROUTER_NAME
LAN_QOS_PROFILE: $LAN_QOS_PROFILE"

if [ "$TYPE" = "platform" ]; then
    echo "PLATFORM_DOMAIN: $PLATFORM_DOMAIN"
elif [ "$TYPE" = "c2" ]; then
    echo "C2_DOMAIN: $C2_DOMAIN
XML_FILES: $XML_FILES"
fi

echo "-------------------------------- $ROUTER_NAME CONFIGS: -------------------------"
