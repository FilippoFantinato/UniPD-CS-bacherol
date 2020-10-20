import string

chipertext = ""

with open("encrypted.txt", "r") as f:
	chipertext = f.read()

plaintext = ""

map = {
	"A": "L", 
	"B": "S", 
	"C": "R", 
	"D": "O", 
	"E": "a", 
	"F": "A", 
	"G": "D", 
	"H": "B", 
	"I": "G", 
	"J": "P", 
	"K": "I", 
	"L": "H", 
	"M": "N", 
	"N": "T", 
	"O": "a", 
	"P": "Y", 
	"Q": "M", 
	"R": "a", 
	"S": "V", 
	"T": "U", 
	"U": "E", 
	"V": "W", 
	"W": "F", 
	"X": "C", 
	"Y": "a", 
	"Z": "a",
}

for key in chipertext:
	plaintext = plaintext + (map[key] if key.isalpha() else key);

print(plaintext)
