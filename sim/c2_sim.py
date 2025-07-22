# (c) 2024 Copyright, Real-Time Innovations, Inc.  All rights reserved.
# RTI grants Licensee a license to use, modify, compile, and create derivative
# works of the Software.  Licensee has the right to distribute object form only
# for use with RTI products.  The Software is provided "as is", with no warranty
# of any type, including any warranty for fitness for any purpose. RTI is under
# no obligation to maintain or support the Software.  RTI shall not be liable for
# any incidental or consequential damages arising out of the use or inability to
# use the software.

import rti.connextdds as dds
from rti.types.builtin import String
import time
import argparse
import random
import threading
import rti.asyncio
import asyncio
import uuid

class C2Sim:
    def __init__(self, args):

      # Load QoS/Types from XML files
      self.qos_provider = dds.QosProvider(args.files)

      # Create a Participant from specific QOS Profile
      self.participant = dds.DomainParticipant(
          args.domain_id, self.qos_provider.participant_qos_from_profile(
              args.qos_profile)
      )

      #Pull in DynamicData types
      self.c2_cmd_type = self.qos_provider.type("c2_command")
      self.c2_cmd_ack_type = self.qos_provider.type("c2_command_ack")
      self.platform_status_type = self.qos_provider.type("platform_status")
      self.contact_report_type = self.qos_provider.type("contact_report")


      # Create Topics and associate with types
      self.c2_cmd_topic = dds.DynamicData.Topic(
          self.participant,
          "C2Command",
          self.c2_cmd_type
      )
      self.platform_cmd_ack_topic = dds.DynamicData.Topic(
          self.participant,
          "PlatformCommandAck",
          self.c2_cmd_ack_type
      )
      self.platform_status_topic = dds.DynamicData.Topic(
          self.participant,
          "PlatformStatus",
          self.platform_status_type
      )

      self.contact_report_topic = dds.DynamicData.Topic(
          self.participant,
          "ContactReport",
          self.contact_report_type
      )

      # Create DataWriters/DataReaders with the specified QoS profiles
      self.c2_cmd_writer = dds.DynamicData.DataWriter(
          self.c2_cmd_topic,
          self.qos_provider.datawriter_qos_from_profile(args.qos_profile)
      )
      self.c2_contact_report_writer = dds.DynamicData.DataWriter(
          self.contact_report_topic,
          self.qos_provider.datawriter_qos_from_profile(args.qos_profile)
      )
      self.platform_cmd_ack_reader = dds.DynamicData.DataReader(
          self.platform_cmd_ack_topic,
          self.qos_provider.datareader_qos_from_profile(args.qos_profile)
      )
      self.platform_status_reader = dds.DynamicData.DataReader(
          self.platform_status_topic,
          self.qos_provider.datareader_qos_from_profile(args.qos_profile)
      )
      self.contact_report_reader = dds.DynamicData.DataReader(
          self.contact_report_topic,
          self.qos_provider.datareader_qos_from_profile(args.qos_profile)
      )

      print("ignoring self published ContactReports")
      self.participant.ignore_datawriter(
          self.c2_contact_report_writer.instance_handle)

    async def read_status_data(self):
      print("Waiting for Status data")
      async for data in self.platform_status_reader.take_data_async():
        print(f'- Received Status data with Session ID: {data["msg.session_id[1]"]}')
       

    async def read_cmd_ack_data(self):
      print("Waiting for CommandAck data")
      async for data in self.platform_cmd_ack_reader.take_data_async():
        print(f'- Received CommandAck data with Session ID: {data["msg.session_id[1]"]}')

    async def read_contact_report_data(self):
      print("Waiting for ContactReport data")
      async for data in self.contact_report_reader.take_data_async():
        print(
            f'- Received ContactReport Data: {data["msg.session_id[1]"]} from {data["msg.source_type"]}')

    async def write_cmd(self):
      # Create GUID's
      source_guid = uuid.UUID(str(args.src_guid))
      source_guid_list = list(source_guid.bytes)

      dest_guid = uuid.UUID(str(args.dest_guid))
      dest_guid_list = list(dest_guid.bytes)

      # Create Command sample
      cmd_sample = dds.DynamicData(self.c2_cmd_type)

      # Set Source GUID
      cmd_sample["msg.source_id"] = source_guid_list

      # Set Destination GUID
      cmd_sample["msg.destination_id"] = dest_guid_list

      # Set Session "GUID"
      session_guid = [args.session_id for d in range(16)]
      cmd_sample["msg.session_id"] = session_guid

      # Create sim "Payload"
      payload = [random.randrange(0, 10, 2) for d in range(16)]
      cmd_sample["msg.payload"] = payload


      # Create Contact Report sample
      contact_report_sample = dds.DynamicData(self.c2_cmd_type)

      # Set Source GUID
      contact_report_sample["msg.source_id"] = source_guid_list

      # Set Source Name
      contact_report_sample["msg.source_type"] = "C2"

      # Set Destination GUID
      contact_report_sample["msg.destination_id"] = dest_guid_list

      # Set Session "GUID"
      session_guid = [args.session_id for d in range(16)]
      contact_report_sample["msg.session_id"] = session_guid

      # Create sim "Payload"
      payload = [random.randrange(0, 10, 2) for d in range(16)]
      contact_report_sample["msg.payload"] = payload


      while True:
          # Send C2 Command
          self.c2_cmd_writer.write(cmd_sample)
          print("Writing to C2Command topic")

          # Send C2 Contact Report
          self.c2_contact_report_writer.write(contact_report_sample)
          print("Writing to ContactReport topic")

          await asyncio.sleep(1)


    async def run(self) -> None:
        await asyncio.gather(
            self.write_cmd(),
            self.read_status_data(),
            self.read_cmd_ack_data(),
            self.read_contact_report_data()
            )




if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="C2 Sim"
    )
    print("\n\nRUNNING C2 SIM\n\n")
    parser.add_argument(
        "-f", "--files", type=str, default="", help="XML Config files"
    )
    parser.add_argument(
        "--src_guid", type=str, default=0, help="Source GUID"
    )
    parser.add_argument(
        "--dest_guid", type=str, default=1, help="Destination GUID"
    )
    parser.add_argument(
        "--qos_profile", type=str, default=0, help="QOS Profile"
    )
    parser.add_argument(
        "--session_id", type=int, default=0, help="Session ID"
    )
    parser.add_argument(
        "-d", "--domain_id", type=int, default=0, help="Domain ID"
    )
    parser.add_argument(
        "-v", "--verbosity", type=int, default=1, help="How much debugging output to show | Range: 0-3 | Default: 1",
    )

    args = parser.parse_args()

    verbosity_levels = {
        0: dds.Verbosity.SILENT,
        1: dds.Verbosity.EXCEPTION,
        2: dds.Verbosity.WARNING,
        3: dds.Verbosity.STATUS_ALL,
    }

    # Sets Connext verbosity to help debugging
    verbosity = verbosity_levels.get(args.verbosity, dds.Verbosity.EXCEPTION)

    dds.Logger.instance.verbosity = verbosity

    try:
      # Run
      rti.asyncio.run(C2Sim(args).run())
        
    except KeyboardInterrupt:
        pass


