// Problem: E - Min of Restricted Sum
// Contest: AtCoder - AtCoder Beginner Contest 396
// URL: https://atcoder.jp/contests/abc396/tasks/abc396_e
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;
using pii= std::pair<int,int>;

void solve(){
	int n,m;
	std::cin >> n >> m;
	
	std::vector<std::vector<pii>> adj(n);
	for(int i = 0; i < m; ++i){
		int u,v,w;
		std::cin >> u >> v >> w;
		--u,--v;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	
	std::vector<bool> vis(n);
	std::vector<int> dsu;
	std::vector<int> dist(n);
	
	auto dfs = [&](auto &&self,int u)->void{
		vis[u] = true;
		dsu.push_back(u);
		for(auto &[v,w]:adj[u]){
			if(vis[v]){
				if(dist[u]!=(dist[v]^w)){
					std::cout << "-1\n";
					exit(0);
				}
				continue;
			}
			dist[v] = dist[u]^w;
			self(self,v);
		}
	};
	
	std::vector<int> ans(n);
	for(int i = 0; i < n; ++i){
		if(vis[i]){
			continue;
		}
		dfs(dfs,i);
		int rt = 0;
		for(int j = 0; j <= 30; ++j){
			int cnt0 = 0,cnt1 = 0;
			for(auto &u:dsu){
				if((dist[u]>>j)&1){
					++cnt1;
				}else{
					++cnt0;
				}
			}
			if(cnt1>cnt0){
				rt |= (1<<j);
			}
		}
		for(auto &u:dsu){
			ans[u] = dist[u]^rt;
		}
		dsu.clear();
	}
	
	for(int i = 0; i < n; ++i){
		std::cout << ans[i] << " \n"[i+1==n];
	}
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