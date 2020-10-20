import codecs
from collections import Counter

def getLengthKey(msg):
	for step in range(1, 50):
		match = total = 0
		for i in range(len(msg)):
			for j in range(i + step, len(msg), step):
				total += 1
				if msg[i] == msg[j]: match += 1

		ioc = float(match) / float(total)
		print("%3d%7.2f%% %s" % (step, 100*ioc, "#" * int(0.5 + 500*ioc)))

def getFrequencies(msg, key_length):
	frequencies = []

	for i in range(0, key_length):
		frequency = Counter()
		for ch in msg[i::key_length]:
			frequency[ch] += 1
		frequencies.append(frequency)

	return frequencies


def getMostCommonCh(frequencies):
	key_numbers = []

	for frequency in frequencies:
		k = ord(frequency.most_common(1)[0][0]) ^ ord(' ')
		print ('{k} -> \' \''.format(**locals()))
		key_numbers.append(k)

		others = ''
		for val, freq in frequency.most_common(10):
			others += chr(ord(val) ^ k) + ' '
		print ('Other common letters: {others}\n'.format(**locals()))

	return key_numbers


def stringXOR(msg, key):
	return ''.join([chr(ord(a)^b) for a, b in zip(msg, expandKey(key, len(msg)))])


def expandKey(key, length):
	return (key*(length//len(key) + 1))[:length]


def splitText(msg, n):
	return [codecs.decode(msg[i:i+n], "hex") for i in range(0, len(msg), n)]
	

def main():
	with open("encrypted_ascii.txt", "r") as f:
		msg = f.read()

		# hexMsg = codecs.decode(msg, "hex")

		# print(msg)

		# getLengthKey(msg)

		key_length = 8

		frequencies = getFrequencies(msg, key_length)

		key = getMostCommonCh(frequencies)
		print(stringXOR(msg, key))

		# splitted_text = splitText(msg, possible_length)

		# print(splitted_text)
		# text = codecs.decode(f.read(), "hex");
		# key = codecs.decode("40c1d154c4f226527480405154f19071b1f01451306160000121d", "ascii");
		
		# # hexText = f.read();

		# possible_length = [2, 4, 8, 16]

		# print(text);


if __name__ == "__main__":
	main()
