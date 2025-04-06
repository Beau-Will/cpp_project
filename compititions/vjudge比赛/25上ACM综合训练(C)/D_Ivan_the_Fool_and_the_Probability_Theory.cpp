#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr int P1 = 1000000007,P2 = 998244353;

template<const int T>
struct mod_int{
    const static int _mod = T;
    int _x;

    template<typename P>
    mod_int(P n = P{}):_x(n%_mod){}
    int get_value(){
        return _x;
    }
    mod_int():_x(0){

    }
    friend std::istream &operator >> (std::istream &is,mod_int &t){
        return is >> t._x;
    }
    friend std::ostream &operator << (std::ostream &os,const mod_int &t){
        return os << t._x;
    }
    mod_int operator + (const mod_int &a) const{
        int sum = _x+a._x;
        return mod_int(sum>=_mod?sum-_mod:sum);
    }
    mod_int operator - (const mod_int &a) const{
        int minus = _x-a._x;
        return mod_int(minus>=0?minus:minus+_mod);
    }
    mod_int operator * (const mod_int &a) const{
        i64 mul = 1LL*_x*a._x;
        return mod_int(mul%_mod);
    }
    mod_int operator / (const mod_int &a) const{
        return mod_int(1LL*_x*a.inv()%_mod);
    }
    bool operator == (const mod_int &a) const{
        return _x==a._x;
    }
    bool operator != (const mod_int &a) const{
        return _x!=a._x;
    }
    void operator += (const mod_int &a){
        _x += a._x;
        if(_x>=_mod){
            _x -= _mod;
        }
    }
    void operator -= (const mod_int &a){
        _x -= a._x;
        if(_x<0){
            _x += _mod;
        }
    }
    void operator *= (const mod_int &a){
        _x = 1LL*_x*a._x%_mod;
    }
    void operator /= (const mod_int &a){
        _x = 1LL * _x * a.inv()%_mod;
    }
    friend mod_int operator + (int a,const mod_int &b){
        int sum = a+b._x;
        return mod_int(sum>=_mod?sum-_mod:sum);
    }
    friend mod_int operator - (int a,const mod_int &b){
        int minus = a - b._x;
        return mod_int(minus<0?minus+_mod:minus);
    }
    friend mod_int operator * (int a,const mod_int &b){
        i64 mul = 1LL*a*b._x;
        return mod_int(mul%_mod);
    }
    friend mod_int operator / (int a,const mod_int &b){
        i64 div = 1LL*a*b.inv();
        return mod_int(div%_mod);
    }

    template<typename Q>
    mod_int quick_power(Q n) const{
        mod_int res(1),a(_x);
        for(;n;a = a*a){
            if(n&1){
                res = res*a;
            }
            n >>= 1;
        }
        return res;
    }
    mod_int inv() const{
        return quick_power(_mod-2);
    }
};

using Z = mod_int<P1>;
// using Z = mod_int<P2>;

using Matrix = std::array<std::array<Z,3>,3>;

void solve(){
    i64 n,m;
    std::cin >> n >> m;

    auto mul = [&](Matrix &a,Matrix &b)->Matrix{
        Matrix c;
        for(int i = 1; i <= 2; ++i){
            for(int j = 1; j <= 2; ++j){
                c[i][j] = 0;
            }
        }
        for(int i = 1; i <= 2; ++i){
            for(int j = 1; j <= 2; ++j){
                for(int k = 1; k <= 2; ++k){
                    c[i][k] += a[i][j]*b[j][k];
                }
            }
        }
        return c;
    };

    auto quick_power = [&](Matrix a,i64 b)->Matrix{
        Matrix res;
        for(int i = 1; i <= 2; ++i){
            for(int j = 1; j <= 2; ++j){
                res[i][j] = 0;
            }
        }
        for(int i = 1; i <= 2; ++i){
            res[i][i] = 1;
        }
        for(;b;a = mul(a,a)){
            if(b&1){
                res = mul(res,a);
            }
            b >>= 1;
        }
        return res;
    };

    Matrix A1,B1;
    B1[1][1] = B1[1][2] = B1[2][1] = 1,B1[2][2] = 0;
    A1[1][1] = A1[2][1] = 1,A1[1][2] = A1[2][2] = 0;

    auto Bn = quick_power(B1,n-1);
    auto Bm = quick_power(B1,m-1);

    auto An = mul(Bn,A1);
    auto Am = mul(Bm,A1);

    std::cout << (An[1][1]+Am[1][1]-1)*2 << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}