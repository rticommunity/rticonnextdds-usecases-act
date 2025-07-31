#!/bin/bash

# Used for Routing Service
export C2_DOMAIN=20
export TYPE="c2"
export ROUTER_NAME="C2_20"

# Used for Platform Sim
export LAN_QOS_PROFILE="LAN::default_participant_qos"
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