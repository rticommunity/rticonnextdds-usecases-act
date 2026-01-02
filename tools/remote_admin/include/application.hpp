/*
 * (c) Copyright, Real-Time Innovations, 2024.  All rights reserved.
 * RTI grants Licensee a license to use, modify, compile, and create derivative
 * works of the software solely for use with RTI Connext DDS. Licensee may
 * redistribute copies of the software provided that all such copies are subject
 * to this license. The software is provided "as is", with no warranty of any
 * type, including any warranty for fitness for any purpose. RTI is under no
 * obligation to maintain or support the software. RTI shall not be liable for
 * any incidental or consequential damages arising out of the use or inability
 * to use the software.
 */

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <iostream>
#include <csignal>
#include <dds/core/ddscore.hpp>
#include <cstring>

namespace application {

// Catch control-C and tell application to shut down
static bool shutdown_requested = false;

// Default values - single source of truth
static constexpr unsigned int DEFAULT_ADMIN_DOMAIN_ID = 100;
static const std::string DEFAULT_REMOTE_ADMIN_QOS_PROFILE =
        "REMOTE_ADMIN::remote_admin_requester_qos";

inline void stop_handler(int)
{
    shutdown_requested = true;
    std::cout << "preparing to shut down..." << std::endl;
}

inline void setup_signal_handlers()
{
    signal(SIGINT, stop_handler);
    signal(SIGTERM, stop_handler);
}

enum class ParseReturn { ok, failure, exit };

struct ApplicationArguments {
    // Parse result - always initialize!
    ParseReturn parse_result = ParseReturn::ok;

    // Parameters with defaults from constants
    int domain_id = DEFAULT_ADMIN_DOMAIN_ID;
    std::string qos_profile = DEFAULT_REMOTE_ADMIN_QOS_PROFILE;

    // Required parameters - empty means "not provided"
    std::string name = "";
    std::string node_type = "platform";  // "platform" or "control"
    std::string team = "";

    // Flags with sensible defaults
    bool update_team = false;
    bool enable_team_comms = false;
    bool update_enable_team_comms = false;
    bool enable_full_status = false;
    bool update_enable_full_status = false;
};

// Parses application arguments.
inline ApplicationArguments parse_arguments(int argc, char *argv[])
{
    int arg_processing = 1;
    bool show_usage = false;

    ApplicationArguments args;  // Uses defaults from member initializers

    while (arg_processing < argc) {
        if ((argc > arg_processing + 1)
            && (strcmp(argv[arg_processing], "-d") == 0
                || strcmp(argv[arg_processing], "--domain") == 0)) {
            args.domain_id = atoi(argv[arg_processing + 1]);
            arg_processing += 2;
        } else if (
                (argc > arg_processing + 1)
                && (strcmp(argv[arg_processing], "-q") == 0
                    || strcmp(argv[arg_processing], "--qos") == 0)) {
            args.qos_profile = argv[arg_processing + 1];
            arg_processing += 2;
        } else if (
                (argc > arg_processing + 1)
                && (strcmp(argv[arg_processing], "-n") == 0
                    || strcmp(argv[arg_processing], "--name") == 0)) {
            args.name = argv[arg_processing + 1];
            arg_processing += 2;
        } else if (
                (argc > arg_processing + 1)
                && (strcmp(argv[arg_processing], "-t") == 0
                    || strcmp(argv[arg_processing], "--team") == 0)) {
            args.team = argv[arg_processing + 1];
            args.update_team = true;
            arg_processing += 2;
        } else if (
                (argc > arg_processing + 1)
                && (strcmp(argv[arg_processing], "--type") == 0)) {
            std::string type_value = argv[arg_processing + 1];
            if (type_value == "platform" || type_value == "control") {
                args.node_type = type_value;
            } else {
                std::cout << "Bad parameter value for --type. Use 'platform' or 'control'." << std::endl;
                show_usage = true;
                args.parse_result = ParseReturn::failure;
                break;
            }
            arg_processing += 2;
        } else if (
                (argc > arg_processing + 1)
                && strcmp(argv[arg_processing], "--enable-team-comms") == 0) {
            std::string team_comms_value = argv[arg_processing + 1];
            if (team_comms_value == "true" || team_comms_value == "1") {
                args.enable_team_comms = true;
            } else if (team_comms_value == "false" || team_comms_value == "0") {
                args.enable_team_comms = false;
            } else {
                std::cout << "Bad parameter value for --enable-team-comms. Use 'true' or 'false'." << std::endl;
                show_usage = true;
                args.parse_result = ParseReturn::failure;
                break;
            }
            args.update_enable_team_comms = true;
            arg_processing += 2;
        } else if (
                (argc > arg_processing + 1)
                && strcmp(argv[arg_processing], "--enable-full-status") == 0) {
            std::string full_status_value = argv[arg_processing + 1];
            if (full_status_value == "true" || full_status_value == "1") {
                args.enable_full_status = true;
            } else if (full_status_value == "false" || full_status_value == "0") {
                args.enable_full_status = false;
            } else {
                std::cout << "Bad parameter value for --enable-full-status. Use 'true' or 'false'." << std::endl;
                show_usage = true;
                args.parse_result = ParseReturn::failure;
                break;
            }
            args.update_enable_full_status = true;
            arg_processing += 2;
        } else if (
                strcmp(argv[arg_processing], "-h") == 0
                || strcmp(argv[arg_processing], "--help") == 0) {
            std::cout << "Remote Admin Service Controller." << std::endl;
            show_usage = true;
            args.parse_result = ParseReturn::exit;
            break;
        } else {
            std::cout << "Bad parameter." << std::endl;
            show_usage = true;
            args.parse_result = ParseReturn::failure;
            break;
        }
    }
    if (show_usage) {
        std::cout << "Usage:\n"
                     "   -d, --domain     <int>             Domain ID \n"
                     "   -q, --qos        <string>          QOS Profile (library::profile)\n"
                     "   -n, --name       <string>          Resource name "
                     "(routing service instance) i.e. 'Platform_30' \n"
                     "                                      REQUIRED\n"
                     "   --type           <string>          Node type: 'platform' or 'control' (default: platform)\n"
                     "   -t, --team       <string>          Team ID (DDS Partition) to assign "
                     "resource to (e.g., A, B, C, or ALL) \n"
                     "Only applicable to Platforms: \n"
                     "   --enable-team-comms <bool>        Enable (true) or disable (false) "
                     "Platform to Platform topic routes within team.\n"
                     "   --enable-full-status <bool>       Enable (true) or disable (false) "
                     "full-rate platform status data transmission.\n"
                     "                                      When disabled, only 1Hz status is transmitted.\n"
                     "\n"
                     "Note: QoS XML files are loaded from NDDS_QOS_PROFILES environment variable.\n"
                     "      Use the send_remote_cmd.sh wrapper script to automatically load system_params.sh\n"

                  << std::endl;
    }

    // Validate required parameters
    if (!show_usage && args.name.empty()) {
        std::cout << "Error: --name parameter is required." << std::endl;
        args.parse_result = ParseReturn::failure;
    }

    return args;
}

}  // namespace application

#endif  // APPLICATION_HPP
