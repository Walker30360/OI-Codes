nx = input()
n = int(nx)
t = 1
a = 0
while t <= n :
    a += 1
    a *= 10
    t += 1
a /= 10
print((int)(a % 998244353))