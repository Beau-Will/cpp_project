// Problem: D - Minimum XOR Path
// Contest: AtCoder - AtCoder Beginner Contest 396
// URL: https://atcoder.jp/contests/abc396/tasks/abc396_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;
using pii = std::pair<int,i64>;

constexpr i64 inf = 9e18;

void solve(){
	int n,m;
	std::cin >> n >> m;
	
	std::vector<std::vector<pii>> adj(n);
	
	for(int i = 0; i < m; ++i){
		int u,v;i64 w;
		std::cin >> u >> v >> w;
		--u,--v;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	
	i64 ans = inf;
	std::vector<bool> vis(n);
	auto dfs = [&](auto &&self,int u,i64 sum)->void{
		if(u==n-1){
			ans = std::min(ans,sum);
			return;
		}
		for(auto &[v,w]:adj[u]){
			if(vis[v]){
				continue;
			}
			vis[v] = true;
			self(self,v,sum^w);
			vis[v] = false;
		}
	};
	
	vis[0] = true;
	dfs(dfs,0,0LL);
	
	std::cout << ans << "\n";
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int t = 1;
	//std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}