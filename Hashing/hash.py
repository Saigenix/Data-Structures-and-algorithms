def hash(string):
    x = (ord(string[0])) << 7
    if x == 0 : x+= 11
    for chr in string[1:]:
        x = ((1000003 * x) ^ ord(chr)) & (1<<32)
    return x


print(hash("Sai"))