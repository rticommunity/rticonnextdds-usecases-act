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
# NODE ROUTER START SCRIPT TEMPLATE
################################################################################
# Instructions:
# 1. Copy this file to your deployment folder (e.g., my_deployment/nodes/<node_name>/start_router.sh)
# 2. Replace {{PARAM_FILE}} with your parameter filename (e.g., node_params.sh)
# 3. Update the paths to system_params.sh and config files based on your directory structure
# 4. Make executable: chmod +x start_router.sh
# 5. Run from the node directory: cd <node_folder> && ./start_router.sh
#
# This script starts the RTI Routing Service which handles message routing
# between LAN, WAN, and C2 domains.
#
# Example directory structure:
#   my_deployment/
#   ├── config/                     (copy from repo)
#   │   ├── qos/
#   │   └── routing/
#   ├── params/system_params.sh
#   └── nodes/platform_12/
#       ├── node_params.sh          (this is {{PARAM_FILE}})
#       └── start_router.sh         (this script)
#
# Path examples (adjust based on your structure):
#   - To system_params.sh: ../../params/system_params.sh
#   - To config files: ../../config/ (already set in system_params.sh)
################################################################################

# Source node parameters
# Replace {{PARAM_FILE}} with actual filename (e.g., node_params.sh)
source ./{{PARAM_FILE}}

# Source SYSTEM parameters
# UPDATE THIS PATH based on your deployment structure
source ../../params/system_params.sh

# Check NDDSHOME variable
if [[ -z "${NDDSHOME}" ]]; then
    echo "Must set the NDDSHOME environment variable "
    exit 1;
fi

################################################################################
#                                 VERBOSITY                                    #
################################################################################

# Controls what type of messages are logged.
# <service_level> is the verbosity level for the service logs
# <dds_level> is the verbosity level for the DDS logs. 

# Both can take any of the following values:
# | SILENT      | No messages will be logged. (lowest verbosity) |
# | ERROR       | Log only high-priority error messages. (default) |
# | WARN        | Log warning and error messages. |
# | LOCAL       | Log verbose info, warnings, and errors about local Connext objects. |
# | REMOTE      | Log verbose info, warnings, and errors about remote objects. |

# Format:  <service_level>[:<dds_level>]
# Default: ERROR:ERROR

verbosity=ERROR:ERROR


# Run Routing Service
# Uses $TYPE from node params (either "platform" or "c2")
$NDDSHOME/bin/rtiroutingservice -appName $ROUTER_NAME -cfgName $TYPE -verbosity $verbosity
