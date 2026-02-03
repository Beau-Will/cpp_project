import sys

input = lambda : sys.stdin.readline().strip()

def quick_power(a, b):
  res = 1
  while b != 0:
    if b & 1:
      res *= a
    a = a * a
    b //= 2
  return res


ans = []
t = int(input())
for i in range(t):
  n, k = map(int, input().split())
  if k == 1:
    ans.append(n)
    continue
  elif k >= 65:
    ans.append(1)
    continue
  lo = 1
  hi = 1000000000
  while lo < hi:
    mid = (lo + hi) // 2
    if n - quick_power(mid, k) > 0:
      low = mid + 1
    else:
      high = mid
  if abs(n - quick_power(lo - 1, k)) < abs(n - quick_power(lo, k)):
    ans.append(lo - 1)
  else:
    ans.append(lo)

print("\n".join(map(str, ans)))