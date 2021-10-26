#!/usr/bin/env python3

frequencies = {}

with open("encrpyted.txt", "rt") as f:
	for char in f.read():
		if char.isalpha():
			if char in frequencies:
				frequencies[char] += 1
			else:
				frequencies[char] = 1

total = 0

for key in frequencies:
	total = total + frequencies[key]

for key in frequencies:
	print(key, ' - ', frequencies[key] / total * 100)
