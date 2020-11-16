import random
from datetime import date

def xyz(x, y):
    random.seed(x)
    z = []
    r = range(y)
    for i in r:
        z.append(random.randint(1, 100))
    return z

def zyx(x):
    z = date.today().year
    y = xyz(z, len(x))

    aaaaaa = ''
    for i in range(len(x), 0, -1):
        t = i - 1
        bbbbbb = y[t]
        ccccccccc = x[t]
        qwertyui = chr(bbbbbb ^ ord(ccccccccc))

        aaaaaa += qwertyui
    return aaaaaa
