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
# NODE START SCRIPT TEMPLATE
################################################################################
# Instructions:
# 1. Copy this file to your deployment folder (e.g., my_deployment/nodes/<node_name>/start_app.sh)
# 2. Replace {{PARAM_FILE}} with your parameter filename (e.g., node_params.sh)
# 3. Update paths to config files based on your directory structure
# 4. Customize the "SYSTEM-SPECIFIC PROCESSES" section for your use case
# 5. Make executable: chmod +x start_app.sh
# 6. Run from the node directory: cd <node_folder> && ./start_app.sh
#
# This template provides a starting point for running your custom application.
# Replace the example section with your actual application/processes.
#
# Example directory structure:
#   my_deployment/
#   ├── config/                     (copy from repo)
#   │   ├── qos/
#   │   └── routing/
#   ├── params/system_params.sh
#   └── nodes/platform_12/
#       ├── node_params.sh          (this is {{PARAM_FILE}})
#       ├── start_router.sh
#       └── start_app.sh            (this script)
#
# Path examples (adjust based on your structure):
#   - To config files: ../../config/qos/
#   - To your types: ./types/ or ../../shared/types/
################################################################################

# Source node parameters
# Replace {{PARAM_FILE}} with actual filename (e.g., node_params.sh)
source ./{{PARAM_FILE}}

# Set verbosity
# 0: dds.Verbosity.SILENT
# 1: dds.Verbosity.EXCEPTION
# 2: dds.Verbosity.WARNING
# 3: dds.Verbosity.STATUS_ALL
VERBOSITY=2

# Platform nodes need to set XML_FILES (C2 params already define it)
if [ "$TYPE" = "platform" ]; then
    # LAN QOS file - UPDATE THIS PATH based on your deployment structure
    # Example with recommended structure: ../../config/qos/lan_qos_lib.xml
    XML_FILES="UPDATE_PATH_TO/config/qos/lan_qos_lib.xml;"
    
    # Add Types file - UPDATE THIS PATH based on where your types are stored
    # Example: ./types/act_types.xml if types folder is in node directory
    # Example: ../../shared/types/act_types.xml if types are shared
    XML_FILES+="UPDATE_PATH_TO/types/act_types.xml"
fi

################################################################################

echo "
-------------------------------- NODE CONFIGS: --------------------------------
XML FILES:  $XML_FILES
QOS_PROFILE:  $LAN_QOS_PROFILE
DOMAIN_ID:  $DOMAIN_ID
SOURCE:  $ROUTER_NAME
TYPE:  $TYPE
VERBOSITY:  $VERBOSITY
-------------------------------- NODE CONFIGS: --------------------------------"

################################################################################
# INSERT YOUR SYSTEM-SPECIFIC PROCESSES HERE
################################################################################
# Replace the example below with your actual application/processes for your use case.
# 
# Examples of what you might run:
#   - Your custom C++/Java/Python application
#   - Hardware interface initialization
#   - Data acquisition processes
#   - Monitoring and logging tools
#   - System health checks
#   - Third-party software integration
#
# Example (Python simulator - replace with your application):
#   python3 ./python_node/${TYPE}_sim.py --files ${XML_FILES} \
#                                        --qos_profile ${LAN_QOS_PROFILE} \
#                                        --domain_id ${DOMAIN_ID} \
#                                        --source ${ROUTER_NAME} \
#                                        --destination ${DESTINATION} \
#                                        --session ${SESSION_ID} \
#                                        --verbosity ${VERBOSITY}
#
# Example (Custom C++ application):
#   ./bin/my_app --domain ${DOMAIN_ID} --name ${ROUTER_NAME}
#
# Example (Multiple processes):
#   ./bin/sensor_reader --domain ${DOMAIN_ID} &
#   ./bin/data_processor --domain ${DOMAIN_ID} &
#   ./bin/controller --domain ${DOMAIN_ID}
################################################################################



################################################################################
