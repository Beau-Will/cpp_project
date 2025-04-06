#include <bits/stdc++.h>

using i64 = long long;

constexpr int P1 = 1000000007,P2 = 998244353;

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
using mint = ModInt<P1>;
using Z = ModInt<P2>;

void solve(){
    int n,m,k,q;
    std::cin >> n >> m >> k >> q;

    std::vector<std::pair<int,int>> query(q);
    for(int i = 0; i < q; ++i){
        std::cin >> query[i].first >> query[i].second;
    }
    
    std::set<std::pair<int,int>> set;
    i64 cnt = 0;
    int rows = 0,cols = 0;
    std::vector<bool> row(n+1),col(m+1);
    for(int i = q-1; i >= 0; --i){
        bool flag1 = false,flag2 = false,flag3 = false,flag4 = false;
        if(set.count(query[i])){
            continue;
        }
        if(row[query[i].first]){
            flag1 = true;
        }
        if(col[query[i].second]){
            flag2 = true;
        }

        if(rows==n){
            flag3 = true;
        }
        if(cols==m){
            flag4 = true;
        }

        if(!row[query[i].first]){
            row[query[i].first] = true;
            ++rows;
        }
        if(!col[query[i].second]){
            col[query[i].second] = true;
            ++cols;
        }
        set.insert(query[i]);

        if(flag1&&flag2){
            continue;
        }

        if(flag3 || flag4){
            continue;
        }

        ++cnt;
    }

    std::cout << Z(k).pow(cnt) << "\n";
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