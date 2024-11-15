msg = "{$#=7(2Kk&>DA8/P6%Y}ZnUbLdUM_TDG"

for i in range(127):
	tmp = ''.join([chr(ord(t) + i) for t in msg])

	print(tmp)
