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

# Source NODE params
source ./params/c2_20_params.sh

# Source SYSTEM parameters
source ./params/system_params.sh

# Check NDDSHOME variable
if [[ -z "${NDDSHOME}" ]]; then
    echo "Must set the NDDSHOME environment variable "
    exit 1;
fi

################################################################################
#                                 VERBOSITY                                    #
################################################################################

verbosity=ERROR:ERROR

# Run Routing Service
$NDDSHOME/bin/rtiroutingservice -appName $ROUTER_NAME -cfgName $TYPE -verbosity $verbosity
