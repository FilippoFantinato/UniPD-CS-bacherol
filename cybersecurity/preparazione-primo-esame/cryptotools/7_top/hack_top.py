import sys
import random
import time

sys.path.append("/home/filippofantinato/Desktop/UniPD/cybersecurity/libraries")

from encodingdecoding import *

def get_time(msg):
	time = xor_bytes(msg, [0x88] * len(msg))

	return time.decode("ascii")

def main():
	with open("top_secret", "br") as f: 

		msg = f.read()
		# time = get_time(msg)
		time = 1513719133.8728752
		print(f"Time: {time}")


		cur_time = str(time).encode('ASCII')
		msg = msg[:len(msg) - len(cur_time)]
		random.seed(cur_time)

		key = [random.randrange(256) for _ in msg]
		c = xor_bytes(msg, key)

		print(f"Flag: {c}")


if __name__ == '__main__':
	main()
