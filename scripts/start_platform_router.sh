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
# PLATFORM ROUTER LAUNCHER
################################################################################
# This script dynamically configures and launches a platform routing service
# based on the provided platform ID.
#
# Usage:
#   ./start_platform_router.sh --id <platform_id> [options]
#
# Examples:
#   ./start_platform_router.sh --id 30
#   ./start_platform_router.sh --id 31 --verbosity LOCAL:WARN
#   ./start_platform_router.sh --id 32
#   ./start_platform_router.sh --print-config --id 30
#
# Options:
#   --id <num>              Platform ID (required, range: 30-99)
#   --domain <num>          Override platform domain ID (default: same as platform ID)
#   --router-name <name>    Override router name (default: Platform_<id>)
#   --verbosity <level>     Routing service verbosity (default: ERROR:ERROR)
#                           Format: <service_level>[:<dds_level>]
#                           Levels: SILENT, ERROR, WARN, LOCAL, REMOTE
#   --print-config          Print configuration and exit
#   --help                  Show this help message
################################################################################

# Default values
PLATFORM_ID=""
PLATFORM_DOMAIN=""
ROUTER_NAME=""
VERBOSITY="ERROR:ERROR"
PRINT_CONFIG=false

# Parse arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        --id)
            PLATFORM_ID="$2"
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

# Compute derived values
if [[ -z "$PLATFORM_DOMAIN" ]]; then
    PLATFORM_DOMAIN=$PLATFORM_ID
fi

if [[ -z "$ROUTER_NAME" ]]; then
    ROUTER_NAME="Platform_${PLATFORM_ID}"
fi

# Set fixed configuration values
TYPE="platform"

# Export environment variables for routing service
export PLATFORM_DOMAIN
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
================================ PLATFORM ROUTER CONFIG ================================
PLATFORM_ID:      $PLATFORM_ID
ROUTER_NAME:      $ROUTER_NAME (unique identifier for routing service and remote commands)
PLATFORM_DOMAIN:  $PLATFORM_DOMAIN
TYPE:             $TYPE
VERBOSITY:        $VERBOSITY
NDDSHOME:         $NDDSHOME
NDDS_QOS_PROFILES: $NDDS_QOS_PROFILES
================================ PLATFORM ROUTER CONFIG ================================"
    exit 0
fi

# Display configuration
echo "
================================ PLATFORM ROUTER CONFIG ================================
PLATFORM_ID:      $PLATFORM_ID
ROUTER_NAME:      $ROUTER_NAME
PLATFORM_DOMAIN:  $PLATFORM_DOMAIN
TYPE:             $TYPE
VERBOSITY:        $VERBOSITY
================================ PLATFORM ROUTER CONFIG ================================"

# Run Routing Service
$NDDSHOME/bin/rtiroutingservice -appName $ROUTER_NAME -cfgName $TYPE -verbosity $VERBOSITY
