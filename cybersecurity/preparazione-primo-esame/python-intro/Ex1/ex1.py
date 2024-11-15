key = 2

word = input("Word: ")

print(''.join([chr(ord(s) + key) for s in word]))
