// Problem: 最大最小路
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/99458/F
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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
	int n,a,b;std::cin >> n >> a >> b;
	
	std::vector<int> w(n);
	for(int i = 0;i<n;++i){
		std::cin >> w[i];
	}
	
	std::vector<std::vector<int>> adj(n);
	
	for(int i = 0;i<n-1;++i){
		int u,v;std::cin >> u >> v;
		--u,--v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	
	i64 ans = 0;
	
	auto dfs = [&](auto &&self,int u,int fa,int max)->void{
		max = std::max(max,w[u]);
		if(max>=b){
			++ans;
		}
		for(const auto v:adj[u]){
			if(v!=fa){
				self(self,v,u,max);
			}
		}
	};
	
	for(int i = 0;i<n;++i){
		if(w[i]<=a){
			dfs(dfs,i,-1,0);
		}
	}
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