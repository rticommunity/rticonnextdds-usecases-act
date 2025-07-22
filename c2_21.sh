#!/bin/bash

# Used for Routing Service
export GUID="21192b12469b48d0b8bcdbde51c3ab81"
export C2_DOMAIN=21
export TYPE="c2"
export ROUTER_NAME="C2-21"

# Used for Platform Sim
export LAN_QOS_PROFILE="LAN::default_participant_qos"
export SESSION_ID=21
export DOMAIN_ID=$C2_DOMAIN

# Matches Platform10
export DEST_GUID="ef32b88e6e0c49e99886ae20c28d7f3c"

echo "
-------------------------------- $ROUTER_NAME CONFIGS: -------------------------
GUID: $GUID
C2_DOMAIN: $C2_DOMAIN
TYPE: $TYPE
ROUTER_NAME: $ROUTER_NAME
LAN_QOS_PROFILE: $LAN_QOS_PROFILE
SESSION: $SESSION
DOMAIN_ID: $DOMAIN_ID
DEST_GUID: $DEST_GUID
-------------------------------- $ROUTER_NAME CONFIGS: -------------------------"