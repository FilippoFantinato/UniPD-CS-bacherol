import sys

key = 2
string = sys.argv[1]
newString = ""

for index in range(0, len(string)) :
	newString += chr(ord(string[index]) + key);

print("In: " + string)
print("Out: " + newString);
