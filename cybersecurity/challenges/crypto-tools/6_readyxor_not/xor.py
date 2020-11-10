import base64

original_data = "El Psy Congroo"
encrypted_data = base64.b64decode("IFhiPhZNYi0KWiUcCls=".encode("ascii")).decode("ascii")
encrypted_flag = base64.b64decode("I3gDKVh1Lh4EVyMDBFo=".encode("ascii")).decode("ascii")

def sxor(s1,s2):    
    # convert strings to a list of character pair tuples
    # go through each tuple, converting them to ASCII code (ord)
    # perform exclusive or on the ASCII code
    # then convert the result back to ASCII (chr)
    # merge the resulting array of characters as a string
    return ''.join(chr(ord(a) ^ ord(b)) for a,b in zip(s1,s2))


print(sxor(sxor(original_data, encrypted_data), encrypted_flag))