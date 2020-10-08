FILENAME = "challenge.txt"
book = open(FILENAME, "r")
secretWord = "" 

for ch in book.read():
	if ch.isupper():
		secretWord = secretWord + ch

print("Secret word: " + secretWord.replace("ZERO", "0").replace("ONE", "1"))
