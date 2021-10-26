import sys

sys.path.append("/home/filippofantinato/Desktop/UniPD/cybersecurity/libraries")

from encodingdecoding import *

original_data = "El Psy Congroo"
encrypted_data = "IFhiPhZNYi0KWiUcCls="
encrypted_flag = "I3gDKVh1Lh4EVyMDBFo="

plain_data = decoding_base64(encrypted_data)
plain_flag = decoding_base64(encrypted_flag)

print(plain_data)
print(plain_flag)

key = xor(plain_data, original_data)
print(key)

flag = xor(plain_flag, key)

print(f"Flag: {flag}")
