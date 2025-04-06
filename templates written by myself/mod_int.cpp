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