#!/bin/bash



# NOTE: Source a platform/c2 ENV script before running

# Add QOS file
XML_FILES+="./qos/act_qos_lib.xml;"
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
SRC_GUID:  $GUID
DEST_GUID:  $DEST_GUID
SESSION_ID:  $SESSION_ID
VERBOSITY:  $VERBOSITY
-------------------------------- SIM CONFIGS: --------------------------------"


# RUN
python3 ./sim/${TYPE}_sim.py --files ${XML_FILES} \
                             --qos_profile ${LAN_QOS_PROFILE} \
                             --domain_id ${DOMAIN_ID} \
                             --src_guid ${GUID} \
                             --dest_guid ${DEST_GUID} \
                             --session_id ${SESSION_ID} \
                             --verbosity ${VERBOSITY}





