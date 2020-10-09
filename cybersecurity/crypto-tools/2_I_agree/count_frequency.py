text = "caesar is everything. But he took it to the next level."
text2 = "vhixoieemksktorywzvhxzijqni";


def count_frequency(txt):
	freq = { }

	for ch in txt:
		if not ch in freq:
			freq[ch] = 0

		freq[ch] = freq[ch] + 1

	for f in freq:
		

	return freq

print("Text: ", count_frequency(text))

print("Chiper: ", count_frequency(text2))
