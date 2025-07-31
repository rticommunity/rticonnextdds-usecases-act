#!/bin/bash

# Used for Routing Service

export PLATFORM_DOMAIN=10
export TYPE="platform"
export ROUTER_NAME="USV_10"

# Used for Platform Sim
export LAN_QOS_PROFILE="LAN::default_participant_qos"
export SESSION_ID=10
export DOMAIN_ID=$PLATFORM_DOMAIN
export DESTINATION="C2_20"

echo "
-------------------------------- $ROUTER_NAME CONFIGS: -------------------------
TYPE: $TYPE
ROUTER_NAME: $ROUTER_NAME
LAN_QOS_PROFILE: $LAN_QOS_PROFILE
SESSION_ID: $SESSION_ID
DOMAIN_ID: $DOMAIN_ID
DESTINATION: $DESTINATION
-------------------------------- $ROUTER_NAME CONFIGS: -------------------------"