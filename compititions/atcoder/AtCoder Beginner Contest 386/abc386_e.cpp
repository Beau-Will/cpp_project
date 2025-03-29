// Problem: E -  Maximize XOR
// Contest: AtCoder - AtCoder Beginner Contest 386
// URL: https://atcoder.jp/contests/abc386/tasks/abc386_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define push_back emplace_back
#define push emplace
#define all(v) v.begin(),v.end()

void solve(){
	int n,k;std::cin >> n >> k;
	std::vector<i64> a(n);
	for(int i = 0;i<n;++i){
		std::cin >> a[i];
	}
	std::vector<i64> suf(n+1);
	for(int i = n-1;i>=0;--i){
		suf[i] = suf[i+1]^a[i];
	}
	i64 ans = 0;
	auto dfs = [&](auto &&dfs,int i,int k,i64 sum){
		if(k==0){
			ans = std::max(ans,sum);
			return;
		}
		if(i+k==n){
			ans = std::max(ans,sum^suf[i]);
			return;
		}
		dfs(dfs,i+1,k,sum);
		dfs(dfs,i+1,k-1,sum^a[i]);
	};
	dfs(dfs,0,k,0LL);
	std::cout << ans << '\n';
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