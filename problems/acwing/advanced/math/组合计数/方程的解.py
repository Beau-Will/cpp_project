# 由于需要实现高精度，因此直接用Python来写了
import sys

input = lambda : sys.stdin.readline().strip()

k, x = map(int, input().split())
x = pow(x % 1000, x, 1000)

fac = [0] * 1000
fac[0] = 1
for i in range(1, 1000):
  fac[i] = fac[i-1] * i

def C(n, m):
  return fac[n] // fac[m] // fac[n-m]

print(C(x - 1, k - 1))