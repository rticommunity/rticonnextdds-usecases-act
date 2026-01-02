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
export ROUTER_NAME="Control_20"

# Node Router Params
export CONTROL_DOMAIN=20
export TYPE="control"

# Node Sim Params
export LAN_QOS_PROFILE="LAN::domain_participant_qos"
export SESSION_ID=20
export DOMAIN_ID=$CONTROL_DOMAIN

# XML Files for Control Nodes
XML_FILES="../config/qos/lan_qos_lib.xml;"
XML_FILES+="../node_sim/datamodel/act_types.xml"
export XML_FILES

# Matches Platform_10 ROUTER_NAME for addressing ControlCommand messages
export DESTINATION="Platform_10"

echo "
-------------------------------- $ROUTER_NAME CONFIGS: -------------------------
CONTROL_DOMAIN: $CONTROL_DOMAIN
TYPE: $TYPE
ROUTER_NAME: $ROUTER_NAME
LAN_QOS_PROFILE: $LAN_QOS_PROFILE
SESSION_ID: $SESSION_ID
DOMAIN_ID: $DOMAIN_ID
XML_FILES: $XML_FILES
DESTINATION: $DESTINATION
-------------------------------- $ROUTER_NAME CONFIGS: -------------------------"