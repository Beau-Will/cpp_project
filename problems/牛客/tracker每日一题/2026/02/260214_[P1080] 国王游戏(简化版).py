standard_input, packages = 1, 1

if 1:
  if standard_input:
    import sys
    input = lambda : sys.stdin.readline().strip()

    import math
    inf = math.inf
    P1, P2 = 10 ** 9 + 7, 998244353

    def I():
      return input()
    def II():
      return int(input())
    def MII():
      return map(int, input().split())
    def LI():
      return input().split()
    def LII():
      return list(map(int, input().split()))
    def LFI():
      return list(map(float, input().split()))
    def GMI():
      return map(lambda x : int(x) - 1, input().split())
    def LGMI():
      return list(map(lambda x : int(x) - 1, input().split()))
  
  if packages:
    import random
    import os

    import bisect
    import typing
    from io import BytesIO, IOBase
    from collections import Counter, defaultdict, deque
    from copy import deepcopy
    from heapq import merge, heapify, heappop, heappush, heappushpop, nlargest, nsmallest, heapreplace
    from itertools import accumulate, combinations, permutations, count, product
    from operator import add, iand, ior, itemgetter, mul, xor
    from string import ascii_lowercase, ascii_uppercase, ascii_letters
    from typing import *
    from functools import cmp_to_key
  
  fmax = lambda a, b : a if a > b else b
  fmin = lambda a, b : a if a < b else b

def solve():
  n = II()
  c = []
  for i in range(n + 1):
    ai, bi = MII()
    c.append((ai, bi))
  c[1:] = sorted(c[1:], key = lambda t: t[0] * t[1])
  pre = [1 for i in range(n + 1)]
  pre[0] = c[0][0]
  for i in range(1, n + 1):
    pre[i] = pre[i - 1] * c[i][0]
  ans = 0
  for i in range(1, n + 1):
    ans = fmax(ans, pre[i - 1] // c[i][1])
  print(ans)
  return

T = 1
# T = II()

for Ti in range(T):
  solve()