

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ServiceAdmin.idl
using RTI Code Generator (rtiddsgen) version 4.3.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef ServiceAdminPlugin_1325755560_h
#define ServiceAdminPlugin_1325755560_h

#include "ServiceAdmin.hpp"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#include "ServiceCommonPlugin.hpp"

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

namespace RTI {
    namespace Service {
        namespace Admin {

            #define EntityNamePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define EntityNamePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define EntityNamePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define EntityNamePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define EntityNamePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern EntityName*
            EntityNamePluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern EntityName*
            EntityNamePluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern EntityName*
            EntityNamePluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            EntityNamePluginSupport_copy_data(
                EntityName *out,
                const EntityName *in);

            NDDSUSERDllExport extern void 
            EntityNamePluginSupport_destroy_data_w_params(
                EntityName *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            EntityNamePluginSupport_destroy_data_ex(
                EntityName *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            EntityNamePluginSupport_destroy_data(
                EntityName *sample);

            NDDSUSERDllExport extern void 
            EntityNamePluginSupport_print_data(
                const EntityName *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            EntityNamePlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                EntityName *out,
                const EntityName *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern unsigned int 
            EntityNamePlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            EntityNamePlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            EntityNamePlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            EntityNamePlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            #define ResourceIdentifierPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define ResourceIdentifierPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define ResourceIdentifierPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define ResourceIdentifierPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define ResourceIdentifierPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern ResourceIdentifier*
            ResourceIdentifierPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern ResourceIdentifier*
            ResourceIdentifierPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern ResourceIdentifier*
            ResourceIdentifierPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            ResourceIdentifierPluginSupport_copy_data(
                ResourceIdentifier *out,
                const ResourceIdentifier *in);

            NDDSUSERDllExport extern void 
            ResourceIdentifierPluginSupport_destroy_data_w_params(
                ResourceIdentifier *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            ResourceIdentifierPluginSupport_destroy_data_ex(
                ResourceIdentifier *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            ResourceIdentifierPluginSupport_destroy_data(
                ResourceIdentifier *sample);

            NDDSUSERDllExport extern void 
            ResourceIdentifierPluginSupport_print_data(
                const ResourceIdentifier *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            ResourceIdentifierPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                ResourceIdentifier *out,
                const ResourceIdentifier *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern unsigned int 
            ResourceIdentifierPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            ResourceIdentifierPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            ResourceIdentifierPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            ResourceIdentifierPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            #define StringBodyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define StringBodyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define StringBodyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define StringBodyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define StringBodyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern StringBody*
            StringBodyPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern StringBody*
            StringBodyPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern StringBody*
            StringBodyPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            StringBodyPluginSupport_copy_data(
                StringBody *out,
                const StringBody *in);

            NDDSUSERDllExport extern void 
            StringBodyPluginSupport_destroy_data_w_params(
                StringBody *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            StringBodyPluginSupport_destroy_data_ex(
                StringBody *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            StringBodyPluginSupport_destroy_data(
                StringBody *sample);

            NDDSUSERDllExport extern void 
            StringBodyPluginSupport_print_data(
                const StringBody *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            StringBodyPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                StringBody *out,
                const StringBody *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern unsigned int 
            StringBodyPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            StringBodyPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            StringBodyPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            StringBodyPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            #define OctetBodyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define OctetBodyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define OctetBodyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define OctetBodyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define OctetBodyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern OctetBody*
            OctetBodyPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern OctetBody*
            OctetBodyPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern OctetBody*
            OctetBodyPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            OctetBodyPluginSupport_copy_data(
                OctetBody *out,
                const OctetBody *in);

            NDDSUSERDllExport extern void 
            OctetBodyPluginSupport_destroy_data_w_params(
                OctetBody *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            OctetBodyPluginSupport_destroy_data_ex(
                OctetBody *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            OctetBodyPluginSupport_destroy_data(
                OctetBody *sample);

            NDDSUSERDllExport extern void 
            OctetBodyPluginSupport_print_data(
                const OctetBody *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            OctetBodyPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                OctetBody *out,
                const OctetBody *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern unsigned int 
            OctetBodyPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            OctetBodyPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            OctetBodyPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            OctetBodyPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern unsigned int 
            CommandActionKindPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern unsigned int 
            CommandActionKindPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            CommandActionKindPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* ----------------------------------------------------------------------------
            Support functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern void
            CommandActionKindPluginSupport_print_data(
                const CommandActionKind *sample,
                const char *desc,
                unsigned int indent_level);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern unsigned int 
            CommandReplyRetcodePlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern unsigned int 
            CommandReplyRetcodePlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            CommandReplyRetcodePlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* ----------------------------------------------------------------------------
            Support functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern void
            CommandReplyRetcodePluginSupport_print_data(
                const CommandReplyRetcode *sample,
                const char *desc,
                unsigned int indent_level);

            /* The type used to store keys for instances of type struct
            * AnotherSimple.
            *
            * By default, this type is struct CommandRequest
            * itself. However, if for some reason this choice is not practical for your
            * system (e.g. if sizeof(struct CommandRequest)
            * is very large), you may redefine this typedef in terms of another type of
            * your choosing. HOWEVER, if you define the KeyHolder type to be something
            * other than struct AnotherSimple, the
            * following restriction applies: the key of struct
            * CommandRequest must consist of a
            * single field of your redefined KeyHolder type and that field must be the
            * first field in struct CommandRequest.
            */
            typedef class CommandRequest CommandRequestKeyHolder;

            #define CommandRequestPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define CommandRequestPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define CommandRequestPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define CommandRequestPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
            #define CommandRequestPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

            #define CommandRequestPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define CommandRequestPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern CommandRequest*
            CommandRequestPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern CommandRequest*
            CommandRequestPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern CommandRequest*
            CommandRequestPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            CommandRequestPluginSupport_copy_data(
                CommandRequest *out,
                const CommandRequest *in);

            NDDSUSERDllExport extern void 
            CommandRequestPluginSupport_destroy_data_w_params(
                CommandRequest *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            CommandRequestPluginSupport_destroy_data_ex(
                CommandRequest *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            CommandRequestPluginSupport_destroy_data(
                CommandRequest *sample);

            NDDSUSERDllExport extern void 
            CommandRequestPluginSupport_print_data(
                const CommandRequest *sample,
                const char *desc,
                unsigned int indent);

            NDDSUSERDllExport extern CommandRequest*
            CommandRequestPluginSupport_create_key_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern CommandRequest*
            CommandRequestPluginSupport_create_key(void);

            NDDSUSERDllExport extern void 
            CommandRequestPluginSupport_destroy_key_ex(
                CommandRequestKeyHolder *key,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            CommandRequestPluginSupport_destroy_key(
                CommandRequestKeyHolder *key);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern PRESTypePluginParticipantData 
            CommandRequestPlugin_on_participant_attached(
                void *registration_data, 
                const struct PRESTypePluginParticipantInfo *participant_info,
                RTIBool top_level_registration, 
                void *container_plugin_context,
                RTICdrTypeCode *typeCode);

            NDDSUSERDllExport extern void 
            CommandRequestPlugin_on_participant_detached(
                PRESTypePluginParticipantData participant_data);

            NDDSUSERDllExport extern PRESTypePluginEndpointData 
            CommandRequestPlugin_on_endpoint_attached(
                PRESTypePluginParticipantData participant_data,
                const struct PRESTypePluginEndpointInfo *endpoint_info,
                RTIBool top_level_registration, 
                void *container_plugin_context);

            NDDSUSERDllExport extern void 
            CommandRequestPlugin_on_endpoint_detached(
                PRESTypePluginEndpointData endpoint_data);

            NDDSUSERDllExport extern void    
            CommandRequestPlugin_return_sample(
                PRESTypePluginEndpointData endpoint_data,
                CommandRequest *sample,
                void *handle);    

            NDDSUSERDllExport extern RTIBool 
            CommandRequestPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                CommandRequest *out,
                const CommandRequest *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            CommandRequestPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const CommandRequest *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            CommandRequestPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                CommandRequest **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            CommandRequestPlugin_deserialize_from_cdr_buffer(
                CommandRequest *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            CommandRequestPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            CommandRequestPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            CommandRequestPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            CommandRequestPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            CommandRequestPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                CommandRequest ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool 
            CommandRequestPlugin_instance_to_key(
                PRESTypePluginEndpointData endpoint_data,
                CommandRequestKeyHolder *key, 
                const CommandRequest *instance);

            NDDSUSERDllExport extern RTIBool 
            CommandRequestPlugin_key_to_instance(
                PRESTypePluginEndpointData endpoint_data,
                CommandRequest *instance, 
                const CommandRequestKeyHolder *key);

            NDDSUSERDllExport extern RTIBool 
            CommandRequestPlugin_serialized_sample_to_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                struct RTICdrStream *cdrStream, 
                DDS_KeyHash_t *keyhash,
                RTIBool deserialize_encapsulation,
                void *endpoint_plugin_qos); 

            /* Plugin Functions */
            NDDSUSERDllExport extern struct PRESTypePlugin*
            CommandRequestPlugin_new(void);

            NDDSUSERDllExport extern void
            CommandRequestPlugin_delete(struct PRESTypePlugin *);

            #define CommandReplyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define CommandReplyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define CommandReplyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define CommandReplyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define CommandReplyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern CommandReply*
            CommandReplyPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern CommandReply*
            CommandReplyPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern CommandReply*
            CommandReplyPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            CommandReplyPluginSupport_copy_data(
                CommandReply *out,
                const CommandReply *in);

            NDDSUSERDllExport extern void 
            CommandReplyPluginSupport_destroy_data_w_params(
                CommandReply *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            CommandReplyPluginSupport_destroy_data_ex(
                CommandReply *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            CommandReplyPluginSupport_destroy_data(
                CommandReply *sample);

            NDDSUSERDllExport extern void 
            CommandReplyPluginSupport_print_data(
                const CommandReply *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern PRESTypePluginParticipantData 
            CommandReplyPlugin_on_participant_attached(
                void *registration_data, 
                const struct PRESTypePluginParticipantInfo *participant_info,
                RTIBool top_level_registration, 
                void *container_plugin_context,
                RTICdrTypeCode *typeCode);

            NDDSUSERDllExport extern void 
            CommandReplyPlugin_on_participant_detached(
                PRESTypePluginParticipantData participant_data);

            NDDSUSERDllExport extern PRESTypePluginEndpointData 
            CommandReplyPlugin_on_endpoint_attached(
                PRESTypePluginParticipantData participant_data,
                const struct PRESTypePluginEndpointInfo *endpoint_info,
                RTIBool top_level_registration, 
                void *container_plugin_context);

            NDDSUSERDllExport extern void 
            CommandReplyPlugin_on_endpoint_detached(
                PRESTypePluginEndpointData endpoint_data);

            NDDSUSERDllExport extern void    
            CommandReplyPlugin_return_sample(
                PRESTypePluginEndpointData endpoint_data,
                CommandReply *sample,
                void *handle);    

            NDDSUSERDllExport extern RTIBool 
            CommandReplyPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                CommandReply *out,
                const CommandReply *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            CommandReplyPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const CommandReply *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            CommandReplyPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                CommandReply **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            CommandReplyPlugin_deserialize_from_cdr_buffer(
                CommandReply *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            CommandReplyPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            CommandReplyPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            CommandReplyPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            CommandReplyPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            CommandReplyPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                CommandReply ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            /* Plugin Functions */
            NDDSUSERDllExport extern struct PRESTypePlugin*
            CommandReplyPlugin_new(void);

            NDDSUSERDllExport extern void
            CommandReplyPlugin_delete(struct PRESTypePlugin *);

        } /* namespace Admin  */
    } /* namespace Service  */
} /* namespace RTI  */

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* ServiceAdminPlugin_1325755560_h */

