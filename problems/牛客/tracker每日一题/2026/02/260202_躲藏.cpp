#include <iostream>
#include <string>
#include <cassert>
#include <vector>

using i64 = long long;

constexpr i64 P = 2000120420010122;

template<class T>
constexpr T power(T a, i64 b) {
  T res = 1;
  for (; b; b /= 2, a *= a) {
    if (b % 2) {
      res *= a;
    }
  }
  return res;
}

constexpr i64 mul(i64 a, i64 b, i64 p) {
  i64 res = a * b - i64(1.L * a * b / p) * p;
  res %= p;
  if (res < 0) {
    res += p;
  }
  return res;
}

template<i64 P>
struct MLong {
  i64 x;
  constexpr MLong() : x{} {}
  constexpr MLong(i64 x) : x{norm(x % getMod())} {}

  static i64 Mod;
  constexpr static i64 getMod() {
    if (P > 0) {
      return P;
    } else {
      return Mod;
    }
  }
  constexpr static void setMod(i64 Mod_) {
    Mod = Mod_;
  }
  constexpr i64 norm(i64 x) const {
    if (x < 0) {
      x += getMod();
    }
    if (x >= getMod()) {
      x -= getMod();
    }
    return x;
  }
  constexpr i64 val() const {
    return x;
  }
  explicit constexpr operator i64() const {
    return x;
  }
  constexpr MLong operator-() const {
    MLong res;
    res.x = norm(getMod() - x);
    return res;
  }
  constexpr MLong inv() const {
    assert(x != 0);
    return power(*this, getMod() - 2);
  }
  constexpr MLong& operator*=(MLong rhs)& {
    x = mul(x, rhs.x, getMod());
    return *this;
  }
  constexpr MLong& operator+=(MLong rhs)& {
    x = norm(x + rhs.x);
    return *this;
  }
  constexpr MLong& operator-=(MLong rhs)& {
    x = norm(x - rhs.x);
    return *this;
  }
  constexpr MLong& operator/=(MLong rhs)& {
    return *this *= rhs.inv();
  }
  friend constexpr MLong operator*(MLong lhs, MLong rhs) {
    MLong res = lhs;
    res *= rhs;
    return res;
  }
  friend constexpr MLong operator+(MLong lhs, MLong rhs) {
    MLong res = lhs;
    res += rhs;
    return res;
  }
  friend constexpr MLong operator-(MLong lhs, MLong rhs) {
    MLong res = lhs;
    res -= rhs;
    return res;
  }
  friend constexpr MLong operator/(MLong lhs, MLong rhs) {
    MLong res = lhs;
    res /= rhs;
    return res;
  }
  friend constexpr std::istream& operator>>(std::istream& is, MLong& a) {
    i64 v;
    is >> v;
    a = MLong(v);
    return is;
  }
  friend constexpr std::ostream& operator<<(std::ostream& os, const MLong& a) {
    return os << a.val();
  }
  friend constexpr bool operator==(MLong lhs, MLong rhs) {
    return lhs.val() == rhs.val();
  }
  friend constexpr bool operator!=(MLong lhs, MLong rhs) {
    return lhs.val() != rhs.val();
  }
};

template<>
i64 MLong<0LL>::Mod = i64(1E18) + 9;

using Z = MLong<P>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s;
  while (std::cin >> s) {

    int n = s.size();
    s = " " + s;

    std::vector<Z> dp(4);

    for (int i = 1; i <= n; i++) {
      dp[0] += (std::tolower(s[i]) == 'c');
      dp[1] += (std::tolower(s[i]) == 'w') * dp[0];
      dp[2] += (std::tolower(s[i]) == 'b') * dp[1];
      dp[3] += (std::tolower(s[i]) == 'c') * dp[2];
    }

    std::cout << dp[3] << "\n";
  }

  return 0;
}