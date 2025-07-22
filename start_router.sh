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


# Topics (Data "Lanes")
# Comma separated, no spaces, NULL if empty i.e. PlatformStatus1,PlatformStatus2
export PLATFORM_EVENT_TOPICS=PlatformCommandAck,ContactReport #PLATFORM -> C2 (Aperiodic- Ensured Delivery CommandAck etc.)

export PLATFORM_STATUS_FULL_TOPICS=NULL #PLATFORM -> C2 (Periodic- Full Rate)
export PLATFORM_STATUS_1SEC_TOPICS=NULL #PLATFORM -> C2 (Periodic- Downsampled to every 1 Sec)
export PLATFORM_STATUS_10SEC_TOPICS=PlatformStatus #PLATFORM -> C2 (Periodic- Downsampled to every 10 Secs)
export PLATFORM_STATUS_30SEC_TOPICS=NULL #PLATFORM -> C2 (Periodic- Downsampled to every 30 Secs)
export PLATFORM_STATUS_60SEC_TOPICS=NULL #PLATFORM -> C2 (Periodic- Downsampled to every 60 Secs)

export PLATFORM_TO_PLATFORM_TOPICS=PlatformData #Platform -> Platform (Periodic- Full Rate)

export C2_COMMAND_GUID_FILTER_TOPICS=C2Command #C2 -> Platform Aperiodic- (Targeted delivery by GUID address)
export C2_EVENT_TOPICS=ContactReport


echo "
-------------------------------- ROUTER CONFIGS: --------------------------------
XML FILES used:  $NDDS_QOS_PROFILES
PLATFORM_EVENT_TOPICS:  $PLATFORM_EVENT_TOPICS
PLATFORM_STATUS_FULL_TOPICS: $PLATFORM_STATUS_FULL_TOPICS
PLATFORM_STATUS_1SEC_TOPICS:  $PLATFORM_STATUS_1SEC_TOPICS
PLATFORM_STATUS_10SEC_TOPICS:  $PLATFORM_STATUS_10SEC_TOPICS
PLATFORM_STATUS_30SEC_TOPICS:  $PLATFORM_STATUS_30SEC_TOPICS
PLATFORM_STATUS_60SEC_TOPICS:  $PLATFORM_STATUS_60SEC_TOPICS
C2_COMMAND_GUID_FILTER_TOPICS:  $C2_COMMAND_GUID_FILTER_TOPICS
C2_EVENT_TOPICS:  $C2_EVENT_TOPICS
PLATFORM_TO_PLATFORM_TOPICS:  $PLATFORM_TO_PLATFORM_TOPICS

ROUTER_NAME = $ROUTER_NAME
-------------------------------- ROUTER CONFIGS: --------------------------------"


# Run Routing Service
$NDDSHOME/bin/rtiroutingservice -appName $ROUTER_NAME -cfgName $TYPE -verbosity $verbosity