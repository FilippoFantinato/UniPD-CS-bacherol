import string
import random

length = 10
vocabolary = list(string.ascii_letters) + list(string.digits)

password = ''.join(random.choices(vocabolary, k = length))

print(password)