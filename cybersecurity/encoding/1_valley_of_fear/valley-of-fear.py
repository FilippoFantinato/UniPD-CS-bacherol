FILENAME = "book.txt"

secretWord = ""

secrets = [(1, 9, 4), (4, 2, 8), (4, 8, 3), (7, 1, 5), (8, 10, 1)]

book = open(FILENAME, "r")
bookLines = book.readlines()
bookLine = 0

paragraph = 1
paragraphLine = 1

for secretIndex in range(0, len(secrets)):
	secret = secrets[secretIndex]

	for bookLine in range(bookLine, len(bookLines)):
		line = bookLines[bookLine]

		if paragraph > secret[0]:
			break

		if paragraph == secret[0] and paragraphLine == secret[1]:
			secretWord = secretWord + line[secret[2] - 1]
			print(paragraph, "", paragraphLine, line[secret[2] - 1])
			break;

		paragraphLine = paragraphLine + 1

		if not line.strip():
			paragraph = paragraph + 1
			paragraphLine = 1



print("Secret word: " + secretWord);
