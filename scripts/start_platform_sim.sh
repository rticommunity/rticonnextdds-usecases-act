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
# PLATFORM SIMULATOR LAUNCHER
################################################################################
# This script dynamically configures and launches a platform simulator based
# on the provided platform ID.
#
# Usage:
#   ./start_platform_sim.sh --id <platform_id> [options]
#
# Examples:
#   ./start_platform_sim.sh --id 30
#   ./start_platform_sim.sh --id 31 --destination Control_21
#   ./start_platform_sim.sh --id 32 --verbosity 3
#   ./start_platform_sim.sh --print-config --id 30
#
# Options:
#   --id <num>              Platform ID (required, range: 30-99)
#   --destination <name>    Control station destination (default: Control_20)
#   --domain <num>          Override platform domain ID (default: same as platform ID)
#   --router-name <name>    Override router name (default: Platform_<id>)
#   --verbosity <0-3>       Simulator verbosity (default: 2)
#   --print-config          Print configuration and exit
#   --help                  Show this help message
################################################################################

# Default values
PLATFORM_ID=""
DESTINATION="Control_20"
PLATFORM_DOMAIN=""
ROUTER_NAME=""
VERBOSITY=2
PRINT_CONFIG=false

# Parse arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        --id)
            PLATFORM_ID="$2"
            shift 2
            ;;
        --destination)
            DESTINATION="$2"
            shift 2
            ;;
        --domain)
            PLATFORM_DOMAIN="$2"
            shift 2
            ;;
        --router-name)
            ROUTER_NAME="$2"
            shift 2
            ;;
        --verbosity)
            VERBOSITY="$2"
            shift 2
            ;;
        --print-config)
            PRINT_CONFIG=true
            shift
            ;;
        --help)
            head -n 35 "$0" | tail -n 24
            exit 0
            ;;
        *)
            echo "Error: Unknown option '$1'"
            echo "Use --help for usage information"
            exit 1
            ;;
    esac
done

# Validate required arguments
if [[ -z "$PLATFORM_ID" ]]; then
    echo "Error: --id <platform_id> is required"
    echo "Use --help for usage information"
    exit 1
fi

# Validate platform ID range
if [[ "$PLATFORM_ID" -lt 30 ]] || [[ "$PLATFORM_ID" -gt 99 ]]; then
    echo "Error: Platform ID must be in range 30-99 (got: $PLATFORM_ID)"
    exit 1
fi

# Compute derived values (use platform ID as default)
if [[ -z "$PLATFORM_DOMAIN" ]]; then
    PLATFORM_DOMAIN=$PLATFORM_ID
fi

if [[ -z "$ROUTER_NAME" ]]; then
    ROUTER_NAME="Platform_${PLATFORM_ID}"
fi

# Check for RTI license
if [[ -z "${RTI_LICENSE_FILE}" ]] && [[ ! -f "${NDDSHOME}/rti_license.dat" ]]; then
    echo "Error: RTI license not found. Either:"
    echo "  1. Set RTI_LICENSE_FILE environment variable, or"
    echo "  2. Place rti_license.dat in \$NDDSHOME directory"
    exit 1
fi

# Source system parameters (for initial peers, etc.)
source ../params/system_params.sh

# Set fixed configuration values
TYPE="platform"
LAN_QOS_PROFILE="LAN_QOS_LIB::platform_lan_participant_qos"
DOMAIN_ID=$PLATFORM_DOMAIN

# Print configuration if requested
if [[ "$PRINT_CONFIG" == true ]]; then
    echo "
================================ PLATFORM SIM CONFIG ================================
PLATFORM_ID:      $PLATFORM_ID
ROUTER_NAME:      $ROUTER_NAME (unique identifier for routing service and remote commands)
PLATFORM_DOMAIN:  $PLATFORM_DOMAIN
TYPE:             $TYPE
DOMAIN_ID:        $DOMAIN_ID
DESTINATION:      $DESTINATION
LAN_QOS_PROFILE:  $LAN_QOS_PROFILE
NDDS_QOS_PROFILES: $NDDS_QOS_PROFILES
VERBOSITY:        $VERBOSITY
================================ PLATFORM SIM CONFIG ================================"
    exit 0
fi

# Display configuration
echo "
================================ PLATFORM SIM CONFIG ================================
PLATFORM_ID:      $PLATFORM_ID
ROUTER_NAME:      $ROUTER_NAME
DOMAIN_ID:        $DOMAIN_ID
DESTINATION:      $DESTINATION
VERBOSITY:        $VERBOSITY
================================ PLATFORM SIM CONFIG ================================"

# Run Platform Simulator
python3 ../node_sim/python/platform_sim.py --qos_profile ${LAN_QOS_PROFILE} \
                                 --domain_id ${DOMAIN_ID} \
                                 --source ${ROUTER_NAME} \
                                 --destination ${DESTINATION} \
                                 --session ${PLATFORM_ID} \
                                 --verbosity ${VERBOSITY}
