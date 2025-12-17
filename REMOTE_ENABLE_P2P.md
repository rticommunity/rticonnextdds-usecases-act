# Remote Control Example

This example demonstrates using the RemoteAdmin tool to dynamically enable platform-to-platform (P2P) communication between two running routing services.

## Scenario

Two platforms (Platform-10 and Platform-11) are running with routing services. We use the RemoteAdmin tool to:
1. Enable P2P communication on both platforms
2. Verify that platforms exchange data directly through the WAN domain

## What This Demonstrates

- **Remote Administration**: Control routing service behavior without restarting
- **Dynamic Route Control**: Enable/disable P2P sessions at runtime
- **P2P Communication**: Platform-to-platform data exchange bypassing C2

## Prerequisites

- RTI Connext DDS 7.3.0+ ([C++ setup guide](https://community.rti.com/static/documentation/developers/get-started/apt-install.html))
- Built RemoteAdmin tool (`tools/remote_admin/build/RemoteAdmin`)
- Python 3 with RTI Connext DDS Python API ([setup guide](https://community.rti.com/static/documentation/developers/get-started/pip-install.html#section-pip-install))
- `NDDSHOME` environment variable set
- `RTI_LICENSE_FILE` environment variable set

## Running the Example

### Terminal 1: Start Platform-10

```bash
cd start_scripts
./start_platform10_sim.sh
```

Leave this running. Platform-10 will publish PlatformData on the PLATFORM_TO_PLATFORM_CHANNEL.

### Terminal 2: Start Platform-10 Routing Service

```bash
cd start_scripts
./start_platform10_router.sh
```

Leave this running. The routing service starts with P2P routes available but can be enabled/disabled remotely.

### Terminal 3: Start Platform-11

```bash
cd start_scripts
./start_platform11_sim.sh
```

Leave this running. Platform-11 will subscribe to PlatformData from other platforms. Initially, you won't see any messages.

### Terminal 4: Start Platform-11 Routing Service

```bash
cd start_scripts
./start_platform11_router.sh
```

Leave this running.

### Terminal 5: Enable P2P Communication

Now enable P2P on both platforms using RemoteAdmin:

```bash
cd tools/remote_admin

# Enable P2P on Platform-10
./remote_admin.sh -n Platform-10 --p2p true

# Wait a moment, then enable P2P on Platform-11
./remote_admin.sh -n Platform-11 --p2p true
```

**Note**: Each RemoteAdmin command is uniquely addressed to a specific node using the `-n` (name) parameter. This ensures that commands only affect the targeted routing service (Platform-10 or Platform-11), allowing precise control of individual nodes in a multi-platform deployment.

## Expected Results

**Before enabling P2P:**
- Platform-10 publishes PlatformData on its local domain (10)
- Platform-11 does NOT receive any data (P2P routes disabled)
- Terminal 3 (Platform-11) shows no "Received PlatformData" messages

**After enabling P2P:**
- Platform-10: PlatformData → routing service → WAN domain (0)
- Platform-11: routing service receives from WAN → forwards to Platform-11 domain (11)
- Terminal 3 (Platform-11) shows: **"Received PlatformData with Session ID xx"**

## Validation

Watch Terminal 3 (Platform-11 simulator) for output like:
```
Received PlatformData with Session ID 42
```

This confirms P2P communication is working!

## Disable P2P (Optional)

To disable P2P communication:

```bash
cd tools/remote_admin

# Disable P2P on Platform-10
./remote_admin.sh -n Platform-10 --p2p false

# Disable P2P on Platform-11
./remote_admin.sh -n Platform-11 --p2p false
```

Platform-11 should stop receiving messages from Platform-10.

## Architecture

**Before RemoteAdmin:**

```
┌─────────────┐                        ┌─────────────┐
│ Platform-10 │                        │ Platform-11 │
│ Domain: 10  │                        │ Domain: 11  │
│             │                        │             │
│ Simulator   │                        │ Simulator   │
│     │       │                        │      │      │
│     ▼       │                        │      ▼      │
│ PlatformData│       WAN Domain 0     │ PlatformData│
│     │       │                        │      │      │
│     ▼       │                        │      ▼      │
│ Routing Svc │                        │ Routing Svc │
│  (P2P OFF)  │ ────────X──────────────│  (P2P OFF)  │
└─────────────┘     No Data Flow       └─────────────┘
```

**After RemoteAdmin enables P2P:**

```
┌─────────────┐                        ┌─────────────┐
│ Platform-10 │                        │ Platform-11 │
│ Domain: 10  │                        │ Domain: 11  │
│             │                        │             │
│ Simulator   │                        │ Simulator   │
│     │  ▲    │                        │     │  ▲    │
│     ▼  │    │                        │     ▼  │    │
│ PlatformData│       WAN Domain 0     │ PlatformData│
│     │  ▲    │                        │     │  ▲    │
│     ▼  │    │                        │     ▼  │    │
│ Routing Svc │                        │ Routing Svc │
│  (P2P ON)   │ ◄────────────────────► │  (P2P ON)   │
└─────────────┘   Bidirectional P2P ✓  └─────────────┘
```

## How It Works

1. **Initial State**: Routing services are running but P2P sessions are disabled
2. **RemoteAdmin Command**: Sends UPDATE command to routing service on admin domain (100)
3. **Session Update**: Routing service enables `platform_to_wan_p2p` and `wan_to_platform_p2p` sessions
4. **Data Flow**: PlatformData now flows: Platform-10 → WAN → Platform-11
5. **Validation**: Platform-11 simulator receives and displays the data

## Cleanup

Stop all processes with Ctrl+C in each terminal, or run:

```bash
pkill -f "platform_sim.py"
pkill -f "rtiroutingservice"
```

## Troubleshooting

**RemoteAdmin can't connect:**
- Verify routing services are running
- Check that admin domain is 100 (default)
- Ensure `config/params/system_params.sh` is loaded (routing service scripts do this automatically)

**Platform-11 not receiving data:**
- Verify both P2P enable commands succeeded (check for "Command returned: OK")
- Confirm PlatformData is in PLATFORM_TO_PLATFORM_CHANNEL (check `config/params/system_params.sh`)
- Look at routing service output for errors

**RemoteAdmin memory errors:**
- Ensure you rebuilt RemoteAdmin after the QoS profile fix
- Run: `cd tools/remote_admin && rm -rf build && mkdir build && cd build && cmake .. && make`

## Related Documentation

- **RemoteAdmin Tool**: See `tools/remote_admin/README.md` for detailed usage
- **QUICKSTART**: See `examples/QUICKSTART.md` for basic setup
- **MULTI_PLATFORM**: See `examples/MULTI_PLATFORM.md` for more complex scenarios
