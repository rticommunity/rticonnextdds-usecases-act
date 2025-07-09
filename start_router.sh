#!/bin/bash

exit=false

# Check NDDSHOME variable
if [[ -z "${NDDSHOME}" ]]; then
    echo "Must set the NDDSHOME environment variable "
    exit 1;
fi

if [ "$1" == "platform" ] ; then
    export PLATFORM_MODE=true
    type=$1

    if [ "$3" ] ; then 
        export PLATFORM_DOMAIN=$3
    fi
elif [ "$1" == "c2" ] ; then
    export C2_MODE=true
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



# Add Necessary Files to XML ENV Variable
export NDDS_QOS_PROFILES=""

# Add QOS File
NDDS_QOS_PROFILES+="./qos/act_qos_lib.xml;"

# Add Routing Service file
NDDS_QOS_PROFILES+="./router_config/routing_service_config.xml"

if $exit; then
    echo 'pass in: \n
        arg1: c2 or platform \n
        arg2: Name: i.e. "USV-1" or "C2-1" \n
        arg3: Domain ID to override defaults'
else
    echo "XML FILES used: " $NDDS_QOS_PROFILES
    
    $NDDSHOME/bin/rtiroutingservice -appName $name -cfgName $type -verbosity ERROR:LOCAL

fi