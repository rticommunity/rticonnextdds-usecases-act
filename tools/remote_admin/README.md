# Remote Admin Service Controller

A command-line utility for remotely controlling RTI Routing Service configurations, specifically designed to dynamically enable/disable platform-to-platform (P2P) communication routes during runtime.

## Overview

The Remote Admin tool uses RTI Connext DDS Remote Administration capabilities to send commands to running Routing Service instances. It allows operators to modify routing service behavior without restarting the service, providing dynamic control over data flow between platforms and C2 stations.

## Terminology

Understanding these key terms will help you use the Remote Admin tool effectively:

### Resource
The **resource** is the name of the RTI Routing Service instance you want to control. This corresponds to the `-appName` parameter used when starting the routing service.
- **Example**: `Platform-10`, `Platform-11`, `C2-20`, `USV-1`
- **Usage**: Specified with `-n` or `--name` flag

### Resource ID / Resource Identifier
The **resource identifier** is the full hierarchical path to a specific entity within a routing service instance. It follows RTI's resource naming convention for remote administration.
- **Format**: `/routing_services/<name>/domain_routes/<config_name>/...`
  - `<name>` = routing service instance name (e.g., "Platform-10")
  - `<config_name>` = routing service configuration ("platform" or "c2")
- **Example**: `/routing_services/Platform-10/domain_routes/platform/sessions/platform_to_wan_p2p/state`
- **Purpose**: Uniquely identifies the entity to be controlled or queried

### Domain Route
A **domain route** is a configuration block within Routing Service that defines participants and sessions for bridging DDS domains. In the ACT use case, domain routes connect the LAN, WAN, and C2 domains.
- **In XML**: Defined as `<domain_route name="dr">` within a `<routing_service>` configuration block
- **In Paths**: The segment `/domain_routes/dr/` where "dr" is the default domain route name
- **Example Path**: `/routing_services/platform/domain_routes/dr/sessions/...`
  - Here "platform" is the routing service configuration name from `<routing_service name="platform">`
  - "dr" is the domain route name from `<domain_route name="dr">`
- **Purpose**: Groups participants and sessions that handle domain-to-domain data flow

### Session
A **session** within Routing Service represents a logical grouping of topic routes. Sessions can be enabled or disabled to control specific data flows.
- **Common Sessions**:
  - `platform_to_wan_p2p` - Platform to WAN peer-to-peer communication
  - `wan_to_platform_p2p` - WAN to Platform peer-to-peer communication
- **Example Path**: `/sessions/platform_to_wan_p2p/state`

### P2P (Peer-to-Peer)
**P2P** or **platform-to-platform** communication refers to direct data exchange between platforms without involving C2 stations. This is useful for collaborative autonomous operations.
- **Control**: Enable/disable with `--p2p true` or `--p2p false` flags
- **Sessions**: Controls both `platform_to_wan_p2p` and `wan_to_platform_p2p` sessions

### Participant
A **participant** is a DDS Domain Participant within the routing service. It represents the routing service's presence in a specific DDS domain.
- **Platform participants**: `platform_wan` - Platform node's WAN domain participant
- **C2 participants**: `c2_wan` - C2 node's WAN domain participant
- **Path Example**: `/participants/platform_wan`

### Group / Partition
A **group** (implemented as a DDS Domain Participant partition) is used to logically separate and organize data flow. Assigning a resource to a group ensures it only communicates with others in the same group.
- **Usage**: Specified with `-g` or `--group` flag
- **Example**: Group `5` might represent a specific mission or team
- **DDS Concept**: Implemented using DDS Domain Participant Partitions in QoS

### QoS Profile
A **QoS profile** is a named set of Quality of Service settings that control data delivery behavior (reliability, durability, etc.).
- **Format**: `library_name::profile_name`
- **Default**: `REMOTE_ADMIN::remote_admin_default`
- **Usage**: Specified with `-q` or `--qos` flag
- **Location**: Defined in XML QoS configuration files

### Domain ID
The **domain ID** is the DDS domain number on which remote administration commands are sent and received.
- **Default**: `100` (administrative domain)
- **Usage**: Specified with `-d` or `--domain` flag
- **Purpose**: Separates administrative traffic from application data

### Command Request/Reply
Remote administration uses a request-reply pattern ([API Reference](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/services/routing_service/remote_admin.html#api-reference)) where:
- **Command Request**: The command sent to the routing service (enable/disable, update configuration)
- **Command Reply**: The response from the routing service indicating success or failure
- **Topics**: `rti/service/admin/command_request` and `rti/service/admin/command_reply`

### Entity State
The **entity state** represents whether a routing service entity (like a session) is active or inactive.
- **States**: `ENABLED`, `DISABLED`
- **Control**: P2P commands set session state to enable or disable data flow

## Features

- **Remote Control**: Send commands to Routing Service instances over DDS
- **P2P Route Management**: Enable/disable platform-to-platform communication routes
- **Group Assignment**: Assign resources to specific groups
- **Flexible Configuration**: Override domain ID and QoS settings

## Building

The project uses CMake and requires RTI Connext DDS 7.3.0 or later.

### Prerequisites

- RTI Connext DDS 7.3.0+
- CMake 3.16+
- C++11 compatible compiler
- `NDDSHOME` environment variable set to your RTI Connext installation
- Git submodules initialized (see [main README](../../README.md#getting-started) for clone instructions)

### Build Instructions

```bash
# Ensure submodules are initialized (if not done during clone)
git submodule update --init --recursive

cd tools/remote_admin
rm -rf build
mkdir build
cd build
cmake ..
make
```

The executable `RemoteAdmin` will be created in the `build` directory.


## Usage

**Important**: Use the `send_remote_cmd.sh` wrapper script to run RemoteAdmin. The wrapper automatically loads system parameters including WAN latency settings required for proper operation with the routing service.

System parameters are located in `params/system_params.sh` at the repository root.

```bash
cd scripts
./send_remote_cmd.sh -n Platform_10 --p2p true
```

**Note**: The `-n` parameter uses the unique identifier (PLATFORM_NAME or C2_NAME) defined in each node's params file:
- Platform nodes: Use PLATFORM_NAME from `params/platform_*_params.sh` (e.g., Platform_10, Platform_11)
- C2 nodes: Use C2_NAME from `params/c2_*_params.sh` (e.g., C2_20)

The wrapper script:
- Sources `system_params.sh` automatically from `config/params/`
- Exports `NDDS_QOS_PROFILES` environment variable for XML file loading
- Uses the admin domain and QoS settings from system parameters
- Passes through all command-line arguments to RemoteAdmin

### Command-Line Arguments

```
Remote Admin Service Controller.
Usage:
   -d, --domain     <int>             Domain ID 
   -q, --qos        <string>          QOS Profile (library::profile)
   -n, --name       <string>          Resource name (routing service instance) i.e. 'Platform_10' 
                                      REQUIRED
   -t, --type       <string>          Node type: 'platform' or 'c2' (default: platform)
   -g, --group      <int>             Group ID (DDS Partition - see https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/users_manual/users_manual/PARTITION_QosPolicy.htm) to assign resource to 
Only applicable to Platforms: 
   --p2p            <bool>            Enable (true) or disable (false) Platform to Platform topic routes.

Note: QoS XML files are loaded from NDDS_QOS_PROFILES environment variable.
      Use the send_remote_cmd.sh wrapper script to automatically load system_params.sh
```

### Required Arguments

- `-n, --name <string>`: The name of the routing service instance to control (e.g., 'Platform_10', 'USV_1'). This must match the routing service's application name.

### Optional Arguments

- `-d, --domain <int>`: Domain ID for remote administration (default: 100)
- `-q, --qos <string>`: QoS profile to use (default: REMOTE_ADMIN::remote_admin_default)
- `-t, --type <string>`: Node type - either "platform" or "c2" (default: platform). This determines which routing service configuration and participant names are used in the resource identifier path.
- `-g, --group <int>`: Group ID ([DDS Partition](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/users_manual/users_manual/PARTITION_QosPolicy.htm)) to assign the resource to
- `--p2p <bool>`: Enable (true) or disable (false) platform-to-platform communication routes

## Usage Examples

For complete step-by-step walkthroughs demonstrating RemoteAdmin usage, see:

- **[REMOTE_ENABLE_P2P.md](../../REMOTE_ENABLE_P2P.md)**: Enable peer-to-peer communication between platforms
- **[REMOTE_CONTROL_GROUP.md](../../REMOTE_CONTROL_GROUP.md)**: Dynamically assign nodes to different groups and verify isolation

## How It Works

The Remote Admin tool ([API Reference](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/services/routing_service/remote_admin.html#api-reference)):

1. Creates a DDS Requester that communicates on the administrative domain (default: 100)
2. Builds a `CommandRequest` message with:
   - Action: `UPDATE_ACTION`
   - Resource identifier: `/routing_services/<resource>/domain_routes/platform/sessions/platform_to_platform_session/state`
   - Application name: The resource name provided
   - Entity state: `ENABLED` or `DISABLED` based on the command
3. Sends the request to the target routing service
4. Waits up to 10 seconds for a reply
5. Reports success or failure

## Files

- `send_remote_cmd.sh`: Wrapper script that sources system_params.sh and invokes RemoteAdmin
- `src/remote_admin.cxx`: Main application source
- `include/application.hpp`: Argument parsing and application utilities
- `resources/types/ServiceAdmin.idl`: IDL definitions for admin commands
- `resources/types/ServiceCommon.idl`: IDL definitions for common service types
- `CMakeLists.txt`: Build configuration
- `build/RemoteAdmin`: Compiled executable (after building)

## Troubleshooting

### No Response from Routing Service

- Verify the routing service is running with the correct application name
- Check that the remote administration domain matches (default: 100)
- Ensure `NDDSHOME` is set correctly
- Verify network connectivity between the RemoteAdmin tool and routing service

### Build Errors

- Ensure RTI Connext DDS 7.3.0+ is installed
- Verify `NDDSHOME` environment variable is set
- Check that CMake can find the RTI Connext installation
- Clean the build directory and reconfigure if you encounter cached path issues

### Invalid Command Response

- Verify the resource identifier matches your routing service configuration
- Check the routing service logs for error messages
- Ensure the session path exists in your routing service configuration

## License

(c) Copyright, Real-Time Innovations, 2024. All rights reserved.

RTI grants Licensee a license to use, modify, compile, and create derivative works of the software solely for use with RTI Connext DDS.
