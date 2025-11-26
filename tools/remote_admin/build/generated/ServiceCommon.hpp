

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ServiceCommon.idl
using RTI Code Generator (rtiddsgen) version 4.3.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef ServiceCommon_1902811798_hpp
#define ServiceCommon_1902811798_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/External.hpp"
#include "rti/core/LongDouble.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/core/array.hpp"
#include "rti/topic/TopicTraits.hpp"

#include "omg/types/string_view.hpp"

#include "rti/core/BoundedSequence.hpp"
#include "dds/core/Optional.hpp"

#ifndef NDDS_STANDALONE_TYPE
#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

namespace RTI {
    namespace Service {

        static const int32_t BOUNDED_STRING_LENGTH_MAX = 255L;

        typedef std::string BoundedString;
        struct BoundedString_AliasTag_t {};

        static const int32_t FILE_PATH_MAX_LENGTH = 1024L;

        typedef std::string FilePath;
        struct FilePath_AliasTag_t {};

        static const int32_t RESOURCE_IDENTIFIER_LENGTH_MAX = 2048L;

        typedef std::string ResourceId;
        struct ResourceId_AliasTag_t {};

        typedef std::string XmlString;
        struct XmlString_AliasTag_t {};
        enum class EntityStateKind {
            INVALID, 
            ENABLED, 
            DISABLED, 
            STARTED, 
            STOPPED, 
            RUNNING, 
            PAUSED
        };

        NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const EntityStateKind& sample);

        class NDDSUSERDllExport EntityState {
          public:

            EntityState();

            explicit EntityState(const ::RTI::Service::EntityStateKind& state_);

            ::RTI::Service::EntityStateKind& state() noexcept {
                return m_state_;
            }

            const ::RTI::Service::EntityStateKind& state() const noexcept {
                return m_state_;
            }

            void state(const ::RTI::Service::EntityStateKind& value) {

                m_state_ = value;
            }

            void state(::RTI::Service::EntityStateKind&& value) {
                m_state_ = std::move(value);
            }
            bool operator == (const EntityState& other_) const;
            bool operator != (const EntityState& other_) const;

            void swap(EntityState& other_) noexcept ;

          private:

            ::RTI::Service::EntityStateKind m_state_;

        };

        inline void swap(EntityState& a, EntityState& b)  noexcept 
        {
            a.swap(b);
        }

        NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const EntityState& sample);

        static const int32_t BUILTIN_TOPIC_KEY_VALUE_LENGTH = 4L;

        class NDDSUSERDllExport BuiltinTopicKey {
          public:

            BuiltinTopicKey();

            explicit BuiltinTopicKey(const ::dds::core::array< uint32_t, (RTI::Service::BUILTIN_TOPIC_KEY_VALUE_LENGTH)>& value_);

            ::dds::core::array< uint32_t, (RTI::Service::BUILTIN_TOPIC_KEY_VALUE_LENGTH)>& value() noexcept {
                return m_value_;
            }

            const ::dds::core::array< uint32_t, (RTI::Service::BUILTIN_TOPIC_KEY_VALUE_LENGTH)>& value() const noexcept {
                return m_value_;
            }

            void value(const ::dds::core::array< uint32_t, (RTI::Service::BUILTIN_TOPIC_KEY_VALUE_LENGTH)>& value) {

                m_value_ = value;
            }

            void value(::dds::core::array< uint32_t, (RTI::Service::BUILTIN_TOPIC_KEY_VALUE_LENGTH)>&& value) {
                m_value_ = std::move(value);
            }
            bool operator == (const BuiltinTopicKey& other_) const;
            bool operator != (const BuiltinTopicKey& other_) const;

            void swap(BuiltinTopicKey& other_) noexcept ;

          private:

            ::dds::core::array< uint32_t, (RTI::Service::BUILTIN_TOPIC_KEY_VALUE_LENGTH)> m_value_ {};

        };

        inline void swap(BuiltinTopicKey& a, BuiltinTopicKey& b)  noexcept 
        {
            a.swap(b);
        }

        NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BuiltinTopicKey& sample);

        namespace Monitoring {

            static const int32_t RESOURCE_GUID_VALUE_LENGTH = 16L;

            class NDDSUSERDllExport ResourceGuid {
              public:

                ResourceGuid();

                explicit ResourceGuid(const ::dds::core::array< uint8_t, (RTI::Service::Monitoring::RESOURCE_GUID_VALUE_LENGTH)>& value_);

                ::dds::core::array< uint8_t, (RTI::Service::Monitoring::RESOURCE_GUID_VALUE_LENGTH)>& value() noexcept {
                    return m_value_;
                }

                const ::dds::core::array< uint8_t, (RTI::Service::Monitoring::RESOURCE_GUID_VALUE_LENGTH)>& value() const noexcept {
                    return m_value_;
                }

                void value(const ::dds::core::array< uint8_t, (RTI::Service::Monitoring::RESOURCE_GUID_VALUE_LENGTH)>& value) {

                    m_value_ = value;
                }

                void value(::dds::core::array< uint8_t, (RTI::Service::Monitoring::RESOURCE_GUID_VALUE_LENGTH)>&& value) {
                    m_value_ = std::move(value);
                }
                bool operator == (const ResourceGuid& other_) const;
                bool operator != (const ResourceGuid& other_) const;

                void swap(ResourceGuid& other_) noexcept ;

              private:

                ::dds::core::array< uint8_t, (RTI::Service::Monitoring::RESOURCE_GUID_VALUE_LENGTH)> m_value_ {};

            };

            inline void swap(ResourceGuid& a, ResourceGuid& b)  noexcept 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ResourceGuid& sample);

            class NDDSUSERDllExport KeyedResource {
              public:

                KeyedResource();

                KeyedResource(const ::RTI::Service::Monitoring::ResourceGuid& object_guid_,const ::RTI::Service::Monitoring::ResourceGuid& owner_guid_);

                ::RTI::Service::Monitoring::ResourceGuid& object_guid() noexcept {
                    return m_object_guid_;
                }

                const ::RTI::Service::Monitoring::ResourceGuid& object_guid() const noexcept {
                    return m_object_guid_;
                }

                void object_guid(const ::RTI::Service::Monitoring::ResourceGuid& value) {

                    m_object_guid_ = value;
                }

                void object_guid(::RTI::Service::Monitoring::ResourceGuid&& value) {
                    m_object_guid_ = std::move(value);
                }
                ::RTI::Service::Monitoring::ResourceGuid& owner_guid() noexcept {
                    return m_owner_guid_;
                }

                const ::RTI::Service::Monitoring::ResourceGuid& owner_guid() const noexcept {
                    return m_owner_guid_;
                }

                void owner_guid(const ::RTI::Service::Monitoring::ResourceGuid& value) {

                    m_owner_guid_ = value;
                }

                void owner_guid(::RTI::Service::Monitoring::ResourceGuid&& value) {
                    m_owner_guid_ = std::move(value);
                }
                bool operator == (const KeyedResource& other_) const;
                bool operator != (const KeyedResource& other_) const;

                void swap(KeyedResource& other_) noexcept ;

              private:

                ::RTI::Service::Monitoring::ResourceGuid m_object_guid_;
                ::RTI::Service::Monitoring::ResourceGuid m_owner_guid_;

            };

            inline void swap(KeyedResource& a, KeyedResource& b)  noexcept 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const KeyedResource& sample);

            class NDDSUSERDllExport StatisticMetrics {
              public:

                StatisticMetrics();

                StatisticMetrics(uint64_t period_ms_,int64_t count_,float mean_,float minimum_,float maximum_,float std_dev_);

                uint64_t& period_ms() noexcept {
                    return m_period_ms_;
                }

                const uint64_t& period_ms() const noexcept {
                    return m_period_ms_;
                }

                void period_ms(uint64_t value) {

                    m_period_ms_ = value;
                }

                int64_t& count() noexcept {
                    return m_count_;
                }

                const int64_t& count() const noexcept {
                    return m_count_;
                }

                void count(int64_t value) {

                    m_count_ = value;
                }

                float& mean() noexcept {
                    return m_mean_;
                }

                const float& mean() const noexcept {
                    return m_mean_;
                }

                void mean(float value) {

                    m_mean_ = value;
                }

                float& minimum() noexcept {
                    return m_minimum_;
                }

                const float& minimum() const noexcept {
                    return m_minimum_;
                }

                void minimum(float value) {

                    m_minimum_ = value;
                }

                float& maximum() noexcept {
                    return m_maximum_;
                }

                const float& maximum() const noexcept {
                    return m_maximum_;
                }

                void maximum(float value) {

                    m_maximum_ = value;
                }

                float& std_dev() noexcept {
                    return m_std_dev_;
                }

                const float& std_dev() const noexcept {
                    return m_std_dev_;
                }

                void std_dev(float value) {

                    m_std_dev_ = value;
                }

                bool operator == (const StatisticMetrics& other_) const;
                bool operator != (const StatisticMetrics& other_) const;

                void swap(StatisticMetrics& other_) noexcept ;

              private:

                uint64_t m_period_ms_;
                int64_t m_count_;
                float m_mean_;
                float m_minimum_;
                float m_maximum_;
                float m_std_dev_;

            };

            inline void swap(StatisticMetrics& a, StatisticMetrics& b)  noexcept 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const StatisticMetrics& sample);

            class NDDSUSERDllExport StatisticVariable {
              public:

                StatisticVariable();

                explicit StatisticVariable(const ::RTI::Service::Monitoring::StatisticMetrics& publication_period_metrics_);

                ::RTI::Service::Monitoring::StatisticMetrics& publication_period_metrics() noexcept {
                    return m_publication_period_metrics_;
                }

                const ::RTI::Service::Monitoring::StatisticMetrics& publication_period_metrics() const noexcept {
                    return m_publication_period_metrics_;
                }

                void publication_period_metrics(const ::RTI::Service::Monitoring::StatisticMetrics& value) {

                    m_publication_period_metrics_ = value;
                }

                void publication_period_metrics(::RTI::Service::Monitoring::StatisticMetrics&& value) {
                    m_publication_period_metrics_ = std::move(value);
                }
                bool operator == (const StatisticVariable& other_) const;
                bool operator != (const StatisticVariable& other_) const;

                void swap(StatisticVariable& other_) noexcept ;

              private:

                ::RTI::Service::Monitoring::StatisticMetrics m_publication_period_metrics_;

            };

            inline void swap(StatisticVariable& a, StatisticVariable& b)  noexcept 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const StatisticVariable& sample);

            class NDDSUSERDllExport CountStatus {
              public:

                CountStatus();

                CountStatus(int64_t total_count_,int64_t current_count_,int64_t current_count_peak_);

                int64_t& total_count() noexcept {
                    return m_total_count_;
                }

                const int64_t& total_count() const noexcept {
                    return m_total_count_;
                }

                void total_count(int64_t value) {

                    m_total_count_ = value;
                }

                int64_t& current_count() noexcept {
                    return m_current_count_;
                }

                const int64_t& current_count() const noexcept {
                    return m_current_count_;
                }

                void current_count(int64_t value) {

                    m_current_count_ = value;
                }

                int64_t& current_count_peak() noexcept {
                    return m_current_count_peak_;
                }

                const int64_t& current_count_peak() const noexcept {
                    return m_current_count_peak_;
                }

                void current_count_peak(int64_t value) {

                    m_current_count_peak_ = value;
                }

                bool operator == (const CountStatus& other_) const;
                bool operator != (const CountStatus& other_) const;

                void swap(CountStatus& other_) noexcept ;

              private:

                int64_t m_total_count_;
                int64_t m_current_count_;
                int64_t m_current_count_peak_;

            };

            inline void swap(CountStatus& a, CountStatus& b)  noexcept 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const CountStatus& sample);

            class NDDSUSERDllExport ProcessConfig {
              public:

                ProcessConfig();

                explicit ProcessConfig(uint64_t id_);

                uint64_t& id() noexcept {
                    return m_id_;
                }

                const uint64_t& id() const noexcept {
                    return m_id_;
                }

                void id(uint64_t value) {

                    m_id_ = value;
                }

                bool operator == (const ProcessConfig& other_) const;
                bool operator != (const ProcessConfig& other_) const;

                void swap(ProcessConfig& other_) noexcept ;

              private:

                uint64_t m_id_;

            };

            inline void swap(ProcessConfig& a, ProcessConfig& b)  noexcept 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ProcessConfig& sample);

            class NDDSUSERDllExport ProcessPeriodic {
              public:

                ProcessPeriodic();

                ProcessPeriodic(const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& cpu_usage_percentage_,const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& physical_memory_kb_,const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& total_memory_kb_,int32_t uptime_sec_);

                ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& cpu_usage_percentage() noexcept {
                    return m_cpu_usage_percentage_;
                }

                const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& cpu_usage_percentage() const noexcept {
                    return m_cpu_usage_percentage_;
                }

                void cpu_usage_percentage(const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& value) {

                    m_cpu_usage_percentage_ = value;
                }

                void cpu_usage_percentage(::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >&& value) {
                    m_cpu_usage_percentage_ = std::move(value);
                }
                ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& physical_memory_kb() noexcept {
                    return m_physical_memory_kb_;
                }

                const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& physical_memory_kb() const noexcept {
                    return m_physical_memory_kb_;
                }

                void physical_memory_kb(const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& value) {

                    m_physical_memory_kb_ = value;
                }

                void physical_memory_kb(::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >&& value) {
                    m_physical_memory_kb_ = std::move(value);
                }
                ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& total_memory_kb() noexcept {
                    return m_total_memory_kb_;
                }

                const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& total_memory_kb() const noexcept {
                    return m_total_memory_kb_;
                }

                void total_memory_kb(const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& value) {

                    m_total_memory_kb_ = value;
                }

                void total_memory_kb(::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >&& value) {
                    m_total_memory_kb_ = std::move(value);
                }
                int32_t& uptime_sec() noexcept {
                    return m_uptime_sec_;
                }

                const int32_t& uptime_sec() const noexcept {
                    return m_uptime_sec_;
                }

                void uptime_sec(int32_t value) {

                    m_uptime_sec_ = value;
                }

                bool operator == (const ProcessPeriodic& other_) const;
                bool operator != (const ProcessPeriodic& other_) const;

                void swap(ProcessPeriodic& other_) noexcept ;

              private:

                ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable > m_cpu_usage_percentage_;
                ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable > m_physical_memory_kb_;
                ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable > m_total_memory_kb_;
                int32_t m_uptime_sec_;

            };

            inline void swap(ProcessPeriodic& a, ProcessPeriodic& b)  noexcept 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ProcessPeriodic& sample);

            class NDDSUSERDllExport ThreadPeriodic {
              public:

                ThreadPeriodic();

                ThreadPeriodic(uint64_t id_,const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& cpu_usage_percentage_);

                uint64_t& id() noexcept {
                    return m_id_;
                }

                const uint64_t& id() const noexcept {
                    return m_id_;
                }

                void id(uint64_t value) {

                    m_id_ = value;
                }

                ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& cpu_usage_percentage() noexcept {
                    return m_cpu_usage_percentage_;
                }

                const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& cpu_usage_percentage() const noexcept {
                    return m_cpu_usage_percentage_;
                }

                void cpu_usage_percentage(const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& value) {

                    m_cpu_usage_percentage_ = value;
                }

                void cpu_usage_percentage(::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >&& value) {
                    m_cpu_usage_percentage_ = std::move(value);
                }
                bool operator == (const ThreadPeriodic& other_) const;
                bool operator != (const ThreadPeriodic& other_) const;

                void swap(ThreadPeriodic& other_) noexcept ;

              private:

                uint64_t m_id_;
                ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable > m_cpu_usage_percentage_;

            };

            inline void swap(ThreadPeriodic& a, ThreadPeriodic& b)  noexcept 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ThreadPeriodic& sample);

            #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
            // On Windows, dll-export template instantiations of standard types used by
            // other dll-exported types
            template class NDDSUSERDllExport std::allocator< ::RTI::Service::Monitoring::ThreadPeriodic >;
            template class NDDSUSERDllExport std::vector< ::RTI::Service::Monitoring::ThreadPeriodic >;
            #endif
            class NDDSUSERDllExport ThreadPoolPeriodic {
              public:

                ThreadPoolPeriodic();

                explicit ThreadPoolPeriodic(const ::dds::core::optional< std::vector< ::RTI::Service::Monitoring::ThreadPeriodic > >& threads_);

                ::dds::core::optional< std::vector< ::RTI::Service::Monitoring::ThreadPeriodic > >& threads() noexcept {
                    return m_threads_;
                }

                const ::dds::core::optional< std::vector< ::RTI::Service::Monitoring::ThreadPeriodic > >& threads() const noexcept {
                    return m_threads_;
                }

                void threads(const ::dds::core::optional< std::vector< ::RTI::Service::Monitoring::ThreadPeriodic > >& value) {

                    m_threads_ = value;
                }

                void threads(::dds::core::optional< std::vector< ::RTI::Service::Monitoring::ThreadPeriodic > >&& value) {
                    m_threads_ = std::move(value);
                }
                bool operator == (const ThreadPoolPeriodic& other_) const;
                bool operator != (const ThreadPoolPeriodic& other_) const;

                void swap(ThreadPoolPeriodic& other_) noexcept ;

              private:

                ::dds::core::optional< std::vector< ::RTI::Service::Monitoring::ThreadPeriodic > > m_threads_;

            };

            inline void swap(ThreadPoolPeriodic& a, ThreadPoolPeriodic& b)  noexcept 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ThreadPoolPeriodic& sample);

            class NDDSUSERDllExport HostPeriodic {
              public:

                HostPeriodic();

                HostPeriodic(const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& cpu_usage_percentage_,const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& free_memory_kb_,const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& free_swap_memory_kb_,int32_t uptime_sec_);

                ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& cpu_usage_percentage() noexcept {
                    return m_cpu_usage_percentage_;
                }

                const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& cpu_usage_percentage() const noexcept {
                    return m_cpu_usage_percentage_;
                }

                void cpu_usage_percentage(const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& value) {

                    m_cpu_usage_percentage_ = value;
                }

                void cpu_usage_percentage(::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >&& value) {
                    m_cpu_usage_percentage_ = std::move(value);
                }
                ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& free_memory_kb() noexcept {
                    return m_free_memory_kb_;
                }

                const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& free_memory_kb() const noexcept {
                    return m_free_memory_kb_;
                }

                void free_memory_kb(const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& value) {

                    m_free_memory_kb_ = value;
                }

                void free_memory_kb(::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >&& value) {
                    m_free_memory_kb_ = std::move(value);
                }
                ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& free_swap_memory_kb() noexcept {
                    return m_free_swap_memory_kb_;
                }

                const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& free_swap_memory_kb() const noexcept {
                    return m_free_swap_memory_kb_;
                }

                void free_swap_memory_kb(const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& value) {

                    m_free_swap_memory_kb_ = value;
                }

                void free_swap_memory_kb(::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >&& value) {
                    m_free_swap_memory_kb_ = std::move(value);
                }
                int32_t& uptime_sec() noexcept {
                    return m_uptime_sec_;
                }

                const int32_t& uptime_sec() const noexcept {
                    return m_uptime_sec_;
                }

                void uptime_sec(int32_t value) {

                    m_uptime_sec_ = value;
                }

                bool operator == (const HostPeriodic& other_) const;
                bool operator != (const HostPeriodic& other_) const;

                void swap(HostPeriodic& other_) noexcept ;

              private:

                ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable > m_cpu_usage_percentage_;
                ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable > m_free_memory_kb_;
                ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable > m_free_swap_memory_kb_;
                int32_t m_uptime_sec_;

            };

            inline void swap(HostPeriodic& a, HostPeriodic& b)  noexcept 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const HostPeriodic& sample);

            class NDDSUSERDllExport HostConfig {
              public:

                HostConfig();

                HostConfig(const std::string& name_,uint32_t id_,int64_t total_memory_kb_,int64_t total_swap_memory_kb_,const std::string& target_);

                std::string& name() noexcept {
                    return m_name_;
                }

                const std::string& name() const noexcept {
                    return m_name_;
                }

                void name(const std::string& value) {

                    m_name_ = value;
                }

                void name(std::string&& value) {
                    m_name_ = std::move(value);
                }
                uint32_t& id() noexcept {
                    return m_id_;
                }

                const uint32_t& id() const noexcept {
                    return m_id_;
                }

                void id(uint32_t value) {

                    m_id_ = value;
                }

                int64_t& total_memory_kb() noexcept {
                    return m_total_memory_kb_;
                }

                const int64_t& total_memory_kb() const noexcept {
                    return m_total_memory_kb_;
                }

                void total_memory_kb(int64_t value) {

                    m_total_memory_kb_ = value;
                }

                int64_t& total_swap_memory_kb() noexcept {
                    return m_total_swap_memory_kb_;
                }

                const int64_t& total_swap_memory_kb() const noexcept {
                    return m_total_swap_memory_kb_;
                }

                void total_swap_memory_kb(int64_t value) {

                    m_total_swap_memory_kb_ = value;
                }

                std::string& target() noexcept {
                    return m_target_;
                }

                const std::string& target() const noexcept {
                    return m_target_;
                }

                void target(const std::string& value) {

                    m_target_ = value;
                }

                void target(std::string&& value) {
                    m_target_ = std::move(value);
                }
                bool operator == (const HostConfig& other_) const;
                bool operator != (const HostConfig& other_) const;

                void swap(HostConfig& other_) noexcept ;

              private:

                std::string m_name_;
                uint32_t m_id_;
                int64_t m_total_memory_kb_;
                int64_t m_total_swap_memory_kb_;
                std::string m_target_;

            };

            inline void swap(HostConfig& a, HostConfig& b)  noexcept 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const HostConfig& sample);

            class NDDSUSERDllExport NetworkPerformance {
              public:

                NetworkPerformance();

                NetworkPerformance(const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& samples_per_sec_,const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& bytes_per_sec_,const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& latency_millisec_);

                ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& samples_per_sec() noexcept {
                    return m_samples_per_sec_;
                }

                const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& samples_per_sec() const noexcept {
                    return m_samples_per_sec_;
                }

                void samples_per_sec(const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& value) {

                    m_samples_per_sec_ = value;
                }

                void samples_per_sec(::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >&& value) {
                    m_samples_per_sec_ = std::move(value);
                }
                ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& bytes_per_sec() noexcept {
                    return m_bytes_per_sec_;
                }

                const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& bytes_per_sec() const noexcept {
                    return m_bytes_per_sec_;
                }

                void bytes_per_sec(const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& value) {

                    m_bytes_per_sec_ = value;
                }

                void bytes_per_sec(::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >&& value) {
                    m_bytes_per_sec_ = std::move(value);
                }
                ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& latency_millisec() noexcept {
                    return m_latency_millisec_;
                }

                const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& latency_millisec() const noexcept {
                    return m_latency_millisec_;
                }

                void latency_millisec(const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& value) {

                    m_latency_millisec_ = value;
                }

                void latency_millisec(::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >&& value) {
                    m_latency_millisec_ = std::move(value);
                }
                bool operator == (const NetworkPerformance& other_) const;
                bool operator != (const NetworkPerformance& other_) const;

                void swap(NetworkPerformance& other_) noexcept ;

              private:

                ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable > m_samples_per_sec_;
                ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable > m_bytes_per_sec_;
                ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable > m_latency_millisec_;

            };

            inline void swap(NetworkPerformance& a, NetworkPerformance& b)  noexcept 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const NetworkPerformance& sample);

            class NDDSUSERDllExport EntityConfig {
              public:

                EntityConfig();

                EntityConfig(const std::string& resource_id_,const std::string& configuration_);

                std::string& resource_id() noexcept {
                    return m_resource_id_;
                }

                const std::string& resource_id() const noexcept {
                    return m_resource_id_;
                }

                void resource_id(const std::string& value) {

                    m_resource_id_ = value;
                }

                void resource_id(std::string&& value) {
                    m_resource_id_ = std::move(value);
                }
                std::string& configuration() noexcept {
                    return m_configuration_;
                }

                const std::string& configuration() const noexcept {
                    return m_configuration_;
                }

                void configuration(const std::string& value) {

                    m_configuration_ = value;
                }

                void configuration(std::string&& value) {
                    m_configuration_ = std::move(value);
                }
                bool operator == (const EntityConfig& other_) const;
                bool operator != (const EntityConfig& other_) const;

                void swap(EntityConfig& other_) noexcept ;

              private:

                std::string m_resource_id_;
                std::string m_configuration_;

            };

            inline void swap(EntityConfig& a, EntityConfig& b)  noexcept 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const EntityConfig& sample);

            class NDDSUSERDllExport EntityEvent {
              public:

                EntityEvent();

                explicit EntityEvent(const ::RTI::Service::EntityStateKind& state_);

                ::RTI::Service::EntityStateKind& state() noexcept {
                    return m_state_;
                }

                const ::RTI::Service::EntityStateKind& state() const noexcept {
                    return m_state_;
                }

                void state(const ::RTI::Service::EntityStateKind& value) {

                    m_state_ = value;
                }

                void state(::RTI::Service::EntityStateKind&& value) {
                    m_state_ = std::move(value);
                }
                bool operator == (const EntityEvent& other_) const;
                bool operator != (const EntityEvent& other_) const;

                void swap(EntityEvent& other_) noexcept ;

              private:

                ::RTI::Service::EntityStateKind m_state_;

            };

            inline void swap(EntityEvent& a, EntityEvent& b)  noexcept 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const EntityEvent& sample);

            enum class DistributionTopicKind {
                CONFIG, 
                EVENT, 
                PERIODIC
            };

            NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const DistributionTopicKind& sample);
            enum class ResourceKindIndex {
                DDS_INDEX = 1, 
                ROUTING_INDEX = 10000, 
                RECORDING_INDEX = 20000, 
                CDS_INDEX = 30000
            };

            NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const ResourceKindIndex& sample);
            enum class ResourceKind {
                UNKNOWN, 
                ROUTING_SERVICE = 10000, 
                ROUTING_DOMAIN_ROUTE, 
                ROUTING_SESSION, 
                ROUTING_AUTO_ROUTE, 
                ROUTING_ROUTE, 
                ROUTING_INPUT, 
                ROUTING_OUTPUT, 
                RECORDING_SERVICE = 20000, 
                RECORDING_SESSION, 
                RECORDING_TOPIC_GROUP, 
                RECORDING_TOPIC, 
                CDS_SERVICE = 30000, 
                CDS_FORWARDER, 
                CDS_DATABASE, 
                CDS_RECEIVER, 
                CDS_SENDER
            };

            NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const ResourceKind& sample);

            static const std::string CONFIG_TOPIC_NAME = "rti/service/monitoring/config";

            static const std::string EVENT_TOPIC_NAME = "rti/service/monitoring/event";

            static const std::string PERIODIC_TOPIC_NAME = "rti/service/monitoring/periodic";

            static const std::string CONFIG_REGISTERED_TYPE_NAME = "RTI::Service::Monitoring::Config";

            static const std::string EVENT_REGISTERED_TYPE_NAME = "RTI::Service::Monitoring::Event";

            static const std::string PERIODIC_REGISTERED_TYPE_NAME = "RTI::Service::Monitoring::Periodic";
        } // namespace Monitoring  
    } // namespace Service  
} // namespace RTI  

#ifdef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace topic {
        template <>
        struct default_enumerator< ::RTI::Service::EntityStateKind>
        {
            static const ::RTI::Service::EntityStateKind value;
        };
        template <>
        struct default_enumerator< ::RTI::Service::Monitoring::DistributionTopicKind>
        {
            static const ::RTI::Service::Monitoring::DistributionTopicKind value;
        };
        template <>
        struct default_enumerator< ::RTI::Service::Monitoring::ResourceKindIndex>
        {
            static const ::RTI::Service::Monitoring::ResourceKindIndex value;
        };
        template <>
        struct default_enumerator< ::RTI::Service::Monitoring::ResourceKind>
        {
            static const ::RTI::Service::Monitoring::ResourceKind value;
        };
    }
}
#else

namespace rti {
    namespace flat {
        namespace topic {
        }
    }
}
namespace dds {
    namespace topic {

        template<>
        struct topic_type_name< ::RTI::Service::EntityState > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::EntityState";
            }
        };

        template<>
        struct is_topic_type< ::RTI::Service::EntityState > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::RTI::Service::EntityState > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::RTI::Service::EntityState& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::RTI::Service::EntityState& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::RTI::Service::EntityState& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::RTI::Service::EntityState& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::RTI::Service::BuiltinTopicKey > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::BuiltinTopicKey";
            }
        };

        template<>
        struct topic_type_support< ::RTI::Service::BuiltinTopicKey > {
            NDDSUSERDllExport 
            static void reset_sample(::RTI::Service::BuiltinTopicKey& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::RTI::Service::BuiltinTopicKey& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::RTI::Service::Monitoring::ResourceGuid > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::ResourceGuid";
            }
        };

        template<>
        struct is_topic_type< ::RTI::Service::Monitoring::ResourceGuid > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::RTI::Service::Monitoring::ResourceGuid > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::RTI::Service::Monitoring::ResourceGuid& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::RTI::Service::Monitoring::ResourceGuid& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::RTI::Service::Monitoring::ResourceGuid& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::RTI::Service::Monitoring::ResourceGuid& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::RTI::Service::Monitoring::KeyedResource > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::KeyedResource";
            }
        };

        template<>
        struct is_topic_type< ::RTI::Service::Monitoring::KeyedResource > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::RTI::Service::Monitoring::KeyedResource > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::RTI::Service::Monitoring::KeyedResource& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::RTI::Service::Monitoring::KeyedResource& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::RTI::Service::Monitoring::KeyedResource& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::RTI::Service::Monitoring::KeyedResource& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::RTI::Service::Monitoring::StatisticMetrics > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::StatisticMetrics";
            }
        };

        template<>
        struct topic_type_support< ::RTI::Service::Monitoring::StatisticMetrics > {
            NDDSUSERDllExport 
            static void reset_sample(::RTI::Service::Monitoring::StatisticMetrics& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::RTI::Service::Monitoring::StatisticMetrics& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::RTI::Service::Monitoring::StatisticVariable > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::StatisticVariable";
            }
        };

        template<>
        struct topic_type_support< ::RTI::Service::Monitoring::StatisticVariable > {
            NDDSUSERDllExport 
            static void reset_sample(::RTI::Service::Monitoring::StatisticVariable& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::RTI::Service::Monitoring::StatisticVariable& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::RTI::Service::Monitoring::CountStatus > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::CountStatus";
            }
        };

        template<>
        struct topic_type_support< ::RTI::Service::Monitoring::CountStatus > {
            NDDSUSERDllExport 
            static void reset_sample(::RTI::Service::Monitoring::CountStatus& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::RTI::Service::Monitoring::CountStatus& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::RTI::Service::Monitoring::ProcessConfig > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::ProcessConfig";
            }
        };

        template<>
        struct topic_type_support< ::RTI::Service::Monitoring::ProcessConfig > {
            NDDSUSERDllExport 
            static void reset_sample(::RTI::Service::Monitoring::ProcessConfig& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::RTI::Service::Monitoring::ProcessConfig& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::RTI::Service::Monitoring::ProcessPeriodic > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::ProcessPeriodic";
            }
        };

        template<>
        struct topic_type_support< ::RTI::Service::Monitoring::ProcessPeriodic > {
            NDDSUSERDllExport 
            static void reset_sample(::RTI::Service::Monitoring::ProcessPeriodic& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::RTI::Service::Monitoring::ProcessPeriodic& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::RTI::Service::Monitoring::ThreadPeriodic > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::ThreadPeriodic";
            }
        };

        template<>
        struct topic_type_support< ::RTI::Service::Monitoring::ThreadPeriodic > {
            NDDSUSERDllExport 
            static void reset_sample(::RTI::Service::Monitoring::ThreadPeriodic& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::RTI::Service::Monitoring::ThreadPeriodic& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::RTI::Service::Monitoring::ThreadPoolPeriodic > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::ThreadPoolPeriodic";
            }
        };

        template<>
        struct topic_type_support< ::RTI::Service::Monitoring::ThreadPoolPeriodic > {
            NDDSUSERDllExport 
            static void reset_sample(::RTI::Service::Monitoring::ThreadPoolPeriodic& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::RTI::Service::Monitoring::ThreadPoolPeriodic& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::RTI::Service::Monitoring::HostPeriodic > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::HostPeriodic";
            }
        };

        template<>
        struct topic_type_support< ::RTI::Service::Monitoring::HostPeriodic > {
            NDDSUSERDllExport 
            static void reset_sample(::RTI::Service::Monitoring::HostPeriodic& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::RTI::Service::Monitoring::HostPeriodic& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::RTI::Service::Monitoring::HostConfig > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::HostConfig";
            }
        };

        template<>
        struct topic_type_support< ::RTI::Service::Monitoring::HostConfig > {
            NDDSUSERDllExport 
            static void reset_sample(::RTI::Service::Monitoring::HostConfig& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::RTI::Service::Monitoring::HostConfig& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::RTI::Service::Monitoring::NetworkPerformance > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::NetworkPerformance";
            }
        };

        template<>
        struct topic_type_support< ::RTI::Service::Monitoring::NetworkPerformance > {
            NDDSUSERDllExport 
            static void reset_sample(::RTI::Service::Monitoring::NetworkPerformance& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::RTI::Service::Monitoring::NetworkPerformance& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::RTI::Service::Monitoring::EntityConfig > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::EntityConfig";
            }
        };

        template<>
        struct topic_type_support< ::RTI::Service::Monitoring::EntityConfig > {
            NDDSUSERDllExport 
            static void reset_sample(::RTI::Service::Monitoring::EntityConfig& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::RTI::Service::Monitoring::EntityConfig& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::RTI::Service::Monitoring::EntityEvent > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::EntityEvent";
            }
        };

        template<>
        struct topic_type_support< ::RTI::Service::Monitoring::EntityEvent > {
            NDDSUSERDllExport 
            static void reset_sample(::RTI::Service::Monitoring::EntityEvent& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::RTI::Service::Monitoring::EntityEvent& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
    }
}

namespace rti { 
    namespace topic {

        template<>
        struct dynamic_type< ::RTI::Service::BoundedString_AliasTag_t > {
            typedef ::dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::AliasType& get();
        };

        template<>
        struct dynamic_type< ::RTI::Service::FilePath_AliasTag_t > {
            typedef ::dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::AliasType& get();
        };

        template<>
        struct dynamic_type< ::RTI::Service::ResourceId_AliasTag_t > {
            typedef ::dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::AliasType& get();
        };

        template<>
        struct dynamic_type< ::RTI::Service::XmlString_AliasTag_t > {
            typedef ::dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::AliasType& get();
        };

        template <>
        struct default_enumerator< ::RTI::Service::EntityStateKind>
        {
            static const ::RTI::Service::EntityStateKind value;
        };
        template<>
        struct dynamic_type< ::RTI::Service::EntityStateKind > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };

        template <>
        struct extensibility< ::RTI::Service::EntityStateKind > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::RTI::Service::EntityState > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::RTI::Service::EntityState > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::RTI::Service::BuiltinTopicKey > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::RTI::Service::BuiltinTopicKey > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::FINAL;    };

        template<>
        struct dynamic_type< ::RTI::Service::Monitoring::ResourceGuid > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::RTI::Service::Monitoring::ResourceGuid > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::FINAL;    };

        template<>
        struct dynamic_type< ::RTI::Service::Monitoring::KeyedResource > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::RTI::Service::Monitoring::KeyedResource > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;    };

        template<>
        struct dynamic_type< ::RTI::Service::Monitoring::StatisticMetrics > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::RTI::Service::Monitoring::StatisticMetrics > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::RTI::Service::Monitoring::StatisticVariable > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::RTI::Service::Monitoring::StatisticVariable > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::RTI::Service::Monitoring::CountStatus > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::RTI::Service::Monitoring::CountStatus > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;    };

        template<>
        struct dynamic_type< ::RTI::Service::Monitoring::ProcessConfig > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::RTI::Service::Monitoring::ProcessConfig > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::RTI::Service::Monitoring::ProcessPeriodic > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::RTI::Service::Monitoring::ProcessPeriodic > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;    };

        template<>
        struct dynamic_type< ::RTI::Service::Monitoring::ThreadPeriodic > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::RTI::Service::Monitoring::ThreadPeriodic > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;    };

        template<>
        struct dynamic_type< ::RTI::Service::Monitoring::ThreadPoolPeriodic > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::RTI::Service::Monitoring::ThreadPoolPeriodic > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;    };

        template<>
        struct dynamic_type< ::RTI::Service::Monitoring::HostPeriodic > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::RTI::Service::Monitoring::HostPeriodic > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::RTI::Service::Monitoring::HostConfig > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::RTI::Service::Monitoring::HostConfig > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::RTI::Service::Monitoring::NetworkPerformance > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::RTI::Service::Monitoring::NetworkPerformance > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::RTI::Service::Monitoring::EntityConfig > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::RTI::Service::Monitoring::EntityConfig > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;    };

        template<>
        struct dynamic_type< ::RTI::Service::Monitoring::EntityEvent > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::RTI::Service::Monitoring::EntityEvent > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;    };

        template <>
        struct default_enumerator< ::RTI::Service::Monitoring::DistributionTopicKind>
        {
            static const ::RTI::Service::Monitoring::DistributionTopicKind value;
        };
        template<>
        struct dynamic_type< ::RTI::Service::Monitoring::DistributionTopicKind > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };

        template <>
        struct extensibility< ::RTI::Service::Monitoring::DistributionTopicKind > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template <>
        struct default_enumerator< ::RTI::Service::Monitoring::ResourceKindIndex>
        {
            static const ::RTI::Service::Monitoring::ResourceKindIndex value;
        };
        template<>
        struct dynamic_type< ::RTI::Service::Monitoring::ResourceKindIndex > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };

        template <>
        struct extensibility< ::RTI::Service::Monitoring::ResourceKindIndex > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;    };

        template <>
        struct default_enumerator< ::RTI::Service::Monitoring::ResourceKind>
        {
            static const ::RTI::Service::Monitoring::ResourceKind value;
        };
        template<>
        struct dynamic_type< ::RTI::Service::Monitoring::ResourceKind > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };

        template <>
        struct extensibility< ::RTI::Service::Monitoring::ResourceKind > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;    };

    }
}

#endif // NDDS_STANDALONE_TYPE
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // ServiceCommon_1902811798_hpp

