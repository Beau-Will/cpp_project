#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

/**
 * @brief 普通生成函数多项式（形式幂级数截断）
 * @tparam Coef 系数类型，支持 + * = 0 等基本运算
 */
template<typename Coef = i64>
struct OGF {
  using value_type = Coef;
  using size_type = std::size_t;

  std::vector<Coef> coeffs;  // coeffs[i] = x^i 系数

  /* ---------- 构造函数 ---------- */
  OGF() = default;
  explicit OGF(size_type n) : coeffs(n, Coef(0)) {}
  OGF(std::initializer_list<Coef> list) : coeffs(list) {}
  OGF(const std::vector<Coef>& v) : coeffs(v) {}
  OGF(std::vector<Coef>&& v) : coeffs(std::move(v)) {}

  /**
   * @brief 区间多项式：系数在 [low, high] 均为 val (默认1)
   *        若 low>high 得到零多项式
   */
  OGF(int low, int high, Coef val = Coef(1)) {
    if (low > high) return;
    coeffs.resize(high + 1, Coef(0));
    for (int i = low; i <= high; ++i)
      coeffs[i] = val;
  }

  /* ---------- 常数多项式 ---------- */
  static OGF constant(Coef c) {
    OGF p(1);
    p.coeffs[0] = c;
    return p;
  }
  static OGF one() {
    return constant(Coef(1));
  }
  static OGF zero() {
    return OGF();
  }

  /* ---------- 系数访问 ---------- */
  Coef at(size_type i) const {
    return i < coeffs.size() ? coeffs[i] : Coef(0);
  }

  void set(size_type i, Coef c) {
    if (i >= coeffs.size())
      coeffs.resize(i + 1, Coef(0));
    coeffs[i] = c;
  }

  /* ---------- 基本信息 ---------- */
  size_type size() const {
    return coeffs.size();
  }
  bool empty() const {
    return coeffs.empty();
  }

  /// 多项式次数（最高非零指数），零多项式返回 -1
  int degree() const {
    if (coeffs.empty()) return -1;
    int d = static_cast<int>(coeffs.size()) - 1;
    while (d >= 0 && coeffs[d] == Coef(0)) d--;
    return d;
  }

  /// 去除尾部零系数
  OGF& trim() {
    while (!coeffs.empty() && coeffs.back() == Coef(0))
      coeffs.pop_back();
    return *this;
  }

  /* ---------- 多项式运算 ---------- */
  OGF operator+(const OGF& other) const {
    size_type n = std::max(coeffs.size(), other.coeffs.size());
    OGF res(n);
    for (size_type i = 0; i < n; ++i)
      res.coeffs[i] = this->at(i) + other.at(i);
    res.trim();
    return res;
  }

  /**
   * @brief 乘法（支持截断）
   * @param max_degree 结果保留最高次数，-1 不截断
   */
  OGF mul(const OGF& other, int max_degree = -1) const {
    if (coeffs.empty() || other.coeffs.empty())
      return OGF();

    size_type n1 = coeffs.size();
    size_type n2 = other.coeffs.size();
    size_type res_size = n1 + n2 - 1;
    if (max_degree >= 0)
      res_size = std::min<size_type>(res_size, max_degree + 1);

    OGF res(res_size);
    for (size_type i = 0; i < n1; ++i) {
      if (coeffs[i] == Coef(0)) continue;
      for (size_type j = 0; j < n2; ++j) {
        if (i + j >= res_size) break;
        if (other.coeffs[j] == Coef(0)) continue;
        res.coeffs[i + j] += coeffs[i] * other.coeffs[j];
      }
    }
    return res;
  }

  OGF operator*(const OGF& other) const {
    return mul(other);
  }

  /* ---------- 输出 ---------- */
  void print(std::ostream& os = std::cout) const {
    bool first = true;
    for (size_type i = 0; i < coeffs.size(); ++i) {
      if (coeffs[i] != Coef(0)) {
        if (!first) os << " + ";
        os << coeffs[i] << "x^" << i;
        first = false;
      }
    }
    if (first) os << "0";
  }

  friend std::ostream& operator<<(std::ostream& os, const OGF& p) {
    p.print(os);
    return os;
  }
};

void solve(){
  using OGF = OGF<i64>;

  int n, m;
  while(std::cin >> n >> m){
    OGF ans = OGF::one();

    for(int i = 0; i < n; i++){
      int a, b;
      std::cin >> a >> b;
      OGF fruit(a, b);
      ans = ans.mul(fruit, m);
    }

    std::cout << ans.at(m) << "\n";
  }
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