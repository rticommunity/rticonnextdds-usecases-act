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

class PlatformSim:
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
      self.platform_data_type = self.qos_provider.type("platform_data")


      # Create Topics and associate with types
      self.c2_cmd_topic = dds.DynamicData.Topic(
          self.participant,
          "C2Command",
          self.c2_cmd_type
      )
      self.c2_cmd_ack_topic = dds.DynamicData.Topic(
          self.participant,
          "PlatformCommandAck",
          self.c2_cmd_ack_type
      )
      self.platform_status_topic = dds.DynamicData.Topic(
          self.participant,
          "PlatformStatus",
          self.platform_status_type
      )
      self.platform_data_topic = dds.DynamicData.Topic(
          self.participant,
          "PlatformData",
          self.platform_data_type
      )

      # Create DataWriters/DataReaders with the specified QoS profiles
      self.c2_cmd_reader = dds.DynamicData.DataReader(
          self.c2_cmd_topic,
          self.qos_provider.datareader_qos_from_profile(args.qos_profile)
      )
      self.platform_data_reader = dds.DynamicData.DataReader(
          self.platform_data_topic,
          self.qos_provider.datareader_qos_from_profile(args.qos_profile)
      )
      self.c2_cmd_ack_writer = dds.DynamicData.DataWriter(
          self.c2_cmd_ack_topic,
          self.qos_provider.datawriter_qos_from_profile(args.qos_profile)
      )
      self.platform_status_writer = dds.DynamicData.DataWriter(
          self.platform_status_topic,
          self.qos_provider.datawriter_qos_from_profile(args.qos_profile)
      )
      self.platform_data_writer = dds.DynamicData.DataWriter(
          self.platform_data_topic,
          self.qos_provider.datawriter_qos_from_profile(args.qos_profile)
      )

      time.sleep(2)

      print("ignoring self published PlatformData")
      self.participant.ignore_datawriter(self.platform_data_writer.instance_handle)


    async def read_c2_command(self):
      print("Waiting for C2 Commands")
      async for data in self.c2_cmd_reader.take_data_async():
        print(f'- Received Command with Session ID: {data["msg.session_id[1]"]}')

    async def read_platform_data(self):
      print("Waiting for Platform Data ")
      async for data in self.platform_data_reader.take_data_async():
        print(f'- Received Platform Data with Session ID: {data["msg.session_id[1]"]}')


    async def write_cmd_ack(self):
      # Create sample
      cmd_ack_sample = dds.DynamicData(self.c2_cmd_ack_type)

      # Set Source GUID
      source_guid = uuid.UUID(str(args.src_guid))
      source_guid_list = list(source_guid.bytes)
      cmd_ack_sample["msg.source"] = source_guid_list

      # Set Destination GUID
      dest_guid = uuid.UUID(str(args.dest_guid))
      dest_guid_list = list(dest_guid.bytes)
      cmd_ack_sample["msg.destination"] = dest_guid_list

      # Set Session "GUID"
      session_guid = [args.session_id for d in range(16)]
      cmd_ack_sample["msg.session_id"] = session_guid

      # Create sim "Payload"
      payload = [random.randrange(0, 10, 2) for d in range(16)]
      cmd_ack_sample["msg.payload"] = payload

      while True:
          self.c2_cmd_ack_writer.write(cmd_ack_sample)
          print("Writing to C2CommandAck topic")
          await asyncio.sleep(1)

    async def write_status(self):
      # Create sample
      status_sample = dds.DynamicData(self.platform_status_type)

      # Set Source GUID
      source_guid = uuid.UUID(str(args.src_guid))
      source_guid_list = list(source_guid.bytes)
      status_sample["msg.source"] = source_guid_list

      # Set Destination GUID
      dest_guid = uuid.UUID(str(args.dest_guid))
      dest_guid_list = list(dest_guid.bytes)
      status_sample["msg.destination"] = dest_guid_list

      # Set Session "GUID"
      session_guid = [args.session_id for d in range(16)]
      status_sample["msg.session_id"] = session_guid

      # Create sim "Payload"
      payload = [random.randrange(0, 10, 2) for d in range(16)]
      status_sample["msg.payload"] = payload

      while True:
          self.platform_status_writer.write(status_sample)
          print("Writing to PlatformStatus topic")
          await asyncio.sleep(1)

    async def write_data(self):
      # Create sample
      data_sample = dds.DynamicData(self.platform_data_type)

      # Set Source GUID
      source_guid = uuid.UUID(str(args.src_guid))
      source_guid_list = list(source_guid.bytes)
      data_sample["msg.source"] = source_guid_list

      # Set Destination GUID
      dest_guid = uuid.UUID(str(args.dest_guid))
      dest_guid_list = list(dest_guid.bytes)
      data_sample["msg.destination"] = dest_guid_list

      # Set Session "GUID"
      session_guid = [args.session_id for d in range(16)]
      data_sample["msg.session_id"] = session_guid

      # Create sim "Payload"
      payload = [random.randrange(0, 10, 2) for d in range(16)]
      data_sample["msg.payload"] = payload

      while True:
          self.platform_data_writer.write(data_sample)
          print("Writing to PlatformData topic")
          await asyncio.sleep(1)

    async def run(self) -> None:
        await asyncio.gather(
            self.read_c2_command(),
            self.read_platform_data(),
            self.write_cmd_ack(),
            self.write_status(),
            self.write_data()
            )




if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Platform Sim"
    )
    print("\n\nRUNNING PLATFORM SIM\n\n")
    parser.add_argument(
        "-f", "--files", type=str, default="", help="XML Config files"
    )
    parser.add_argument(
        "--src_guid", type=str, default=0, help="Source GUID"
    )
    parser.add_argument(
        "--dest_guid", type=str, default=0, help="Destination GUID"
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
      rti.asyncio.run(PlatformSim(args).run())
        
    except KeyboardInterrupt:
        pass


