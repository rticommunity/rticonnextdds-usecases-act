

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ServiceCommon.idl
using RTI Code Generator (rtiddsgen) version 4.3.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef ServiceCommonPlugin_1902811798_h
#define ServiceCommonPlugin_1902811798_h

#include "ServiceCommon.hpp"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

namespace RTI {
    namespace Service {

        #define BoundedStringPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

        #define BoundedStringPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
        #define BoundedStringPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

        #define BoundedStringPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
        #define BoundedStringPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

        /* --------------------------------------------------------------------------------------
        Support functions:
        * -------------------------------------------------------------------------------------- */

        NDDSUSERDllExport extern BoundedString*
        BoundedStringPluginSupport_create_data_w_params(
            const struct DDS_TypeAllocationParams_t * alloc_params);

        NDDSUSERDllExport extern BoundedString*
        BoundedStringPluginSupport_create_data_ex(RTIBool allocate_pointers);

        NDDSUSERDllExport extern BoundedString*
        BoundedStringPluginSupport_create_data(void);

        NDDSUSERDllExport extern RTIBool 
        BoundedStringPluginSupport_copy_data(
            BoundedString *out,
            const BoundedString *in);

        NDDSUSERDllExport extern void 
        BoundedStringPluginSupport_destroy_data_w_params(
            BoundedString *sample,
            const struct DDS_TypeDeallocationParams_t * dealloc_params);

        NDDSUSERDllExport extern void 
        BoundedStringPluginSupport_destroy_data_ex(
            BoundedString *sample,RTIBool deallocate_pointers);

        NDDSUSERDllExport extern void 
        BoundedStringPluginSupport_destroy_data(
            BoundedString *sample);

        NDDSUSERDllExport extern void 
        BoundedStringPluginSupport_print_data(
            const BoundedString *sample,
            const char *desc,
            unsigned int indent);

        /* ----------------------------------------------------------------------------
        Callback functions:
        * ---------------------------------------------------------------------------- */

        NDDSUSERDllExport extern RTIBool 
        BoundedStringPlugin_copy_sample(
            PRESTypePluginEndpointData endpoint_data,
            BoundedString *out,
            const BoundedString *in);

        /* ----------------------------------------------------------------------------
        (De)Serialize functions:
        * ------------------------------------------------------------------------- */

        NDDSUSERDllExport extern unsigned int 
        BoundedStringPlugin_get_serialized_sample_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        /* --------------------------------------------------------------------------------------
        Key Management functions:
        * -------------------------------------------------------------------------------------- */
        NDDSUSERDllExport extern PRESTypePluginKeyKind 
        BoundedStringPlugin_get_key_kind(void);

        NDDSUSERDllExport extern unsigned int 
        BoundedStringPlugin_get_serialized_key_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern unsigned int 
        BoundedStringPlugin_get_serialized_key_max_size_for_keyhash(
            PRESTypePluginEndpointData endpoint_data,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        #define FilePathPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

        #define FilePathPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
        #define FilePathPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

        #define FilePathPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
        #define FilePathPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

        /* --------------------------------------------------------------------------------------
        Support functions:
        * -------------------------------------------------------------------------------------- */

        NDDSUSERDllExport extern FilePath*
        FilePathPluginSupport_create_data_w_params(
            const struct DDS_TypeAllocationParams_t * alloc_params);

        NDDSUSERDllExport extern FilePath*
        FilePathPluginSupport_create_data_ex(RTIBool allocate_pointers);

        NDDSUSERDllExport extern FilePath*
        FilePathPluginSupport_create_data(void);

        NDDSUSERDllExport extern RTIBool 
        FilePathPluginSupport_copy_data(
            FilePath *out,
            const FilePath *in);

        NDDSUSERDllExport extern void 
        FilePathPluginSupport_destroy_data_w_params(
            FilePath *sample,
            const struct DDS_TypeDeallocationParams_t * dealloc_params);

        NDDSUSERDllExport extern void 
        FilePathPluginSupport_destroy_data_ex(
            FilePath *sample,RTIBool deallocate_pointers);

        NDDSUSERDllExport extern void 
        FilePathPluginSupport_destroy_data(
            FilePath *sample);

        NDDSUSERDllExport extern void 
        FilePathPluginSupport_print_data(
            const FilePath *sample,
            const char *desc,
            unsigned int indent);

        /* ----------------------------------------------------------------------------
        Callback functions:
        * ---------------------------------------------------------------------------- */

        NDDSUSERDllExport extern RTIBool 
        FilePathPlugin_copy_sample(
            PRESTypePluginEndpointData endpoint_data,
            FilePath *out,
            const FilePath *in);

        /* ----------------------------------------------------------------------------
        (De)Serialize functions:
        * ------------------------------------------------------------------------- */

        NDDSUSERDllExport extern unsigned int 
        FilePathPlugin_get_serialized_sample_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        /* --------------------------------------------------------------------------------------
        Key Management functions:
        * -------------------------------------------------------------------------------------- */
        NDDSUSERDllExport extern PRESTypePluginKeyKind 
        FilePathPlugin_get_key_kind(void);

        NDDSUSERDllExport extern unsigned int 
        FilePathPlugin_get_serialized_key_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern unsigned int 
        FilePathPlugin_get_serialized_key_max_size_for_keyhash(
            PRESTypePluginEndpointData endpoint_data,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        #define ResourceIdPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

        #define ResourceIdPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
        #define ResourceIdPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

        #define ResourceIdPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
        #define ResourceIdPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

        /* --------------------------------------------------------------------------------------
        Support functions:
        * -------------------------------------------------------------------------------------- */

        NDDSUSERDllExport extern ResourceId*
        ResourceIdPluginSupport_create_data_w_params(
            const struct DDS_TypeAllocationParams_t * alloc_params);

        NDDSUSERDllExport extern ResourceId*
        ResourceIdPluginSupport_create_data_ex(RTIBool allocate_pointers);

        NDDSUSERDllExport extern ResourceId*
        ResourceIdPluginSupport_create_data(void);

        NDDSUSERDllExport extern RTIBool 
        ResourceIdPluginSupport_copy_data(
            ResourceId *out,
            const ResourceId *in);

        NDDSUSERDllExport extern void 
        ResourceIdPluginSupport_destroy_data_w_params(
            ResourceId *sample,
            const struct DDS_TypeDeallocationParams_t * dealloc_params);

        NDDSUSERDllExport extern void 
        ResourceIdPluginSupport_destroy_data_ex(
            ResourceId *sample,RTIBool deallocate_pointers);

        NDDSUSERDllExport extern void 
        ResourceIdPluginSupport_destroy_data(
            ResourceId *sample);

        NDDSUSERDllExport extern void 
        ResourceIdPluginSupport_print_data(
            const ResourceId *sample,
            const char *desc,
            unsigned int indent);

        /* ----------------------------------------------------------------------------
        Callback functions:
        * ---------------------------------------------------------------------------- */

        NDDSUSERDllExport extern RTIBool 
        ResourceIdPlugin_copy_sample(
            PRESTypePluginEndpointData endpoint_data,
            ResourceId *out,
            const ResourceId *in);

        /* ----------------------------------------------------------------------------
        (De)Serialize functions:
        * ------------------------------------------------------------------------- */

        NDDSUSERDllExport extern unsigned int 
        ResourceIdPlugin_get_serialized_sample_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        /* --------------------------------------------------------------------------------------
        Key Management functions:
        * -------------------------------------------------------------------------------------- */
        NDDSUSERDllExport extern PRESTypePluginKeyKind 
        ResourceIdPlugin_get_key_kind(void);

        NDDSUSERDllExport extern unsigned int 
        ResourceIdPlugin_get_serialized_key_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern unsigned int 
        ResourceIdPlugin_get_serialized_key_max_size_for_keyhash(
            PRESTypePluginEndpointData endpoint_data,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        #define XmlStringPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

        #define XmlStringPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
        #define XmlStringPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

        #define XmlStringPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
        #define XmlStringPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

        /* --------------------------------------------------------------------------------------
        Support functions:
        * -------------------------------------------------------------------------------------- */

        NDDSUSERDllExport extern XmlString*
        XmlStringPluginSupport_create_data_w_params(
            const struct DDS_TypeAllocationParams_t * alloc_params);

        NDDSUSERDllExport extern XmlString*
        XmlStringPluginSupport_create_data_ex(RTIBool allocate_pointers);

        NDDSUSERDllExport extern XmlString*
        XmlStringPluginSupport_create_data(void);

        NDDSUSERDllExport extern RTIBool 
        XmlStringPluginSupport_copy_data(
            XmlString *out,
            const XmlString *in);

        NDDSUSERDllExport extern void 
        XmlStringPluginSupport_destroy_data_w_params(
            XmlString *sample,
            const struct DDS_TypeDeallocationParams_t * dealloc_params);

        NDDSUSERDllExport extern void 
        XmlStringPluginSupport_destroy_data_ex(
            XmlString *sample,RTIBool deallocate_pointers);

        NDDSUSERDllExport extern void 
        XmlStringPluginSupport_destroy_data(
            XmlString *sample);

        NDDSUSERDllExport extern void 
        XmlStringPluginSupport_print_data(
            const XmlString *sample,
            const char *desc,
            unsigned int indent);

        /* ----------------------------------------------------------------------------
        Callback functions:
        * ---------------------------------------------------------------------------- */

        NDDSUSERDllExport extern RTIBool 
        XmlStringPlugin_copy_sample(
            PRESTypePluginEndpointData endpoint_data,
            XmlString *out,
            const XmlString *in);

        /* ----------------------------------------------------------------------------
        (De)Serialize functions:
        * ------------------------------------------------------------------------- */

        NDDSUSERDllExport extern unsigned int 
        XmlStringPlugin_get_serialized_sample_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        /* --------------------------------------------------------------------------------------
        Key Management functions:
        * -------------------------------------------------------------------------------------- */
        NDDSUSERDllExport extern PRESTypePluginKeyKind 
        XmlStringPlugin_get_key_kind(void);

        NDDSUSERDllExport extern unsigned int 
        XmlStringPlugin_get_serialized_key_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern unsigned int 
        XmlStringPlugin_get_serialized_key_max_size_for_keyhash(
            PRESTypePluginEndpointData endpoint_data,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        /* ----------------------------------------------------------------------------
        (De)Serialize functions:
        * ------------------------------------------------------------------------- */

        NDDSUSERDllExport extern unsigned int 
        EntityStateKindPlugin_get_serialized_sample_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        /* --------------------------------------------------------------------------------------
        Key Management functions:
        * -------------------------------------------------------------------------------------- */

        NDDSUSERDllExport extern unsigned int 
        EntityStateKindPlugin_get_serialized_key_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern unsigned int 
        EntityStateKindPlugin_get_serialized_key_max_size_for_keyhash(
            PRESTypePluginEndpointData endpoint_data,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        /* ----------------------------------------------------------------------------
        Support functions:
        * ---------------------------------------------------------------------------- */

        NDDSUSERDllExport extern void
        EntityStateKindPluginSupport_print_data(
            const EntityStateKind *sample,
            const char *desc,
            unsigned int indent_level);

        #define EntityStatePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

        #define EntityStatePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
        #define EntityStatePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

        #define EntityStatePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
        #define EntityStatePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

        /* --------------------------------------------------------------------------------------
        Support functions:
        * -------------------------------------------------------------------------------------- */

        NDDSUSERDllExport extern EntityState*
        EntityStatePluginSupport_create_data_w_params(
            const struct DDS_TypeAllocationParams_t * alloc_params);

        NDDSUSERDllExport extern EntityState*
        EntityStatePluginSupport_create_data_ex(RTIBool allocate_pointers);

        NDDSUSERDllExport extern EntityState*
        EntityStatePluginSupport_create_data(void);

        NDDSUSERDllExport extern RTIBool 
        EntityStatePluginSupport_copy_data(
            EntityState *out,
            const EntityState *in);

        NDDSUSERDllExport extern void 
        EntityStatePluginSupport_destroy_data_w_params(
            EntityState *sample,
            const struct DDS_TypeDeallocationParams_t * dealloc_params);

        NDDSUSERDllExport extern void 
        EntityStatePluginSupport_destroy_data_ex(
            EntityState *sample,RTIBool deallocate_pointers);

        NDDSUSERDllExport extern void 
        EntityStatePluginSupport_destroy_data(
            EntityState *sample);

        NDDSUSERDllExport extern void 
        EntityStatePluginSupport_print_data(
            const EntityState *sample,
            const char *desc,
            unsigned int indent);

        /* ----------------------------------------------------------------------------
        Callback functions:
        * ---------------------------------------------------------------------------- */

        NDDSUSERDllExport extern PRESTypePluginParticipantData 
        EntityStatePlugin_on_participant_attached(
            void *registration_data, 
            const struct PRESTypePluginParticipantInfo *participant_info,
            RTIBool top_level_registration, 
            void *container_plugin_context,
            RTICdrTypeCode *typeCode);

        NDDSUSERDllExport extern void 
        EntityStatePlugin_on_participant_detached(
            PRESTypePluginParticipantData participant_data);

        NDDSUSERDllExport extern PRESTypePluginEndpointData 
        EntityStatePlugin_on_endpoint_attached(
            PRESTypePluginParticipantData participant_data,
            const struct PRESTypePluginEndpointInfo *endpoint_info,
            RTIBool top_level_registration, 
            void *container_plugin_context);

        NDDSUSERDllExport extern void 
        EntityStatePlugin_on_endpoint_detached(
            PRESTypePluginEndpointData endpoint_data);

        NDDSUSERDllExport extern void    
        EntityStatePlugin_return_sample(
            PRESTypePluginEndpointData endpoint_data,
            EntityState *sample,
            void *handle);    

        NDDSUSERDllExport extern RTIBool 
        EntityStatePlugin_copy_sample(
            PRESTypePluginEndpointData endpoint_data,
            EntityState *out,
            const EntityState *in);

        /* ----------------------------------------------------------------------------
        (De)Serialize functions:
        * ------------------------------------------------------------------------- */

        NDDSUSERDllExport extern RTIBool
        EntityStatePlugin_serialize_to_cdr_buffer(
            char * buffer,
            unsigned int * length,
            const EntityState *sample,
            ::dds::core::policy::DataRepresentationId representation
            = ::dds::core::policy::DataRepresentation::xcdr()); 

        NDDSUSERDllExport extern RTIBool 
        EntityStatePlugin_deserialize(
            PRESTypePluginEndpointData endpoint_data,
            EntityState **sample, 
            RTIBool * drop_sample,
            struct RTICdrStream *cdrStream,
            RTIBool deserialize_encapsulation,
            RTIBool deserialize_sample, 
            void *endpoint_plugin_qos);

        NDDSUSERDllExport extern RTIBool
        EntityStatePlugin_deserialize_from_cdr_buffer(
            EntityState *sample,
            const char * buffer,
            unsigned int length);    

        NDDSUSERDllExport extern unsigned int 
        EntityStatePlugin_get_serialized_sample_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        /* --------------------------------------------------------------------------------------
        Key Management functions:
        * -------------------------------------------------------------------------------------- */
        NDDSUSERDllExport extern PRESTypePluginKeyKind 
        EntityStatePlugin_get_key_kind(void);

        NDDSUSERDllExport extern unsigned int 
        EntityStatePlugin_get_serialized_key_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern unsigned int 
        EntityStatePlugin_get_serialized_key_max_size_for_keyhash(
            PRESTypePluginEndpointData endpoint_data,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern RTIBool 
        EntityStatePlugin_deserialize_key(
            PRESTypePluginEndpointData endpoint_data,
            EntityState ** sample,
            RTIBool * drop_sample,
            struct RTICdrStream *cdrStream,
            RTIBool deserialize_encapsulation,
            RTIBool deserialize_key,
            void *endpoint_plugin_qos);

        /* Plugin Functions */
        NDDSUSERDllExport extern struct PRESTypePlugin*
        EntityStatePlugin_new(void);

        NDDSUSERDllExport extern void
        EntityStatePlugin_delete(struct PRESTypePlugin *);

        #define BuiltinTopicKeyPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

        #define BuiltinTopicKeyPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
        #define BuiltinTopicKeyPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

        #define BuiltinTopicKeyPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
        #define BuiltinTopicKeyPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

        /* --------------------------------------------------------------------------------------
        Support functions:
        * -------------------------------------------------------------------------------------- */

        NDDSUSERDllExport extern BuiltinTopicKey*
        BuiltinTopicKeyPluginSupport_create_data_w_params(
            const struct DDS_TypeAllocationParams_t * alloc_params);

        NDDSUSERDllExport extern BuiltinTopicKey*
        BuiltinTopicKeyPluginSupport_create_data_ex(RTIBool allocate_pointers);

        NDDSUSERDllExport extern BuiltinTopicKey*
        BuiltinTopicKeyPluginSupport_create_data(void);

        NDDSUSERDllExport extern RTIBool 
        BuiltinTopicKeyPluginSupport_copy_data(
            BuiltinTopicKey *out,
            const BuiltinTopicKey *in);

        NDDSUSERDllExport extern void 
        BuiltinTopicKeyPluginSupport_destroy_data_w_params(
            BuiltinTopicKey *sample,
            const struct DDS_TypeDeallocationParams_t * dealloc_params);

        NDDSUSERDllExport extern void 
        BuiltinTopicKeyPluginSupport_destroy_data_ex(
            BuiltinTopicKey *sample,RTIBool deallocate_pointers);

        NDDSUSERDllExport extern void 
        BuiltinTopicKeyPluginSupport_destroy_data(
            BuiltinTopicKey *sample);

        NDDSUSERDllExport extern void 
        BuiltinTopicKeyPluginSupport_print_data(
            const BuiltinTopicKey *sample,
            const char *desc,
            unsigned int indent);

        /* ----------------------------------------------------------------------------
        Callback functions:
        * ---------------------------------------------------------------------------- */

        NDDSUSERDllExport extern RTIBool 
        BuiltinTopicKeyPlugin_copy_sample(
            PRESTypePluginEndpointData endpoint_data,
            BuiltinTopicKey *out,
            const BuiltinTopicKey *in);

        /* ----------------------------------------------------------------------------
        (De)Serialize functions:
        * ------------------------------------------------------------------------- */

        NDDSUSERDllExport extern RTIBool
        BuiltinTopicKeyPlugin_serialize_to_cdr_buffer(
            char * buffer,
            unsigned int * length,
            const BuiltinTopicKey *sample,
            ::dds::core::policy::DataRepresentationId representation
            = ::dds::core::policy::DataRepresentation::xcdr()); 

        NDDSUSERDllExport extern RTIBool 
        BuiltinTopicKeyPlugin_deserialize(
            PRESTypePluginEndpointData endpoint_data,
            BuiltinTopicKey **sample, 
            RTIBool * drop_sample,
            struct RTICdrStream *cdrStream,
            RTIBool deserialize_encapsulation,
            RTIBool deserialize_sample, 
            void *endpoint_plugin_qos);

        NDDSUSERDllExport extern RTIBool
        BuiltinTopicKeyPlugin_deserialize_from_cdr_buffer(
            BuiltinTopicKey *sample,
            const char * buffer,
            unsigned int length);    

        NDDSUSERDllExport extern unsigned int 
        BuiltinTopicKeyPlugin_get_serialized_sample_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        /* --------------------------------------------------------------------------------------
        Key Management functions:
        * -------------------------------------------------------------------------------------- */
        NDDSUSERDllExport extern PRESTypePluginKeyKind 
        BuiltinTopicKeyPlugin_get_key_kind(void);

        NDDSUSERDllExport extern unsigned int 
        BuiltinTopicKeyPlugin_get_serialized_key_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern unsigned int 
        BuiltinTopicKeyPlugin_get_serialized_key_max_size_for_keyhash(
            PRESTypePluginEndpointData endpoint_data,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern RTIBool 
        BuiltinTopicKeyPlugin_deserialize_key(
            PRESTypePluginEndpointData endpoint_data,
            BuiltinTopicKey ** sample,
            RTIBool * drop_sample,
            struct RTICdrStream *cdrStream,
            RTIBool deserialize_encapsulation,
            RTIBool deserialize_key,
            void *endpoint_plugin_qos);

        namespace Monitoring {

            #define ResourceGuidPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define ResourceGuidPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define ResourceGuidPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define ResourceGuidPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define ResourceGuidPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern ResourceGuid*
            ResourceGuidPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern ResourceGuid*
            ResourceGuidPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern ResourceGuid*
            ResourceGuidPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            ResourceGuidPluginSupport_copy_data(
                ResourceGuid *out,
                const ResourceGuid *in);

            NDDSUSERDllExport extern void 
            ResourceGuidPluginSupport_destroy_data_w_params(
                ResourceGuid *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            ResourceGuidPluginSupport_destroy_data_ex(
                ResourceGuid *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            ResourceGuidPluginSupport_destroy_data(
                ResourceGuid *sample);

            NDDSUSERDllExport extern void 
            ResourceGuidPluginSupport_print_data(
                const ResourceGuid *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern PRESTypePluginParticipantData 
            ResourceGuidPlugin_on_participant_attached(
                void *registration_data, 
                const struct PRESTypePluginParticipantInfo *participant_info,
                RTIBool top_level_registration, 
                void *container_plugin_context,
                RTICdrTypeCode *typeCode);

            NDDSUSERDllExport extern void 
            ResourceGuidPlugin_on_participant_detached(
                PRESTypePluginParticipantData participant_data);

            NDDSUSERDllExport extern PRESTypePluginEndpointData 
            ResourceGuidPlugin_on_endpoint_attached(
                PRESTypePluginParticipantData participant_data,
                const struct PRESTypePluginEndpointInfo *endpoint_info,
                RTIBool top_level_registration, 
                void *container_plugin_context);

            NDDSUSERDllExport extern void 
            ResourceGuidPlugin_on_endpoint_detached(
                PRESTypePluginEndpointData endpoint_data);

            NDDSUSERDllExport extern void    
            ResourceGuidPlugin_return_sample(
                PRESTypePluginEndpointData endpoint_data,
                ResourceGuid *sample,
                void *handle);    

            NDDSUSERDllExport extern RTIBool 
            ResourceGuidPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                ResourceGuid *out,
                const ResourceGuid *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            ResourceGuidPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const ResourceGuid *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            ResourceGuidPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                ResourceGuid **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            ResourceGuidPlugin_deserialize_from_cdr_buffer(
                ResourceGuid *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            ResourceGuidPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            ResourceGuidPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            ResourceGuidPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            ResourceGuidPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            ResourceGuidPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                ResourceGuid ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            /* Plugin Functions */
            NDDSUSERDllExport extern struct PRESTypePlugin*
            ResourceGuidPlugin_new(void);

            NDDSUSERDllExport extern void
            ResourceGuidPlugin_delete(struct PRESTypePlugin *);

            /* The type used to store keys for instances of type struct
            * AnotherSimple.
            *
            * By default, this type is struct KeyedResource
            * itself. However, if for some reason this choice is not practical for your
            * system (e.g. if sizeof(struct KeyedResource)
            * is very large), you may redefine this typedef in terms of another type of
            * your choosing. HOWEVER, if you define the KeyHolder type to be something
            * other than struct AnotherSimple, the
            * following restriction applies: the key of struct
            * KeyedResource must consist of a
            * single field of your redefined KeyHolder type and that field must be the
            * first field in struct KeyedResource.
            */
            typedef class KeyedResource KeyedResourceKeyHolder;

            #define KeyedResourcePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define KeyedResourcePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define KeyedResourcePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define KeyedResourcePlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
            #define KeyedResourcePlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

            #define KeyedResourcePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define KeyedResourcePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern KeyedResource*
            KeyedResourcePluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern KeyedResource*
            KeyedResourcePluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern KeyedResource*
            KeyedResourcePluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            KeyedResourcePluginSupport_copy_data(
                KeyedResource *out,
                const KeyedResource *in);

            NDDSUSERDllExport extern void 
            KeyedResourcePluginSupport_destroy_data_w_params(
                KeyedResource *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            KeyedResourcePluginSupport_destroy_data_ex(
                KeyedResource *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            KeyedResourcePluginSupport_destroy_data(
                KeyedResource *sample);

            NDDSUSERDllExport extern void 
            KeyedResourcePluginSupport_print_data(
                const KeyedResource *sample,
                const char *desc,
                unsigned int indent);

            NDDSUSERDllExport extern KeyedResource*
            KeyedResourcePluginSupport_create_key_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern KeyedResource*
            KeyedResourcePluginSupport_create_key(void);

            NDDSUSERDllExport extern void 
            KeyedResourcePluginSupport_destroy_key_ex(
                KeyedResourceKeyHolder *key,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            KeyedResourcePluginSupport_destroy_key(
                KeyedResourceKeyHolder *key);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern PRESTypePluginParticipantData 
            KeyedResourcePlugin_on_participant_attached(
                void *registration_data, 
                const struct PRESTypePluginParticipantInfo *participant_info,
                RTIBool top_level_registration, 
                void *container_plugin_context,
                RTICdrTypeCode *typeCode);

            NDDSUSERDllExport extern void 
            KeyedResourcePlugin_on_participant_detached(
                PRESTypePluginParticipantData participant_data);

            NDDSUSERDllExport extern PRESTypePluginEndpointData 
            KeyedResourcePlugin_on_endpoint_attached(
                PRESTypePluginParticipantData participant_data,
                const struct PRESTypePluginEndpointInfo *endpoint_info,
                RTIBool top_level_registration, 
                void *container_plugin_context);

            NDDSUSERDllExport extern void 
            KeyedResourcePlugin_on_endpoint_detached(
                PRESTypePluginEndpointData endpoint_data);

            NDDSUSERDllExport extern void    
            KeyedResourcePlugin_return_sample(
                PRESTypePluginEndpointData endpoint_data,
                KeyedResource *sample,
                void *handle);    

            NDDSUSERDllExport extern RTIBool 
            KeyedResourcePlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                KeyedResource *out,
                const KeyedResource *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            KeyedResourcePlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const KeyedResource *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            KeyedResourcePlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                KeyedResource **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            KeyedResourcePlugin_deserialize_from_cdr_buffer(
                KeyedResource *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            KeyedResourcePlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            KeyedResourcePlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            KeyedResourcePlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            KeyedResourcePlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            KeyedResourcePlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                KeyedResource ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool 
            KeyedResourcePlugin_instance_to_key(
                PRESTypePluginEndpointData endpoint_data,
                KeyedResourceKeyHolder *key, 
                const KeyedResource *instance);

            NDDSUSERDllExport extern RTIBool 
            KeyedResourcePlugin_key_to_instance(
                PRESTypePluginEndpointData endpoint_data,
                KeyedResource *instance, 
                const KeyedResourceKeyHolder *key);

            NDDSUSERDllExport extern RTIBool 
            KeyedResourcePlugin_serialized_sample_to_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                struct RTICdrStream *cdrStream, 
                DDS_KeyHash_t *keyhash,
                RTIBool deserialize_encapsulation,
                void *endpoint_plugin_qos); 

            /* Plugin Functions */
            NDDSUSERDllExport extern struct PRESTypePlugin*
            KeyedResourcePlugin_new(void);

            NDDSUSERDllExport extern void
            KeyedResourcePlugin_delete(struct PRESTypePlugin *);

            #define StatisticMetricsPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define StatisticMetricsPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define StatisticMetricsPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define StatisticMetricsPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define StatisticMetricsPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern StatisticMetrics*
            StatisticMetricsPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern StatisticMetrics*
            StatisticMetricsPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern StatisticMetrics*
            StatisticMetricsPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            StatisticMetricsPluginSupport_copy_data(
                StatisticMetrics *out,
                const StatisticMetrics *in);

            NDDSUSERDllExport extern void 
            StatisticMetricsPluginSupport_destroy_data_w_params(
                StatisticMetrics *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            StatisticMetricsPluginSupport_destroy_data_ex(
                StatisticMetrics *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            StatisticMetricsPluginSupport_destroy_data(
                StatisticMetrics *sample);

            NDDSUSERDllExport extern void 
            StatisticMetricsPluginSupport_print_data(
                const StatisticMetrics *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            StatisticMetricsPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                StatisticMetrics *out,
                const StatisticMetrics *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            StatisticMetricsPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const StatisticMetrics *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            StatisticMetricsPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                StatisticMetrics **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            StatisticMetricsPlugin_deserialize_from_cdr_buffer(
                StatisticMetrics *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            StatisticMetricsPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            StatisticMetricsPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            StatisticMetricsPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            StatisticMetricsPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            StatisticMetricsPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                StatisticMetrics ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define StatisticVariablePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define StatisticVariablePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define StatisticVariablePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define StatisticVariablePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define StatisticVariablePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern StatisticVariable*
            StatisticVariablePluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern StatisticVariable*
            StatisticVariablePluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern StatisticVariable*
            StatisticVariablePluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            StatisticVariablePluginSupport_copy_data(
                StatisticVariable *out,
                const StatisticVariable *in);

            NDDSUSERDllExport extern void 
            StatisticVariablePluginSupport_destroy_data_w_params(
                StatisticVariable *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            StatisticVariablePluginSupport_destroy_data_ex(
                StatisticVariable *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            StatisticVariablePluginSupport_destroy_data(
                StatisticVariable *sample);

            NDDSUSERDllExport extern void 
            StatisticVariablePluginSupport_print_data(
                const StatisticVariable *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            StatisticVariablePlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                StatisticVariable *out,
                const StatisticVariable *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            StatisticVariablePlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const StatisticVariable *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            StatisticVariablePlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                StatisticVariable **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            StatisticVariablePlugin_deserialize_from_cdr_buffer(
                StatisticVariable *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            StatisticVariablePlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            StatisticVariablePlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            StatisticVariablePlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            StatisticVariablePlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            StatisticVariablePlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                StatisticVariable ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define CountStatusPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define CountStatusPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define CountStatusPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define CountStatusPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define CountStatusPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern CountStatus*
            CountStatusPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern CountStatus*
            CountStatusPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern CountStatus*
            CountStatusPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            CountStatusPluginSupport_copy_data(
                CountStatus *out,
                const CountStatus *in);

            NDDSUSERDllExport extern void 
            CountStatusPluginSupport_destroy_data_w_params(
                CountStatus *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            CountStatusPluginSupport_destroy_data_ex(
                CountStatus *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            CountStatusPluginSupport_destroy_data(
                CountStatus *sample);

            NDDSUSERDllExport extern void 
            CountStatusPluginSupport_print_data(
                const CountStatus *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            CountStatusPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                CountStatus *out,
                const CountStatus *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            CountStatusPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const CountStatus *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            CountStatusPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                CountStatus **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            CountStatusPlugin_deserialize_from_cdr_buffer(
                CountStatus *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            CountStatusPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            CountStatusPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            CountStatusPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            CountStatusPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            CountStatusPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                CountStatus ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define ProcessConfigPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define ProcessConfigPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define ProcessConfigPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define ProcessConfigPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define ProcessConfigPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern ProcessConfig*
            ProcessConfigPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern ProcessConfig*
            ProcessConfigPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern ProcessConfig*
            ProcessConfigPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            ProcessConfigPluginSupport_copy_data(
                ProcessConfig *out,
                const ProcessConfig *in);

            NDDSUSERDllExport extern void 
            ProcessConfigPluginSupport_destroy_data_w_params(
                ProcessConfig *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            ProcessConfigPluginSupport_destroy_data_ex(
                ProcessConfig *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            ProcessConfigPluginSupport_destroy_data(
                ProcessConfig *sample);

            NDDSUSERDllExport extern void 
            ProcessConfigPluginSupport_print_data(
                const ProcessConfig *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            ProcessConfigPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                ProcessConfig *out,
                const ProcessConfig *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            ProcessConfigPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const ProcessConfig *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            ProcessConfigPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                ProcessConfig **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            ProcessConfigPlugin_deserialize_from_cdr_buffer(
                ProcessConfig *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            ProcessConfigPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            ProcessConfigPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            ProcessConfigPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            ProcessConfigPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            ProcessConfigPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                ProcessConfig ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define ProcessPeriodicPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define ProcessPeriodicPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define ProcessPeriodicPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define ProcessPeriodicPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define ProcessPeriodicPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern ProcessPeriodic*
            ProcessPeriodicPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern ProcessPeriodic*
            ProcessPeriodicPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern ProcessPeriodic*
            ProcessPeriodicPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            ProcessPeriodicPluginSupport_copy_data(
                ProcessPeriodic *out,
                const ProcessPeriodic *in);

            NDDSUSERDllExport extern void 
            ProcessPeriodicPluginSupport_destroy_data_w_params(
                ProcessPeriodic *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            ProcessPeriodicPluginSupport_destroy_data_ex(
                ProcessPeriodic *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            ProcessPeriodicPluginSupport_destroy_data(
                ProcessPeriodic *sample);

            NDDSUSERDllExport extern void 
            ProcessPeriodicPluginSupport_print_data(
                const ProcessPeriodic *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            ProcessPeriodicPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                ProcessPeriodic *out,
                const ProcessPeriodic *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            ProcessPeriodicPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const ProcessPeriodic *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            ProcessPeriodicPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                ProcessPeriodic **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            ProcessPeriodicPlugin_deserialize_from_cdr_buffer(
                ProcessPeriodic *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            ProcessPeriodicPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            ProcessPeriodicPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            ProcessPeriodicPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            ProcessPeriodicPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            ProcessPeriodicPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                ProcessPeriodic ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define ThreadPeriodicPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define ThreadPeriodicPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define ThreadPeriodicPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define ThreadPeriodicPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define ThreadPeriodicPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern ThreadPeriodic*
            ThreadPeriodicPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern ThreadPeriodic*
            ThreadPeriodicPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern ThreadPeriodic*
            ThreadPeriodicPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            ThreadPeriodicPluginSupport_copy_data(
                ThreadPeriodic *out,
                const ThreadPeriodic *in);

            NDDSUSERDllExport extern void 
            ThreadPeriodicPluginSupport_destroy_data_w_params(
                ThreadPeriodic *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            ThreadPeriodicPluginSupport_destroy_data_ex(
                ThreadPeriodic *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            ThreadPeriodicPluginSupport_destroy_data(
                ThreadPeriodic *sample);

            NDDSUSERDllExport extern void 
            ThreadPeriodicPluginSupport_print_data(
                const ThreadPeriodic *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            ThreadPeriodicPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                ThreadPeriodic *out,
                const ThreadPeriodic *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            ThreadPeriodicPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const ThreadPeriodic *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            ThreadPeriodicPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                ThreadPeriodic **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            ThreadPeriodicPlugin_deserialize_from_cdr_buffer(
                ThreadPeriodic *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            ThreadPeriodicPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            ThreadPeriodicPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            ThreadPeriodicPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            ThreadPeriodicPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            ThreadPeriodicPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                ThreadPeriodic ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define ThreadPoolPeriodicPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define ThreadPoolPeriodicPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define ThreadPoolPeriodicPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define ThreadPoolPeriodicPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define ThreadPoolPeriodicPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern ThreadPoolPeriodic*
            ThreadPoolPeriodicPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern ThreadPoolPeriodic*
            ThreadPoolPeriodicPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern ThreadPoolPeriodic*
            ThreadPoolPeriodicPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            ThreadPoolPeriodicPluginSupport_copy_data(
                ThreadPoolPeriodic *out,
                const ThreadPoolPeriodic *in);

            NDDSUSERDllExport extern void 
            ThreadPoolPeriodicPluginSupport_destroy_data_w_params(
                ThreadPoolPeriodic *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            ThreadPoolPeriodicPluginSupport_destroy_data_ex(
                ThreadPoolPeriodic *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            ThreadPoolPeriodicPluginSupport_destroy_data(
                ThreadPoolPeriodic *sample);

            NDDSUSERDllExport extern void 
            ThreadPoolPeriodicPluginSupport_print_data(
                const ThreadPoolPeriodic *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            ThreadPoolPeriodicPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                ThreadPoolPeriodic *out,
                const ThreadPoolPeriodic *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            ThreadPoolPeriodicPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const ThreadPoolPeriodic *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            ThreadPoolPeriodicPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                ThreadPoolPeriodic **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            ThreadPoolPeriodicPlugin_deserialize_from_cdr_buffer(
                ThreadPoolPeriodic *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            ThreadPoolPeriodicPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            ThreadPoolPeriodicPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            ThreadPoolPeriodicPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            ThreadPoolPeriodicPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            ThreadPoolPeriodicPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                ThreadPoolPeriodic ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define HostPeriodicPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define HostPeriodicPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define HostPeriodicPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define HostPeriodicPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define HostPeriodicPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern HostPeriodic*
            HostPeriodicPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern HostPeriodic*
            HostPeriodicPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern HostPeriodic*
            HostPeriodicPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            HostPeriodicPluginSupport_copy_data(
                HostPeriodic *out,
                const HostPeriodic *in);

            NDDSUSERDllExport extern void 
            HostPeriodicPluginSupport_destroy_data_w_params(
                HostPeriodic *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            HostPeriodicPluginSupport_destroy_data_ex(
                HostPeriodic *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            HostPeriodicPluginSupport_destroy_data(
                HostPeriodic *sample);

            NDDSUSERDllExport extern void 
            HostPeriodicPluginSupport_print_data(
                const HostPeriodic *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            HostPeriodicPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                HostPeriodic *out,
                const HostPeriodic *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            HostPeriodicPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const HostPeriodic *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            HostPeriodicPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                HostPeriodic **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            HostPeriodicPlugin_deserialize_from_cdr_buffer(
                HostPeriodic *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            HostPeriodicPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            HostPeriodicPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            HostPeriodicPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            HostPeriodicPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            HostPeriodicPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                HostPeriodic ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define HostConfigPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define HostConfigPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define HostConfigPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define HostConfigPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define HostConfigPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern HostConfig*
            HostConfigPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern HostConfig*
            HostConfigPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern HostConfig*
            HostConfigPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            HostConfigPluginSupport_copy_data(
                HostConfig *out,
                const HostConfig *in);

            NDDSUSERDllExport extern void 
            HostConfigPluginSupport_destroy_data_w_params(
                HostConfig *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            HostConfigPluginSupport_destroy_data_ex(
                HostConfig *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            HostConfigPluginSupport_destroy_data(
                HostConfig *sample);

            NDDSUSERDllExport extern void 
            HostConfigPluginSupport_print_data(
                const HostConfig *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            HostConfigPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                HostConfig *out,
                const HostConfig *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            HostConfigPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const HostConfig *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            HostConfigPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                HostConfig **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            HostConfigPlugin_deserialize_from_cdr_buffer(
                HostConfig *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            HostConfigPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            HostConfigPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            HostConfigPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            HostConfigPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            HostConfigPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                HostConfig ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define NetworkPerformancePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define NetworkPerformancePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define NetworkPerformancePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define NetworkPerformancePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define NetworkPerformancePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern NetworkPerformance*
            NetworkPerformancePluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern NetworkPerformance*
            NetworkPerformancePluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern NetworkPerformance*
            NetworkPerformancePluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            NetworkPerformancePluginSupport_copy_data(
                NetworkPerformance *out,
                const NetworkPerformance *in);

            NDDSUSERDllExport extern void 
            NetworkPerformancePluginSupport_destroy_data_w_params(
                NetworkPerformance *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            NetworkPerformancePluginSupport_destroy_data_ex(
                NetworkPerformance *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            NetworkPerformancePluginSupport_destroy_data(
                NetworkPerformance *sample);

            NDDSUSERDllExport extern void 
            NetworkPerformancePluginSupport_print_data(
                const NetworkPerformance *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            NetworkPerformancePlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                NetworkPerformance *out,
                const NetworkPerformance *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            NetworkPerformancePlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const NetworkPerformance *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            NetworkPerformancePlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                NetworkPerformance **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            NetworkPerformancePlugin_deserialize_from_cdr_buffer(
                NetworkPerformance *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            NetworkPerformancePlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            NetworkPerformancePlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            NetworkPerformancePlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            NetworkPerformancePlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            NetworkPerformancePlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                NetworkPerformance ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define EntityConfigPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define EntityConfigPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define EntityConfigPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define EntityConfigPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define EntityConfigPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern EntityConfig*
            EntityConfigPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern EntityConfig*
            EntityConfigPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern EntityConfig*
            EntityConfigPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            EntityConfigPluginSupport_copy_data(
                EntityConfig *out,
                const EntityConfig *in);

            NDDSUSERDllExport extern void 
            EntityConfigPluginSupport_destroy_data_w_params(
                EntityConfig *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            EntityConfigPluginSupport_destroy_data_ex(
                EntityConfig *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            EntityConfigPluginSupport_destroy_data(
                EntityConfig *sample);

            NDDSUSERDllExport extern void 
            EntityConfigPluginSupport_print_data(
                const EntityConfig *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            EntityConfigPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                EntityConfig *out,
                const EntityConfig *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            EntityConfigPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const EntityConfig *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            EntityConfigPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                EntityConfig **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            EntityConfigPlugin_deserialize_from_cdr_buffer(
                EntityConfig *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            EntityConfigPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            EntityConfigPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            EntityConfigPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            EntityConfigPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            EntityConfigPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                EntityConfig ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define EntityEventPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define EntityEventPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define EntityEventPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define EntityEventPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define EntityEventPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern EntityEvent*
            EntityEventPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern EntityEvent*
            EntityEventPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern EntityEvent*
            EntityEventPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            EntityEventPluginSupport_copy_data(
                EntityEvent *out,
                const EntityEvent *in);

            NDDSUSERDllExport extern void 
            EntityEventPluginSupport_destroy_data_w_params(
                EntityEvent *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            EntityEventPluginSupport_destroy_data_ex(
                EntityEvent *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            EntityEventPluginSupport_destroy_data(
                EntityEvent *sample);

            NDDSUSERDllExport extern void 
            EntityEventPluginSupport_print_data(
                const EntityEvent *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            EntityEventPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                EntityEvent *out,
                const EntityEvent *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            EntityEventPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const EntityEvent *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            EntityEventPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                EntityEvent **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            EntityEventPlugin_deserialize_from_cdr_buffer(
                EntityEvent *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            EntityEventPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            EntityEventPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            EntityEventPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            EntityEventPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            EntityEventPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                EntityEvent ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *cdrStream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern unsigned int 
            DistributionTopicKindPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern unsigned int 
            DistributionTopicKindPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            DistributionTopicKindPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* ----------------------------------------------------------------------------
            Support functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern void
            DistributionTopicKindPluginSupport_print_data(
                const DistributionTopicKind *sample,
                const char *desc,
                unsigned int indent_level);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern unsigned int 
            ResourceKindIndexPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern unsigned int 
            ResourceKindIndexPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            ResourceKindIndexPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* ----------------------------------------------------------------------------
            Support functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern void
            ResourceKindIndexPluginSupport_print_data(
                const ResourceKindIndex *sample,
                const char *desc,
                unsigned int indent_level);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern unsigned int 
            ResourceKindPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern unsigned int 
            ResourceKindPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            ResourceKindPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* ----------------------------------------------------------------------------
            Support functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern void
            ResourceKindPluginSupport_print_data(
                const ResourceKind *sample,
                const char *desc,
                unsigned int indent_level);

        } /* namespace Monitoring  */
    } /* namespace Service  */
} /* namespace RTI  */

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* ServiceCommonPlugin_1902811798_h */

