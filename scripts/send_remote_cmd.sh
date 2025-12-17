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
# It also automatically builds RemoteAdmin if it's not found.
#
# Remote Admin uses WAN latency settings from system_params.sh for proper
# operation with the routing service.

# Determine script directory
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Path to RemoteAdmin executable
REMOTE_ADMIN_BINARY="../tools/remote_admin/build/RemoteAdmin"

# Check if RemoteAdmin binary exists, build if not
if [ ! -f "$REMOTE_ADMIN_BINARY" ]; then
    echo "RemoteAdmin binary not found. Building..."
    echo ""
    
    # Navigate to remote_admin directory
    cd ../tools/remote_admin || exit 1
    
    # Create build directory if it doesn't exist
    mkdir -p build
    cd build || exit 1
    
    # Run cmake and make
    echo "Running cmake..."
    cmake .. || { echo "ERROR: cmake failed"; exit 1; }
    
    echo "Running make..."
    make || { echo "ERROR: make failed"; exit 1; }
    
    echo ""
    echo "Build complete!"
    echo ""
    
    # Return to scripts directory
    cd "$SCRIPT_DIR" || exit 1
fi

# Load system parameters
SYSTEM_PARAMS="../params/system_params.sh"

if [ -f "$SYSTEM_PARAMS" ]; then
    source "$SYSTEM_PARAMS"
else
    echo "ERROR: system_params.sh not found at $SYSTEM_PARAMS"
    echo ""
    echo "System parameters are required for RemoteAdmin to function properly."
    exit 1
fi

# Use NDDS_QOS_PROFILES environment variable for XML files
# Remote Admin will use this to load all necessary QoS profiles
export NDDS_QOS_PROFILES

# Build the command with parameters from environment
CMD="$REMOTE_ADMIN_BINARY"

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
