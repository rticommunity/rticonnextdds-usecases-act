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
# NOTE: For production deployment, create your own system_params.sh based on
#       templates/params/system_params.template.sh instead of using the
#       examples/node_sim version.

# Determine script directory
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Check for system_params.sh - try examples first, then deployment location
SYSTEM_PARAMS=""

# For development/testing: Use examples params
if [ -f "../../examples/node_sim/params/system_params.sh" ]; then
    SYSTEM_PARAMS="../../examples/node_sim/params/system_params.sh"
    PARAMS_SOURCE="examples (simulation)"
# For deployment: Look for params relative to deployment structure
elif [ -f "../../params/system_params.sh" ]; then
    SYSTEM_PARAMS="../../params/system_params.sh"
    PARAMS_SOURCE="deployment"
fi

if [ -n "$SYSTEM_PARAMS" ]; then
    echo "Loading system parameters from $SYSTEM_PARAMS ($PARAMS_SOURCE)"
    source "$SYSTEM_PARAMS"
else
    echo "Warning: system_params.sh not found"
    echo "  Tried: ../../examples/node_sim/params/system_params.sh (examples)"
    echo "  Tried: ../../params/system_params.sh (deployment)"
    echo "Using default settings..."
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
echo "Params Source: $PARAMS_SOURCE"
echo "Admin Domain: $ADMIN_DOMAIN"
echo "QoS Profiles: $NDDS_QOS_PROFILES"
echo "Command: $CMD"
echo "=============================="
echo ""

# Execute the command
$CMD
