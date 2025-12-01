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

# Remote Admin Wrapper Script
# 
# This script sources system parameters before invoking the RemoteAdmin tool.
# Remote Admin uses WAN latency settings from system_params.sh for proper
# operation with the routing service.
#
# NOTE: System parameters are located in config/params/system_params.sh
#       For production deployment, create your own system_params.sh based on
#       templates/params/system_params.template.sh

# Determine script directory
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Load system parameters from config/params/system_params.sh
SYSTEM_PARAMS="../../config/params/system_params.sh"

if [ -f "$SYSTEM_PARAMS" ]; then
    echo "Loading system parameters from $SYSTEM_PARAMS"
    source "$SYSTEM_PARAMS"
else
    echo "ERROR: system_params.sh not found at $SYSTEM_PARAMS"
    echo ""
    echo "System parameters are required for RemoteAdmin to function properly."
    echo "The system_params.sh file should be located at: config/params/system_params.sh"
    echo ""
    echo "For deployment, you can customize system parameters:"
    echo "  cp templates/params/system_params.template.sh config/params/system_params.sh"
    echo "  # Then edit config/params/system_params.sh for your deployment"
    exit 1
fi

# Build the command with parameters from environment
CMD="$SCRIPT_DIR/build/RemoteAdmin"

# Use NDDS_QOS_PROFILES environment variable for XML files
# Remote Admin will use this to load all necessary QoS profiles
export NDDS_QOS_PROFILES

# Pass through all command-line arguments
CMD="$CMD $@"

echo ""
echo "=============================="
echo "Remote Admin Configuration"
echo "=============================="
echo "Admin Domain: $ADMIN_DOMAIN"
echo "QoS Profiles: $NDDS_QOS_PROFILES"
echo "Command: $CMD"
echo "=============================="
echo ""

# Execute the command
$CMD
