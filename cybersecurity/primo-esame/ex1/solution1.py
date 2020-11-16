import random
from datetime import date

# def xyz(x, y):
#     random.seed(x)
#     z = []
#     r = range(y)
#     for i in r:
#         z.append(random.randint(1, 31))
#     return z

# def zyx(x):
#     z = date.today().year
#     y = xyz(z, len(x))

#     print(f"y: {y}")

#     aaaaaa = ''
#     for i in range(len(x), 0, -1):
#         t = i - 1
#         bbbbbb = y[t]
#         ccccccccc = x[t]
#         print(f"b^c: {y[t]}^{x[t]}")
#         qwertyui = chr(bbbbbb ^ ord(ccccccccc))

#         aaaaaa += qwertyui
#     return aaaaaa

def dec_xyz(x, y):
    random.seed(x)
    print(f"year: {x}")
    z = []
    r = range(y)
    for i in r:
        z.insert(0, random.randint(1, 31))
    return z

def decode(x):
    z = date.today().year
    y = dec_xyz(z, len(x))

    print(f"y: {y}")

    aaaaaa = ''
    for i in range(len(x), 0, -1):
        t = i - 1
        bbbbbb = y[t]
        ccccccccc = x[t]
        print(f"b^c: {y[t]}^{x[t]}")
        qwertyui = chr(bbbbbb ^ ord(ccccccccc))

        aaaaaa += qwertyui
    return aaaaaa


def main(): 
    # res = zyx("ciao come"); 
    # print(f"encode: {res}")

    dec_res = decode("{$#=7(2Kk&>DA8/P6%Y}ZnUbLdUM_TDG")
    print(f"decode: {dec_res}");


if __name__ == '__main__':
    main()
