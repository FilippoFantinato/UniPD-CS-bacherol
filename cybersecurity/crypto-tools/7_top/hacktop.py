import random
import sys
import time
import datetime
import binascii

bytelist = b""

with open(sys.argv[1], "rb") as f:
	byte = f.read(1)
	while (byte != b""):
		byte = f.read(1)
		bytelist = bytelist + byte

print(bytelist)

cur_time = str(time.mktime(datetime.datetime.strptime("2019-05-06 12:09:38.000000 +0200", "%Y-%m-%d %H:%M:%S.%f %z").timetuple())).encode('ASCII')
random.seed(cur_time)

key = [random.randrange(256) for _ in bytelist]
c = bytes([m ^ k for (m,k) in zip(bytelist, key + [0x88]*len(cur_time))])

print(c.decode("ASCII", 'ignore'))

with open("plain.txt", "w") as f:
	f.write(c.decode("ASCII", 'ignore'))
	f.close()
