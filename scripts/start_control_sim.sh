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
# CONTROL SIMULATOR LAUNCHER
################################################################################
# This script dynamically configures and launches a control simulator based
# on the provided control ID.
#
# Usage:
#   ./start_control_sim.sh --id <control_id> [options]
#
# Examples:
#   ./start_control_sim.sh --id 20
#   ./start_control_sim.sh --id 21 --destination Platform_32
#   ./start_control_sim.sh --id 22 --verbosity 3
#   ./start_control_sim.sh --print-config --id 20
#
# Options:
#   --id <num>              Control ID (required, range: 10-29)
#   --destination <name>    Platform destination (default: Platform_30)
#   --domain <num>          Override control domain ID (default: same as control ID)
#   --router-name <name>    Override router name (default: Control_<id>)
#   --verbosity <0-3>       Simulator verbosity (default: 2)
#   --print-config          Print configuration and exit
#   --help                  Show this help message
################################################################################

# Default values
CONTROL_ID=""
DESTINATION="Platform_30"
CONTROL_DOMAIN=""
ROUTER_NAME=""
VERBOSITY=2
PRINT_CONFIG=false

# Parse arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        --id)
            CONTROL_ID="$2"
            shift 2
            ;;
        --destination)
            DESTINATION="$2"
            shift 2
            ;;
        --domain)
            CONTROL_DOMAIN="$2"
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
if [[ -z "$CONTROL_ID" ]]; then
    echo "Error: --id <control_id> is required"
    echo "Use --help for usage information"
    exit 1
fi

# Validate control ID range
if [[ "$CONTROL_ID" -lt 10 ]] || [[ "$CONTROL_ID" -gt 29 ]]; then
    echo "Error: Control ID must be in range 10-29 (got: $CONTROL_ID)"
    exit 1
fi

# Compute derived values (use control ID as default)
if [[ -z "$CONTROL_DOMAIN" ]]; then
    CONTROL_DOMAIN=$CONTROL_ID
fi

if [[ -z "$ROUTER_NAME" ]]; then
    ROUTER_NAME="Control_${CONTROL_ID}"
fi

# Check for RTI license
if [[ -z "${RTI_LICENSE_FILE}" ]] && [[ ! -f "${NDDSHOME}/rti_license.dat" ]]; then
    echo "Error: RTI license not found. Either:"
    echo "  1. Set RTI_LICENSE_FILE environment variable, or"
    echo "  2. Place rti_license.dat in \$NDDSHOME directory"
    exit 1
fi

# Set fixed configuration values
TYPE="control"
LAN_QOS_PROFILE="LAN_QOS_LIB::domain_participant_qos"
DOMAIN_ID=$CONTROL_DOMAIN

# XML Files for Control applications
XML_FILES="../config/qos/lan_qos_lib.xml;"
XML_FILES+="../node_sim/datamodel/act_types.xml"

# Print configuration if requested
if [[ "$PRINT_CONFIG" == true ]]; then
    echo "
================================ CONTROL SIM CONFIG ================================
CONTROL_ID:       $CONTROL_ID
ROUTER_NAME:      $ROUTER_NAME (unique identifier for routing service and remote commands)
CONTROL_DOMAIN:   $CONTROL_DOMAIN
TYPE:             $TYPE
DOMAIN_ID:        $DOMAIN_ID
DESTINATION:      $DESTINATION
LAN_QOS_PROFILE:  $LAN_QOS_PROFILE
XML_FILES:        $XML_FILES
VERBOSITY:        $VERBOSITY
================================ CONTROL SIM CONFIG ================================"
    exit 0
fi

# Display configuration
echo "
================================ CONTROL SIM CONFIG ================================
CONTROL_ID:       $CONTROL_ID
ROUTER_NAME:      $ROUTER_NAME
DOMAIN_ID:        $DOMAIN_ID
DESTINATION:      $DESTINATION
VERBOSITY:        $VERBOSITY
================================ CONTROL SIM CONFIG ================================"

# Run Control Simulator
python3 ../node_sim/python/control_sim.py --files ${XML_FILES} \
                                --qos_profile ${LAN_QOS_PROFILE} \
                                --domain_id ${DOMAIN_ID} \
                                --source ${ROUTER_NAME} \
                                --destination ${DESTINATION} \
                                --session ${CONTROL_ID} \
                                --verbosity ${VERBOSITY}
