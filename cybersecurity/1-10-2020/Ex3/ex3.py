import random

LENGTH = 10
ranges = [(48, 57), (65, 90), (97, 122)]

password = ''.join([chr(random.randint(*random.choice(ranges))) for i in range(0, LENGTH)]);

print("Password: " + password)
