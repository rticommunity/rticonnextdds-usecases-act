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


# Used for Routing Service
export C2_DOMAIN=20
export TYPE="c2"
export ROUTER_NAME="C2_20"

# Used for Platform Sim
export LAN_QOS_PROFILE="LAN::domain_participant_qos"
export SESSION_ID=20
export DOMAIN_ID=$C2_DOMAIN

# Matches Platform10
export DESTINATION="USV_10"

echo "
-------------------------------- $ROUTER_NAME CONFIGS: -------------------------
TYPE: $TYPE
ROUTER_NAME: $ROUTER_NAME
LAN_QOS_PROFILE: $LAN_QOS_PROFILE
SESSION_ID: $SESSION_ID
DOMAIN_ID: $DOMAIN_ID
DESTINATION: $DESTINATION
-------------------------------- $ROUTER_NAME CONFIGS: -------------------------"