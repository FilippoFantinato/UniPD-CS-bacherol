import base64

def encoding_base64(plain_msg):
	plain_msg_bytes = plain_msg.encode('ascii')
	base64_msg_bytes = base64.b64encode(plain_msg_bytes)
	base64_msg = base64_bytes.decode('ascii')

	return base64_msg


def decoding_base64(base64_msg):
	base64_msg_bytes = base64_msg.encode('ascii')
	plain_msg_bytes = base64.b64decode(base64_msg_bytes)
	plain_msg = plain_msg_bytes.decode('ascii')

	return plain_msg

def xor_string(s1, s2):
	return ''.join([chr(ord(a) ^ ord(b)) for (a, b) in zip(s1, s2)])

def xor_bytes(s1, s2):
	return ''.join([chr(a ^ b) for (a, b) in zip(s1, s2)])
