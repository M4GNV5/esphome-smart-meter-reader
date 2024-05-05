from smllib import SmlStreamReader
from binascii import unhexlify

stream = SmlStreamReader()
#with open("sml-message.bin", "rb") as fd:
#    stream.add(fd.read())

with open("message.hex", "r") as fd:
    data = fd.read()
    stream.add(unhexlify(data))

sml_frame = stream.get_frame()
if sml_frame is None:
    print('Bytes missing')
    exit(1)

# return all values but slower
parsed_msgs = sml_frame.parse_frame()
for msg in parsed_msgs:
    # prints a nice overview over the received values
    print(msg.format_msg())
print()

# A quick Shortcut to extract all values without parsing the whole frame
# In rare cases this might raise an InvalidBufferPos exception, then you have to use sml_frame.parse_frame()
obis_values = sml_frame.get_obis()
print(obis_values)

# The obis attribute of the SmlListEntry carries different obis representations as attributes
list_entry = obis_values[0]
print(list_entry.obis)            # 0100010800ff
print(list_entry.obis.obis_code)  # 1-0:1.8.0*255
print(list_entry.obis.obis_short) # 1.8.0
