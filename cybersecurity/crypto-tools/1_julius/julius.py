chipertext = "}{[l^KlwOmwZjmOKW9"

plaintext = ""

# for i in range(1, 127):
# 	for char in chipertext:
# 		plaintext = plaintext + chr((ord(char) + i) % 127)

# 	print(i, " - ", plaintext)
# 	print()
# 	plaintext = ""

# for i in range(1, 127):
for char in chipertext:
		plaintext = plaintext + chr(ord(char) - 24)

print(24, " - ", plaintext)
print()
plaintext = ""
