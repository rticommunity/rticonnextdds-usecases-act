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
- **In Config**: Matches `<routing_service name="...">` in routing service XML

### Resource ID / Resource Identifier
The **resource identifier** is the full hierarchical path to a specific entity within a routing service instance. It follows RTI's resource naming convention for remote administration.
- **Format**: `/routing_services/<name>/domain_routes/<config_name>/...`
  - `<name>` = routing service instance name (e.g., "Platform-10")
  - `<config_name>` = routing service configuration ("platform" or "c2")
- **Example**: `/routing_services/Platform-10/domain_routes/platform/sessions/platform_to_wan_p2p/state`
- **Purpose**: Uniquely identifies the entity to be controlled or queried

### Domain Route
A **domain route** is a configuration block within Routing Service that defines participants and sessions for bridging DDS domains. In the ACT use case, domain routes connect the LAN, WAN, and C2 domains.
- **In XML**: Defined as `<domain_route>` within a `<routing_service>` configuration block (no name attribute)
- **In Paths**: The segment `/domain_routes/<config_name>/` where `config_name` is either "platform" or "c2"
  - This refers to the domain route within that specific routing service configuration
- **Example Path**: `/routing_services/Platform-10/domain_routes/platform/sessions/...`
  - Here "platform" identifies which routing service configuration's domain route to access
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
- **Example**: `wan_platform_participant` - The participant handling WAN domain communication
- **Path**: `/participants/wan_platform_participant`

### Group / Partition
A **group** (implemented as a DDS partition) is used to logically separate and organize data flow. Assigning a resource to a group ensures it only communicates with others in the same group.
- **Usage**: Specified with `-g` or `--group` flag
- **Example**: Group `5` might represent a specific mission or team
- **DDS Concept**: Implemented using DDS Partitions in QoS

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
Remote administration uses a request-reply pattern where:
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

### Build Instructions

```bash
cd tools/remote_admin
rm -rf build
mkdir build
cd build
cmake ..
make
```

The executable `RemoteAdmin` will be created in the `build` directory.


## Usage

**Important**: Use the `remote_admin.sh` wrapper script to run RemoteAdmin. The wrapper automatically loads system parameters including WAN latency settings required for proper operation with the routing service.

System parameters are located in `config/params/system_params.sh` at the repository root.

```bash
cd tools/remote_admin
./remote_admin.sh -n Platform-10 --p2p true
```

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
   -n, --name       <string>          Resource name (routing service instance) i.e. 'Platform-10' 
                                      REQUIRED
   -t, --type       <string>          Node type: 'platform' or 'c2' (default: platform)
   -g, --group      <int>             Group ID (DDS Partition) to assign resource to 
Only applicable to Platforms: 
   --p2p            <bool>            Enable (true) or disable (false) Platform to Platform topic routes.

Note: QoS XML files are loaded from NDDS_QOS_PROFILES environment variable.
      Use the remote_admin.sh wrapper script to automatically load system_params.sh
```

### Required Arguments

- `-n, --name <string>`: The name of the routing service instance to control (e.g., 'Platform-10', 'USV-1'). This must match the routing service's application name.

### Optional Arguments

- `-d, --domain <int>`: Domain ID for remote administration (default: 100)
- `-q, --qos <string>`: QoS profile to use (default: REMOTE_ADMIN::remote_admin_default)
- `-t, --type <string>`: Node type - either "platform" or "c2" (default: platform). This determines which routing service configuration and participant names are used in the resource identifier path.
- `-g, --group <int>`: Group ID (DDS Partition) to assign the resource to
- `--p2p <bool>`: Enable (true) or disable (false) platform-to-platform communication routes

### Examples

Enable Platform-to-Platform Communication:
```bash
./remote_admin.sh -n Platform-10 --p2p true
```

Disable Platform-to-Platform Communication:
```bash
./remote_admin.sh -n Platform-10 --p2p false
```

Assign Platform Resource to Group:
```bash
./remote_admin.sh -n Platform-10 -g 5
```

Assign C2 Resource to Group:
```bash
./remote_admin.sh -n C2-20 -t c2 -g 5
```

Use Custom Domain:
```bash
./remote_admin.sh -d 50 -n USV-1 --p2p true
```

## How It Works

The Remote Admin tool:

1. Creates a DDS Requester that communicates on the administrative domain (default: 100)
2. Builds a `CommandRequest` message with:
   - Action: `UPDATE_ACTION`
   - Resource identifier: `/routing_services/<resource>/domain_routes/platform/sessions/platform_to_platform_session/state`
   - Application name: The resource name provided
   - Entity state: `ENABLED` or `DISABLED` based on the command
3. Sends the request to the target routing service
4. Waits up to 10 seconds for a reply
5. Reports success or failure

## Integration with ACT Use Case

This tool is designed to work with the Autonomous Collaborative Teaming (ACT) routing service architecture. The typical use case:

1. Start your platform routing services (e.g., `./start_router.sh` after sourcing `platform_10.sh`)
2. Use RemoteAdmin to dynamically enable/disable P2P communication between platforms
3. Control data flow without restarting services or modifying configuration files

### Example Scenario

```bash
# Terminal 1: Start Platform-10 routing service
cd start_scripts
./start_platform10_router.sh

# Terminal 2: Start Platform-11 routing service
cd start_scripts
./start_platform11_router.sh

# Terminal 3: Enable P2P communication for Platform-10
cd tools/remote_admin
./remote_admin.sh -n Platform-10 --p2p true

# Terminal 4: Enable P2P communication for Platform-11
cd tools/remote_admin
./remote_admin.sh -n Platform-11 --p2p true
```

Now Platform-10 and Platform-11 can exchange data directly through the WAN domain.

## Files

- `remote_admin.sh`: Wrapper script that sources system_params.sh and invokes RemoteAdmin
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
