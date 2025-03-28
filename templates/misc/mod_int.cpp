using i64 = long long;
 
constexpr int N = 1e6 + 5, P = 1e9 + 7;
 
template<typename T>
T power(T a, i64 b) {
    T ret = 1;
    while (b) {
        if (b & 1) ret = ret * a;
        a = a * a;
        b >>= 1;
    }
    return ret;
}

template<int P>
struct ModInt {
    int val;
 
    static inline int norm(int x) {
        if (x < 0)  x += P;
        if (x >= P) x -= P;
        return x; 
    }
 
    ModInt operator - () const { return ModInt(P - val); }
    inline ModInt inv() const { return power(*this, P - 2); }
 
    ModInt() {}
    ModInt(int val) : val(norm(val % P)) {}
    ModInt(i64 val) : val(norm(val % P)) {}
 
    bool constexpr operator <  (const ModInt &rhs) const { return val < rhs.val; }
    bool constexpr operator == (const ModInt &rhs) const { return val == rhs.val; }
    bool constexpr operator != (const ModInt &rhs) const { return val != rhs.val; }
 
    ModInt &operator += (const ModInt &rhs) & { return val = norm(val + rhs.val), *this; }
    ModInt &operator -= (const ModInt &rhs) & { return val = norm(val - rhs.val), *this; }
    ModInt &operator *= (const ModInt &rhs) & { return val = 1ll * val * rhs.val % P, *this; }
    ModInt &operator /= (const ModInt &rhs) & { return *this *= rhs.inv(); }
 
    ModInt constexpr operator + (const ModInt &rhs) const { ModInt ret = *this; return ret += rhs; }
    ModInt constexpr operator - (const ModInt &rhs) const { ModInt ret = *this; return ret -= rhs; }
    ModInt constexpr operator * (const ModInt &rhs) const { ModInt ret = *this; return ret *= rhs; }
    ModInt constexpr operator / (const ModInt &rhs) const { ModInt ret = *this; return ret /= rhs; }
 
    friend std::istream& operator >> (std::istream& is, ModInt &rhs) {
        i64 val; is >> val;
        return rhs.val = norm(val % P), is;
    }
    friend constexpr std::ostream& operator << (std::ostream& os, const ModInt &rhs) { 
        return os << rhs.val; 
    }
};

using Z = ModInt<P>;