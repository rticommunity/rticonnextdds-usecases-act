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

# Generic node simulator start script
# source ./params/<node>_params.sh

# Set verbosity
# 0: dds.Verbosity.SILENT
# 1: dds.Verbosity.EXCEPTION
# 2: dds.Verbosity.WARNING
# 3: dds.Verbosity.STATUS_ALL
VERBOSITY=2


################################################################################

# RUN - TYPE should be set to "platform" or "c2" in the sourced params file
python3 ./python_node/${TYPE}_sim.py --files ${XML_FILES} \
                                --qos_profile ${LAN_QOS_PROFILE} \
                                --domain_id ${DOMAIN_ID} \
                                --source ${ROUTER_NAME} \
                                --destination ${DESTINATION} \
                                --session ${SESSION_ID} \
                                --verbosity ${VERBOSITY}




