n1 = 320
n2 = 64
n3 = 560

for i in range(2, min(n1, min(n2, n3)) + 1):
	if n1%i == 0 and n2%i == 0 and n3%i == 0:
		print(i)
