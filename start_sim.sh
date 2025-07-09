#!/bin/bash




################################################################################
#            Modify below as needed or override with ENV vars                  #
#            Run as ./start_sim <type> [c2,platform]                           #
################################################################################

if [ "$1" == "c2" ] || [ "$1" == "platform" ] ; then
  export TYPE=$1
else
  echo 'Pass in either "c2" or "platform"'
  exit
fi

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

PLATFORM_GUID="ef32b88e6e0c49e99886ae20c28d7f3c"
C2_GUID="cb8e8858c8c2277f94b632287bed9d05"


# Set args per type
if [ ${TYPE} == "platform" ]; then

  DOMAIN_ID=0
  QOS_PROFILE="act_qos_lib::lan_qos"
  SRC_GUID=${PLATFORM_GUID}
  DEST_GUID=${C2_GUID}
  SESSION_ID=5

elif [ ${TYPE} == "c2" ]; then

  DOMAIN_ID=2
  QOS_PROFILE="act_qos_lib::lan_qos"
  SRC_GUID=${C2_GUID}
  DEST_GUID=${PLATFORM_GUID}
  SESSION_ID=6
fi

################################################################################

echo "-------------------------------- CONFIGS: --------------------------------"
echo "XML FILES: " $XML_FILES
echo "QOS_PROFILE: " $QOS_PROFILE
echo "DOMAIN_ID: " $DOMAIN_ID
echo "SRC_GUID: " $SRC_GUID
echo "DEST_GUID: " $DEST_GUID
echo "SESSION_ID: " $SESSION_ID
echo "VERBOSITY: " $VERBOSITY
echo "-------------------------------- CONFIGS: --------------------------------"


# RUN
python3 ./sim/${TYPE}_sim.py --files ${XML_FILES} \
                             --qos_profile ${QOS_PROFILE} \
                             --domain_id ${DOMAIN_ID} \
                             --src_guid ${SRC_GUID} \
                             --dest_guid ${DEST_GUID} \
                             --session_id ${SESSION_ID} \
                             --verbosity ${VERBOSITY}





