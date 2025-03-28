// Problem: Tokitsukaze and XOR-Triangle
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95336/L
// Memory Limit: 1024 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;
// constexpr int N = 3e5+5,P = 1e9+7;

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
    constexpr MLong &operator*=(MLong rhs) & {
        x = mul(x, rhs.x, getMod());
        return *this;
    }
    constexpr MLong &operator+=(MLong rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MLong &operator-=(MLong rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MLong &operator/=(MLong rhs) & {
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
    friend constexpr std::istream &operator>>(std::istream &is, MLong &a) {
        i64 v;
        is >> v;
        a = MLong(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MLong &a) {
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
 
template<int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{norm(x % getMod())} {}
     
    static int Mod;
    constexpr static int getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    constexpr static void setMod(int Mod_) {
        Mod = Mod_;
    }
    constexpr int norm(int x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr int val() const {
        return x;
    }
    explicit constexpr operator int() const {
        return x;
    }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MInt &operator*=(MInt rhs) & {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) & {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};
 
template<>
int MInt<0>::Mod = 998244353;
 
template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();
 
constexpr int P = 1000000007;
using Z = MInt<P>;


void solve(){
	int n,q;std::cin >> n >> q;
	
	std::vector<int> a(n+1),b(n+1);
	for(int i = 1;i<=n;++i){
		std::cin >> a[i];
	}
	for(int i = 1;i<=n;++i){
		std::cin >> b[i];
	}
	std::vector<std::vector<std::array<Z,2>>> prea(n+1,std::vector<std::array<Z,2>>(32,std::array<Z,2> {}));
	std::vector<std::vector<std::array<Z,2>>> preb(n+1,std::vector<std::array<Z,2>>(32,std::array<Z,2> {}));
	
	for(int j = 0;j<=30;++j){
		prea[0][j][0]=prea[0][j][1]=0;
		preb[0][j][0]=preb[0][j][1]=0;
	}
	
	for(int i = 1;i<=n;++i){
		for(int j = 0;j<=30;++j){
			if(a[i]&(1<<j)){
				prea[i][j][1] = prea[i-1][j][1]+1;
				prea[i][j][0] = prea[i-1][j][0];
			}else{
				prea[i][j][1] = prea[i-1][j][1];
				prea[i][j][0] = prea[i-1][j][0]+1;
			}
		}
	}
	for(int i = 1;i<=n;++i){
		for(int j = 0;j<=30;++j){
			if(b[i]&(1<<j)){
				preb[i][j][1] = preb[i-1][j][1]+1;
				preb[i][j][0] = preb[i-1][j][0];
			}else{
				preb[i][j][1] = preb[i-1][j][1];
				preb[i][j][0] = preb[i-1][j][0]+1;
			}
		}
	}
	
	std::vector<Z> x(n+1);
	for(int i = 1;i<=n;++i){//[1,i-1]
		for(int j = 0;j<=30;++j){
			if(a[i]&(1<<j)){
				x[i] += preb[i-1][j][0]*(1LL<<j);
			}else{
				x[i] += preb[i-1][j][1]*(1LL<<j);
			}
		}
	}
	std::vector<Z> preans(n+1);
	for(int i = 1;i<=n;++i){
		preans[i] = preans[i-1]+x[i];
	}
	
	while(q--){
		int l,r;std::cin >> l >> r;
		
		std::vector<std::array<Z,2>> ta(32,std::array<Z,2> {}),tb(32,std::array<Z,2> {});
		
		for(int j = 0;j<=30;++j){
			ta[j][0] = prea[r][j][0]-prea[l-1][j][0];
			ta[j][1] = prea[r][j][1]-prea[l-1][j][1];
		}
		for(int j = 0;j<=30;++j){
			tb[j][0] = preb[r][j][0];
			tb[j][1] = preb[r][j][1];
		}

		Z ans = 0;
		for(int j = 0;j<=30;++j){
			ans += ta[j][0]*tb[j][1]*(1LL<<j);
			ans += ta[j][1]*tb[j][0]*(1LL<<j);
		}
		ans -= preans[r]-preans[l-1];
		std::cout << ans << "\n";
	}
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int t = 1;
	std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}