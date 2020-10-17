import string

chipertext = "vhixoieemksktorywzvhxzijqni"
key = 13
plaintext = ""

letters = string.ascii_lowercase

for char in chipertext:
	plaintext = plaintext + letters[(letters.index(char) + key) % len(letters)]

print(plaintext)
