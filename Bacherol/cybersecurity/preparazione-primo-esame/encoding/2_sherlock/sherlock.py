with open("challenge.txt") as f:
	text = f.read()

	filtered = (''.join([ t for t in text if t.isupper() ])).replace("ZERO", "0").replace("ONE", "1")
	print(filtered)
