#!/bin/bash


# NOTE: Source a platform/c2 ENV script before running



# Logging Verbosity
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

verbosity=WARN:WARN



# Check NDDSHOME variable
if [[ -z "${NDDSHOME}" ]]; then
    echo "Must set the NDDSHOME environment variable "
    exit 1;
fi

# XML Files
export NDDS_QOS_PROFILES=""

# QOS File
NDDS_QOS_PROFILES+="./qos/act_qos_lib.xml;"

# Routing Service file
NDDS_QOS_PROFILES+="./router_config/routing_service_config.xml"


############################## DATA LANES ######################################
# 
# Add Topics to each "Lane" with REGEX match to move data between Platform and C2
# QoS will be applied as appropriate per Data Pattern of Status/Event/etc.
# Comma separated, no spaces, NULL if empty 
# Can use wildcards such as *Status
################################################################################
export PLATFORM_EVENT=PlatformCommandAck,ContactReport #PLATFORM -> C2 (Aperiodic- Ensured Delivery CommandAck etc.)

export PLATFORM_STATUS_FULL=NULL #PLATFORM -> C2 (Periodic- Full Rate)
export PLATFORM_STATUS_1SEC=NULL #PLATFORM -> C2 (Periodic- Downsampled to every 1 Sec)
export PLATFORM_STATUS_10SEC=PlatformStatus #PLATFORM -> C2 (Periodic- Downsampled to every 10 Secs)
export PLATFORM_STATUS_30SEC=NULL #PLATFORM -> C2 (Periodic- Downsampled to every 30 Secs)
export PLATFORM_STATUS_60SEC=NULL #PLATFORM -> C2 (Periodic- Downsampled to every 60 Secs)

export PLATFORM_TO_PLATFORM=PlatformData #Platform -> Platform (Periodic- Full Rate)

export C2_COMMAND_GUID_FILTER=C2Command #C2 -> Platform Aperiodic- (Targeted delivery by GUID address)
export C2_EVENT=ContactReport


echo "
-------------------------------- ROUTER CONFIGS: --------------------------------
XML FILES used:  $NDDS_QOS_PROFILES
PLATFORM_EVENT:  $PLATFORM_EVENT
PLATFORM_STATUS_FULL: $PLATFORM_STATUS_FULL
PLATFORM_STATUS_1SEC:  $PLATFORM_STATUS_1SEC
PLATFORM_STATUS_10SEC:  $PLATFORM_STATUS_10SEC
PLATFORM_STATUS_30SEC:  $PLATFORM_STATUS_30SEC
PLATFORM_STATUS_60SEC:  $PLATFORM_STATUS_60SEC
C2_COMMAND_GUID_FILTER:  $C2_COMMAND_GUID_FILTER
C2_EVENT:  $C2_EVENT
PLATFORM_TO_PLATFORM:  $PLATFORM_TO_PLATFORM

ROUTER_NAME = $ROUTER_NAME
-------------------------------- ROUTER CONFIGS: --------------------------------"


# Run Routing Service
$NDDSHOME/bin/rtiroutingservice -appName $ROUTER_NAME -cfgName $TYPE -verbosity $verbosity