#!/bin/bash

exit=false

# Check NDDSHOME variable
if [[ -z "${NDDSHOME}" ]]; then
    echo "Must set the NDDSHOME environment variable "
    exit 1;
fi

if [ "$1" == "platform" ] ; then
    type=$1

    if [ "$3" ] ; then 
        export PLATFORM_DOMAIN=$3
    fi
elif [ "$1" == "c2" ] ; then
    type=$1

    if [ "$3" ] ; then 
        export C2_DOMAIN=$3
    fi
else
    exit=true
fi

if [ "$2" ] ; then 
    name=$2
    export ROUTER_NAME=$name
else
    exit=true
fi

# XML Files
export NDDS_QOS_PROFILES=""

# QOS File
NDDS_QOS_PROFILES+="./qos/act_qos_lib.xml;"
# Routing Service file
NDDS_QOS_PROFILES+="./router_config/routing_service_config.xml"


# Topics (Data "Lanes")
# Comma separated, no spaces, NULL if empty
export PLATFORM_COMMAND_TOPICS=PlatformCommandAck #PLATFORM -> C2 (Aperiodic- Ensured Delivery CommandAck etc.)

export PLATFORM_STATUS_TOPICS=NULL #PLATFORM -> C2 (Periodic- Full Rate)
export PLATFORM_STATUS_1SEC_TOPICS=NULL #PLATFORM -> C2 (Periodic- Downsampled to every 1 Sec)
export PLATFORM_STATUS_1SEC_TOPICS=PlatformStatus #PLATFORM -> C2 (Periodic- Downsampled to every 1 Sec)
export PLATFORM_STATUS_10SEC_TOPICS=NULL #PLATFORM -> C2 (Periodic- Downsampled to every 10 Secs)
export PLATFORM_STATUS_30SEC_TOPICS=NULL #PLATFORM -> C2 (Periodic- Downsampled to every 30 Secs)
export PLATFORM_STATUS_60SEC_TOPICS=NULL #PLATFORM -> C2 (Periodic- Downsampled to every 60 Secs)

export C2_COMMAND_TOPICS=C2Command #C2 -> Platform Aperiodic- (Ensured Delivery CommandAck etc.)

export PLATFORM_TO_PLATFORM_TOPICS=PlatformData #Platform -> Platform (Periodic- Full Rate)



if $exit; then
    echo 'pass in: \n
        arg1: c2 or platform \n
        arg2: Name: i.e. "USV-1" or "C2-1" \n
        arg3: Domain ID to override defaults'
else
    echo "XML FILES used: " $NDDS_QOS_PROFILES
    
    $NDDSHOME/bin/rtiroutingservice -appName $name -cfgName $type -verbosity ERROR:LOCAL

fi