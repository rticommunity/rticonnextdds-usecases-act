#!/bin/bash

################################################################################
#            Modify below as needed                                            #
#            Run as ./start_listener <domain> [c2,platform,comms]                    #
################################################################################

if [ "$1" == "c2" ] || [ "$1" == "platform" ] || [ "$1" == "comms" ] ; then
  export TYPE=$1
else
  echo 'Pass in either "c2","platform" or "comms"'
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

# Set args per type
if [ ${TYPE} == "platform" ]; then

  DOMAIN_ID=0
  QOS_PROFILE="act_qos_lib::lan_qos"

elif [ ${TYPE} == "comms" ]; then

  DOMAIN_ID=1
  QOS_PROFILE="act_qos_lib::comms_qos"

elif [ ${TYPE} == "c2" ]; then

  DOMAIN_ID=2
  QOS_PROFILE="act_qos_lib::lan_qos"
fi


################################################################################

echo "-------------------------------- CONFIGS: --------------------------------"
echo "XML FILES: " $XML_FILES
echo "QOS_PROFILE: " $QOS_PROFILE
echo "DOMAIN_ID: " $DOMAIN_ID
echo "VERBOSITY: " $VERBOSITY
echo "TYPE: " $TYPE
echo "-------------------------------- CONFIGS: --------------------------------"


# RUN
python3 ./test/checkout.py --files ${XML_FILES} \
                        --qos_profile ${QOS_PROFILE} \
                        --domain_id ${DOMAIN_ID} \
                        --verbosity ${VERBOSITY} \
                        --type ${TYPE}





