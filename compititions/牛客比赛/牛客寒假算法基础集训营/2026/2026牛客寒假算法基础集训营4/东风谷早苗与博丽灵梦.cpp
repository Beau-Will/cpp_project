#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

/**   int128 库函数自定义
 *    2024-08-14: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=70979004&returnHomeType=1&uid=329687984
 *    2024-09-17: https://qoj.ac/submission/571481
**/
using i128 = __int128;

std::ostream& operator<<(std::ostream& os, i128 n) {
  if (n == 0) {
    return os << 0;
  }
  std::string s;
  while (n > 0) {
    s += char('0' + n % 10);
    n /= 10;
  }
  std::reverse(s.begin(), s.end());
  return os << s;
}

i128 toi128(const std::string& s) {
  i128 n = 0;
  for (auto c : s) {
    n = n * 10 + (c - '0');
  }
  return n;
}

i128 sqrti128(i128 n) {
  i128 lo = 0, hi = 1E16;
  while (lo < hi) {
    i128 x = (lo + hi + 1) / 2;
    if (x * x <= n) {
      lo = x;
    } else {
      hi = x - 1;
    }
  }
  return lo;
}

i128 gcd(i128 a, i128 b) {
  while (b) {
    a %= b;
    std::swap(a, b);
  }
  return a;
}

template<typename T>
constexpr T exgcd(T a, T b, T& x, T& y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  T d = exgcd(b, a % b, y, x);
  y -= (a / b) * x;
  return d;
}

void solve(){
  i64 x, a, s;
  std::cin >> x >> a >> s;

  // 1 ... x
  // a * i + s * j = 1

  i64 gcd = std::gcd(a, s);

  if(x % gcd){
    std::cout << "No\n";
    return;
  }

  x /= gcd, a /= gcd, s /= gcd;

  i64 i, j;
  auto _ = exgcd(a, s, i, j);

  i128 u = static_cast<i128>(i) * x;
  i128 v = static_cast<i128>(j) * x;

  auto floorD = [&](auto a, auto b){
    if(a >= 0){
      return a / b;
    }
    return (a - b + 1) / b;
  };

  auto ceilD = [&](auto a, auto b){
    if(a >= 0){
      return (a + b - 1) / b;
    }
    return a / b;
  };

  i128 l = ceilD((-v), a);
  i128 r = floorD(u, s);
  if(l > r){
    std::cout << "No\n";
    return;
  }

  // std::cout << l << " " << r << "\n";
  
  i128 t = static_cast<i128>(a) + s;
  i128 diff = u - v;
  // assert(diff < 0);
  i128 k = floorD(diff, t);

  std::vector<i128> res = {l, r};

  if(k >= l && k <= r){
    res.push_back(k);
  }
  if(k + 1 >= l && k + 1 <= r){
    res.push_back(k + 1);
  }

  i128 b = l;
  i128 ans1 = u - b * s;
  i128 ans2 = v + b * a;
  i128 max = std::max(ans1, ans2);

  for(int i = 0; i < res.size(); i++){
    auto x = res[i];
    i128 cur = std::max(u - x * s, v + x * a);

    if(cur < max){
      max = cur;
      b = x;
      ans1 = u - x * s;
      ans2 = v + x * a;
    }
  }

  std::cout << "Yes\n";
  std::cout << ans1 << " " << ans2 << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}