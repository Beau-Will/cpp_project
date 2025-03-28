#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;

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

constexpr int mod = 1000000007;

int n,m;
std::vector<Z> a(N);

template<class T>
constexpr T inv(T a) {
    return power(a,mod-2);
}

struct Node{
	int l,r;
	Z sum,mul;
	Z lazy;
}tr[N<<2];

void pushup(int u){
	tr[u].mul = tr[u<<1].mul*tr[u<<1|1].mul;
	tr[u].sum = tr[u<<1].sum+tr[u<<1].mul*tr[u<<1|1].sum;
}

void pushdown(int u){
	if(tr[u].lazy!=mod){
		int len1 = tr[u<<1].r-tr[u<<1].l+1;
		tr[u<<1].lazy = tr[u].lazy;
		tr[u<<1].mul = power(tr[u].lazy,len1);
		if(tr[u].lazy!=1){
			tr[u<<1].sum = (1-power(tr[u].lazy,len1))*tr[u].lazy*inv(1-tr[u].lazy);
		}else{
			tr[u<<1].sum = len1;
		}
		int len2 = tr[u<<1|1].r-tr[u<<1|1].l+1;
		tr[u<<1|1].lazy = tr[u].lazy;
		tr[u<<1|1].mul = power(tr[u].lazy,len2);
		if(tr[u].lazy!=1){
			tr[u<<1|1].sum = (1-power(tr[u].lazy,len2))*tr[u].lazy*inv(1-tr[u].lazy);
		}else{
			tr[u<<1|1].sum = len2;
		}
		tr[u].lazy = mod;
	}
}

void build(int u,int l,int r){
	if(l==r){
		tr[u] = Node{l,r,a[l],a[l],mod};
		return;
	}
	tr[u] = Node{l,r,0,0,mod};
	int mid = l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}

void modify(int u,int l,int r,int x){
	if(tr[u].l>=l&&tr[u].r<=r){
		int len = tr[u].r-tr[u].l+1;
		tr[u].lazy = x;
		tr[u].mul = power(x,len);
		if(tr[u].lazy!=1){
			tr[u].sum = (1-power(tr[u].lazy,len))*tr[u].lazy*inv(1-tr[u].lazy);
		}else{
			tr[u].sum = len;
		}
	}else{
		pushdown(u);
		int mid = tr[u].l+tr[u].r>>1;
		if(l<=mid) modify(u<<1,l,r,x);
		if(r>mid) modify(u<<1|1,l,r,x);
		pushup(u);
	}
}

Node query(int u,int l,int r){
	if(tr[u].l>=l&&tr[u].r<=r){
		return tr[u];
	}
	pushdown(u);
	int mid = tr[u].l+tr[u].r>>1;
	Node ans=Node{l,r,0,1,0};
	if(l<=mid){
		Node tmp = query(u<<1,l,r);
		ans.mul *= tmp.mul;
		ans.sum = tmp.sum;
	}
	if(r>mid){
		Node tmp = query(u<<1|1,l,r);
		ans.sum += ans.mul*tmp.sum;
		ans.mul*=tmp.mul;
	}
	return ans;
}

void solve(){
	std::cin >> n >> m;
	for(int i = 1;i<=n;++i) std::cin >> a[i];
	build(1,1,n);
	while(m--){
		int op,l,r,x;
		std::cin >> op >> l >> r;
		if(op==1){
			std::cin >> x;
			modify(1,l,r,x);
		}else{//op==2
			auto ans = query(1,l,r);
			std::cout << ans.sum << '\n';
		}
	}
	// std::cout << inv(Z(1-2)) << '\n';
}
int main(){
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;
  for(int ti = 0;ti<t;++ti) {
      solve();
  }
	
  return 0;
}