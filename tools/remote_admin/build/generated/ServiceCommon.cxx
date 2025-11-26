

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ServiceCommon.idl
using RTI Code Generator (rtiddsgen) version 4.3.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include <iosfwd>
#include <iomanip>
#include <cmath>
#include <limits>

#ifndef NDDS_STANDALONE_TYPE
#include "rti/topic/cdr/Serialization.hpp"
#include "ServiceCommonPlugin.hpp"
#else
#include "rti/topic/cdr/SerializationHelpers.hpp"
#endif

#include "ServiceCommon.hpp"

#include <rti/util/ostream_operators.hpp>

namespace RTI {

    namespace Service {

        std::ostream& operator << (std::ostream& o,const EntityStateKind& sample)
        {
            ::rti::util::StreamFlagSaver flag_saver (o);
            switch(sample){
                case EntityStateKind::INVALID:
                o << "EntityStateKind::INVALID" << " ";
                break;
                case EntityStateKind::ENABLED:
                o << "EntityStateKind::ENABLED" << " ";
                break;
                case EntityStateKind::DISABLED:
                o << "EntityStateKind::DISABLED" << " ";
                break;
                case EntityStateKind::STARTED:
                o << "EntityStateKind::STARTED" << " ";
                break;
                case EntityStateKind::STOPPED:
                o << "EntityStateKind::STOPPED" << " ";
                break;
                case EntityStateKind::RUNNING:
                o << "EntityStateKind::RUNNING" << " ";
                break;
                case EntityStateKind::PAUSED:
                o << "EntityStateKind::PAUSED" << " ";
                break;
                default:
                {
                    /* Prevents compiler warnings */
                }
            }
            return o;
        }

        // ---- EntityState: 

        EntityState::EntityState() :
            m_state_(RTI::Service::EntityStateKind::INVALID)  {

        }   

        EntityState::EntityState (const ::RTI::Service::EntityStateKind& state_):
            m_state_(state_) {
        }

        void EntityState::swap(EntityState& other_)  noexcept 
        {
            using std::swap;
            swap(m_state_, other_.m_state_);
        }  

        bool EntityState::operator == (const EntityState& other_) const {
            if (m_state_ != other_.m_state_) {
                return false;
            }
            return true;
        }

        bool EntityState::operator != (const EntityState& other_) const {
            return !this->operator ==(other_);
        }

        std::ostream& operator << (std::ostream& o,const EntityState& sample)
        {
            ::rti::util::StreamFlagSaver flag_saver (o);
            o <<"[";
            o << "state: " << sample.state ();
            o <<"]";
            return o;
        }

        // ---- BuiltinTopicKey: 

        BuiltinTopicKey::BuiltinTopicKey()  {

        }   

        BuiltinTopicKey::BuiltinTopicKey (const ::dds::core::array< uint32_t, (RTI::Service::BUILTIN_TOPIC_KEY_VALUE_LENGTH)>& value_):
            m_value_(value_) {
        }

        void BuiltinTopicKey::swap(BuiltinTopicKey& other_)  noexcept 
        {
            using std::swap;
            swap(m_value_, other_.m_value_);
        }  

        bool BuiltinTopicKey::operator == (const BuiltinTopicKey& other_) const {
            if (m_value_ != other_.m_value_) {
                return false;
            }
            return true;
        }

        bool BuiltinTopicKey::operator != (const BuiltinTopicKey& other_) const {
            return !this->operator ==(other_);
        }

        std::ostream& operator << (std::ostream& o,const BuiltinTopicKey& sample)
        {
            ::rti::util::StreamFlagSaver flag_saver (o);
            o <<"[";
            o << "value: " << sample.value ();
            o <<"]";
            return o;
        }

        namespace Monitoring {

            // ---- ResourceGuid: 

            ResourceGuid::ResourceGuid()  {

            }   

            ResourceGuid::ResourceGuid (const ::dds::core::array< uint8_t, (RTI::Service::Monitoring::RESOURCE_GUID_VALUE_LENGTH)>& value_):
                m_value_(value_) {
            }

            void ResourceGuid::swap(ResourceGuid& other_)  noexcept 
            {
                using std::swap;
                swap(m_value_, other_.m_value_);
            }  

            bool ResourceGuid::operator == (const ResourceGuid& other_) const {
                if (m_value_ != other_.m_value_) {
                    return false;
                }
                return true;
            }

            bool ResourceGuid::operator != (const ResourceGuid& other_) const {
                return !this->operator ==(other_);
            }

            std::ostream& operator << (std::ostream& o,const ResourceGuid& sample)
            {
                ::rti::util::StreamFlagSaver flag_saver (o);
                o <<"[";
                o << "value: " << sample.value ();
                o <<"]";
                return o;
            }

            // ---- KeyedResource: 

            KeyedResource::KeyedResource()  {

            }   

            KeyedResource::KeyedResource (const ::RTI::Service::Monitoring::ResourceGuid& object_guid_,const ::RTI::Service::Monitoring::ResourceGuid& owner_guid_):
                m_object_guid_(object_guid_), 
                m_owner_guid_(owner_guid_) {
            }

            void KeyedResource::swap(KeyedResource& other_)  noexcept 
            {
                using std::swap;
                swap(m_object_guid_, other_.m_object_guid_);
                swap(m_owner_guid_, other_.m_owner_guid_);
            }  

            bool KeyedResource::operator == (const KeyedResource& other_) const {
                if (m_object_guid_ != other_.m_object_guid_) {
                    return false;
                }
                if (m_owner_guid_ != other_.m_owner_guid_) {
                    return false;
                }
                return true;
            }

            bool KeyedResource::operator != (const KeyedResource& other_) const {
                return !this->operator ==(other_);
            }

            std::ostream& operator << (std::ostream& o,const KeyedResource& sample)
            {
                ::rti::util::StreamFlagSaver flag_saver (o);
                o <<"[";
                o << "object_guid: " << sample.object_guid ()<<", ";
                o << "owner_guid: " << sample.owner_guid ();
                o <<"]";
                return o;
            }

            // ---- StatisticMetrics: 

            StatisticMetrics::StatisticMetrics() :
                m_period_ms_ (0ull) ,
                m_count_ (0ll) ,
                m_mean_ (0.0f) ,
                m_minimum_ (0.0f) ,
                m_maximum_ (0.0f) ,
                m_std_dev_ (0.0f)  {

            }   

            StatisticMetrics::StatisticMetrics (uint64_t period_ms_,int64_t count_,float mean_,float minimum_,float maximum_,float std_dev_):
                m_period_ms_(period_ms_), 
                m_count_(count_), 
                m_mean_(mean_), 
                m_minimum_(minimum_), 
                m_maximum_(maximum_), 
                m_std_dev_(std_dev_) {
            }

            void StatisticMetrics::swap(StatisticMetrics& other_)  noexcept 
            {
                using std::swap;
                swap(m_period_ms_, other_.m_period_ms_);
                swap(m_count_, other_.m_count_);
                swap(m_mean_, other_.m_mean_);
                swap(m_minimum_, other_.m_minimum_);
                swap(m_maximum_, other_.m_maximum_);
                swap(m_std_dev_, other_.m_std_dev_);
            }  

            bool StatisticMetrics::operator == (const StatisticMetrics& other_) const {
                if (m_period_ms_ != other_.m_period_ms_) {
                    return false;
                }
                if (m_count_ != other_.m_count_) {
                    return false;
                }
                if (std::fabs(m_mean_ - other_.m_mean_) > std::numeric_limits< float>::epsilon()
                && !(std::fabs(m_mean_ - other_.m_mean_) < (std::numeric_limits< float>::min)())) {
                    return false;
                }
                if (std::fabs(m_minimum_ - other_.m_minimum_) > std::numeric_limits< float>::epsilon()
                && !(std::fabs(m_minimum_ - other_.m_minimum_) < (std::numeric_limits< float>::min)())) {
                    return false;
                }
                if (std::fabs(m_maximum_ - other_.m_maximum_) > std::numeric_limits< float>::epsilon()
                && !(std::fabs(m_maximum_ - other_.m_maximum_) < (std::numeric_limits< float>::min)())) {
                    return false;
                }
                if (std::fabs(m_std_dev_ - other_.m_std_dev_) > std::numeric_limits< float>::epsilon()
                && !(std::fabs(m_std_dev_ - other_.m_std_dev_) < (std::numeric_limits< float>::min)())) {
                    return false;
                }
                return true;
            }

            bool StatisticMetrics::operator != (const StatisticMetrics& other_) const {
                return !this->operator ==(other_);
            }

            std::ostream& operator << (std::ostream& o,const StatisticMetrics& sample)
            {
                ::rti::util::StreamFlagSaver flag_saver (o);
                o <<"[";
                o << "period_ms: " << sample.period_ms ()<<", ";
                o << "count: " << sample.count ()<<", ";
                o << "mean: " << std::setprecision(9) << sample.mean ()<<", ";
                o << "minimum: " << std::setprecision(9) << sample.minimum ()<<", ";
                o << "maximum: " << std::setprecision(9) << sample.maximum ()<<", ";
                o << "std_dev: " << std::setprecision(9) << sample.std_dev ();
                o <<"]";
                return o;
            }

            // ---- StatisticVariable: 

            StatisticVariable::StatisticVariable()  {

            }   

            StatisticVariable::StatisticVariable (const ::RTI::Service::Monitoring::StatisticMetrics& publication_period_metrics_):
                m_publication_period_metrics_(publication_period_metrics_) {
            }

            void StatisticVariable::swap(StatisticVariable& other_)  noexcept 
            {
                using std::swap;
                swap(m_publication_period_metrics_, other_.m_publication_period_metrics_);
            }  

            bool StatisticVariable::operator == (const StatisticVariable& other_) const {
                if (m_publication_period_metrics_ != other_.m_publication_period_metrics_) {
                    return false;
                }
                return true;
            }

            bool StatisticVariable::operator != (const StatisticVariable& other_) const {
                return !this->operator ==(other_);
            }

            std::ostream& operator << (std::ostream& o,const StatisticVariable& sample)
            {
                ::rti::util::StreamFlagSaver flag_saver (o);
                o <<"[";
                o << "publication_period_metrics: " << sample.publication_period_metrics ();
                o <<"]";
                return o;
            }

            // ---- CountStatus: 

            CountStatus::CountStatus() :
                m_total_count_ (0ll) ,
                m_current_count_ (0ll) ,
                m_current_count_peak_ (0ll)  {

            }   

            CountStatus::CountStatus (int64_t total_count_,int64_t current_count_,int64_t current_count_peak_):
                m_total_count_(total_count_), 
                m_current_count_(current_count_), 
                m_current_count_peak_(current_count_peak_) {
            }

            void CountStatus::swap(CountStatus& other_)  noexcept 
            {
                using std::swap;
                swap(m_total_count_, other_.m_total_count_);
                swap(m_current_count_, other_.m_current_count_);
                swap(m_current_count_peak_, other_.m_current_count_peak_);
            }  

            bool CountStatus::operator == (const CountStatus& other_) const {
                if (m_total_count_ != other_.m_total_count_) {
                    return false;
                }
                if (m_current_count_ != other_.m_current_count_) {
                    return false;
                }
                if (m_current_count_peak_ != other_.m_current_count_peak_) {
                    return false;
                }
                return true;
            }

            bool CountStatus::operator != (const CountStatus& other_) const {
                return !this->operator ==(other_);
            }

            std::ostream& operator << (std::ostream& o,const CountStatus& sample)
            {
                ::rti::util::StreamFlagSaver flag_saver (o);
                o <<"[";
                o << "total_count: " << sample.total_count ()<<", ";
                o << "current_count: " << sample.current_count ()<<", ";
                o << "current_count_peak: " << sample.current_count_peak ();
                o <<"]";
                return o;
            }

            // ---- ProcessConfig: 

            ProcessConfig::ProcessConfig() :
                m_id_ (0ull)  {

            }   

            ProcessConfig::ProcessConfig (uint64_t id_):
                m_id_(id_) {
            }

            void ProcessConfig::swap(ProcessConfig& other_)  noexcept 
            {
                using std::swap;
                swap(m_id_, other_.m_id_);
            }  

            bool ProcessConfig::operator == (const ProcessConfig& other_) const {
                if (m_id_ != other_.m_id_) {
                    return false;
                }
                return true;
            }

            bool ProcessConfig::operator != (const ProcessConfig& other_) const {
                return !this->operator ==(other_);
            }

            std::ostream& operator << (std::ostream& o,const ProcessConfig& sample)
            {
                ::rti::util::StreamFlagSaver flag_saver (o);
                o <<"[";
                o << "id: " << sample.id ();
                o <<"]";
                return o;
            }

            // ---- ProcessPeriodic: 

            ProcessPeriodic::ProcessPeriodic() :
                m_uptime_sec_ (0)  {

            }   

            ProcessPeriodic::ProcessPeriodic (const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& cpu_usage_percentage_,const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& physical_memory_kb_,const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& total_memory_kb_,int32_t uptime_sec_):
                m_cpu_usage_percentage_(cpu_usage_percentage_), 
                m_physical_memory_kb_(physical_memory_kb_), 
                m_total_memory_kb_(total_memory_kb_), 
                m_uptime_sec_(uptime_sec_) {
            }

            void ProcessPeriodic::swap(ProcessPeriodic& other_)  noexcept 
            {
                using std::swap;
                swap(m_cpu_usage_percentage_, other_.m_cpu_usage_percentage_);
                swap(m_physical_memory_kb_, other_.m_physical_memory_kb_);
                swap(m_total_memory_kb_, other_.m_total_memory_kb_);
                swap(m_uptime_sec_, other_.m_uptime_sec_);
            }  

            bool ProcessPeriodic::operator == (const ProcessPeriodic& other_) const {
                if (m_cpu_usage_percentage_ != other_.m_cpu_usage_percentage_) {
                    return false;
                }
                if (m_physical_memory_kb_ != other_.m_physical_memory_kb_) {
                    return false;
                }
                if (m_total_memory_kb_ != other_.m_total_memory_kb_) {
                    return false;
                }
                if (m_uptime_sec_ != other_.m_uptime_sec_) {
                    return false;
                }
                return true;
            }

            bool ProcessPeriodic::operator != (const ProcessPeriodic& other_) const {
                return !this->operator ==(other_);
            }

            std::ostream& operator << (std::ostream& o,const ProcessPeriodic& sample)
            {
                ::rti::util::StreamFlagSaver flag_saver (o);
                o <<"[";
                o << "cpu_usage_percentage: " << sample.cpu_usage_percentage ()<<", ";
                o << "physical_memory_kb: " << sample.physical_memory_kb ()<<", ";
                o << "total_memory_kb: " << sample.total_memory_kb ()<<", ";
                o << "uptime_sec: " << sample.uptime_sec ();
                o <<"]";
                return o;
            }

            // ---- ThreadPeriodic: 

            ThreadPeriodic::ThreadPeriodic() :
                m_id_ (0ull)  {

            }   

            ThreadPeriodic::ThreadPeriodic (uint64_t id_,const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& cpu_usage_percentage_):
                m_id_(id_), 
                m_cpu_usage_percentage_(cpu_usage_percentage_) {
            }

            void ThreadPeriodic::swap(ThreadPeriodic& other_)  noexcept 
            {
                using std::swap;
                swap(m_id_, other_.m_id_);
                swap(m_cpu_usage_percentage_, other_.m_cpu_usage_percentage_);
            }  

            bool ThreadPeriodic::operator == (const ThreadPeriodic& other_) const {
                if (m_id_ != other_.m_id_) {
                    return false;
                }
                if (m_cpu_usage_percentage_ != other_.m_cpu_usage_percentage_) {
                    return false;
                }
                return true;
            }

            bool ThreadPeriodic::operator != (const ThreadPeriodic& other_) const {
                return !this->operator ==(other_);
            }

            std::ostream& operator << (std::ostream& o,const ThreadPeriodic& sample)
            {
                ::rti::util::StreamFlagSaver flag_saver (o);
                o <<"[";
                o << "id: " << sample.id ()<<", ";
                o << "cpu_usage_percentage: " << sample.cpu_usage_percentage ();
                o <<"]";
                return o;
            }

            // ---- ThreadPoolPeriodic: 

            ThreadPoolPeriodic::ThreadPoolPeriodic()  {

            }   

            ThreadPoolPeriodic::ThreadPoolPeriodic (const ::dds::core::optional< std::vector< ::RTI::Service::Monitoring::ThreadPeriodic > >& threads_):
                m_threads_(threads_) {
            }

            void ThreadPoolPeriodic::swap(ThreadPoolPeriodic& other_)  noexcept 
            {
                using std::swap;
                swap(m_threads_, other_.m_threads_);
            }  

            bool ThreadPoolPeriodic::operator == (const ThreadPoolPeriodic& other_) const {
                if (m_threads_ != other_.m_threads_) {
                    return false;
                }
                return true;
            }

            bool ThreadPoolPeriodic::operator != (const ThreadPoolPeriodic& other_) const {
                return !this->operator ==(other_);
            }

            std::ostream& operator << (std::ostream& o,const ThreadPoolPeriodic& sample)
            {
                ::rti::util::StreamFlagSaver flag_saver (o);
                o <<"[";
                o << "threads: " << sample.threads ();
                o <<"]";
                return o;
            }

            // ---- HostPeriodic: 

            HostPeriodic::HostPeriodic() :
                m_uptime_sec_ (0)  {

            }   

            HostPeriodic::HostPeriodic (const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& cpu_usage_percentage_,const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& free_memory_kb_,const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& free_swap_memory_kb_,int32_t uptime_sec_):
                m_cpu_usage_percentage_(cpu_usage_percentage_), 
                m_free_memory_kb_(free_memory_kb_), 
                m_free_swap_memory_kb_(free_swap_memory_kb_), 
                m_uptime_sec_(uptime_sec_) {
            }

            void HostPeriodic::swap(HostPeriodic& other_)  noexcept 
            {
                using std::swap;
                swap(m_cpu_usage_percentage_, other_.m_cpu_usage_percentage_);
                swap(m_free_memory_kb_, other_.m_free_memory_kb_);
                swap(m_free_swap_memory_kb_, other_.m_free_swap_memory_kb_);
                swap(m_uptime_sec_, other_.m_uptime_sec_);
            }  

            bool HostPeriodic::operator == (const HostPeriodic& other_) const {
                if (m_cpu_usage_percentage_ != other_.m_cpu_usage_percentage_) {
                    return false;
                }
                if (m_free_memory_kb_ != other_.m_free_memory_kb_) {
                    return false;
                }
                if (m_free_swap_memory_kb_ != other_.m_free_swap_memory_kb_) {
                    return false;
                }
                if (m_uptime_sec_ != other_.m_uptime_sec_) {
                    return false;
                }
                return true;
            }

            bool HostPeriodic::operator != (const HostPeriodic& other_) const {
                return !this->operator ==(other_);
            }

            std::ostream& operator << (std::ostream& o,const HostPeriodic& sample)
            {
                ::rti::util::StreamFlagSaver flag_saver (o);
                o <<"[";
                o << "cpu_usage_percentage: " << sample.cpu_usage_percentage ()<<", ";
                o << "free_memory_kb: " << sample.free_memory_kb ()<<", ";
                o << "free_swap_memory_kb: " << sample.free_swap_memory_kb ()<<", ";
                o << "uptime_sec: " << sample.uptime_sec ();
                o <<"]";
                return o;
            }

            // ---- HostConfig: 

            HostConfig::HostConfig() :
                m_name_ ("") ,
                m_id_ (0u) ,
                m_total_memory_kb_ (0ll) ,
                m_total_swap_memory_kb_ (0ll) ,
                m_target_ ("")  {

            }   

            HostConfig::HostConfig (const std::string& name_,uint32_t id_,int64_t total_memory_kb_,int64_t total_swap_memory_kb_,const std::string& target_):
                m_name_(name_), 
                m_id_(id_), 
                m_total_memory_kb_(total_memory_kb_), 
                m_total_swap_memory_kb_(total_swap_memory_kb_), 
                m_target_(target_) {
            }

            void HostConfig::swap(HostConfig& other_)  noexcept 
            {
                using std::swap;
                swap(m_name_, other_.m_name_);
                swap(m_id_, other_.m_id_);
                swap(m_total_memory_kb_, other_.m_total_memory_kb_);
                swap(m_total_swap_memory_kb_, other_.m_total_swap_memory_kb_);
                swap(m_target_, other_.m_target_);
            }  

            bool HostConfig::operator == (const HostConfig& other_) const {
                if (m_name_ != other_.m_name_) {
                    return false;
                }
                if (m_id_ != other_.m_id_) {
                    return false;
                }
                if (m_total_memory_kb_ != other_.m_total_memory_kb_) {
                    return false;
                }
                if (m_total_swap_memory_kb_ != other_.m_total_swap_memory_kb_) {
                    return false;
                }
                if (m_target_ != other_.m_target_) {
                    return false;
                }
                return true;
            }

            bool HostConfig::operator != (const HostConfig& other_) const {
                return !this->operator ==(other_);
            }

            std::ostream& operator << (std::ostream& o,const HostConfig& sample)
            {
                ::rti::util::StreamFlagSaver flag_saver (o);
                o <<"[";
                o << "name: " << sample.name ()<<", ";
                o << "id: " << sample.id ()<<", ";
                o << "total_memory_kb: " << sample.total_memory_kb ()<<", ";
                o << "total_swap_memory_kb: " << sample.total_swap_memory_kb ()<<", ";
                o << "target: " << sample.target ();
                o <<"]";
                return o;
            }

            // ---- NetworkPerformance: 

            NetworkPerformance::NetworkPerformance()  {

            }   

            NetworkPerformance::NetworkPerformance (const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& samples_per_sec_,const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& bytes_per_sec_,const ::dds::core::optional< ::RTI::Service::Monitoring::StatisticVariable >& latency_millisec_):
                m_samples_per_sec_(samples_per_sec_), 
                m_bytes_per_sec_(bytes_per_sec_), 
                m_latency_millisec_(latency_millisec_) {
            }

            void NetworkPerformance::swap(NetworkPerformance& other_)  noexcept 
            {
                using std::swap;
                swap(m_samples_per_sec_, other_.m_samples_per_sec_);
                swap(m_bytes_per_sec_, other_.m_bytes_per_sec_);
                swap(m_latency_millisec_, other_.m_latency_millisec_);
            }  

            bool NetworkPerformance::operator == (const NetworkPerformance& other_) const {
                if (m_samples_per_sec_ != other_.m_samples_per_sec_) {
                    return false;
                }
                if (m_bytes_per_sec_ != other_.m_bytes_per_sec_) {
                    return false;
                }
                if (m_latency_millisec_ != other_.m_latency_millisec_) {
                    return false;
                }
                return true;
            }

            bool NetworkPerformance::operator != (const NetworkPerformance& other_) const {
                return !this->operator ==(other_);
            }

            std::ostream& operator << (std::ostream& o,const NetworkPerformance& sample)
            {
                ::rti::util::StreamFlagSaver flag_saver (o);
                o <<"[";
                o << "samples_per_sec: " << sample.samples_per_sec ()<<", ";
                o << "bytes_per_sec: " << sample.bytes_per_sec ()<<", ";
                o << "latency_millisec: " << sample.latency_millisec ();
                o <<"]";
                return o;
            }

            // ---- EntityConfig: 

            EntityConfig::EntityConfig() :
                m_resource_id_ ("") ,
                m_configuration_ ("")  {

            }   

            EntityConfig::EntityConfig (const std::string& resource_id_,const std::string& configuration_):
                m_resource_id_(resource_id_), 
                m_configuration_(configuration_) {
            }

            void EntityConfig::swap(EntityConfig& other_)  noexcept 
            {
                using std::swap;
                swap(m_resource_id_, other_.m_resource_id_);
                swap(m_configuration_, other_.m_configuration_);
            }  

            bool EntityConfig::operator == (const EntityConfig& other_) const {
                if (m_resource_id_ != other_.m_resource_id_) {
                    return false;
                }
                if (m_configuration_ != other_.m_configuration_) {
                    return false;
                }
                return true;
            }

            bool EntityConfig::operator != (const EntityConfig& other_) const {
                return !this->operator ==(other_);
            }

            std::ostream& operator << (std::ostream& o,const EntityConfig& sample)
            {
                ::rti::util::StreamFlagSaver flag_saver (o);
                o <<"[";
                o << "resource_id: " << sample.resource_id ()<<", ";
                o << "configuration: " << sample.configuration ();
                o <<"]";
                return o;
            }

            // ---- EntityEvent: 

            EntityEvent::EntityEvent() :
                m_state_(RTI::Service::EntityStateKind::INVALID)  {

            }   

            EntityEvent::EntityEvent (const ::RTI::Service::EntityStateKind& state_):
                m_state_(state_) {
            }

            void EntityEvent::swap(EntityEvent& other_)  noexcept 
            {
                using std::swap;
                swap(m_state_, other_.m_state_);
            }  

            bool EntityEvent::operator == (const EntityEvent& other_) const {
                if (m_state_ != other_.m_state_) {
                    return false;
                }
                return true;
            }

            bool EntityEvent::operator != (const EntityEvent& other_) const {
                return !this->operator ==(other_);
            }

            std::ostream& operator << (std::ostream& o,const EntityEvent& sample)
            {
                ::rti::util::StreamFlagSaver flag_saver (o);
                o <<"[";
                o << "state: " << sample.state ();
                o <<"]";
                return o;
            }

            std::ostream& operator << (std::ostream& o,const DistributionTopicKind& sample)
            {
                ::rti::util::StreamFlagSaver flag_saver (o);
                switch(sample){
                    case DistributionTopicKind::CONFIG:
                    o << "DistributionTopicKind::CONFIG" << " ";
                    break;
                    case DistributionTopicKind::EVENT:
                    o << "DistributionTopicKind::EVENT" << " ";
                    break;
                    case DistributionTopicKind::PERIODIC:
                    o << "DistributionTopicKind::PERIODIC" << " ";
                    break;
                    default:
                    {
                        /* Prevents compiler warnings */
                    }
                }
                return o;
            }

            std::ostream& operator << (std::ostream& o,const ResourceKindIndex& sample)
            {
                ::rti::util::StreamFlagSaver flag_saver (o);
                switch(sample){
                    case ResourceKindIndex::DDS_INDEX:
                    o << "ResourceKindIndex::DDS_INDEX" << " ";
                    break;
                    case ResourceKindIndex::ROUTING_INDEX:
                    o << "ResourceKindIndex::ROUTING_INDEX" << " ";
                    break;
                    case ResourceKindIndex::RECORDING_INDEX:
                    o << "ResourceKindIndex::RECORDING_INDEX" << " ";
                    break;
                    case ResourceKindIndex::CDS_INDEX:
                    o << "ResourceKindIndex::CDS_INDEX" << " ";
                    break;
                    default:
                    {
                        /* Prevents compiler warnings */
                    }
                }
                return o;
            }

            std::ostream& operator << (std::ostream& o,const ResourceKind& sample)
            {
                ::rti::util::StreamFlagSaver flag_saver (o);
                switch(sample){
                    case ResourceKind::UNKNOWN:
                    o << "ResourceKind::UNKNOWN" << " ";
                    break;
                    case ResourceKind::ROUTING_SERVICE:
                    o << "ResourceKind::ROUTING_SERVICE" << " ";
                    break;
                    case ResourceKind::ROUTING_DOMAIN_ROUTE:
                    o << "ResourceKind::ROUTING_DOMAIN_ROUTE" << " ";
                    break;
                    case ResourceKind::ROUTING_SESSION:
                    o << "ResourceKind::ROUTING_SESSION" << " ";
                    break;
                    case ResourceKind::ROUTING_AUTO_ROUTE:
                    o << "ResourceKind::ROUTING_AUTO_ROUTE" << " ";
                    break;
                    case ResourceKind::ROUTING_ROUTE:
                    o << "ResourceKind::ROUTING_ROUTE" << " ";
                    break;
                    case ResourceKind::ROUTING_INPUT:
                    o << "ResourceKind::ROUTING_INPUT" << " ";
                    break;
                    case ResourceKind::ROUTING_OUTPUT:
                    o << "ResourceKind::ROUTING_OUTPUT" << " ";
                    break;
                    case ResourceKind::RECORDING_SERVICE:
                    o << "ResourceKind::RECORDING_SERVICE" << " ";
                    break;
                    case ResourceKind::RECORDING_SESSION:
                    o << "ResourceKind::RECORDING_SESSION" << " ";
                    break;
                    case ResourceKind::RECORDING_TOPIC_GROUP:
                    o << "ResourceKind::RECORDING_TOPIC_GROUP" << " ";
                    break;
                    case ResourceKind::RECORDING_TOPIC:
                    o << "ResourceKind::RECORDING_TOPIC" << " ";
                    break;
                    case ResourceKind::CDS_SERVICE:
                    o << "ResourceKind::CDS_SERVICE" << " ";
                    break;
                    case ResourceKind::CDS_FORWARDER:
                    o << "ResourceKind::CDS_FORWARDER" << " ";
                    break;
                    case ResourceKind::CDS_DATABASE:
                    o << "ResourceKind::CDS_DATABASE" << " ";
                    break;
                    case ResourceKind::CDS_RECEIVER:
                    o << "ResourceKind::CDS_RECEIVER" << " ";
                    break;
                    case ResourceKind::CDS_SENDER:
                    o << "ResourceKind::CDS_SENDER" << " ";
                    break;
                    default:
                    {
                        /* Prevents compiler warnings */
                    }
                }
                return o;
            }

        } // namespace Monitoring  

    } // namespace Service  

} // namespace RTI  

#ifdef NDDS_STANDALONE_TYPE
namespace rti {
    namespace topic {
        const ::RTI::Service::EntityStateKind default_enumerator< ::RTI::Service::EntityStateKind>::value = ::RTI::Service::EntityStateKind::INVALID;
        const ::RTI::Service::Monitoring::DistributionTopicKind default_enumerator< ::RTI::Service::Monitoring::DistributionTopicKind>::value = ::RTI::Service::Monitoring::DistributionTopicKind::CONFIG;
        const ::RTI::Service::Monitoring::ResourceKindIndex default_enumerator< ::RTI::Service::Monitoring::ResourceKindIndex>::value = ::RTI::Service::Monitoring::ResourceKindIndex::DDS_INDEX;
        const ::RTI::Service::Monitoring::ResourceKind default_enumerator< ::RTI::Service::Monitoring::ResourceKind>::value = ::RTI::Service::Monitoring::ResourceKind::UNKNOWN;
    }
}

#else
// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code< ::RTI::Service::BoundedString_AliasTag_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode BoundedString_g_tc_string;

                static DDS_TypeCode BoundedString_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"RTI::Service::BoundedString", /* Name */
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
                    }}; /* Type code for  BoundedString */

                if (is_initialized) {
                    return &BoundedString_g_tc;
                }

                is_initialized = RTI_TRUE;

                BoundedString_g_tc_string = initialize_string_typecode(((RTI::Service::BOUNDED_STRING_LENGTH_MAX)));

                BoundedString_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                BoundedString_g_tc._data._typeCode =  (RTICdrTypeCode *)&BoundedString_g_tc_string;

                /* Initialize the values for member annotations. */
                BoundedString_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                BoundedString_g_tc._data._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                BoundedString_g_tc._data._sampleAccessInfo = sample_access_info();
                BoundedString_g_tc._data._typePlugin = type_plugin_info();    

                return &BoundedString_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo BoundedString_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo BoundedString_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &BoundedString_g_sampleAccessInfo;
                }

                BoundedString_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                BoundedString_g_sampleAccessInfo.memberAccessInfos = 
                BoundedString_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::BoundedString);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        BoundedString_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        BoundedString_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                BoundedString_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                BoundedString_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::BoundedString >;

                BoundedString_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &BoundedString_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin BoundedString_g_typePlugin = 
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

                return &BoundedString_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::AliasType& dynamic_type< ::RTI::Service::BoundedString_AliasTag_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::AliasType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::BoundedString_AliasTag_t >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::FilePath_AliasTag_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode FilePath_g_tc_string;

                static DDS_TypeCode FilePath_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"RTI::Service::FilePath", /* Name */
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
                    }}; /* Type code for  FilePath */

                if (is_initialized) {
                    return &FilePath_g_tc;
                }

                is_initialized = RTI_TRUE;

                FilePath_g_tc_string = initialize_string_typecode(((RTI::Service::FILE_PATH_MAX_LENGTH)));

                FilePath_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                FilePath_g_tc._data._typeCode =  (RTICdrTypeCode *)&FilePath_g_tc_string;

                /* Initialize the values for member annotations. */
                FilePath_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                FilePath_g_tc._data._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                FilePath_g_tc._data._sampleAccessInfo = sample_access_info();
                FilePath_g_tc._data._typePlugin = type_plugin_info();    

                return &FilePath_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo FilePath_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo FilePath_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &FilePath_g_sampleAccessInfo;
                }

                FilePath_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                FilePath_g_sampleAccessInfo.memberAccessInfos = 
                FilePath_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::FilePath);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        FilePath_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        FilePath_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                FilePath_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                FilePath_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::FilePath >;

                FilePath_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &FilePath_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin FilePath_g_typePlugin = 
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

                return &FilePath_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::AliasType& dynamic_type< ::RTI::Service::FilePath_AliasTag_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::AliasType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::FilePath_AliasTag_t >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::ResourceId_AliasTag_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode ResourceId_g_tc_string;

                static DDS_TypeCode ResourceId_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"RTI::Service::ResourceId", /* Name */
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
                    }}; /* Type code for  ResourceId */

                if (is_initialized) {
                    return &ResourceId_g_tc;
                }

                is_initialized = RTI_TRUE;

                ResourceId_g_tc_string = initialize_string_typecode(((RTI::Service::RESOURCE_IDENTIFIER_LENGTH_MAX)));

                ResourceId_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                ResourceId_g_tc._data._typeCode =  (RTICdrTypeCode *)&ResourceId_g_tc_string;

                /* Initialize the values for member annotations. */
                ResourceId_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ResourceId_g_tc._data._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                ResourceId_g_tc._data._sampleAccessInfo = sample_access_info();
                ResourceId_g_tc._data._typePlugin = type_plugin_info();    

                return &ResourceId_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo ResourceId_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ResourceId_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ResourceId_g_sampleAccessInfo;
                }

                ResourceId_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                ResourceId_g_sampleAccessInfo.memberAccessInfos = 
                ResourceId_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::ResourceId);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ResourceId_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ResourceId_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ResourceId_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ResourceId_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::ResourceId >;

                ResourceId_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ResourceId_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ResourceId_g_typePlugin = 
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

                return &ResourceId_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::AliasType& dynamic_type< ::RTI::Service::ResourceId_AliasTag_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::AliasType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::ResourceId_AliasTag_t >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::XmlString_AliasTag_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode XmlString_g_tc_string;

                static DDS_TypeCode XmlString_g_tc =
                {{
                        DDS_TK_ALIAS, /* Kind*/
                        DDS_BOOLEAN_FALSE,/* Is a pointer? */
                        -1, /* Ignored */
                        (char *)"RTI::Service::XmlString", /* Name */
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
                    }}; /* Type code for  XmlString */

                if (is_initialized) {
                    return &XmlString_g_tc;
                }

                is_initialized = RTI_TRUE;

                XmlString_g_tc_string = initialize_string_typecode(RTIXCdrLong_MAX);

                XmlString_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                XmlString_g_tc._data._typeCode =  (RTICdrTypeCode *)&XmlString_g_tc_string;

                /* Initialize the values for member annotations. */
                XmlString_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                XmlString_g_tc._data._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                XmlString_g_tc._data._sampleAccessInfo = sample_access_info();
                XmlString_g_tc._data._typePlugin = type_plugin_info();    

                return &XmlString_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo XmlString_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo XmlString_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &XmlString_g_sampleAccessInfo;
                }

                XmlString_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                XmlString_g_sampleAccessInfo.memberAccessInfos = 
                XmlString_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::XmlString);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        XmlString_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        XmlString_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                XmlString_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                XmlString_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::XmlString >;

                XmlString_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &XmlString_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin XmlString_g_typePlugin = 
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

                return &XmlString_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::AliasType& dynamic_type< ::RTI::Service::XmlString_AliasTag_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::AliasType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::XmlString_AliasTag_t >::get())));
        }

        const ::RTI::Service::EntityStateKind default_enumerator< ::RTI::Service::EntityStateKind>::value = ::RTI::Service::EntityStateKind::INVALID;
        template<>
        struct native_type_code< ::RTI::Service::EntityStateKind > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member EntityStateKind_g_tc_members[7]=
                {

                    {
                        (char *)"INVALID",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::EntityStateKind::INVALID), 
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
                        (char *)"ENABLED",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::EntityStateKind::ENABLED), 
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
                        (char *)"DISABLED",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::EntityStateKind::DISABLED), 
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
                        (char *)"STARTED",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::EntityStateKind::STARTED), 
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
                        (char *)"STOPPED",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::EntityStateKind::STOPPED), 
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
                        (char *)"RUNNING",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::EntityStateKind::RUNNING), 
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
                        (char *)"PAUSED",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::EntityStateKind::PAUSED), 
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

                static DDS_TypeCode EntityStateKind_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::EntityStateKind", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        7, /* Number of members */
                        EntityStateKind_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for EntityStateKind*/

                if (is_initialized) {
                    return &EntityStateKind_g_tc;
                }

                is_initialized = RTI_TRUE;

                EntityStateKind_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                EntityStateKind_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                EntityStateKind_g_tc._data._annotations._defaultValue._u.long_value = 0;

                EntityStateKind_g_tc._data._sampleAccessInfo = sample_access_info();
                EntityStateKind_g_tc._data._typePlugin = type_plugin_info();    

                return &EntityStateKind_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo EntityStateKind_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo EntityStateKind_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &EntityStateKind_g_sampleAccessInfo;
                }

                EntityStateKind_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                EntityStateKind_g_sampleAccessInfo.memberAccessInfos = 
                EntityStateKind_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::EntityStateKind);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        EntityStateKind_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        EntityStateKind_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                EntityStateKind_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                EntityStateKind_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::EntityStateKind >;

                EntityStateKind_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &EntityStateKind_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin EntityStateKind_g_typePlugin = 
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

                return &EntityStateKind_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::EnumType& dynamic_type< ::RTI::Service::EntityStateKind >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::EntityStateKind >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::EntityState > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member EntityState_g_tc_members[1]=
                {

                    {
                        (char *)"state",/* Member name */
                        {
                            245289886,/* Representation ID */
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

                static DDS_TypeCode EntityState_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::EntityState", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        EntityState_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for EntityState*/

                if (is_initialized) {
                    return &EntityState_g_tc;
                }

                is_initialized = RTI_TRUE;

                EntityState_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                EntityState_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::EntityStateKind>::get().native();

                /* Initialize the values for member annotations. */
                EntityState_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                EntityState_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;

                EntityState_g_tc._data._sampleAccessInfo = sample_access_info();
                EntityState_g_tc._data._typePlugin = type_plugin_info();    

                return &EntityState_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::RTI::Service::EntityState *sample;

                static RTIXCdrMemberAccessInfo EntityState_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo EntityState_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &EntityState_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::RTI::Service::EntityState);
                if (sample == NULL) {
                    return NULL;
                }

                EntityState_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->state() - (char *)sample);

                EntityState_g_sampleAccessInfo.memberAccessInfos = 
                EntityState_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::EntityState);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        EntityState_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        EntityState_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                EntityState_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                EntityState_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::EntityState >;

                EntityState_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &EntityState_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin EntityState_g_typePlugin = 
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

                return &EntityState_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::RTI::Service::EntityState >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::EntityState >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::BuiltinTopicKey > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode BuiltinTopicKey_g_tc_value_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,(RTI::Service::BUILTIN_TOPIC_KEY_VALUE_LENGTH), NULL,NULL);

                static DDS_TypeCode_Member BuiltinTopicKey_g_tc_members[1]=
                {

                    {
                        (char *)"value",/* Member name */
                        {
                            12673824,/* Representation ID */
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

                static DDS_TypeCode BuiltinTopicKey_g_tc =
                {{
                        DDS_TK_STRUCT| DDS_TK_FINAL_EXTENSIBILITY, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::BuiltinTopicKey", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        BuiltinTopicKey_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for BuiltinTopicKey*/

                if (is_initialized) {
                    return &BuiltinTopicKey_g_tc;
                }

                is_initialized = RTI_TRUE;

                BuiltinTopicKey_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                BuiltinTopicKey_g_tc_value_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_ulong;
                BuiltinTopicKey_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& BuiltinTopicKey_g_tc_value_array;

                /* Initialize the values for member annotations. */

                BuiltinTopicKey_g_tc._data._sampleAccessInfo = sample_access_info();
                BuiltinTopicKey_g_tc._data._typePlugin = type_plugin_info();    

                return &BuiltinTopicKey_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::RTI::Service::BuiltinTopicKey *sample;

                static RTIXCdrMemberAccessInfo BuiltinTopicKey_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo BuiltinTopicKey_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &BuiltinTopicKey_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::RTI::Service::BuiltinTopicKey);
                if (sample == NULL) {
                    return NULL;
                }

                BuiltinTopicKey_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->value() - (char *)sample);

                BuiltinTopicKey_g_sampleAccessInfo.memberAccessInfos = 
                BuiltinTopicKey_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::BuiltinTopicKey);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        BuiltinTopicKey_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        BuiltinTopicKey_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                BuiltinTopicKey_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                BuiltinTopicKey_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::BuiltinTopicKey >;

                BuiltinTopicKey_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &BuiltinTopicKey_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin BuiltinTopicKey_g_typePlugin = 
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

                return &BuiltinTopicKey_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::RTI::Service::BuiltinTopicKey >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::BuiltinTopicKey >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::Monitoring::ResourceGuid > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode ResourceGuid_g_tc_value_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,(RTI::Service::Monitoring::RESOURCE_GUID_VALUE_LENGTH), NULL,NULL);

                static DDS_TypeCode_Member ResourceGuid_g_tc_members[1]=
                {

                    {
                        (char *)"value",/* Member name */
                        {
                            12673824,/* Representation ID */
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

                static DDS_TypeCode ResourceGuid_g_tc =
                {{
                        DDS_TK_STRUCT| DDS_TK_FINAL_EXTENSIBILITY, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::Monitoring::ResourceGuid", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        ResourceGuid_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ResourceGuid*/

                if (is_initialized) {
                    return &ResourceGuid_g_tc;
                }

                is_initialized = RTI_TRUE;

                ResourceGuid_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                ResourceGuid_g_tc_value_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_octet;
                ResourceGuid_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& ResourceGuid_g_tc_value_array;

                /* Initialize the values for member annotations. */

                ResourceGuid_g_tc._data._sampleAccessInfo = sample_access_info();
                ResourceGuid_g_tc._data._typePlugin = type_plugin_info();    

                return &ResourceGuid_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::RTI::Service::Monitoring::ResourceGuid *sample;

                static RTIXCdrMemberAccessInfo ResourceGuid_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ResourceGuid_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ResourceGuid_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::RTI::Service::Monitoring::ResourceGuid);
                if (sample == NULL) {
                    return NULL;
                }

                ResourceGuid_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->value() - (char *)sample);

                ResourceGuid_g_sampleAccessInfo.memberAccessInfos = 
                ResourceGuid_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Monitoring::ResourceGuid);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ResourceGuid_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ResourceGuid_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ResourceGuid_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ResourceGuid_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Monitoring::ResourceGuid >;

                ResourceGuid_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ResourceGuid_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ResourceGuid_g_typePlugin = 
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

                return &ResourceGuid_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::RTI::Service::Monitoring::ResourceGuid >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Monitoring::ResourceGuid >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::Monitoring::KeyedResource > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member KeyedResource_g_tc_members[2]=
                {

                    {
                        (char *)"object_guid",/* Member name */
                        {
                            40060539,/* Representation ID */
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
                        (char *)"owner_guid",/* Member name */
                        {
                            165202898,/* Representation ID */
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

                static DDS_TypeCode KeyedResource_g_tc =
                {{
                        DDS_TK_STRUCT| DDS_TK_MUTABLE_EXTENSIBILITY, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::Monitoring::KeyedResource", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        KeyedResource_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for KeyedResource*/

                if (is_initialized) {
                    return &KeyedResource_g_tc;
                }

                is_initialized = RTI_TRUE;

                KeyedResource_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                KeyedResource_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::Monitoring::ResourceGuid>::get().native();
                KeyedResource_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::Monitoring::ResourceGuid>::get().native();

                /* Initialize the values for member annotations. */

                KeyedResource_g_tc._data._sampleAccessInfo = sample_access_info();
                KeyedResource_g_tc._data._typePlugin = type_plugin_info();    

                return &KeyedResource_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::RTI::Service::Monitoring::KeyedResource *sample;

                static RTIXCdrMemberAccessInfo KeyedResource_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo KeyedResource_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &KeyedResource_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::RTI::Service::Monitoring::KeyedResource);
                if (sample == NULL) {
                    return NULL;
                }

                KeyedResource_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->object_guid() - (char *)sample);

                KeyedResource_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->owner_guid() - (char *)sample);

                KeyedResource_g_sampleAccessInfo.memberAccessInfos = 
                KeyedResource_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Monitoring::KeyedResource);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        KeyedResource_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        KeyedResource_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                KeyedResource_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                KeyedResource_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Monitoring::KeyedResource >;

                KeyedResource_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &KeyedResource_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin KeyedResource_g_typePlugin = 
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

                return &KeyedResource_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::RTI::Service::Monitoring::KeyedResource >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Monitoring::KeyedResource >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::Monitoring::StatisticMetrics > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member StatisticMetrics_g_tc_members[6]=
                {

                    {
                        (char *)"period_ms",/* Member name */
                        {
                            165434195,/* Representation ID */
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
                        (char *)"count",/* Member name */
                        {
                            69899490,/* Representation ID */
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
                        (char *)"mean",/* Member name */
                        {
                            145833401,/* Representation ID */
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
                        (char *)"minimum",/* Member name */
                        {
                            203654115,/* Representation ID */
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
                        (char *)"maximum",/* Member name */
                        {
                            149074021,/* Representation ID */
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
                        (char *)"std_dev",/* Member name */
                        {
                            136822783,/* Representation ID */
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

                static DDS_TypeCode StatisticMetrics_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::Monitoring::StatisticMetrics", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        6, /* Number of members */
                        StatisticMetrics_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for StatisticMetrics*/

                if (is_initialized) {
                    return &StatisticMetrics_g_tc;
                }

                is_initialized = RTI_TRUE;

                StatisticMetrics_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                StatisticMetrics_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulonglong;
                StatisticMetrics_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_longlong;
                StatisticMetrics_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                StatisticMetrics_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                StatisticMetrics_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                StatisticMetrics_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                /* Initialize the values for member annotations. */
                StatisticMetrics_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ULONGLONG;
                StatisticMetrics_g_tc_members[0]._annotations._defaultValue._u.ulong_long_value = 0ull;
                StatisticMetrics_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_ULONGLONG;
                StatisticMetrics_g_tc_members[0]._annotations._minValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MIN;
                StatisticMetrics_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_ULONGLONG;
                StatisticMetrics_g_tc_members[0]._annotations._maxValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MAX;
                StatisticMetrics_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_LONGLONG;
                StatisticMetrics_g_tc_members[1]._annotations._defaultValue._u.long_long_value = 0ll;
                StatisticMetrics_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_LONGLONG;
                StatisticMetrics_g_tc_members[1]._annotations._minValue._u.long_long_value = RTIXCdrLongLong_MIN;
                StatisticMetrics_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_LONGLONG;
                StatisticMetrics_g_tc_members[1]._annotations._maxValue._u.long_long_value = RTIXCdrLongLong_MAX;
                StatisticMetrics_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                StatisticMetrics_g_tc_members[2]._annotations._defaultValue._u.float_value = 0.0f;
                StatisticMetrics_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                StatisticMetrics_g_tc_members[2]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                StatisticMetrics_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                StatisticMetrics_g_tc_members[2]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;
                StatisticMetrics_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                StatisticMetrics_g_tc_members[3]._annotations._defaultValue._u.float_value = 0.0f;
                StatisticMetrics_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                StatisticMetrics_g_tc_members[3]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                StatisticMetrics_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                StatisticMetrics_g_tc_members[3]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;
                StatisticMetrics_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                StatisticMetrics_g_tc_members[4]._annotations._defaultValue._u.float_value = 0.0f;
                StatisticMetrics_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                StatisticMetrics_g_tc_members[4]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                StatisticMetrics_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                StatisticMetrics_g_tc_members[4]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;
                StatisticMetrics_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                StatisticMetrics_g_tc_members[5]._annotations._defaultValue._u.float_value = 0.0f;
                StatisticMetrics_g_tc_members[5]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                StatisticMetrics_g_tc_members[5]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                StatisticMetrics_g_tc_members[5]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                StatisticMetrics_g_tc_members[5]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

                StatisticMetrics_g_tc._data._sampleAccessInfo = sample_access_info();
                StatisticMetrics_g_tc._data._typePlugin = type_plugin_info();    

                return &StatisticMetrics_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::RTI::Service::Monitoring::StatisticMetrics *sample;

                static RTIXCdrMemberAccessInfo StatisticMetrics_g_memberAccessInfos[6] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo StatisticMetrics_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &StatisticMetrics_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::RTI::Service::Monitoring::StatisticMetrics);
                if (sample == NULL) {
                    return NULL;
                }

                StatisticMetrics_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->period_ms() - (char *)sample);

                StatisticMetrics_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->count() - (char *)sample);

                StatisticMetrics_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->mean() - (char *)sample);

                StatisticMetrics_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->minimum() - (char *)sample);

                StatisticMetrics_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->maximum() - (char *)sample);

                StatisticMetrics_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->std_dev() - (char *)sample);

                StatisticMetrics_g_sampleAccessInfo.memberAccessInfos = 
                StatisticMetrics_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Monitoring::StatisticMetrics);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        StatisticMetrics_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        StatisticMetrics_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                StatisticMetrics_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                StatisticMetrics_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Monitoring::StatisticMetrics >;

                StatisticMetrics_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &StatisticMetrics_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin StatisticMetrics_g_typePlugin = 
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

                return &StatisticMetrics_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::RTI::Service::Monitoring::StatisticMetrics >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Monitoring::StatisticMetrics >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::Monitoring::StatisticVariable > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member StatisticVariable_g_tc_members[1]=
                {

                    {
                        (char *)"publication_period_metrics",/* Member name */
                        {
                            232134331,/* Representation ID */
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

                static DDS_TypeCode StatisticVariable_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::Monitoring::StatisticVariable", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        StatisticVariable_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for StatisticVariable*/

                if (is_initialized) {
                    return &StatisticVariable_g_tc;
                }

                is_initialized = RTI_TRUE;

                StatisticVariable_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                StatisticVariable_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::Monitoring::StatisticMetrics>::get().native();

                /* Initialize the values for member annotations. */

                StatisticVariable_g_tc._data._sampleAccessInfo = sample_access_info();
                StatisticVariable_g_tc._data._typePlugin = type_plugin_info();    

                return &StatisticVariable_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::RTI::Service::Monitoring::StatisticVariable *sample;

                static RTIXCdrMemberAccessInfo StatisticVariable_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo StatisticVariable_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &StatisticVariable_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::RTI::Service::Monitoring::StatisticVariable);
                if (sample == NULL) {
                    return NULL;
                }

                StatisticVariable_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->publication_period_metrics() - (char *)sample);

                StatisticVariable_g_sampleAccessInfo.memberAccessInfos = 
                StatisticVariable_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Monitoring::StatisticVariable);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        StatisticVariable_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        StatisticVariable_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                StatisticVariable_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                StatisticVariable_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Monitoring::StatisticVariable >;

                StatisticVariable_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &StatisticVariable_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin StatisticVariable_g_typePlugin = 
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

                return &StatisticVariable_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::RTI::Service::Monitoring::StatisticVariable >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Monitoring::StatisticVariable >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::Monitoring::CountStatus > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member CountStatus_g_tc_members[3]=
                {

                    {
                        (char *)"total_count",/* Member name */
                        {
                            52314676,/* Representation ID */
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
                        (char *)"current_count",/* Member name */
                        {
                            210848979,/* Representation ID */
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
                        (char *)"current_count_peak",/* Member name */
                        {
                            130880564,/* Representation ID */
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

                static DDS_TypeCode CountStatus_g_tc =
                {{
                        DDS_TK_STRUCT| DDS_TK_MUTABLE_EXTENSIBILITY, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::Monitoring::CountStatus", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        CountStatus_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for CountStatus*/

                if (is_initialized) {
                    return &CountStatus_g_tc;
                }

                is_initialized = RTI_TRUE;

                CountStatus_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                CountStatus_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_longlong;
                CountStatus_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_longlong;
                CountStatus_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_longlong;

                /* Initialize the values for member annotations. */
                CountStatus_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONGLONG;
                CountStatus_g_tc_members[0]._annotations._defaultValue._u.long_long_value = 0ll;
                CountStatus_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONGLONG;
                CountStatus_g_tc_members[0]._annotations._minValue._u.long_long_value = RTIXCdrLongLong_MIN;
                CountStatus_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONGLONG;
                CountStatus_g_tc_members[0]._annotations._maxValue._u.long_long_value = RTIXCdrLongLong_MAX;
                CountStatus_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_LONGLONG;
                CountStatus_g_tc_members[1]._annotations._defaultValue._u.long_long_value = 0ll;
                CountStatus_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_LONGLONG;
                CountStatus_g_tc_members[1]._annotations._minValue._u.long_long_value = RTIXCdrLongLong_MIN;
                CountStatus_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_LONGLONG;
                CountStatus_g_tc_members[1]._annotations._maxValue._u.long_long_value = RTIXCdrLongLong_MAX;
                CountStatus_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_LONGLONG;
                CountStatus_g_tc_members[2]._annotations._defaultValue._u.long_long_value = 0ll;
                CountStatus_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_LONGLONG;
                CountStatus_g_tc_members[2]._annotations._minValue._u.long_long_value = RTIXCdrLongLong_MIN;
                CountStatus_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_LONGLONG;
                CountStatus_g_tc_members[2]._annotations._maxValue._u.long_long_value = RTIXCdrLongLong_MAX;

                CountStatus_g_tc._data._sampleAccessInfo = sample_access_info();
                CountStatus_g_tc._data._typePlugin = type_plugin_info();    

                return &CountStatus_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::RTI::Service::Monitoring::CountStatus *sample;

                static RTIXCdrMemberAccessInfo CountStatus_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo CountStatus_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &CountStatus_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::RTI::Service::Monitoring::CountStatus);
                if (sample == NULL) {
                    return NULL;
                }

                CountStatus_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->total_count() - (char *)sample);

                CountStatus_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->current_count() - (char *)sample);

                CountStatus_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->current_count_peak() - (char *)sample);

                CountStatus_g_sampleAccessInfo.memberAccessInfos = 
                CountStatus_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Monitoring::CountStatus);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        CountStatus_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        CountStatus_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                CountStatus_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                CountStatus_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Monitoring::CountStatus >;

                CountStatus_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &CountStatus_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin CountStatus_g_typePlugin = 
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

                return &CountStatus_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::RTI::Service::Monitoring::CountStatus >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Monitoring::CountStatus >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::Monitoring::ProcessConfig > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member ProcessConfig_g_tc_members[1]=
                {

                    {
                        (char *)"id",/* Member name */
                        {
                            79104952,/* Representation ID */
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

                static DDS_TypeCode ProcessConfig_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::Monitoring::ProcessConfig", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        ProcessConfig_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ProcessConfig*/

                if (is_initialized) {
                    return &ProcessConfig_g_tc;
                }

                is_initialized = RTI_TRUE;

                ProcessConfig_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                ProcessConfig_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulonglong;

                /* Initialize the values for member annotations. */
                ProcessConfig_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ULONGLONG;
                ProcessConfig_g_tc_members[0]._annotations._defaultValue._u.ulong_long_value = 0ull;
                ProcessConfig_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_ULONGLONG;
                ProcessConfig_g_tc_members[0]._annotations._minValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MIN;
                ProcessConfig_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_ULONGLONG;
                ProcessConfig_g_tc_members[0]._annotations._maxValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MAX;

                ProcessConfig_g_tc._data._sampleAccessInfo = sample_access_info();
                ProcessConfig_g_tc._data._typePlugin = type_plugin_info();    

                return &ProcessConfig_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::RTI::Service::Monitoring::ProcessConfig *sample;

                static RTIXCdrMemberAccessInfo ProcessConfig_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ProcessConfig_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ProcessConfig_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::RTI::Service::Monitoring::ProcessConfig);
                if (sample == NULL) {
                    return NULL;
                }

                ProcessConfig_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->id() - (char *)sample);

                ProcessConfig_g_sampleAccessInfo.memberAccessInfos = 
                ProcessConfig_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Monitoring::ProcessConfig);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ProcessConfig_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ProcessConfig_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ProcessConfig_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ProcessConfig_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Monitoring::ProcessConfig >;

                ProcessConfig_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ProcessConfig_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ProcessConfig_g_typePlugin = 
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

                return &ProcessConfig_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::RTI::Service::Monitoring::ProcessConfig >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Monitoring::ProcessConfig >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::Monitoring::ProcessPeriodic > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member ProcessPeriodic_g_tc_members[4]=
                {

                    {
                        (char *)"cpu_usage_percentage",/* Member name */
                        {
                            22539634,/* Representation ID */
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
                        (char *)"physical_memory_kb",/* Member name */
                        {
                            128452345,/* Representation ID */
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
                        (char *)"total_memory_kb",/* Member name */
                        {
                            89601480,/* Representation ID */
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
                        (char *)"uptime_sec",/* Member name */
                        {
                            233937351,/* Representation ID */
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

                static DDS_TypeCode ProcessPeriodic_g_tc =
                {{
                        DDS_TK_STRUCT| DDS_TK_MUTABLE_EXTENSIBILITY, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::Monitoring::ProcessPeriodic", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        ProcessPeriodic_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ProcessPeriodic*/

                if (is_initialized) {
                    return &ProcessPeriodic_g_tc;
                }

                is_initialized = RTI_TRUE;

                ProcessPeriodic_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                ProcessPeriodic_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::Monitoring::StatisticVariable>::get().native();
                ProcessPeriodic_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::Monitoring::StatisticVariable>::get().native();
                ProcessPeriodic_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::Monitoring::StatisticVariable>::get().native();
                ProcessPeriodic_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

                /* Initialize the values for member annotations. */
                ProcessPeriodic_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                ProcessPeriodic_g_tc_members[3]._annotations._defaultValue._u.long_value = 0;
                ProcessPeriodic_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                ProcessPeriodic_g_tc_members[3]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                ProcessPeriodic_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                ProcessPeriodic_g_tc_members[3]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                ProcessPeriodic_g_tc._data._sampleAccessInfo = sample_access_info();
                ProcessPeriodic_g_tc._data._typePlugin = type_plugin_info();    

                return &ProcessPeriodic_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::RTI::Service::Monitoring::ProcessPeriodic *sample;

                static RTIXCdrMemberAccessInfo ProcessPeriodic_g_memberAccessInfos[4] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ProcessPeriodic_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ProcessPeriodic_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::RTI::Service::Monitoring::ProcessPeriodic);
                if (sample == NULL) {
                    return NULL;
                }

                ProcessPeriodic_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->cpu_usage_percentage() - (char *)sample);

                ProcessPeriodic_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->physical_memory_kb() - (char *)sample);

                ProcessPeriodic_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->total_memory_kb() - (char *)sample);

                ProcessPeriodic_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->uptime_sec() - (char *)sample);

                ProcessPeriodic_g_sampleAccessInfo.memberAccessInfos = 
                ProcessPeriodic_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Monitoring::ProcessPeriodic);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ProcessPeriodic_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ProcessPeriodic_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ProcessPeriodic_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ProcessPeriodic_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Monitoring::ProcessPeriodic >;

                ProcessPeriodic_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ProcessPeriodic_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ProcessPeriodic_g_typePlugin = 
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

                return &ProcessPeriodic_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::RTI::Service::Monitoring::ProcessPeriodic >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Monitoring::ProcessPeriodic >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::Monitoring::ThreadPeriodic > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member ThreadPeriodic_g_tc_members[2]=
                {

                    {
                        (char *)"id",/* Member name */
                        {
                            79104952,/* Representation ID */
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
                        (char *)"cpu_usage_percentage",/* Member name */
                        {
                            22539634,/* Representation ID */
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
                    }
                };

                static DDS_TypeCode ThreadPeriodic_g_tc =
                {{
                        DDS_TK_STRUCT| DDS_TK_MUTABLE_EXTENSIBILITY, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::Monitoring::ThreadPeriodic", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        ThreadPeriodic_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ThreadPeriodic*/

                if (is_initialized) {
                    return &ThreadPeriodic_g_tc;
                }

                is_initialized = RTI_TRUE;

                ThreadPeriodic_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                ThreadPeriodic_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulonglong;
                ThreadPeriodic_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::Monitoring::StatisticVariable>::get().native();

                /* Initialize the values for member annotations. */
                ThreadPeriodic_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ULONGLONG;
                ThreadPeriodic_g_tc_members[0]._annotations._defaultValue._u.ulong_long_value = 0ull;
                ThreadPeriodic_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_ULONGLONG;
                ThreadPeriodic_g_tc_members[0]._annotations._minValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MIN;
                ThreadPeriodic_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_ULONGLONG;
                ThreadPeriodic_g_tc_members[0]._annotations._maxValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MAX;

                ThreadPeriodic_g_tc._data._sampleAccessInfo = sample_access_info();
                ThreadPeriodic_g_tc._data._typePlugin = type_plugin_info();    

                return &ThreadPeriodic_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::RTI::Service::Monitoring::ThreadPeriodic *sample;

                static RTIXCdrMemberAccessInfo ThreadPeriodic_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ThreadPeriodic_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ThreadPeriodic_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::RTI::Service::Monitoring::ThreadPeriodic);
                if (sample == NULL) {
                    return NULL;
                }

                ThreadPeriodic_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->id() - (char *)sample);

                ThreadPeriodic_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->cpu_usage_percentage() - (char *)sample);

                ThreadPeriodic_g_sampleAccessInfo.memberAccessInfos = 
                ThreadPeriodic_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Monitoring::ThreadPeriodic);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ThreadPeriodic_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ThreadPeriodic_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ThreadPeriodic_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ThreadPeriodic_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Monitoring::ThreadPeriodic >;

                ThreadPeriodic_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ThreadPeriodic_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ThreadPeriodic_g_typePlugin = 
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

                return &ThreadPeriodic_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::RTI::Service::Monitoring::ThreadPeriodic >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Monitoring::ThreadPeriodic >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::Monitoring::ThreadPoolPeriodic > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode ThreadPoolPeriodic_g_tc_threads_sequence;

                static DDS_TypeCode_Member ThreadPoolPeriodic_g_tc_members[1]=
                {

                    {
                        (char *)"threads",/* Member name */
                        {
                            83761417,/* Representation ID */
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
                    }
                };

                static DDS_TypeCode ThreadPoolPeriodic_g_tc =
                {{
                        DDS_TK_STRUCT| DDS_TK_MUTABLE_EXTENSIBILITY, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::Monitoring::ThreadPoolPeriodic", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        ThreadPoolPeriodic_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ThreadPoolPeriodic*/

                if (is_initialized) {
                    return &ThreadPoolPeriodic_g_tc;
                }

                is_initialized = RTI_TRUE;

                ThreadPoolPeriodic_g_tc_threads_sequence = initialize_sequence_typecode< std::vector< ::RTI::Service::Monitoring::ThreadPeriodic > >(RTIXCdrLong_MAX);

                ThreadPoolPeriodic_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                ThreadPoolPeriodic_g_tc_threads_sequence._data._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::Monitoring::ThreadPeriodic>::get().native();
                ThreadPoolPeriodic_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& ThreadPoolPeriodic_g_tc_threads_sequence;

                /* Initialize the values for member annotations. */

                ThreadPoolPeriodic_g_tc._data._sampleAccessInfo = sample_access_info();
                ThreadPoolPeriodic_g_tc._data._typePlugin = type_plugin_info();    

                return &ThreadPoolPeriodic_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::RTI::Service::Monitoring::ThreadPoolPeriodic *sample;

                static RTIXCdrMemberAccessInfo ThreadPoolPeriodic_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ThreadPoolPeriodic_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ThreadPoolPeriodic_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::RTI::Service::Monitoring::ThreadPoolPeriodic);
                if (sample == NULL) {
                    return NULL;
                }

                ThreadPoolPeriodic_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->threads() - (char *)sample);

                ThreadPoolPeriodic_g_sampleAccessInfo.memberAccessInfos = 
                ThreadPoolPeriodic_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Monitoring::ThreadPoolPeriodic);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ThreadPoolPeriodic_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ThreadPoolPeriodic_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ThreadPoolPeriodic_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ThreadPoolPeriodic_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Monitoring::ThreadPoolPeriodic >;

                ThreadPoolPeriodic_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ThreadPoolPeriodic_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ThreadPoolPeriodic_g_typePlugin = 
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

                return &ThreadPoolPeriodic_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::RTI::Service::Monitoring::ThreadPoolPeriodic >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Monitoring::ThreadPoolPeriodic >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::Monitoring::HostPeriodic > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member HostPeriodic_g_tc_members[4]=
                {

                    {
                        (char *)"cpu_usage_percentage",/* Member name */
                        {
                            22539634,/* Representation ID */
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
                        (char *)"free_memory_kb",/* Member name */
                        {
                            226325808,/* Representation ID */
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
                        (char *)"free_swap_memory_kb",/* Member name */
                        {
                            225988660,/* Representation ID */
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
                        (char *)"uptime_sec",/* Member name */
                        {
                            233937351,/* Representation ID */
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

                static DDS_TypeCode HostPeriodic_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::Monitoring::HostPeriodic", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        HostPeriodic_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for HostPeriodic*/

                if (is_initialized) {
                    return &HostPeriodic_g_tc;
                }

                is_initialized = RTI_TRUE;

                HostPeriodic_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                HostPeriodic_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::Monitoring::StatisticVariable>::get().native();
                HostPeriodic_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::Monitoring::StatisticVariable>::get().native();
                HostPeriodic_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::Monitoring::StatisticVariable>::get().native();
                HostPeriodic_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

                /* Initialize the values for member annotations. */
                HostPeriodic_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                HostPeriodic_g_tc_members[3]._annotations._defaultValue._u.long_value = 0;
                HostPeriodic_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                HostPeriodic_g_tc_members[3]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                HostPeriodic_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                HostPeriodic_g_tc_members[3]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                HostPeriodic_g_tc._data._sampleAccessInfo = sample_access_info();
                HostPeriodic_g_tc._data._typePlugin = type_plugin_info();    

                return &HostPeriodic_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::RTI::Service::Monitoring::HostPeriodic *sample;

                static RTIXCdrMemberAccessInfo HostPeriodic_g_memberAccessInfos[4] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo HostPeriodic_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &HostPeriodic_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::RTI::Service::Monitoring::HostPeriodic);
                if (sample == NULL) {
                    return NULL;
                }

                HostPeriodic_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->cpu_usage_percentage() - (char *)sample);

                HostPeriodic_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->free_memory_kb() - (char *)sample);

                HostPeriodic_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->free_swap_memory_kb() - (char *)sample);

                HostPeriodic_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->uptime_sec() - (char *)sample);

                HostPeriodic_g_sampleAccessInfo.memberAccessInfos = 
                HostPeriodic_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Monitoring::HostPeriodic);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        HostPeriodic_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        HostPeriodic_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                HostPeriodic_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                HostPeriodic_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Monitoring::HostPeriodic >;

                HostPeriodic_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &HostPeriodic_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin HostPeriodic_g_typePlugin = 
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

                return &HostPeriodic_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::RTI::Service::Monitoring::HostPeriodic >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Monitoring::HostPeriodic >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::Monitoring::HostConfig > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member HostConfig_g_tc_members[5]=
                {

                    {
                        (char *)"name",/* Member name */
                        {
                            210987184,/* Representation ID */
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
                        (char *)"id",/* Member name */
                        {
                            79104952,/* Representation ID */
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
                        (char *)"total_memory_kb",/* Member name */
                        {
                            89601480,/* Representation ID */
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
                        (char *)"total_swap_memory_kb",/* Member name */
                        {
                            153693844,/* Representation ID */
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
                        (char *)"target",/* Member name */
                        {
                            251375170,/* Representation ID */
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

                static DDS_TypeCode HostConfig_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::Monitoring::HostConfig", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        5, /* Number of members */
                        HostConfig_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for HostConfig*/

                if (is_initialized) {
                    return &HostConfig_g_tc;
                }

                is_initialized = RTI_TRUE;

                HostConfig_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                HostConfig_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::BoundedString_AliasTag_t>::get().native();
                HostConfig_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
                HostConfig_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_longlong;
                HostConfig_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_longlong;
                HostConfig_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::BoundedString_AliasTag_t>::get().native();

                /* Initialize the values for member annotations. */
                HostConfig_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                HostConfig_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
                HostConfig_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                HostConfig_g_tc_members[1]._annotations._defaultValue._u.ulong_value = 0u;
                HostConfig_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                HostConfig_g_tc_members[1]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                HostConfig_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                HostConfig_g_tc_members[1]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;
                HostConfig_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_LONGLONG;
                HostConfig_g_tc_members[2]._annotations._defaultValue._u.long_long_value = 0ll;
                HostConfig_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_LONGLONG;
                HostConfig_g_tc_members[2]._annotations._minValue._u.long_long_value = RTIXCdrLongLong_MIN;
                HostConfig_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_LONGLONG;
                HostConfig_g_tc_members[2]._annotations._maxValue._u.long_long_value = RTIXCdrLongLong_MAX;
                HostConfig_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_LONGLONG;
                HostConfig_g_tc_members[3]._annotations._defaultValue._u.long_long_value = 0ll;
                HostConfig_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_LONGLONG;
                HostConfig_g_tc_members[3]._annotations._minValue._u.long_long_value = RTIXCdrLongLong_MIN;
                HostConfig_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_LONGLONG;
                HostConfig_g_tc_members[3]._annotations._maxValue._u.long_long_value = RTIXCdrLongLong_MAX;
                HostConfig_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                HostConfig_g_tc_members[4]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                HostConfig_g_tc._data._sampleAccessInfo = sample_access_info();
                HostConfig_g_tc._data._typePlugin = type_plugin_info();    

                return &HostConfig_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::RTI::Service::Monitoring::HostConfig *sample;

                static RTIXCdrMemberAccessInfo HostConfig_g_memberAccessInfos[5] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo HostConfig_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &HostConfig_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::RTI::Service::Monitoring::HostConfig);
                if (sample == NULL) {
                    return NULL;
                }

                HostConfig_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->name() - (char *)sample);

                HostConfig_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->id() - (char *)sample);

                HostConfig_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->total_memory_kb() - (char *)sample);

                HostConfig_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->total_swap_memory_kb() - (char *)sample);

                HostConfig_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->target() - (char *)sample);

                HostConfig_g_sampleAccessInfo.memberAccessInfos = 
                HostConfig_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Monitoring::HostConfig);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        HostConfig_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        HostConfig_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                HostConfig_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                HostConfig_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Monitoring::HostConfig >;

                HostConfig_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &HostConfig_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin HostConfig_g_typePlugin = 
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

                return &HostConfig_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::RTI::Service::Monitoring::HostConfig >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Monitoring::HostConfig >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::Monitoring::NetworkPerformance > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member NetworkPerformance_g_tc_members[3]=
                {

                    {
                        (char *)"samples_per_sec",/* Member name */
                        {
                            56607360,/* Representation ID */
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
                        (char *)"bytes_per_sec",/* Member name */
                        {
                            172643302,/* Representation ID */
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
                        (char *)"latency_millisec",/* Member name */
                        {
                            25379405,/* Representation ID */
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
                    }
                };

                static DDS_TypeCode NetworkPerformance_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::Monitoring::NetworkPerformance", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        NetworkPerformance_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for NetworkPerformance*/

                if (is_initialized) {
                    return &NetworkPerformance_g_tc;
                }

                is_initialized = RTI_TRUE;

                NetworkPerformance_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                NetworkPerformance_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::Monitoring::StatisticVariable>::get().native();
                NetworkPerformance_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::Monitoring::StatisticVariable>::get().native();
                NetworkPerformance_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::Monitoring::StatisticVariable>::get().native();

                /* Initialize the values for member annotations. */

                NetworkPerformance_g_tc._data._sampleAccessInfo = sample_access_info();
                NetworkPerformance_g_tc._data._typePlugin = type_plugin_info();    

                return &NetworkPerformance_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::RTI::Service::Monitoring::NetworkPerformance *sample;

                static RTIXCdrMemberAccessInfo NetworkPerformance_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo NetworkPerformance_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &NetworkPerformance_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::RTI::Service::Monitoring::NetworkPerformance);
                if (sample == NULL) {
                    return NULL;
                }

                NetworkPerformance_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->samples_per_sec() - (char *)sample);

                NetworkPerformance_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->bytes_per_sec() - (char *)sample);

                NetworkPerformance_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->latency_millisec() - (char *)sample);

                NetworkPerformance_g_sampleAccessInfo.memberAccessInfos = 
                NetworkPerformance_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Monitoring::NetworkPerformance);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        NetworkPerformance_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        NetworkPerformance_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                NetworkPerformance_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                NetworkPerformance_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Monitoring::NetworkPerformance >;

                NetworkPerformance_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &NetworkPerformance_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin NetworkPerformance_g_typePlugin = 
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

                return &NetworkPerformance_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::RTI::Service::Monitoring::NetworkPerformance >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Monitoring::NetworkPerformance >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::Monitoring::EntityConfig > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member EntityConfig_g_tc_members[2]=
                {

                    {
                        (char *)"resource_id",/* Member name */
                        {
                            200274914,/* Representation ID */
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
                        (char *)"configuration",/* Member name */
                        {
                            50778572,/* Representation ID */
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

                static DDS_TypeCode EntityConfig_g_tc =
                {{
                        DDS_TK_STRUCT| DDS_TK_MUTABLE_EXTENSIBILITY, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::Monitoring::EntityConfig", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        EntityConfig_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for EntityConfig*/

                if (is_initialized) {
                    return &EntityConfig_g_tc;
                }

                is_initialized = RTI_TRUE;

                EntityConfig_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                EntityConfig_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::ResourceId_AliasTag_t>::get().native();
                EntityConfig_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::XmlString_AliasTag_t>::get().native();

                /* Initialize the values for member annotations. */
                EntityConfig_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                EntityConfig_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
                EntityConfig_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                EntityConfig_g_tc_members[1]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                EntityConfig_g_tc._data._sampleAccessInfo = sample_access_info();
                EntityConfig_g_tc._data._typePlugin = type_plugin_info();    

                return &EntityConfig_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::RTI::Service::Monitoring::EntityConfig *sample;

                static RTIXCdrMemberAccessInfo EntityConfig_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo EntityConfig_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &EntityConfig_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::RTI::Service::Monitoring::EntityConfig);
                if (sample == NULL) {
                    return NULL;
                }

                EntityConfig_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->resource_id() - (char *)sample);

                EntityConfig_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->configuration() - (char *)sample);

                EntityConfig_g_sampleAccessInfo.memberAccessInfos = 
                EntityConfig_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Monitoring::EntityConfig);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        EntityConfig_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        EntityConfig_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                EntityConfig_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                EntityConfig_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Monitoring::EntityConfig >;

                EntityConfig_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &EntityConfig_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin EntityConfig_g_typePlugin = 
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

                return &EntityConfig_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::RTI::Service::Monitoring::EntityConfig >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Monitoring::EntityConfig >::get())));
        }

        template<>
        struct native_type_code< ::RTI::Service::Monitoring::EntityEvent > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member EntityEvent_g_tc_members[1]=
                {

                    {
                        (char *)"state",/* Member name */
                        {
                            245289886,/* Representation ID */
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

                static DDS_TypeCode EntityEvent_g_tc =
                {{
                        DDS_TK_STRUCT| DDS_TK_MUTABLE_EXTENSIBILITY, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::Monitoring::EntityEvent", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        EntityEvent_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for EntityEvent*/

                if (is_initialized) {
                    return &EntityEvent_g_tc;
                }

                is_initialized = RTI_TRUE;

                EntityEvent_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                EntityEvent_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::RTI::Service::EntityStateKind>::get().native();

                /* Initialize the values for member annotations. */
                EntityEvent_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                EntityEvent_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;

                EntityEvent_g_tc._data._sampleAccessInfo = sample_access_info();
                EntityEvent_g_tc._data._typePlugin = type_plugin_info();    

                return &EntityEvent_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::RTI::Service::Monitoring::EntityEvent *sample;

                static RTIXCdrMemberAccessInfo EntityEvent_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo EntityEvent_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &EntityEvent_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::RTI::Service::Monitoring::EntityEvent);
                if (sample == NULL) {
                    return NULL;
                }

                EntityEvent_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->state() - (char *)sample);

                EntityEvent_g_sampleAccessInfo.memberAccessInfos = 
                EntityEvent_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Monitoring::EntityEvent);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        EntityEvent_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        EntityEvent_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                EntityEvent_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                EntityEvent_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Monitoring::EntityEvent >;

                EntityEvent_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &EntityEvent_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin EntityEvent_g_typePlugin = 
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

                return &EntityEvent_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::RTI::Service::Monitoring::EntityEvent >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Monitoring::EntityEvent >::get())));
        }

        const ::RTI::Service::Monitoring::DistributionTopicKind default_enumerator< ::RTI::Service::Monitoring::DistributionTopicKind>::value = ::RTI::Service::Monitoring::DistributionTopicKind::CONFIG;
        template<>
        struct native_type_code< ::RTI::Service::Monitoring::DistributionTopicKind > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member DistributionTopicKind_g_tc_members[3]=
                {

                    {
                        (char *)"CONFIG",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::DistributionTopicKind::CONFIG), 
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
                        (char *)"EVENT",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::DistributionTopicKind::EVENT), 
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
                        (char *)"PERIODIC",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::DistributionTopicKind::PERIODIC), 
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

                static DDS_TypeCode DistributionTopicKind_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::Monitoring::DistributionTopicKind", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        DistributionTopicKind_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for DistributionTopicKind*/

                if (is_initialized) {
                    return &DistributionTopicKind_g_tc;
                }

                is_initialized = RTI_TRUE;

                DistributionTopicKind_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                DistributionTopicKind_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                DistributionTopicKind_g_tc._data._annotations._defaultValue._u.long_value = 0;

                DistributionTopicKind_g_tc._data._sampleAccessInfo = sample_access_info();
                DistributionTopicKind_g_tc._data._typePlugin = type_plugin_info();    

                return &DistributionTopicKind_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo DistributionTopicKind_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo DistributionTopicKind_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &DistributionTopicKind_g_sampleAccessInfo;
                }

                DistributionTopicKind_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                DistributionTopicKind_g_sampleAccessInfo.memberAccessInfos = 
                DistributionTopicKind_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Monitoring::DistributionTopicKind);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        DistributionTopicKind_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        DistributionTopicKind_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                DistributionTopicKind_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                DistributionTopicKind_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Monitoring::DistributionTopicKind >;

                DistributionTopicKind_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &DistributionTopicKind_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin DistributionTopicKind_g_typePlugin = 
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

                return &DistributionTopicKind_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::EnumType& dynamic_type< ::RTI::Service::Monitoring::DistributionTopicKind >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Monitoring::DistributionTopicKind >::get())));
        }

        const ::RTI::Service::Monitoring::ResourceKindIndex default_enumerator< ::RTI::Service::Monitoring::ResourceKindIndex>::value = ::RTI::Service::Monitoring::ResourceKindIndex::DDS_INDEX;
        template<>
        struct native_type_code< ::RTI::Service::Monitoring::ResourceKindIndex > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member ResourceKindIndex_g_tc_members[4]=
                {

                    {
                        (char *)"DDS_INDEX",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::ResourceKindIndex::DDS_INDEX), 
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
                        (char *)"ROUTING_INDEX",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::ResourceKindIndex::ROUTING_INDEX), 
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
                        (char *)"RECORDING_INDEX",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::ResourceKindIndex::RECORDING_INDEX), 
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
                        (char *)"CDS_INDEX",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::ResourceKindIndex::CDS_INDEX), 
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

                static DDS_TypeCode ResourceKindIndex_g_tc =
                {{
                        DDS_TK_ENUM| DDS_TK_MUTABLE_EXTENSIBILITY, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::Monitoring::ResourceKindIndex", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        ResourceKindIndex_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ResourceKindIndex*/

                if (is_initialized) {
                    return &ResourceKindIndex_g_tc;
                }

                is_initialized = RTI_TRUE;

                ResourceKindIndex_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                ResourceKindIndex_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                ResourceKindIndex_g_tc._data._annotations._defaultValue._u.long_value = 1;

                ResourceKindIndex_g_tc._data._sampleAccessInfo = sample_access_info();
                ResourceKindIndex_g_tc._data._typePlugin = type_plugin_info();    

                return &ResourceKindIndex_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo ResourceKindIndex_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ResourceKindIndex_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ResourceKindIndex_g_sampleAccessInfo;
                }

                ResourceKindIndex_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                ResourceKindIndex_g_sampleAccessInfo.memberAccessInfos = 
                ResourceKindIndex_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Monitoring::ResourceKindIndex);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ResourceKindIndex_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ResourceKindIndex_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ResourceKindIndex_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ResourceKindIndex_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Monitoring::ResourceKindIndex >;

                ResourceKindIndex_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ResourceKindIndex_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ResourceKindIndex_g_typePlugin = 
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

                return &ResourceKindIndex_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::EnumType& dynamic_type< ::RTI::Service::Monitoring::ResourceKindIndex >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Monitoring::ResourceKindIndex >::get())));
        }

        const ::RTI::Service::Monitoring::ResourceKind default_enumerator< ::RTI::Service::Monitoring::ResourceKind>::value = ::RTI::Service::Monitoring::ResourceKind::UNKNOWN;
        template<>
        struct native_type_code< ::RTI::Service::Monitoring::ResourceKind > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member ResourceKind_g_tc_members[17]=
                {

                    {
                        (char *)"UNKNOWN",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::ResourceKind::UNKNOWN), 
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
                        (char *)"ROUTING_SERVICE",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::ResourceKind::ROUTING_SERVICE), 
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
                        (char *)"ROUTING_DOMAIN_ROUTE",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::ResourceKind::ROUTING_DOMAIN_ROUTE), 
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
                        (char *)"ROUTING_SESSION",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::ResourceKind::ROUTING_SESSION), 
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
                        (char *)"ROUTING_AUTO_ROUTE",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::ResourceKind::ROUTING_AUTO_ROUTE), 
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
                        (char *)"ROUTING_ROUTE",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::ResourceKind::ROUTING_ROUTE), 
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
                        (char *)"ROUTING_INPUT",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::ResourceKind::ROUTING_INPUT), 
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
                        (char *)"ROUTING_OUTPUT",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::ResourceKind::ROUTING_OUTPUT), 
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
                        (char *)"RECORDING_SERVICE",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::ResourceKind::RECORDING_SERVICE), 
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
                        (char *)"RECORDING_SESSION",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::ResourceKind::RECORDING_SESSION), 
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
                        (char *)"RECORDING_TOPIC_GROUP",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::ResourceKind::RECORDING_TOPIC_GROUP), 
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
                        (char *)"RECORDING_TOPIC",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::ResourceKind::RECORDING_TOPIC), 
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
                        (char *)"CDS_SERVICE",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::ResourceKind::CDS_SERVICE), 
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
                        (char *)"CDS_FORWARDER",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::ResourceKind::CDS_FORWARDER), 
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
                        (char *)"CDS_DATABASE",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::ResourceKind::CDS_DATABASE), 
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
                        (char *)"CDS_RECEIVER",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::ResourceKind::CDS_RECEIVER), 
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
                        (char *)"CDS_SENDER",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::RTI::Service::Monitoring::ResourceKind::CDS_SENDER), 
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

                static DDS_TypeCode ResourceKind_g_tc =
                {{
                        DDS_TK_ENUM| DDS_TK_MUTABLE_EXTENSIBILITY, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"RTI::Service::Monitoring::ResourceKind", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        17, /* Number of members */
                        ResourceKind_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ResourceKind*/

                if (is_initialized) {
                    return &ResourceKind_g_tc;
                }

                is_initialized = RTI_TRUE;

                ResourceKind_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                ResourceKind_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                ResourceKind_g_tc._data._annotations._defaultValue._u.long_value = 0;

                ResourceKind_g_tc._data._sampleAccessInfo = sample_access_info();
                ResourceKind_g_tc._data._typePlugin = type_plugin_info();    

                return &ResourceKind_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo ResourceKind_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ResourceKind_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ResourceKind_g_sampleAccessInfo;
                }

                ResourceKind_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                ResourceKind_g_sampleAccessInfo.memberAccessInfos = 
                ResourceKind_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::RTI::Service::Monitoring::ResourceKind);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ResourceKind_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ResourceKind_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ResourceKind_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ResourceKind_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::RTI::Service::Monitoring::ResourceKind >;

                ResourceKind_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ResourceKind_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ResourceKind_g_typePlugin = 
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

                return &ResourceKind_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::EnumType& dynamic_type< ::RTI::Service::Monitoring::ResourceKind >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::RTI::Service::Monitoring::ResourceKind >::get())));
        }
    }
}

namespace dds { 
    namespace topic {
        void topic_type_support< ::RTI::Service::EntityState >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::RTI::Service::EntityStatePlugin_new,
                ::RTI::Service::EntityStatePlugin_delete);
        }

        std::vector<char>& topic_type_support< ::RTI::Service::EntityState >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::RTI::Service::EntityState& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = EntityStatePlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = EntityStatePlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::RTI::Service::EntityState >::from_cdr_buffer(::RTI::Service::EntityState& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = EntityStatePlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::RTI::Service::EntityState from cdr buffer");
        }

        void topic_type_support< ::RTI::Service::EntityState >::reset_sample(::RTI::Service::EntityState& sample) 
        {
            sample.state(RTI::Service::EntityStateKind::INVALID);
        }

        void topic_type_support< ::RTI::Service::EntityState >::allocate_sample(::RTI::Service::EntityState& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.state(),  -1, -1);
        }

        void topic_type_support< ::RTI::Service::BuiltinTopicKey >::reset_sample(::RTI::Service::BuiltinTopicKey& sample) 
        {
            ::rti::topic::reset_sample(sample.value());
        }

        void topic_type_support< ::RTI::Service::BuiltinTopicKey >::allocate_sample(::RTI::Service::BuiltinTopicKey& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.value(),  -1, -1);
        }
        void topic_type_support< ::RTI::Service::Monitoring::ResourceGuid >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::RTI::Service::Monitoring::ResourceGuidPlugin_new,
                ::RTI::Service::Monitoring::ResourceGuidPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::RTI::Service::Monitoring::ResourceGuid >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::RTI::Service::Monitoring::ResourceGuid& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = ResourceGuidPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = ResourceGuidPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::RTI::Service::Monitoring::ResourceGuid >::from_cdr_buffer(::RTI::Service::Monitoring::ResourceGuid& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = ResourceGuidPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::RTI::Service::Monitoring::ResourceGuid from cdr buffer");
        }

        void topic_type_support< ::RTI::Service::Monitoring::ResourceGuid >::reset_sample(::RTI::Service::Monitoring::ResourceGuid& sample) 
        {
            ::rti::topic::reset_sample(sample.value());
        }

        void topic_type_support< ::RTI::Service::Monitoring::ResourceGuid >::allocate_sample(::RTI::Service::Monitoring::ResourceGuid& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.value(),  -1, -1);
        }
        void topic_type_support< ::RTI::Service::Monitoring::KeyedResource >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::RTI::Service::Monitoring::KeyedResourcePlugin_new,
                ::RTI::Service::Monitoring::KeyedResourcePlugin_delete);
        }

        std::vector<char>& topic_type_support< ::RTI::Service::Monitoring::KeyedResource >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::RTI::Service::Monitoring::KeyedResource& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = KeyedResourcePlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = KeyedResourcePlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::RTI::Service::Monitoring::KeyedResource >::from_cdr_buffer(::RTI::Service::Monitoring::KeyedResource& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = KeyedResourcePlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::RTI::Service::Monitoring::KeyedResource from cdr buffer");
        }

        void topic_type_support< ::RTI::Service::Monitoring::KeyedResource >::reset_sample(::RTI::Service::Monitoring::KeyedResource& sample) 
        {
            ::rti::topic::reset_sample(sample.object_guid());
            ::rti::topic::reset_sample(sample.owner_guid());
        }

        void topic_type_support< ::RTI::Service::Monitoring::KeyedResource >::allocate_sample(::RTI::Service::Monitoring::KeyedResource& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.object_guid(),  -1, -1);
            ::rti::topic::allocate_sample(sample.owner_guid(),  -1, -1);
        }

        void topic_type_support< ::RTI::Service::Monitoring::StatisticMetrics >::reset_sample(::RTI::Service::Monitoring::StatisticMetrics& sample) 
        {
            sample.period_ms(0ull);
            sample.count(0ll);
            sample.mean(0.0f);
            sample.minimum(0.0f);
            sample.maximum(0.0f);
            sample.std_dev(0.0f);
        }

        void topic_type_support< ::RTI::Service::Monitoring::StatisticMetrics >::allocate_sample(::RTI::Service::Monitoring::StatisticMetrics& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }

        void topic_type_support< ::RTI::Service::Monitoring::StatisticVariable >::reset_sample(::RTI::Service::Monitoring::StatisticVariable& sample) 
        {
            ::rti::topic::reset_sample(sample.publication_period_metrics());
        }

        void topic_type_support< ::RTI::Service::Monitoring::StatisticVariable >::allocate_sample(::RTI::Service::Monitoring::StatisticVariable& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.publication_period_metrics(),  -1, -1);
        }

        void topic_type_support< ::RTI::Service::Monitoring::CountStatus >::reset_sample(::RTI::Service::Monitoring::CountStatus& sample) 
        {
            sample.total_count(0ll);
            sample.current_count(0ll);
            sample.current_count_peak(0ll);
        }

        void topic_type_support< ::RTI::Service::Monitoring::CountStatus >::allocate_sample(::RTI::Service::Monitoring::CountStatus& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }

        void topic_type_support< ::RTI::Service::Monitoring::ProcessConfig >::reset_sample(::RTI::Service::Monitoring::ProcessConfig& sample) 
        {
            sample.id(0ull);
        }

        void topic_type_support< ::RTI::Service::Monitoring::ProcessConfig >::allocate_sample(::RTI::Service::Monitoring::ProcessConfig& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }

        void topic_type_support< ::RTI::Service::Monitoring::ProcessPeriodic >::reset_sample(::RTI::Service::Monitoring::ProcessPeriodic& sample) 
        {
            ::rti::topic::reset_sample(sample.cpu_usage_percentage());
            ::rti::topic::reset_sample(sample.physical_memory_kb());
            ::rti::topic::reset_sample(sample.total_memory_kb());
            sample.uptime_sec(0);
        }

        void topic_type_support< ::RTI::Service::Monitoring::ProcessPeriodic >::allocate_sample(::RTI::Service::Monitoring::ProcessPeriodic& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }

        void topic_type_support< ::RTI::Service::Monitoring::ThreadPeriodic >::reset_sample(::RTI::Service::Monitoring::ThreadPeriodic& sample) 
        {
            sample.id(0ull);
            ::rti::topic::reset_sample(sample.cpu_usage_percentage());
        }

        void topic_type_support< ::RTI::Service::Monitoring::ThreadPeriodic >::allocate_sample(::RTI::Service::Monitoring::ThreadPeriodic& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }

        void topic_type_support< ::RTI::Service::Monitoring::ThreadPoolPeriodic >::reset_sample(::RTI::Service::Monitoring::ThreadPoolPeriodic& sample) 
        {
            ::rti::topic::reset_sample(sample.threads());
        }

        void topic_type_support< ::RTI::Service::Monitoring::ThreadPoolPeriodic >::allocate_sample(::RTI::Service::Monitoring::ThreadPoolPeriodic& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }

        void topic_type_support< ::RTI::Service::Monitoring::HostPeriodic >::reset_sample(::RTI::Service::Monitoring::HostPeriodic& sample) 
        {
            ::rti::topic::reset_sample(sample.cpu_usage_percentage());
            ::rti::topic::reset_sample(sample.free_memory_kb());
            ::rti::topic::reset_sample(sample.free_swap_memory_kb());
            sample.uptime_sec(0);
        }

        void topic_type_support< ::RTI::Service::Monitoring::HostPeriodic >::allocate_sample(::RTI::Service::Monitoring::HostPeriodic& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }

        void topic_type_support< ::RTI::Service::Monitoring::HostConfig >::reset_sample(::RTI::Service::Monitoring::HostConfig& sample) 
        {
            sample.name("");
            sample.id(0u);
            sample.total_memory_kb(0ll);
            sample.total_swap_memory_kb(0ll);
            sample.target("");
        }

        void topic_type_support< ::RTI::Service::Monitoring::HostConfig >::allocate_sample(::RTI::Service::Monitoring::HostConfig& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.name(),  -1, (RTI::Service::BOUNDED_STRING_LENGTH_MAX));
            ::rti::topic::allocate_sample(sample.target(),  -1, (RTI::Service::BOUNDED_STRING_LENGTH_MAX));
        }

        void topic_type_support< ::RTI::Service::Monitoring::NetworkPerformance >::reset_sample(::RTI::Service::Monitoring::NetworkPerformance& sample) 
        {
            ::rti::topic::reset_sample(sample.samples_per_sec());
            ::rti::topic::reset_sample(sample.bytes_per_sec());
            ::rti::topic::reset_sample(sample.latency_millisec());
        }

        void topic_type_support< ::RTI::Service::Monitoring::NetworkPerformance >::allocate_sample(::RTI::Service::Monitoring::NetworkPerformance& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }

        void topic_type_support< ::RTI::Service::Monitoring::EntityConfig >::reset_sample(::RTI::Service::Monitoring::EntityConfig& sample) 
        {
            sample.resource_id("");
            sample.configuration("");
        }

        void topic_type_support< ::RTI::Service::Monitoring::EntityConfig >::allocate_sample(::RTI::Service::Monitoring::EntityConfig& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.resource_id(),  -1, (RTI::Service::RESOURCE_IDENTIFIER_LENGTH_MAX));
            ::rti::topic::allocate_sample(sample.configuration(),  -1, -1);
        }

        void topic_type_support< ::RTI::Service::Monitoring::EntityEvent >::reset_sample(::RTI::Service::Monitoring::EntityEvent& sample) 
        {
            sample.state(RTI::Service::EntityStateKind::INVALID);
        }

        void topic_type_support< ::RTI::Service::Monitoring::EntityEvent >::allocate_sample(::RTI::Service::Monitoring::EntityEvent& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.state(),  -1, -1);
        }
    }
}  

#endif // NDDS_STANDALONE_TYPE
