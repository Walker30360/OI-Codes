a = input()
b = input()
a = int(a)
b = int(b)
while a:
    b %= a
    tmp = a
    a = b
    b = tmp
print(b)