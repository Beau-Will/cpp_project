#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

/**
 * @brief 指数生成函数多项式（存储系数为实际排列数，EGF 乘法自动乘组合数）
 * @tparam Coef 系数类型，支持 +, *, =, 0 等基本运算
 */
template<typename Coef = i64>
struct EGF {
    using value_type = Coef;
    using size_type = std::size_t;

    std::vector<Coef> coeffs;   // coeffs[i] = x^i 的系数（排列数）

    /* ---------- 静态组合数表（按需扩展） ---------- */
    static std::vector<std::vector<Coef>> comb;
    static void ensure_comb(int n) {
        if ((int)comb.size() > n) return;
        int old = comb.size();
        comb.resize(n + 1);
        for (int i = old; i <= n; ++i) {
            comb[i].resize(i + 1);
            comb[i][0] = comb[i][i] = Coef(1);
            for (int j = 1; j < i; ++j)
                comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
        }
    }
    static Coef C(int n, int k) {
        if (k < 0 || k > n) return Coef(0);
        ensure_comb(n);
        return comb[n][k];
    }

    /* ---------- 构造函数 ---------- */
    EGF() = default;
    explicit EGF(size_type n) : coeffs(n, Coef(0)) {}
    EGF(std::initializer_list<Coef> list) : coeffs(list) {}
    EGF(const std::vector<Coef>& v) : coeffs(v) {}
    EGF(std::vector<Coef>&& v) : coeffs(std::move(v)) {}

    /// 区间多项式：系数在 [low, high] 均为 val（默认 1）
    EGF(int low, int high, Coef val = Coef(1)) {
        if (low > high) return;
        coeffs.resize(high + 1, Coef(0));
        for (int i = low; i <= high; ++i)
            coeffs[i] = val;
    }

    /* ---------- 常数多项式 ---------- */
    static EGF constant(Coef c) {
        EGF p(1);
        p.coeffs[0] = c;
        return p;
    }
    static EGF one() { return constant(Coef(1)); }
    static EGF zero() { return EGF(); }

    /* ---------- 系数访问 ---------- */
    Coef at(size_type i) const {
        return i < coeffs.size() ? coeffs[i] : Coef(0);
    }
    void set(size_type i, Coef c) {
        if (i >= coeffs.size()) coeffs.resize(i + 1, Coef(0));
        coeffs[i] = c;
    }

    /* ---------- 基本信息 ---------- */
    size_type size() const { return coeffs.size(); }
    bool empty() const { return coeffs.empty(); }

    /// 多项式次数（最高非零指数），零多项式返回 -1
    int degree() const {
        if (coeffs.empty()) return -1;
        int d = (int)coeffs.size() - 1;
        while (d >= 0 && coeffs[d] == Coef(0)) --d;
        return d;
    }

    /// 去除尾部零系数
    EGF& trim() {
        while (!coeffs.empty() && coeffs.back() == Coef(0))
            coeffs.pop_back();
        return *this;
    }

    /* ---------- 加法（普通多项式加法） ---------- */
    EGF operator+(const EGF& other) const {
        size_type n = std::max(coeffs.size(), other.coeffs.size());
        EGF res(n);
        for (size_type i = 0; i < n; ++i)
            res.coeffs[i] = this->at(i) + other.at(i);
        res.trim();
        return res;
    }

    /* ---------- EGF 乘法（组合数卷积） ---------- */
    EGF mul(const EGF& other, int max_degree = -1) const {
        if (coeffs.empty() || other.coeffs.empty())
            return EGF();

        size_type n1 = coeffs.size();
        size_type n2 = other.coeffs.size();
        size_type res_size = n1 + n2 - 1;
        if (max_degree >= 0)
            res_size = std::min<size_type>(res_size, max_degree + 1);

        EGF res(res_size);
        for (size_type i = 0; i < n1; ++i) {
            if (coeffs[i] == Coef(0)) continue;
            for (size_type j = 0; j < n2; ++j) {
                size_type k = i + j;
                if (k >= res_size) break;
                if (other.coeffs[j] == Coef(0)) continue;
                // EGF 卷积：C(k, i) * a_i * b_j
                res.coeffs[k] += C(k, i) * coeffs[i] * other.coeffs[j];
            }
        }
        return res;
    }

    EGF operator*(const EGF& other) const {
        return mul(other);
    }

    /* ---------- 输出（调试用） ---------- */
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
    friend std::ostream& operator<<(std::ostream& os, const EGF& p) {
        p.print(os);
        return os;
    }
};

// 静态成员初始化
template<typename Coef>
std::vector<std::vector<Coef>> EGF<Coef>::comb;

void solve(){
  using Poly = EGF<i64>;
  int n, m;
  while(std::cin >> n >> m){
    Poly ans = Poly::one();
    for(int i = 0; i < n; i++){
      int x;
      std::cin >> x;
      ans = ans.mul(Poly(0, x, 1), m);
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