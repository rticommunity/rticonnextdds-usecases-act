#!/bin/bash

# Used for Routing Service
export GUID="a4ae2f7ecb374a2a893407340d78f5c1"
export PLATFORM_DOMAIN=11
export TYPE="platform"
export ROUTER_NAME="USV-11"

# Used for Platform Sim
export LAN_QOS_PROFILE="LAN::default_participant_qos"
export SESSION_ID=11
export DOMAIN_ID=$PLATFORM_DOMAIN
export DEST_GUID="cb8e8858c8c2277f94b632287bed9d05"

echo "
-------------------------------- $ROUTER_NAME CONFIGS: -------------------------
GUID: $GUID
PLATFORM_DOMAIN: $PLATFORM_DOMAIN
TYPE: $TYPE
ROUTER_NAME: $ROUTER_NAME
LAN_QOS_PROFILE: $LAN_QOS_PROFILE
SESSION: $SESSION
DOMAIN_ID: $DOMAIN_ID
DEST_GUID: $DEST_GUID
-------------------------------- $ROUTER_NAME CONFIGS: -------------------------"