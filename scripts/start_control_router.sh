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
# CONTROL ROUTER LAUNCHER
################################################################################
# This script dynamically configures and launches a control routing service
# based on the provided control ID.
#
# Usage:
#   ./start_control_router.sh --id <control_id> [options]
#
# Examples:
#   ./start_control_router.sh --id 20
#   ./start_control_router.sh --id 21 --verbosity LOCAL:WARN
#   ./start_control_router.sh --id 22
#   ./start_control_router.sh --print-config --id 20
#
# Options:
#   --id <num>              Control ID (required, range: 10-29)
#   --domain <num>          Override control domain ID (default: same as control ID)
#   --router-name <name>    Override router name (default: Control_<id>)
#   --verbosity <level>     Routing service verbosity (default: ERROR:ERROR)
#                           Format: <service_level>[:<dds_level>]
#                           Levels: SILENT, ERROR, WARN, LOCAL, REMOTE
#   --print-config          Print configuration and exit
#   --help                  Show this help message
################################################################################

# Default values
CONTROL_ID=""
CONTROL_DOMAIN=""
ROUTER_NAME=""
VERBOSITY="ERROR:ERROR"
PRINT_CONFIG=false

# Parse arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        --id)
            CONTROL_ID="$2"
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
            head -n 32 "$0" | tail -n 21
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

# Compute derived values
if [[ -z "$CONTROL_DOMAIN" ]]; then
    CONTROL_DOMAIN=$CONTROL_ID
fi

if [[ -z "$ROUTER_NAME" ]]; then
    ROUTER_NAME="Control_${CONTROL_ID}"
fi

# Set fixed configuration values
TYPE="control"

# Export environment variables for routing service
export CONTROL_DOMAIN
export ROUTER_NAME
export TYPE

# Source SYSTEM parameters
source ../params/system_params.sh

# Check NDDSHOME variable
if [[ -z "${NDDSHOME}" ]]; then
    echo "Error: Must set the NDDSHOME environment variable"
    exit 1
fi

# Print configuration if requested
if [[ "$PRINT_CONFIG" == true ]]; then
    echo "
================================ CONTROL ROUTER CONFIG ================================
CONTROL_ID:       $CONTROL_ID
ROUTER_NAME:      $ROUTER_NAME (unique identifier for routing service and remote commands)
CONTROL_DOMAIN:   $CONTROL_DOMAIN
TYPE:             $TYPE
VERBOSITY:        $VERBOSITY
NDDSHOME:         $NDDSHOME
NDDS_QOS_PROFILES: $NDDS_QOS_PROFILES
================================ CONTROL ROUTER CONFIG ================================"
    exit 0
fi

# Display configuration
echo "
================================ CONTROL ROUTER CONFIG ================================
CONTROL_ID:       $CONTROL_ID
ROUTER_NAME:      $ROUTER_NAME
CONTROL_DOMAIN:   $CONTROL_DOMAIN
TYPE:             $TYPE
VERBOSITY:        $VERBOSITY
================================ CONTROL ROUTER CONFIG ================================"

# Run Routing Service
$NDDSHOME/bin/rtiroutingservice -appName $ROUTER_NAME -cfgName $TYPE -verbosity $VERBOSITY
