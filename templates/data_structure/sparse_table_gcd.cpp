#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace
//ST表实现求解区间gcd

void solve(){
	int n,m;std::cin >> n >> m;
	
	std::vector<int> a(n);
	
	for(int i = 0;i<n;++i){
		std::cin >> a[i];
	}
	std::vector<std::vector<int>> st(n+1,std::vector<int>(std::floor(std::log2(n))+1,0));
	
	for(int i = 0;i<n;++i){
		st[i][0] = a[i];
	}
	
	for(int j = 1;(1<<j)<=n;++j){
		for(int i = 0;i+(1<<j)-1<=n;++i){
			st[i][j] = std::__gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	
	while(m--){
		int l,r;std::cin >> l >> r;
		--l,--r;
		int k = std::floor(std::log2(r-l+1));
		std::cout << std::gcd(st[l][k],st[r-(1<<k)+1][k]) << '\n';
	}
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int tt = 1;
	// std::cin >> tt;
	for(int ti = 0;ti<tt;++ti){
		solve();
	}
	
	return 0;
}