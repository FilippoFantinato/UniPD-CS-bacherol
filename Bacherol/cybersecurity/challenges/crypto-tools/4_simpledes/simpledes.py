def string2binary(text):
    return ''.join(f"{ord(c):08b}" for c in text)

def splitBlock(block):
	Lr = block[:6]
	Rr = block[6:]

	return Lr, Rr

def expandRr(Rr):
	Rr = Rr[:2] + (Rr[3]+Rr[2])*2 + Rr[4:]

	return Rr

def xor(s1, s2):
	res = int(s1, 2)^int(s2, 2)

	return f"{res:08b}"

def alterRr(Rr1, Rr2):
	SB1 = [
		["101", "010", "001", "110", "011", "100", "111", "000"],
		["001", "100", "110", "010", "000", "111", "101", "011"]
	]
	SB2 = [
		["100", "000", "110", "101", "111", "001", "011", "010"],
		["101", "011", "000", "111", "110", "010", "001", "100"]
	]

	alteredRr = SB1[int(Rr1[0], 2)][int(Rr1[1:], 2)] + SB2[int(Rr2[0], 2)][int(Rr2[1:], 2)]

	return alteredRr

def encryptDes(plaintext, key, R, n):
	plaintext = string2binary(plaintext)
	key = string2binary(key)
	encrypted_text = ""

	for i, block in enumerate(plaintext[k:k+n] for k in range(0, len(plaintext), n)):
		for r in range(R):

			Lr, Rr = splitBlock(block)

			print(f"{(i, r)}", Lr, Rr)

			Rr_expanded = expandRr(Rr)

			curr_key = key[(i*R + r):(i*R + r + 8)]
			alteredRr = xor(Rr_expanded, curr_key)

			Rr1 = alteredRr[:4]
			Rr2 = alteredRr[4:]
			
			print(f"{(i, r)}", Rr1, Rr2)
			alteredRr = alterRr(Rr1, Rr2)
			alteredRr = xor(Lr, alteredRr)[2:]

			block = Rr + alteredRr
		encrypted_text += block

	return encrypted_text

def decryptDes(chipertext, key, R, n):
	plaintext = ""
	key = string2binary(key)

	for i, block in enumerate(chipertext[k:k+n] for k in range(0, len(chipertext), n)):
		for r in range(R-1, -1, -1):
			Rr, alteredRrLr = splitBlock(block)

			Rr_expanded = expandRr(Rr)

			curr_key = key[(i*R + r):(i*R + r + 8)]
			alteredRr = xor(Rr_expanded, curr_key)

			Rr1 = alteredRr[:4]
			Rr2 = alteredRr[4:]
			
			print(f"{(i, r)}", Rr1, Rr2)
			alteredRr = alterRr(Rr1, Rr2)

			Lr = xor(Rr, alteredRr)[2:]
			block = Lr + Rr

		plaintext += block
		
	res = ''
	for i in range(len(plaintext) // 8):
		res += chr(int(plaintext[(i * 8): ((i+1) * 8)] ,2))
    # print(res)

	return res


def main():
	plaintext = "Min0n!"
	chipertext = "011001010010001010001100010110000001000110000101"
	key = "Mu"
	R = 2
	n = 12

	# print("Encrypted:", encryptDes(plaintext, key, R, n));
	print("Decrypted:", decryptDes(chipertext, key, R, n));

if __name__ == "__main__":
	main()
