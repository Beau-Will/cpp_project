#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr int P1 = 1'000'000'007,P2 = 998'244'353;

template<const int T>
struct ModInt {
    const static int mod = T;
    int x;
    ModInt(int x = 0) : x(x % mod) {}
    ModInt(long long x) : x(int(x % mod)) {} 
    int val() { return x; }
    ModInt operator + (const ModInt &a) const { int x0 = x + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); }
    ModInt operator - (const ModInt &a) const { int x0 = x - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }
    ModInt operator * (const ModInt &a) const { return ModInt(1LL * x * a.x % mod); }
    ModInt operator / (const ModInt &a) const { return *this * a.inv(); }
    bool operator == (const ModInt &a) const { return x == a.x; };
    bool operator != (const ModInt &a) const { return x != a.x; };
    void operator += (const ModInt &a) { x += a.x; if (x >= mod) x -= mod; }
    void operator -= (const ModInt &a) { x -= a.x; if (x < 0) x += mod; }
    void operator *= (const ModInt &a) { x = 1LL * x * a.x % mod; }
    void operator /= (const ModInt &a) { *this = *this / a; }
    friend ModInt operator + (int y, const ModInt &a){ int x0 = y + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); }
    friend ModInt operator - (int y, const ModInt &a){ int x0 = y - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }
    friend ModInt operator * (int y, const ModInt &a){ return ModInt(1LL * y * a.x % mod);}
    friend ModInt operator / (int y, const ModInt &a){ return ModInt(y) / a;}
    friend std::ostream &operator<<(std::ostream &os, const ModInt &a) { return os << a.x;}
    friend std::istream &operator>>(std::istream &is, ModInt &t){return is >> t.x;}
 
    ModInt pow(i64 n) const {
        ModInt res(1), mul(x);
        while(n){
            if (n & 1) res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }
     
    ModInt inv() const {
        int a = x, b = mod, u = 1, v = 0;
        while (b) {
            int t = a / b;
            a -= t * b; std::swap(a, b);
            u -= t * v; std::swap(u, v);
        }
        if (u < 0) u += mod;
        return u;
    }
     
};
// using mint = ModInt<P1>;
using Z = ModInt<P1>;

void solve(){
    int n,V,cost;
    std::cin >> n >> V >> cost;

    std::vector<int> v(n+1);
    for(int i = 1; i <= n; ++i){
        std::cin >> v[i];
    }

    std::vector dp(V+1,std::vector<Z>(cost+1));

    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= V; ++j){
            for(int k = v[i]; k <= cost; ++k){
                dp[j][k] += dp[j-1][k-v[i]];
            }
        }
    }

    Z ans(0);
    for(int i = 0; i <= cost; ++i){
        ans += dp[V][i];
    }

    std::cout << ans << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}