#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

void solve(){
	
	int n,q;
	std::cin >> n >> q;
	
	std::vector<int> a(n+1);
	for(int i = 1;i<=n;++i){
		std::cin >> a[i];
	}
	
	std::vector<int> d(n);
	
	for(int i = 1;i<=n-1;++i){
		d[i] = std::abs(a[i+1]-a[i]);
	}
	
	std::vector<std::vector<int>> st(n+1,std::vector<int>(std::floor(std::log2(n))+1,0));
	
	for(int i = 1;i<=n-1;++i){
		st[i][0] = d[i];
	}
	
	for(int j = 1;(1<<j)<=n-1;++j){
		for(int i = 1;i+((1<<j)-1)<=n-1;++i){
			st[i][j] = std::__gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	
	while(q--){
		int l,r;std::cin >> l >> r;
		--r;
		if(r<l){
			std::cout << 0 << " \n"[q==0];
			continue;
		}
		int k = std::floor(std::log2(r-l+1));
		int gcd = std::__gcd(st[l][k],st[r-(1<<k)+1][k]);
		std::cout << gcd << " \n"[q==0];
	}
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int tt = 1;
	std::cin >> tt;
	for(int ti = 0;ti<tt;++ti){
		solve();
	}
	
	return 0;
}