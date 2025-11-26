# Templates for ACT Project

This folder contains template files for creating new nodes (platforms or C2 stations) in the ACT system.

**IMPORTANT**: These templates are for **customer deployments only**. The `examples/` folder contains demo/reference implementations for learning - do not mix your production deployment with the examples.

## Quick Start

1. Create your deployment folder structure (outside of this repo or in a separate location)
2. Copy `config/` folder from this repo to your deployment (contains QoS and routing configurations)
3. Copy templates to your deployment and customize
4. Update all path references to match your structure

## Templates Available

### Parameter Files (`params/`)
- **`system_params.template.sh`** - System-wide parameters (WAN settings, data channels)
- **`node_params.template.sh`** - Node-specific parameters (works for both platforms and C2)

### Start Scripts (`scripts/`)
- **`start_node_router.template.sh`** - Router start script (works for both platforms and C2)
- **`start_node.template.sh`** - Node application start script template (customize for your use case)

## Deployment Overview

**For production deployments**, create your own deployment directory structure using these templates as starting points. The `examples/` folder is for learning only - your production deployment should be completely separate.

### Recommended Deployment Structure

```
<your_deployment_folder>/
├── config/                       # Copy from repo
│   ├── qos/                     # QoS profiles
│   │   ├── lan_qos_lib.xml
│   │   ├── wan_qos_lib.xml
│   │   └── remoteadmin_qos_lib.xml
│   └── routing/                 # Routing service config
│       └── routing_service_config.xml
├── params/
│   └── system_params.sh         # Shared by all nodes
└── nodes/
    ├── platform_<id>/
    │   ├── node_params.sh
    │   ├── start_router.sh
    │   └── start_<app>.sh
    └── c2_<id>/
        ├── node_params.sh
        ├── start_router.sh
        └── start_<app>.sh
```

## How to Use Templates

All templates use **{{PLACEHOLDERS}}** that you replace with actual values. The node templates work for both platforms and C2 stations - just set the `TYPE` parameter accordingly.

### Adding a New Platform (e.g., Platform 12)

1. **Create your deployment directory structure:**
   ```bash
   mkdir -p my_deployment/config
   mkdir -p my_deployment/params
   mkdir -p my_deployment/nodes/platform_12
   ```

2. **Copy config folder from repository:**
   ```bash
   cp -r config/* my_deployment/config/
   ```

3. **Copy and setup system parameters (one time, shared by all nodes):**
   ```bash
   cp templates/params/system_params.template.sh my_deployment/params/system_params.sh
   # Edit my_deployment/params/system_params.sh
   # Update paths: ../config/qos/ and ../config/routing/
   ```

3. **Copy and setup system parameters (one time, shared by all nodes):**
   ```bash
   cp templates/params/system_params.template.sh my_deployment/params/system_params.sh
   # Edit my_deployment/params/system_params.sh
   # Update paths: ../config/qos/ and ../config/routing/
   ```

4. **Create platform parameter file:**
   ```bash
   cp templates/params/node_params.template.sh my_deployment/nodes/platform_12/node_params.sh
   ```

5. **Edit the parameter file:**
   ```bash
   # Open my_deployment/nodes/platform_12/node_params.sh
   # Replace placeholders:
   #   {{NODE_TYPE}} → platform
   #   {{DOMAIN_ID}} → 12
   #   {{NODE_NAME}} → USV_12
   ```

6. **Create router start script:**
   ```bash
   cp templates/scripts/start_node_router.template.sh my_deployment/nodes/platform_12/start_router.sh
   ```

7. **Edit router script:**
   ```bash
   # Open my_deployment/nodes/platform_12/start_router.sh
   # Replace {{PARAM_FILE}} → node_params.sh
   # Update paths to system_params.sh and config/ based on your directory structure
   ```

8. **Create application start script:**
   ```bash
   cp templates/scripts/start_node.template.sh my_deployment/nodes/platform_12/start_app.sh
   ```

9. **Edit application script:**
   ```bash
   # Open my_deployment/nodes/platform_12/start_app.sh
   # Replace {{PARAM_FILE}} → node_params.sh
   # Customize the "SYSTEM-SPECIFIC PROCESSES" section for your application
   # Update paths based on your directory structure
   ```

10. **Make scripts executable:**
    ```bash
    chmod +x my_deployment/nodes/platform_12/start_router.sh
    chmod +x my_deployment/nodes/platform_12/start_app.sh
    ```

11. **Run your platform:**
    ```bash
    cd my_deployment/nodes/platform_12
    
    # Terminal 1: Router
    ./start_router.sh
    
    # Terminal 2: Your Application
    ./start_app.sh
    ```### Adding a New C2 Station (e.g., C2-21)

1. **Create C2 node directory (assuming deployment structure already exists):**
   ```bash
   mkdir -p my_deployment/nodes/c2_21
   ```

2. **Create C2 parameter file:**
   ```bash
   cp templates/params/node_params.template.sh my_deployment/nodes/c2_21/node_params.sh
   ```

3. **Edit the parameter file:**
   ```bash
   # Open my_deployment/nodes/c2_21/node_params.sh
   # Replace placeholders:
   #   {{NODE_TYPE}} → c2
   #   {{DOMAIN_ID}} → 21
   #   {{NODE_NAME}} → C2_21
   ```

4. **Create router start script:**
   ```bash
   cp templates/scripts/start_node_router.template.sh my_deployment/nodes/c2_21/start_router.sh
   ```

5. **Edit router script:**
   ```bash
   # Open my_deployment/nodes/c2_21/start_router.sh
   # Replace {{PARAM_FILE}} → node_params.sh
   # Update paths to system_params.sh and config/ based on your directory structure
   ```

6. **Create application start script:**
   ```bash
   cp templates/scripts/start_node.template.sh my_deployment/nodes/c2_21/start_app.sh
   ```

7. **Edit application script:**
   ```bash
   # Open my_deployment/nodes/c2_21/start_app.sh
   # Replace {{PARAM_FILE}} → node_params.sh
   # Customize the "SYSTEM-SPECIFIC PROCESSES" section for your application
   # Update paths based on your directory structure
   ```

8. **Make scripts executable:**
   ```bash
   chmod +x my_deployment/nodes/c2_21/start_router.sh
   chmod +x my_deployment/nodes/c2_21/start_app.sh
   ```

9. **Run your C2 station:**
   ```bash
   cd my_deployment/nodes/c2_21
   
   # Terminal 1: Router
   ./start_router.sh
   
   # Terminal 2: Your Application
   ./start_app.sh
   ```

## Placeholder Reference

All templates use `{{PLACEHOLDERS}}` that must be replaced with actual values:

### Node Parameter Template
- `{{NODE_TYPE}}` - Node type: "platform" or "c2"
- `{{DOMAIN_ID}}` - Domain ID for the node (platforms: 10-19, c2: 20-29)
- `{{NODE_NAME}}` - Name of the node (e.g., "USV_10", "C2_20")

### Start Script Templates
- `{{PARAM_FILE}}` - Parameter filename (e.g., node_params.sh)

## Important Notes

- **Node Type**: Set `TYPE="platform"` or `TYPE="c2"` in the parameter file
  - The templates automatically handle differences between node types
  - Router uses `$TYPE` to select correct configuration
  - Application script should be customized for your specific use case

- **Customization**: The `start_node.template.sh` is designed to be modified
  - Copy to your deployment folder and customize for your application
  - Replace the example section with your actual processes
  - Can run C++, Java, Python, or any other applications
  - Supports single process or multiple background processes

- **Path Configuration**: Update paths in your scripts based on your deployment structure
  - System params location: Relative path from node folder to shared `system_params.sh`
  - Config files: Relative path from node folder to `config/qos/` and `config/routing/`
  - Example with recommended structure:
    - From `nodes/platform_12/` to `params/system_params.sh` → `../../params/system_params.sh`
    - From `nodes/platform_12/` to `config/qos/` → `../../config/qos/`
    - From `params/` to `config/qos/` → `../config/qos/`

- **Domain IDs**: Use unique domain IDs for each node
  - Platforms: Typically 10-19
  - C2 Stations: Typically 20-29
  - WAN Domain: Always 0 (system-wide, don't change)

- **Naming Convention** (suggested):
  - Node folders: `platform_<id>/` or `c2_<id>/`
  - Parameter files: `node_params.sh` (consistent name in each node folder)
  - Router scripts: `start_router.sh` (consistent name)
  - Application scripts: `start_app.sh` or `start_<your_app_name>.sh`

- **Working Directory**: Run scripts from their node directory (e.g., `my_deployment/nodes/platform_12/`)

- **System Parameters**: The `system_params.sh` file should be shared by all nodes
  - Contains WAN configuration and data channel definitions
  - Place in a shared location (e.g., `my_deployment/params/`)
  - All node scripts source this file

- **Config Files**: The `config/` folder from this repository contains:
  - QoS profiles (`config/qos/`)
  - Routing service configuration (`config/routing/`)
  - Copy the entire `config/` folder to your deployment directory

## See Also

- `examples/` folder - Contains demo implementations for learning (reference only, not for production deployment)
- Main `README.md` - Architecture and use case overview
