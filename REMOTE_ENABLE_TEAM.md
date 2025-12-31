# Remote Control Example

This example demonstrates using the RemoteAdmin tool to dynamically enable platform-to-platform (TEAM) communication between two running routing services.

## Scenario

Two platforms (Platform_10 and Platform_11) are running with routing services. We use the RemoteAdmin tool to:
1. Enable TEAM communication on both platforms
2. Verify that platforms exchange data directly through the WAN domain

## What This Demonstrates

- **Remote Administration**: Control routing service behavior without restarting
- **Dynamic Route Control**: Enable/disable TEAM sessions at runtime
- **TEAM Communication**: Platform-to-platform data exchange bypassing C2

## Prerequisites

- RTI Connext DDS 7.3.0+ ([C++ setup guide](https://community.rti.com/static/documentation/developers/get-started/apt-install.html))
- Built RemoteAdmin tool (`tools/remote_admin/build/RemoteAdmin`)
- Python 3 with RTI Connext DDS Python API ([setup guide](https://community.rti.com/static/documentation/developers/get-started/pip-install.html#section-pip-install))
- `NDDSHOME` environment variable set
- `RTI_LICENSE_FILE` environment variable set

## Running the Example

### Terminal 1: Start Platform_10

```bash
cd scripts
./start_platform10_sim.sh
```

Leave this running. Platform_10 will publish PlatformData on the PLATFORM_TO_PLATFORM_CHANNEL.

### Terminal 2: Start Platform_10 Routing Service

```bash
cd scripts
./start_platform10_router.sh
```

Leave this running. The routing service starts with TEAM routes available but can be enabled/disabled remotely.

### Terminal 3: Start Platform_11

```bash
cd scripts
./start_platform11_sim.sh
```

Leave this running. Platform_11 will subscribe to PlatformData from other platforms. Initially, you won't see any messages.

### Terminal 4: Start Platform_11 Routing Service

```bash
cd scripts
./start_platform11_router.sh
```

Leave this running.

### Terminal 5: Enable TEAM Communication

Now enable TEAM on both platforms using RemoteAdmin:

```bash
cd tools/remote_admin

# Enable TEAM on Platform_10
./send_remote_cmd.sh -n Platform_10 --team true

# Wait a moment, then enable TEAM on Platform_11
./send_remote_cmd.sh -n Platform_11 --team true
```

**Note**: Each RemoteAdmin command is uniquely addressed to a specific node using the `-n` (name) parameter. This ensures that commands only affect the targeted routing service (Platform_10 or Platform_11), allowing precise control of individual nodes in a multi-platform deployment.

## Expected Results

**Before enabling TEAM:**
- Platform_10 publishes PlatformData on its local domain (10)
- Platform_11 does NOT receive any data (TEAM routes disabled)
- Terminal 3 (Platform_11) shows no "Received PlatformData" messages

**After enabling TEAM:**
- Platform_10: PlatformData → routing service → WAN domain (0)
- Platform_11: routing service receives from WAN → forwards to Platform_11 domain (11)
- Terminal 3 (Platform_11) shows: **"Received PlatformData with Session ID xx"**

## Validation

Watch Terminal 3 (Platform_11 simulator) for output like:
```
Received PlatformData with Session ID 42
```

This confirms TEAM communication is working!

## Disable TEAM (Optional)

To disable TEAM communication:

```bash
cd tools/remote_admin

# Disable TEAM on Platform_10
./send_remote_cmd.sh -n Platform_10 --team false

# Disable TEAM on Platform_11
./send_remote_cmd.sh -n Platform_11 --team false
```

Platform_11 should stop receiving messages from Platform_10.

## Architecture

**Before RemoteAdmin:**

```
┌─────────────┐                        ┌─────────────┐
│ Platform_10 │                        │ Platform_11 │
│ Domain: 10  │                        │ Domain: 11  │
│             │                        │             │
│ Simulator   │                        │ Simulator   │
│     │       │                        │      │      │
│     ▼       │                        │      ▼      │
│ PlatformData│       WAN Domain 0     │ PlatformData│
│     │       │                        │      │      │
│     ▼       │                        │      ▼      │
│ Routing Svc │                        │ Routing Svc │
│  (TEAM OFF)  │ ────────X──────────────│  (TEAM OFF)  │
└─────────────┘     No Data Flow       └─────────────┘
```

**After RemoteAdmin enables TEAM:**

```
┌─────────────┐                        ┌─────────────┐
│ Platform_10 │                        │ Platform_11 │
│ Domain: 10  │                        │ Domain: 11  │
│             │                        │             │
│ Simulator   │                        │ Simulator   │
│     │  ▲    │                        │     │  ▲    │
│     ▼  │    │                        │     ▼  │    │
│ PlatformData│       WAN Domain 0     │ PlatformData│
│     │  ▲    │                        │     │  ▲    │
│     ▼  │    │                        │     ▼  │    │
│ Routing Svc │                        │ Routing Svc │
│  (TEAM ON)   │ ◄────────────────────► │  (TEAM ON)   │
└─────────────┘   Bidirectional TEAM ✓  └─────────────┘
```

## How It Works

1. **Initial State**: Routing services are running but TEAM sessions are disabled
2. **RemoteAdmin Command**: Sends UPDATE command to routing service on admin domain (100)
3. **Session Update**: Routing service enables `platform_to_wan_p2p` and `wan_to_platform_p2p` sessions
4. **Data Flow**: PlatformData now flows: Platform_10 → WAN → Platform_11
5. **Validation**: Platform_11 simulator receives and displays the data



## Related Documentation

- **RemoteAdmin Tool**: See `tools/remote_admin/README.md` for detailed usage
- **QUICKSTART**: See `examples/QUICKSTART.md` for basic setup
- **MULTI_PLATFORM**: See `examples/MULTI_PLATFORM.md` for more complex scenarios

---

## Questions or Feedback?

Reach out to us at **services_community@rti.com** - we welcome your questions and feedback!
