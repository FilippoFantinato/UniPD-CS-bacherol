import random
import sys
import os

def createdTime(msg):
	c = [m ^ k for (m, k) in zip(msg, ([0x88] * len(msg)))]

	return bytes(c).decode("ascii", "ignore")


def hack(time, msg):
	cur_time = str(time).encode('ASCII')
	random.seed(cur_time)
	msg = msg[:len(msg) - len(cur_time)]
	key = [random.randrange(256) for _ in msg]
	c = [m ^ k for (m,k ) in zip(msg, key + [0x88]*len(cur_time))]

	return bytes(c).decode("ascii")


def main():
	filename = sys.argv[1]

	with open(filename, "rb") as f:
		msg = f.read()

		created_time = createdTime(msg)
		print("Created time: ", created_time)

		plaintext = hack(1513719133.8728752, msg)
		print("Plain text: ", plaintext)


if __name__ == "__main__":
	main()
