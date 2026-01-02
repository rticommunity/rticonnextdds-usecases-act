/*
 * (c) 2021 Copyright, Real-Time Innovations, Inc.  All rights reserved.
 *
 * RTI grants Licensee a license to use, modify, compile, and create derivative
 * works of the Software.  Licensee has the right to distribute object form
 * only for use with RTI products.  The Software is provided "as is", with no
 * warranty of any type, including any warranty for fitness for any purpose.
 * RTI is under no obligation to maintain or support the Software.  RTI shall
 * not be liable for any incidental or consequential damages arising out of the
 * use or inability to use the software.
 */

#include "ServiceAdmin.hpp"
#include "ServiceCommon.hpp"
#include "rti/request/RequesterParams.hpp"
#include "rti/request/Requester.hpp"

#include "application.hpp"  // Argument parsing

#include <chrono>
#include <thread>

using namespace application;


using namespace dds::core;
using namespace RTI::Service;
using namespace RTI::Service::Admin;

// Timeout configuration
static constexpr unsigned int WAIT_TIMEOUT_SEC_MAX = 10;

// Session names
static const std::string PLATFORM_TO_WAN_TEAM_SESSION = "platform_to_wan_team";
static const std::string WAN_TO_PLATFORM_TEAM_SESSION = "wan_to_platform_team";
static const std::string PLATFORM_TO_WAN_FULL_STATUS_SESSION = "platform_to_wan_full_status";

// Participant and routing service configuration names
static const std::string PLATFORM_WAN_PARTICIPANT = "platform_wan";
static const std::string CONTROL_WAN_PARTICIPANT = "control_wan";

static const std::string RS_CONFIG_NAME_PLATFORM = "platform";
static const std::string RS_CONFIG_NAME_CONTROL = "control";
static const std::string DEFAULT_DOMAIN_ROUTE_NAME = "dr";

// Resource identifier path segments
static const std::string PATH_ROUTING_SERVICES = "/routing_services/";
static const std::string PATH_DOMAIN_ROUTES = "/domain_routes/";
static const std::string PATH_SESSIONS = "/sessions/";
static const std::string PATH_STATE = "/state";
static const std::string PATH_PARTICIPANTS = "/participants/";

// XML request segments for team update
static const std::string XML_STR_PREFIX = "str://";
static const std::string XML_PARTICIPANT_START = 
    "\"<participant><domain_participant_qos><partition><name><element>";
static const std::string XML_PARTICIPANT_END = 
    "</element></name></partition></domain_participant_qos></participant>\"";


static void send_session_update(
        rti::request::Requester<
                RTI::Service::Admin::CommandRequest,
                RTI::Service::Admin::CommandReply> &requester,
        ApplicationArguments args,
        std::string session_name,
        std::string routing_service_config_name)
{
    try {
        /*
         * Setup command
         */
        CommandRequest request;

        std::string resource_identifier = 
                  PATH_ROUTING_SERVICES + 
                  routing_service_config_name +
                  PATH_DOMAIN_ROUTES + 
                  DEFAULT_DOMAIN_ROUTE_NAME + 
                  PATH_SESSIONS + 
                  session_name + 
                  PATH_STATE;

        // Build Message
        request.action(CommandActionKind::UPDATE_ACTION);
        request.resource_identifier(resource_identifier);
        request.application_name(args.name);

        std::cout << "Sending Remote Admin SESSION UPDATE: \n"
                     "resource_identifier: "
                  << resource_identifier
                  << "\n"
                     "application_name: "
                  << args.name << std::endl;

        if (args.enable_team_comms) {
            // Sets state to Enabled
            dds::topic::topic_type_support<EntityState>::to_cdr_buffer(
                    reinterpret_cast<std::vector<char> &>(request.octet_body()),
                    EntityState(EntityStateKind::ENABLED));
            std::cout << "Enabling Session" << std::endl;
        } else {
            // Sets state to Disabled
            dds::topic::topic_type_support<EntityState>::to_cdr_buffer(
                    reinterpret_cast<std::vector<char> &>(request.octet_body()),
                    EntityState(EntityStateKind::DISABLED));
            std::cout << "Disabling Session" << std::endl;
        }

        /*
         * Send Message
         */
        requester.send_request(request);
        auto replies =
                requester.receive_replies(Duration(WAIT_TIMEOUT_SEC_MAX));
        if (replies.length() == 0) {
            throw dds::core::Error("No reply received within timeout");
        }
        CommandReply reply = replies[0];
        if (reply.retcode() == CommandReplyRetcode::OK_RETCODE) {
            std::cout << "Command returned: " << reply.string_body()
                      << std::endl;
        } else {
            std::cout << "Unsuccessful command returned value "
                      << reply.retcode() << "." << std::endl;
            throw dds::core::Error("Error in replier");
        }
    } catch (const std::exception &ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
        return;
    }
}

static void send_team_update(
        rti::request::Requester<
                RTI::Service::Admin::CommandRequest,
                RTI::Service::Admin::CommandReply> &requester,
        ApplicationArguments args,
        std::string routing_service_config_name)
{
    try {
        /*
         * Setup command
         */
        CommandRequest request;

        // Select participant name based on node type
        std::string participant_name = (args.node_type == "control") 
                                       ? CONTROL_WAN_PARTICIPANT 
                                       : PLATFORM_WAN_PARTICIPANT;

        // Configuration name is from the <routing_service name="..."> in
        // routing_service_config.xml
        std::string resource_identifier = 
                PATH_ROUTING_SERVICES
                + routing_service_config_name 
                + PATH_DOMAIN_ROUTES
                + DEFAULT_DOMAIN_ROUTE_NAME 
                + PATH_PARTICIPANTS
                + participant_name;

        std::string string_body = XML_STR_PREFIX + XML_PARTICIPANT_START
                + args.team + XML_PARTICIPANT_END;

        std::cout << "Sending Remote TEAM UPDATE: \n"
                     "resource_identifier: "
                  << resource_identifier
                  << "\n"
                     "body_text: "
                  << string_body
                  << "\n"
                     "application_name: "
                  << args.name << std::endl;

        // Build Message
        request.action(CommandActionKind::UPDATE_ACTION);
        request.string_body(string_body);
        request.resource_identifier(resource_identifier);
        request.application_name(args.name);

        // Send Message
        requester.send_request(request);
        auto replies =
                requester.receive_replies(Duration(WAIT_TIMEOUT_SEC_MAX));
        if (replies.length() == 0) {
            throw dds::core::Error("No reply received within timeout");
        }
        CommandReply reply = replies[0];
        if (reply.retcode() == CommandReplyRetcode::OK_RETCODE) {
            std::cout << "Command returned: " << reply.string_body()
                      << std::endl;
        } else {
            std::cout << "Unsuccessful command returned value "
                      << reply.retcode() << "." << std::endl;
            throw dds::core::Error("Error in replier");
        }
    } catch (const std::exception &ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
        return;
    }
}

int main(int argc, char *argv[])
{
    try {
        // Parse arguments and handle control-C
        auto arguments = parse_arguments(argc, argv);
        if (arguments.parse_result == ParseReturn::exit) {
            return EXIT_SUCCESS;
        } else if (arguments.parse_result == ParseReturn::failure) {
            return EXIT_FAILURE;
        }
        setup_signal_handlers();

        // QoS provider will use NDDS_QOS_PROFILES environment variable
        // which should be set by send_remote_cmd.sh wrapper or manually
        dds::core::QosProvider qos_provider = dds::core::QosProvider::Default();

        // Create a DomainParticipant with the custom QOS
        dds::domain::DomainParticipant participant(arguments.domain_id);

        // create requester params
        rti::request::RequesterParams requester_params(participant);
        requester_params.request_topic_name(COMMAND_REQUEST_TOPIC_NAME);
        requester_params.reply_topic_name(COMMAND_REPLY_TOPIC_NAME);

        // Set QOS
        requester_params.datareader_qos(
                qos_provider.datareader_qos(arguments.qos_profile));
        requester_params.datawriter_qos(
                qos_provider.datawriter_qos(arguments.qos_profile));

        rti::request::Requester<
                RTI::Service::Admin::CommandRequest,
                RTI::Service::Admin::CommandReply>
                requester(requester_params);

        // Wait for Routing Service Discovery
        dds::core::status::PublicationMatchedStatus matched_status;
        unsigned int wait_count = 0;

        std::cout << "Waiting for a matching replier..." << std::endl;
        while (matched_status.current_count() < 1
               && wait_count < WAIT_TIMEOUT_SEC_MAX) {
            matched_status =
                    requester.request_datawriter().publication_matched_status();
            wait_count++;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        if (matched_status.current_count() < 1) {
            throw dds::core::Error("No matching replier found.");
        }


        if (arguments.update_enable_team_comms) {
            // Enable or disable both TEAM sessions based on --enable-team-comms flag
            send_session_update(
                    requester,
                    arguments,
                    PLATFORM_TO_WAN_TEAM_SESSION,
                    RS_CONFIG_NAME_PLATFORM);
            send_session_update(
                    requester,
                    arguments,
                    WAN_TO_PLATFORM_TEAM_SESSION,
                    RS_CONFIG_NAME_PLATFORM);
        }

        if (arguments.update_enable_full_status) {
            // Enable or disable full platform status session
            // Only applicable to platform nodes - updates platform side only
            send_session_update(
                    requester,
                    arguments,
                    PLATFORM_TO_WAN_FULL_STATUS_SESSION,
                    RS_CONFIG_NAME_PLATFORM);
        }


        if (arguments.update_team) {
            // Select config name based on node type
            std::string config_name = (arguments.node_type == "control") 
                                      ? RS_CONFIG_NAME_CONTROL 
                                      : RS_CONFIG_NAME_PLATFORM;
            send_team_update(requester, arguments, config_name);
        }

    } catch (const std::exception &ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}
