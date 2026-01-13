# Remote Enable Detailed Status

This example demonstrates using the RemoteAdmin tool to dynamically enable detailed platform status transmission from Control side. This allows Control stations to request high-bandwidth, detailed telemetry from platforms on-demand without having this data flow continuously.

## Architecture Background

By default, platforms only transmit low-bandwidth primary status data via `PLATFORM_PRIMARY_STATUS_CHANNEL`. The `PLATFORM_DETAIL_STATUS_CHANNEL` session provides detailed, high-bandwidth telemetry including:
- Full sensor suite data
- High-rate position updates
- Detailed diagnostics

This session is **disabled by default** to conserve bandwidth and only enabled via RemoteAdmin when detailed monitoring is required.

## Prerequisites

Before starting, ensure the following are running:
- **Platform_30 simulator** (with its routing service)
- **Platform_31 simulator** (with its routing service)
- **Control_20 simulator** (with its routing service)

See the main README.md for how to start these components.

## Scenario Overview

**Initial State:**
- Platforms transmit primary status only via `PLATFORM_PRIMARY_STATUS_CHANNEL`
- Detailed status session `platform_to_wan_detail_status` is disabled
- Control receives minimal bandwidth telemetry

**After Enabling Detailed Status:**
- Control enables `PLATFORM_DETAIL_STATUS_CHANNEL` on target platform(s)
- Platform begins transmitting detailed status data
- Control receives detailed, high-bandwidth telemetry

## Step 1: Verify Initial State

Before enabling detailed status, verify that only primary status is being received at Control_20.

```bash
# In Control_20 terminal window, observe status message rate
# You should see only PlatformPrimaryStatus updates
```

## Step 2: Enable Detailed Status from Control

From the Control side, use RemoteAdmin to enable detailed status transmission on Platform_30:

```bash
cd tools/remote_admin

# Enable detailed status on Platform_30
./send_remote_cmd.sh -n Platform_30 --detail true
```

Expected output:

```
=============================================================
Remote Admin - RTI Routing Service Controller
=============================================================
Using system parameters from: rticonnextdds-usecases-act/params
Exported NDDS_QOS_PROFILES: rticonnextdds-usecases-act/config/qos/remoteadmin_qos_lib.xml
=============================================================

Waiting for a matching replier...
Sending Remote Admin SESSION UPDATE: 
resource_identifier: /routing_services/platform/domain_routes/dr/sessions/platform_to_wan_detail_status/state
application_name: Platform_30
Enabling Session
Command returned: OK
```

**Note**: The RemoteAdmin command targets a specific platform using the `-n` (name) parameter. This ensures only the specified platform (Platform_30) enables its detailed status transmission. Control can selectively enable detailed status on individual platforms as needed.

## Expected Results

After enabling detailed status:

1. **Platform_30** routing service enables the `platform_to_wan_detail_status` session
2. **Control_20** begins receiving high-rate, detailed telemetry from Platform_30
3. Status data rate increases significantly (full sensor suite, high-rate position)
4. **Platform_31** continues transmitting only 1Hz status (unchanged)

You can verify this by observing the increased message rate and detailed content in the Control_20 terminal.

## Architecture Changes

### Before RemoteAdmin

```
Platform_30 Domain (30)              WAN Domain (200)              Control Domain (20)
┌─────────────────────┐             ┌──────────────────┐          ┌────────────────────┐
│ Platform_30 Sim     │             │                  │          │                    │
│                     │             │                  │          │                    │
│  Status (1Hz) ──────┼────────────►│ WAN Participant  ├─────────►│  Control_20 Sim    │
│  (1Hz Channel)      │  Enabled    │                  │ Enabled  │  (Receiving 1Hz)   │
│                     │             │                  │          │                    │
│  Full Status ───────┼─────────X   │                  │          │                    │
│  (Full Channel)     │  DISABLED   │                  │          │                    │
└─────────────────────┘             └──────────────────┘          └────────────────────┘
```

### After RemoteAdmin (--enable-full-status true)

```
Platform_30 Domain (30)              WAN Domain (200)              Control Domain (20)
┌─────────────────────┐             ┌──────────────────┐          ┌────────────────────┐
│ Platform_30 Sim     │             │                  │          │                    │
│                     │             │                  │          │                    │
│  Status (1Hz) ──────┼────────────►│ WAN Participant  ├─────────►│  Control_20 Sim    │
│  (1Hz Channel)      │  Enabled    │                  │ Enabled  │  (Receiving 1Hz)   │
│                     │             │                  │          │                    │
│  Full Status ───────┼────────────►│                  ├─────────►│  (Receiving Full)  │
│  (Full Channel)     │  ENABLED    │                  │ ENABLED  │                    │
└─────────────────────┘             └──────────────────┘          └────────────────────┘
```

The RemoteAdmin command operates over **ADMIN_DOMAIN (100)** and updates the `platform_to_wan_full_status` session state on Platform_30's routing service from DISABLED to ENABLED.

## Disable Detailed Status (Optional)

To disable detailed status and return to primary-only transmission:

```bash
cd tools/remote_admin

# Disable detailed status on Platform_30
./send_remote_cmd.sh -n Platform_30 --detail false
```

Control_20 will revert to receiving only primary status data from Platform_30, reducing bandwidth consumption.

## Key Concepts

- **On-Demand Telemetry**: Detailed status is disabled by default and only enabled when detailed monitoring is required
- **Bandwidth Conservation**: Prevents continuous high-bandwidth data transmission when not needed
- **Selective Monitoring**: Control can enable detailed status on specific platforms independently
- **Platform-Side Session**: The `--detail` command updates Platform routing service sessions (not Control side)
- **Session Name**: Updates the `platform_to_wan_detail_status` session on the platform's routing service

## Related Documentation

- **REMOTE_CONTROL_TEAM.md**: Assign platforms to teams using DDS partitions
- **SYSTEM_ARCH.md**: Architecture overview including channel definitions and QoS profiles
- **tools/remote_admin/README.md**: RemoteAdmin tool documentation
