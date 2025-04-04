#include <bits/stdc++.h>

using i64 = long long;

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
using mint = ModInt<P1>;
using Z = ModInt<P2>;

void solve(){
    int n;
    std::cin >> n;

    int fenzi = 0,fenmu = 0;
    auto dfs = [&](auto &&self,int u,int t){

        if(u<=0){
            return;
        }
        if(t==1){
            if(u<4){
                ++fenmu;
                ++fenzi;
            }
            self(self,u-4,t^1);

            if(u==1){
                ++fenmu;
            }
            self(self,u-1,t^1);
        }else{
            if(u==1){
                ++fenzi;
                ++fenmu;
                self(self,u-1,t^1);
            }
            if(u==4){
                ++fenzi;
                ++fenmu;
                self(self,u-4,t^1);
            }
            if(u&1){
                self(self,u-1,t^1);
            }else{
                if(u>4) self(self,u-4,t^1);
                else self(self,u-1,t^1);
            }
            // if(u%4==0){
                // self(self,u-4,t^1);
            // }else{
                // self(self,u-1,t^1);
            // }

            
            // self(self,u-1,t^1);
            // if(u>=4){
            //     self(self,u-4,t^1);
            // }
        }
    };

    dfs(dfs,n,1);

    std::cout << n << ":" << fenzi << "/" << fenmu << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // for(int i = 1; i <= 103; ++i){
        std::cout << Z(5)*Z(6).inv() << "\n";
    // }

    int t = 1;
    std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}