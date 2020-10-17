import string

chipertext = "fYZ7ipGIjFtsXpNLbHdPbXdaam1PS1c5lQ"

vocabulary = list(string.ascii_letters) + list(string.digits)

plaintext = ""

for i in range(1, 26):
	for char in chipertext:
		plaintext = plaintext + vocabulary[(list.index(vocabulary, char) + i) % len(vocabulary)]

	print(plaintext)
	print("\n");
	plaintext = ""
