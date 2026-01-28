#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

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

template<typename T>
constexpr T ChineseRemainerTheorem(const std::vector<T> &a, const std::vector<T> &m) {
	T res = 0;
	T M = 1;
	for (int i = 0; i < m.size(); i++) {
		M *= m[i];
	}
	for(int i = 0; i < m.size(); i++) {
		T Mi = M / m[i];
		T xi, yi;
		T gcd = exgcd(Mi, m[i], xi, yi);
		res = (res + Mi * xi * a[i]) % M;
	}
	return (res + M) % M;
}

void solve(){
  int n;
  std::cin >> n;

  std::vector<i128> a(n),b(n);
  for(int i = 0; i < n; i++){
    i64 ai, bi;
    std::cin >> ai >> bi;
    a[i] = ai, b[i] = bi;
  }

  auto ans = ChineseRemainerTheorem(b, a);

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}