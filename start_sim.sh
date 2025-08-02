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



# NOTE: Source a platform/c2 ENV script before running

# LAN QOS file
XML_FILES+="./qos/lan_qos_lib.xml;"

# Add Types file
XML_FILES+="./types/act_types.xml"

# Set verbosity
# 0: dds.Verbosity.SILENT
# 1: dds.Verbosity.EXCEPTION
# 2: dds.Verbosity.WARNING
# 3: dds.Verbosity.STATUS_ALL
VERBOSITY=2


################################################################################

echo "
-------------------------------- SIM CONFIGS: --------------------------------
XML FILES:  $XML_FILES
QOS_PROFILE:  $LAN_QOS_PROFILE
DOMAIN_ID:  $DOMAIN_ID
SOURCE:  $ROUTER_NAME
DESTINATION:  $DESTINATION
SESSION:  $SESSION
VERBOSITY:  $VERBOSITY
-------------------------------- SIM CONFIGS: --------------------------------"


# RUN
python3 ./sim/${TYPE}_sim.py --files ${XML_FILES} \
                             --qos_profile ${LAN_QOS_PROFILE} \
                             --domain_id ${DOMAIN_ID} \
                             --source ${ROUTER_NAME} \
                             --destination ${DESTINATION} \
                             --session ${SESSION_ID} \
                             --verbosity ${VERBOSITY}





