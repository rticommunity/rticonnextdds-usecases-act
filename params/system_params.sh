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
NDDS_QOS_PROFILES+="../config/routing/routing_service_config.xml;"

# Data Types for ACT applications
NDDS_QOS_PROFILES+="../node_sim/datamodel/act_types.xml"

################################################################################
#                            DOMAIN ARCHITECTURE                               #
################################################################################
# Domain IDs for VLAN simulation (normally there would be physical separation):
#   - CONTROL_DOMAIN range: 10-30 (Control station local LANs)
#   - PLATFORM_DOMAIN range: 30-100 (Platform node local LANs)
#   - ADMIN_DOMAIN: 100 (Remote administration and monitoring)
#   - WAN_DOMAIN: 200 (Wide-area network between all nodes)
################################################################################

export ADMIN_DOMAIN=100
export WAN_DOMAIN=200

echo "
-----------------------------XML PROFILES---------------------------------------
NDDS_QOS_PROFILES = $NDDS_QOS_PROFILES
-----------------------------XML PROFILES---------------------------------------

-----------------------------DOMAIN IDS-----------------------------------------
ADMIN_DOMAIN:  $ADMIN_DOMAIN  (Remote administration and monitoring)
WAN_DOMAIN:    $WAN_DOMAIN  (Wide-area network between all nodes)
-----------------------------DOMAIN IDS-----------------------------------------"


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

################################################################################
#                           DISCOVERY INITIAL PEERS                            #
################################################################################
# These settings define initial peers for participant discovery.
# Format: builtin.<transport>://<address> (e.g., builtin.udpv4://239.255.0.1)
# Transports: udpv4, udpv6, shmem
#
# Reference: https://community.rti.com/static/documentation/connext-dds/current/doc/api/connext_dds/api_c/group__NDDS__DISCOVERY__PEERS.html

# Base multicast addresses for discovery
export LAN_MULTICAST_ADDRESS="builtin.udpv4://239.255.0.1"
export WAN_MULTICAST_ADDRESS="builtin.udpv4://239.255.0.2"

# Multicast receive addresses (derived from base addresses for QoS XML)
export LAN_RECEIVE_MULTICAST="${LAN_MULTICAST_ADDRESS}"
export WAN_RECEIVE_MULTICAST="${WAN_MULTICAST_ADDRESS}"

# Platform LAN initial peers (multicast, loopback, and shmem)
export PLATFORM_LAN_PEER1="${LAN_MULTICAST_ADDRESS}"
export PLATFORM_LAN_PEER2="builtin.udpv4://127.0.0.1"
export PLATFORM_LAN_PEER3="builtin.shmem://"

# Platform WAN initial peers (multicast)
# NOTE: For improved scalability or production, set to unicast IP addresses or
# DNS names of Control stations (e.g., "builtin.udpv4://control1.example.com").
export PLATFORM_WAN_PEER1="${WAN_MULTICAST_ADDRESS}"

# Control LAN initial peers (multicast, loopback, and shmem)
export CONTROL_LAN_PEER1="${LAN_MULTICAST_ADDRESS}"
export CONTROL_LAN_PEER2="builtin.udpv4://127.0.0.1"
export CONTROL_LAN_PEER3="builtin.shmem://"

# Control WAN initial peers (multicast)
export CONTROL_WAN_PEER1="${WAN_MULTICAST_ADDRESS}"


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
export PLATFORM_PRIMARY_STATUS_1HZ_CHANNEL=PlatformPrimaryStatus

# Platform Status Topics to be enabled dynamically, FULL rate
export PLATFORM_DETAIL_STATUS_CHANNEL=PlatformDetailStatus

# Platform topics to be shared within the Team
export PLATFORM_TEAM_CHANNEL=PlatformData

# Controller Topics such as ContactReports etc. resent if dropped
export CONTROL_EVENTS_CHANNEL=NULL

# Controller Commands filtered by destination
export CONTROLLER_COMMANDS_CHANNEL=ControlCommand

# Message field to filter on for Commands Destination
export CONTROL_COMMAND_FILTER_FIELD=msg.destination

# Value to use as Filter- In this case unique identifier of Router Name
export CONTROL_COMMAND_FILTER_MATCH=$ROUTER_NAME

echo "
-----------------------------DATA CHANNELS--------------------------------------
PLATFORM_EVENTS_CHANNEL = $PLATFORM_EVENTS_CHANNEL
PLATFORM_DETAIL_STATUS_CHANNEL = $PLATFORM_DETAIL_STATUS_CHANNEL
PLATFORM_PRIMARY_STATUS_1HZ_CHANNEL = $PLATFORM_PRIMARY_STATUS_1HZ_CHANNEL
PLATFORM_TEAM_CHANNEL = $PLATFORM_TEAM_CHANNEL
CONTROL_EVENTS_CHANNEL = $CONTROL_EVENTS_CHANNEL
CONTROL_COMMANDS_CHANNEL = $CONTROL_COMMANDS_CHANNEL
CONTROL_COMMAND_FILTER_FIELD = $CONTROL_COMMAND_FILTER_FIELD
CONTROL_COMMAND_FILTER_MATCH = $CONTROL_COMMAND_FILTER_MATCH
-----------------------------DATA CHANNELS--------------------------------------"

################################################################################
#                             QOS PROFILE NAMES                                #
################################################################################
# These specify which QoS profiles from the XML files to use for each 
# participant and endpoint type

# Domain Participant QoS Profiles
export PLATFORM_PARTICIPANT_QOS=LAN_QOS_LIB::platform_lan_participant_qos      # Platform local LAN
export CONTROL_PARTICIPANT_QOS=LAN_QOS_LIB::control_lan_participant_qos        # Control local LAN

# WAN Platform Participant QoS - Choose IPv4 or IPv6 transport
export WAN_PLATFORM_PARTICIPANT_QOS=WAN_QOS_LIB::platform_participant_udpv4_qos    # Platform WAN side (IPv4)
# export WAN_PLATFORM_PARTICIPANT_QOS=WAN_QOS_LIB::platform_participant_udpv6_qos  # Platform WAN side (IPv6) - uncomment to use

# WAN Control Participant QoS - Choose IPv4 or IPv6 transport
export WAN_CONTROL_PARTICIPANT_QOS=WAN_QOS_LIB::control_participant_udpv4_qos      # Control WAN side (IPv4)
# export WAN_CONTROL_PARTICIPANT_QOS=WAN_QOS_LIB::control_participant_udpv6_qos    # Control WAN side (IPv6) - uncomment to use

# DataReader/DataWriter QoS Profiles for Events (reliable, persistent)
export PLATFORM_EVENT_QOS=LAN_QOS_LIB::platform_event_qos    # Platform side events
export CONTROL_EVENT_QOS=LAN_QOS_LIB::control_event_qos      # Control side events  
export WAN_EVENT_QOS=WAN_QOS_LIB::event_qos                  # WAN side events

# DataReader/DataWriter QoS Profiles for Status (best-effort, periodic)
export PLATFORM_STATUS_QOS=LAN_QOS_LIB::platform_status_qos  # Platform side status
export CONTROL_STATUS_QOS=LAN_QOS_LIB::control_status_qos    # Control side status
export WAN_STATUS_QOS=WAN_QOS_LIB::status_qos                # WAN side status

# DataReader/DataWriter QoS Profiles for Team communication (partition-based)
export WAN_TEAM_QOS=WAN_QOS_LIB::status_qos                  # WAN side team coordination

################################################################################
#                           SESSION ENABLE FLAGS                               #
################################################################################
# Control which routing sessions are enabled by default (true/false)

# Enable remote administration interface on ADMIN_DOMAIN (default: true)
export REMOTE_ADMIN_MODE=true

# Enable detailed debug logging (default: false)
export DEBUG_MODE=false

# Enable platform detailed status transmission (disabled by default to save bandwidth)
# Can be dynamically enabled via RemoteAdmin --detail command
export DETAIL_STATUS_ENABLE=false

# Enable platform-to-platform team communication (disabled by default)
# Platforms must be assigned to teams via RemoteAdmin -t command
export TEAM_ENABLE=false

echo "
-----------------------------QOS PROFILES---------------------------------------
PLATFORM_PARTICIPANT_QOS = $PLATFORM_PARTICIPANT_QOS
CONTROL_PARTICIPANT_QOS = $CONTROL_PARTICIPANT_QOS
WAN_PLATFORM_PARTICIPANT_QOS = $WAN_PLATFORM_PARTICIPANT_QOS
WAN_CONTROL_PARTICIPANT_QOS = $WAN_CONTROL_PARTICIPANT_QOS
PLATFORM_EVENT_QOS = $PLATFORM_EVENT_QOS
CONTROL_EVENT_QOS = $CONTROL_EVENT_QOS
WAN_EVENT_QOS = $WAN_EVENT_QOS
PLATFORM_STATUS_QOS = $PLATFORM_STATUS_QOS
CONTROL_STATUS_QOS = $CONTROL_STATUS_QOS
WAN_STATUS_QOS = $WAN_STATUS_QOS
WAN_TEAM_QOS = $WAN_TEAM_QOS
-----------------------------QOS PROFILES---------------------------------------

-----------------------------SESSION FLAGS--------------------------------------
REMOTE_ADMIN_MODE = $REMOTE_ADMIN_MODE
DEBUG_MODE = $DEBUG_MODE
DETAIL_STATUS_ENABLE = $DETAIL_STATUS_ENABLE
TEAM_ENABLE = $TEAM_ENABLE
-----------------------------SESSION FLAGS--------------------------------------"

################################################################################