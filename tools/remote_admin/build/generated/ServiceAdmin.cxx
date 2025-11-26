

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ServiceAdmin.idl
using RTI Code Generator (rtiddsgen) version 4.3.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include <iosfwd>
#include <iomanip>

#ifndef NDDS_STANDALONE_TYPE
#include "rti/topic/cdr/Serialization.hpp"
#include "ServiceAdminPlugin.hpp"
#else
#include "rti/topic/cdr/SerializationHelpers.hpp"
#endif

#include "ServiceAdmin.hpp"

#include <rti/util/ostream_operators.hpp>

namespace RTI {

    namespace Service {

        namespace Admin {

            std::ostream& operator << (std::ostream& o,const CommandActionKind& sample)
            {
                ::rti::util::StreamFlagSaver flag_saver (o);
                switch(sample){
                    case CommandActionKind::CREATE_ACTION:
                    o << "CommandActionKind::CREATE_ACTION" << " ";
                    break;
                    case CommandActionKind::GET_ACTION:
                    o << "CommandActionKind::GET_ACTION" << " ";
                    break;
                    case CommandActionKind::UPDATE_ACTION:
                    o << "CommandActionKind::UPDATE_ACTION" << " ";
                    break;
                    case CommandActionKind::DELETE_ACTION:
                    o << "CommandActionKind::DELETE_ACTION" << " ";
                    break;
                    default:
                    {
                        /* Prevents compiler warnings */
                    }
                }
                return o;
            }

            std::ostream& operator << (std::ostream& o,const CommandReplyRetcode& sample)
            {
                ::rti::util::StreamFlagSaver flag_saver (o);
                switch(sample){
                    case CommandReplyRetcode::OK_RETCODE:
                    o << "CommandReplyRetcode::OK_RETCODE" << " ";
                    break;
                    case CommandReplyRetcode::ERROR_RETCODE:
                    o << "CommandReplyRetcode::ERROR_RETCODE" << " ";
                    break;
                    default:
                    {
                        /* Prevents compiler warnings */
                    }
                }
                return o;
            }

            // ---- CommandRequest: 

            CommandRequest::CommandRequest() :
                m_instance_id_ (0) ,
                m_action_(RTI::Service::Admin::CommandActionKind::CREATE_ACTION) ,
                m_resource_identifier_ ("") ,
                m_string_body_ ("")  {

            }   

            CommandRequest::CommandRequest (int32_t instance_id_,const ::dds::core::optional< std::string >& application_name_,const ::RTI::Service::Admin::CommandActionKind& action_,const std::string& resource_identifier_,const std::string& string_body_,const ::RTI::Service::Admin::OctetBody& octet_body_):
                m_instance_id_(instance_id_), 
                m_application_name_(application_name_), 
                m_action_(action_), 
                m_resource_identifier_(resource_identifier_), 
                m_string_body_(string_body_), 
                m_octet_body_(octet_body_) {
            }

            void CommandRequest::swap(CommandRequest& other_)  noexcept 
            {
                using std::swap;
                swap(m_instance_id_, other_.m_instance_id_);
                swap(m_application_name_, other_.m_application_name_);
                swap(m_action_, other_.m_action_);
                swap(m_resource_identifier_, other_.m_resource_identifier_);
                swap(m_string_body_, other_.m_string_body_);
                swap(m_octet_body_, other_.m_octet_body_);
            }  

            bool CommandRequest::operator == (const CommandRequest& other_) const {
                if (m_instance_id_ != other_.m_instance_id_) {
                    return false;
                }
                if (m_application_name_ != other_.m_application_name_) {
                    return false;
                }
                if (m_action_ != other_.m_action_) {
                    return false;
                }
                if (m_resource_identifier_ != other_.m_resource_identifier_) {
                    return false;
                }
                if (m_string_body_ != other_.m_string_body_) {
                    return false;
                }
                if (m_octet_body_ != other_.m_octet_body_) {
                    return false;
                }
                return true;
            }

            bool CommandRequest::operator != (const CommandRequest& other_) const {
                return !this->operator ==(other_);
            }

            std::ostream& operator << (std::ostream& o,const CommandRequest& sample)
            {
                ::rti::util::StreamFlagSaver flag_saver (o);
                o <<"[";
                o << "instance_id: " << sample.instance_id ()<<", ";
                o << "application_name: " << sample.application_name ()<<", ";
                o << "action: " << sample.action ()<<", ";
                o << "resource_identifier: " << sample.resource_identifier ()<<", ";
                o << "string_body: " << sample.string_body ()<<", ";
                o << "octet_body: " << sample.octet_body ();
                o <<"]";
                return o;
            }

            // ---- CommandReply: 

            CommandReply::CommandReply() :
                m_retcode_(RTI::Service::Admin::CommandReplyRetcode::OK_RETCODE) ,
                m_native_retcode_ (0) ,
                m_string_body_ ("")  {

            }   

            CommandReply::CommandReply (const ::RTI::Service::Admin::CommandReplyRetcode& retcode_,int32_t native_retcode_,const std::string& string_body_,const ::RTI::Service::Admin::OctetBody& octet_body_):
                m_retcode_(retcode_), 
                m_native_retcode_(native_retcode_), 
                m_string_body_(string_body_), 
                m_octet_body_(octet_body_) {
            }

            void CommandReply::swap(CommandReply& other_)  noexcept 
            {
                using std::swap;
                swap(m_retcode_, other_.m_retcode_);
                swap(m_native_retcode_, other_.m_native_retcode_);
                swap(m_string_body_, other_.m_string_body_);
                swap(m_octet_body_, other_.m_octet_body_);
            }  

            bool CommandReply::operator == (const CommandReply& other_) const {
                if (m_retcode_ != other_.m_retcode_) {
                    return false;
                }
                if (m_native_retcode_ != other_.m_native_retcode_) {
                    return false;
                }
                if (m_string_body_ != other_.m_string_body_) {
                    return false;
                }
                if (m_octet_body_ != other_.m_octet_body_) {
                    return false;
                }
                return true;
            }

            bool CommandReply::operator != (const CommandReply& other_) const {
                return !this->operator ==(other_);
            }

            std::ostream& operator << (std::ostream& o,const CommandReply& sample)
            {
                ::rti::util::StreamFlagSaver flag_saver (o);
                o <<"[";
                o << "retcode: " << sample.retcode ()<<", ";
                o << "native_retcode: " << sample.native_retcode ()<<", ";
                o << "string_body: " << sample.string_body ()<<", ";
                o << "octet_body: " << sample.octet_body ();
                o <<"]";
                return o;
            }

        } // namespace Admin  

    } // namespace Service  

} // namespace RTI  

#ifdef NDDS_STANDALONE_TYPE
namespace rti {
    namespace topic {
        const ::RTI::Service::Admin::CommandActionKind default_enumerator< ::RTI::Service::Admin::CommandActionKind>::value = ::RTI::Service::Admin::CommandActionKind::CREATE_ACTION;
        const ::RTI::Service::Admin::CommandReplyRetcode default_enumerator< ::RTI::Service::Admin::CommandReplyRetcode>::value = ::RTI::Service::Admin::CommandReplyRetcode::OK_RETCODE;
    }
}

#else
// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code< ::RTI::Service::Admin::EntityName_AliasTag_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode EntityName_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"RTI::Service::Admin::EntityName", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for  EntityName */

                if (is_initialized) {
                    return &EntityName_g_tc;
                }

                is_initialized = RTI_TRUE;

                EntityName_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                EntityName_g_tc._data._typeCode =  (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::BoundedString_AliasTag_t>::get().native();

                /* Initialize the values for member annotations. */
                EntityName_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                EntityName_g_tc._data._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                EntityName_g_tc._data._sampleAccessInfo = sample_access_info();
                EntityName_g_tc._data._typePlugin = type_plugin_info();    

                return &EntityName_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo EntityName_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo EntityName_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &EntityName_g_sampleAccessInfo;
                }

                EntityName_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                EntityName_g_sampleAccessInfo.memberAccessInfos = 
                EntityName_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Admin::EntityName);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        EntityName_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        EntityName_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                EntityName_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                EntityName_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Admin::EntityName >;

                EntityName_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &EntityName_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin EntityName_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &EntityName_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::AliasType& dynamic_type< ::RTI::Service::Admin::EntityName_AliasTag_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::AliasType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Admin::EntityName_AliasTag_t >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::Admin::ResourceIdentifier_AliasTag_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode ResourceIdentifier_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"RTI::Service::Admin::ResourceIdentifier", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for  ResourceIdentifier */

                if (is_initialized) {
                    return &ResourceIdentifier_g_tc;
                }

                is_initialized = RTI_TRUE;

                ResourceIdentifier_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                ResourceIdentifier_g_tc._data._typeCode =  (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::ResourceId_AliasTag_t>::get().native();

                /* Initialize the values for member annotations. */
                ResourceIdentifier_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ResourceIdentifier_g_tc._data._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                ResourceIdentifier_g_tc._data._sampleAccessInfo = sample_access_info();
                ResourceIdentifier_g_tc._data._typePlugin = type_plugin_info();    

                return &ResourceIdentifier_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo ResourceIdentifier_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ResourceIdentifier_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ResourceIdentifier_g_sampleAccessInfo;
                }

                ResourceIdentifier_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                ResourceIdentifier_g_sampleAccessInfo.memberAccessInfos = 
                ResourceIdentifier_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Admin::ResourceIdentifier);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ResourceIdentifier_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ResourceIdentifier_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ResourceIdentifier_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ResourceIdentifier_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Admin::ResourceIdentifier >;

                ResourceIdentifier_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ResourceIdentifier_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ResourceIdentifier_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &ResourceIdentifier_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::AliasType& dynamic_type< ::RTI::Service::Admin::ResourceIdentifier_AliasTag_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::AliasType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Admin::ResourceIdentifier_AliasTag_t >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::Admin::StringBody_AliasTag_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode StringBody_g_tc_string;

                static DDS_TypeCode StringBody_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"RTI::Service::Admin::StringBody", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for  StringBody */

                if (is_initialized) {
                    return &StringBody_g_tc;
                }

                is_initialized = RTI_TRUE;

                StringBody_g_tc_string = initialize_string_typecode(RTIXCdrLong_MAX);

                StringBody_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                StringBody_g_tc._data._typeCode =  (RTICdrTypeCode *)&StringBody_g_tc_string;

                /* Initialize the values for member annotations. */
                StringBody_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                StringBody_g_tc._data._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                StringBody_g_tc._data._sampleAccessInfo = sample_access_info();
                StringBody_g_tc._data._typePlugin = type_plugin_info();    

                return &StringBody_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo StringBody_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo StringBody_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &StringBody_g_sampleAccessInfo;
                }

                StringBody_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                StringBody_g_sampleAccessInfo.memberAccessInfos = 
                StringBody_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Admin::StringBody);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        StringBody_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        StringBody_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                StringBody_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                StringBody_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Admin::StringBody >;

                StringBody_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &StringBody_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin StringBody_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &StringBody_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::AliasType& dynamic_type< ::RTI::Service::Admin::StringBody_AliasTag_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::AliasType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Admin::StringBody_AliasTag_t >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::Admin::OctetBody_AliasTag_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode OctetBody_g_tc_sequence;

                static DDS_TypeCode OctetBody_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"RTI::Service::Admin::OctetBody", /* Name */
                        NULL, /* Content type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for  OctetBody */

                if (is_initialized) {
                    return &OctetBody_g_tc;
                }

                is_initialized = RTI_TRUE;

                OctetBody_g_tc_sequence = initialize_sequence_typecode< std::vector< uint8_t > >(RTIXCdrLong_MAX);

                OctetBody_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                OctetBody_g_tc_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                OctetBody_g_tc._data._typeCode =  (RTICdrTypeCode *)& OctetBody_g_tc_sequence;

                /* Initialize the values for member annotations. */

                OctetBody_g_tc._data._sampleAccessInfo = sample_access_info();
                OctetBody_g_tc._data._typePlugin = type_plugin_info();    

                return &OctetBody_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo OctetBody_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo OctetBody_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &OctetBody_g_sampleAccessInfo;
                }

                OctetBody_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                OctetBody_g_sampleAccessInfo.memberAccessInfos = 
                OctetBody_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Admin::OctetBody);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        OctetBody_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        OctetBody_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                OctetBody_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                OctetBody_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Admin::OctetBody >;

                OctetBody_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &OctetBody_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin OctetBody_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &OctetBody_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::AliasType& dynamic_type< ::RTI::Service::Admin::OctetBody_AliasTag_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::AliasType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Admin::OctetBody_AliasTag_t >::get())));
        }

        const ::RTI::Service::Admin::CommandActionKind default_enumerator< ::RTI::Service::Admin::CommandActionKind>::value = ::RTI::Service::Admin::CommandActionKind::CREATE_ACTION;
        template<>
        struct native_type_code< ::RTI::Service::Admin::CommandActionKind > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member CommandActionKind_g_tc_members[4]=
                {

                    {
                        (char *)"CREATE_ACTION",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Admin::CommandActionKind::CREATE_ACTION), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"GET_ACTION",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Admin::CommandActionKind::GET_ACTION), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"UPDATE_ACTION",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Admin::CommandActionKind::UPDATE_ACTION), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"DELETE_ACTION",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Admin::CommandActionKind::DELETE_ACTION), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode CommandActionKind_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::Admin::CommandActionKind", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        CommandActionKind_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for CommandActionKind*/

                if (is_initialized) {
                    return &CommandActionKind_g_tc;
                }

                is_initialized = RTI_TRUE;

                CommandActionKind_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                CommandActionKind_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                CommandActionKind_g_tc._data._annotations._defaultValue._u.long_value = 0;

                CommandActionKind_g_tc._data._sampleAccessInfo = sample_access_info();
                CommandActionKind_g_tc._data._typePlugin = type_plugin_info();    

                return &CommandActionKind_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo CommandActionKind_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo CommandActionKind_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &CommandActionKind_g_sampleAccessInfo;
                }

                CommandActionKind_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                CommandActionKind_g_sampleAccessInfo.memberAccessInfos = 
                CommandActionKind_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Admin::CommandActionKind);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        CommandActionKind_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        CommandActionKind_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                CommandActionKind_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                CommandActionKind_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Admin::CommandActionKind >;

                CommandActionKind_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &CommandActionKind_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin CommandActionKind_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &CommandActionKind_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::EnumType& dynamic_type< ::RTI::Service::Admin::CommandActionKind >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Admin::CommandActionKind >::get())));
        }

        const ::RTI::Service::Admin::CommandReplyRetcode default_enumerator< ::RTI::Service::Admin::CommandReplyRetcode>::value = ::RTI::Service::Admin::CommandReplyRetcode::OK_RETCODE;
        template<>
        struct native_type_code< ::RTI::Service::Admin::CommandReplyRetcode > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member CommandReplyRetcode_g_tc_members[2]=
                {

                    {
                        (char *)"OK_RETCODE",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Admin::CommandReplyRetcode::OK_RETCODE), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"ERROR_RETCODE",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Admin::CommandReplyRetcode::ERROR_RETCODE), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode CommandReplyRetcode_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::Admin::CommandReplyRetcode", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        CommandReplyRetcode_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for CommandReplyRetcode*/

                if (is_initialized) {
                    return &CommandReplyRetcode_g_tc;
                }

                is_initialized = RTI_TRUE;

                CommandReplyRetcode_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                CommandReplyRetcode_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                CommandReplyRetcode_g_tc._data._annotations._defaultValue._u.long_value = 0;

                CommandReplyRetcode_g_tc._data._sampleAccessInfo = sample_access_info();
                CommandReplyRetcode_g_tc._data._typePlugin = type_plugin_info();    

                return &CommandReplyRetcode_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo CommandReplyRetcode_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo CommandReplyRetcode_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &CommandReplyRetcode_g_sampleAccessInfo;
                }

                CommandReplyRetcode_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                CommandReplyRetcode_g_sampleAccessInfo.memberAccessInfos = 
                CommandReplyRetcode_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Admin::CommandReplyRetcode);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        CommandReplyRetcode_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        CommandReplyRetcode_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                CommandReplyRetcode_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                CommandReplyRetcode_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Admin::CommandReplyRetcode >;

                CommandReplyRetcode_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &CommandReplyRetcode_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin CommandReplyRetcode_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &CommandReplyRetcode_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::EnumType& dynamic_type< ::RTI::Service::Admin::CommandReplyRetcode >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Admin::CommandReplyRetcode >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::Admin::CommandRequest > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode CommandRequest_g_tc_application_name_string;

                static DDS_TypeCode_Member CommandRequest_g_tc_members[6]=
                {

                    {
                        (char *)"instance_id",/* Member name */
                        {
                            265072465,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"application_name",/* Member name */
                        {
                            20524100,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"action",/* Member name */
                        {
                            156601409,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"resource_identifier",/* Member name */
                        {
                            152744383,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"string_body",/* Member name */
                        {
                            152094850,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"octet_body",/* Member name */
                        {
                            223242733,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode CommandRequest_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::Admin::CommandRequest", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        6, /* Number of members */
                        CommandRequest_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for CommandRequest*/

                if (is_initialized) {
                    return &CommandRequest_g_tc;
                }

                is_initialized = RTI_TRUE;

                CommandRequest_g_tc_application_name_string = initialize_string_typecode(((RTI::Service::BOUNDED_STRING_LENGTH_MAX)));

                CommandRequest_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                CommandRequest_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                CommandRequest_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&CommandRequest_g_tc_application_name_string;
                CommandRequest_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::Admin::CommandActionKind>::get().native();
                CommandRequest_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::Admin::ResourceIdentifier_AliasTag_t>::get().native();
                CommandRequest_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::Admin::StringBody_AliasTag_t>::get().native();
                CommandRequest_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::Admin::OctetBody_AliasTag_t>::get().native();

                /* Initialize the values for member annotations. */
                CommandRequest_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                CommandRequest_g_tc_members[0]._annotations._defaultValue._u.long_value = 0;
                CommandRequest_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                CommandRequest_g_tc_members[0]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                CommandRequest_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                CommandRequest_g_tc_members[0]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;
                CommandRequest_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                CommandRequest_g_tc_members[2]._annotations._defaultValue._u.enumerated_value = 0;
                CommandRequest_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                CommandRequest_g_tc_members[3]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
                CommandRequest_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                CommandRequest_g_tc_members[4]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                CommandRequest_g_tc._data._sampleAccessInfo = sample_access_info();
                CommandRequest_g_tc._data._typePlugin = type_plugin_info();    

                return &CommandRequest_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::RTI::Service::Admin::CommandRequest *sample;

                static RTIXCdrMemberAccessInfo CommandRequest_g_memberAccessInfos[6] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo CommandRequest_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &CommandRequest_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::RTI::Service::Admin::CommandRequest);
                if (sample == NULL) {
                    return NULL;
                }

                CommandRequest_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->instance_id() - (char *)sample);

                CommandRequest_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->application_name() - (char *)sample);

                CommandRequest_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->action() - (char *)sample);

                CommandRequest_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->resource_identifier() - (char *)sample);

                CommandRequest_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->string_body() - (char *)sample);

                CommandRequest_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->octet_body() - (char *)sample);

                CommandRequest_g_sampleAccessInfo.memberAccessInfos = 
                CommandRequest_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Admin::CommandRequest);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        CommandRequest_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        CommandRequest_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                CommandRequest_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                CommandRequest_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Admin::CommandRequest >;

                CommandRequest_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &CommandRequest_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin CommandRequest_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &CommandRequest_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::RTI::Service::Admin::CommandRequest >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Admin::CommandRequest >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::Admin::CommandReply > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member CommandReply_g_tc_members[4]=
                {

                    {
                        (char *)"retcode",/* Member name */
                        {
                            7375107,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"native_retcode",/* Member name */
                        {
                            157115781,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"string_body",/* Member name */
                        {
                            152094850,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"octet_body",/* Member name */
                        {
                            223242733,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode CommandReply_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::Admin::CommandReply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        CommandReply_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for CommandReply*/

                if (is_initialized) {
                    return &CommandReply_g_tc;
                }

                is_initialized = RTI_TRUE;

                CommandReply_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                CommandReply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::Admin::CommandReplyRetcode>::get().native();
                CommandReply_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                CommandReply_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::Admin::StringBody_AliasTag_t>::get().native();
                CommandReply_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::Admin::OctetBody_AliasTag_t>::get().native();

                /* Initialize the values for member annotations. */
                CommandReply_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                CommandReply_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;
                CommandReply_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                CommandReply_g_tc_members[1]._annotations._defaultValue._u.long_value = 0;
                CommandReply_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                CommandReply_g_tc_members[1]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                CommandReply_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                CommandReply_g_tc_members[1]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;
                CommandReply_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                CommandReply_g_tc_members[2]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                CommandReply_g_tc._data._sampleAccessInfo = sample_access_info();
                CommandReply_g_tc._data._typePlugin = type_plugin_info();    

                return &CommandReply_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::RTI::Service::Admin::CommandReply *sample;

                static RTIXCdrMemberAccessInfo CommandReply_g_memberAccessInfos[4] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo CommandReply_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &CommandReply_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::RTI::Service::Admin::CommandReply);
                if (sample == NULL) {
                    return NULL;
                }

                CommandReply_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->retcode() - (char *)sample);

                CommandReply_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->native_retcode() - (char *)sample);

                CommandReply_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->string_body() - (char *)sample);

                CommandReply_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->octet_body() - (char *)sample);

                CommandReply_g_sampleAccessInfo.memberAccessInfos = 
                CommandReply_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Admin::CommandReply);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        CommandReply_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        CommandReply_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                CommandReply_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                CommandReply_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Admin::CommandReply >;

                CommandReply_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &CommandReply_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin CommandReply_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &CommandReply_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::RTI::Service::Admin::CommandReply >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Admin::CommandReply >::get())));
        }
    }
}

namespace dds { 
    namespace topic {
        void topic_type_support< ::RTI::Service::Admin::CommandRequest >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::RTI::Service::Admin::CommandRequestPlugin_new,
                ::RTI::Service::Admin::CommandRequestPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::RTI::Service::Admin::CommandRequest >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::RTI::Service::Admin::CommandRequest& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = CommandRequestPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = CommandRequestPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::RTI::Service::Admin::CommandRequest >::from_cdr_buffer(::RTI::Service::Admin::CommandRequest& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = CommandRequestPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::RTI::Service::Admin::CommandRequest from cdr buffer");
        }

        void topic_type_support< ::RTI::Service::Admin::CommandRequest >::reset_sample(::RTI::Service::Admin::CommandRequest& sample) 
        {
            sample.instance_id(0);
            ::rti::topic::reset_sample(sample.application_name());
            sample.action(RTI::Service::Admin::CommandActionKind::CREATE_ACTION);
            sample.resource_identifier("");
            sample.string_body("");
            ::rti::topic::reset_sample(sample.octet_body());
        }

        void topic_type_support< ::RTI::Service::Admin::CommandRequest >::allocate_sample(::RTI::Service::Admin::CommandRequest& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.action(),  -1, -1);
            ::rti::topic::allocate_sample(sample.resource_identifier(),  -1, (RTI::Service::RESOURCE_IDENTIFIER_LENGTH_MAX));
            ::rti::topic::allocate_sample(sample.string_body(),  -1, -1);
            ::rti::topic::allocate_sample(sample.octet_body(),  -1, -1);
        }
        void topic_type_support< ::RTI::Service::Admin::CommandReply >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::RTI::Service::Admin::CommandReplyPlugin_new,
                ::RTI::Service::Admin::CommandReplyPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::RTI::Service::Admin::CommandReply >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::RTI::Service::Admin::CommandReply& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = CommandReplyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = CommandReplyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::RTI::Service::Admin::CommandReply >::from_cdr_buffer(::RTI::Service::Admin::CommandReply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = CommandReplyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::RTI::Service::Admin::CommandReply from cdr buffer");
        }

        void topic_type_support< ::RTI::Service::Admin::CommandReply >::reset_sample(::RTI::Service::Admin::CommandReply& sample) 
        {
            sample.retcode(RTI::Service::Admin::CommandReplyRetcode::OK_RETCODE);
            sample.native_retcode(0);
            sample.string_body("");
            ::rti::topic::reset_sample(sample.octet_body());
        }

        void topic_type_support< ::RTI::Service::Admin::CommandReply >::allocate_sample(::RTI::Service::Admin::CommandReply& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.retcode(),  -1, -1);
            ::rti::topic::allocate_sample(sample.string_body(),  -1, -1);
            ::rti::topic::allocate_sample(sample.octet_body(),  -1, -1);
        }
    }
}  

#endif // NDDS_STANDALONE_TYPE
