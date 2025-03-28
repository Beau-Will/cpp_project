// Problem: E - Path Decomposition of a Tree
// Contest: AtCoder - OMRON Corporation Programming Contest 2025 (AtCoder Beginner Contest 397)
// URL: https://atcoder.jp/contests/abc397/tasks/abc397_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,k;std::cin >> n >> k;
	
	std::vector<std::vector<int>> adj(n*k);
	for(int i = 0;i<n*k-1;++i){
		int u,v;std::cin >> u >> v;
		--u,--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	std::vector<int> siz(n*k);
	
	auto dfs = [&](auto &&self,int u,int fa)->void{
		siz[u] = 1;
		int son = 0;
		for(auto &v:adj[u]){
			if(v==fa){
				continue;
			}
			self(self,v,u);
			if(siz[v]){
				++son;
				siz[u] += siz[v];
			}
		}
		if(siz[u]<k){
			if(u==0||son>1){
				std::cout << "No\n";
				exit(0);
			}
		}else if(siz[u]==k){
			if(son>2){
				std::cout << "No\n";
				exit(0);
			}else{
				siz[u] = 0;
			}
		}else{
			std::cout << "No\n";
			exit(0);
		}
	};
	
	dfs(dfs,0,-1);
	
	std::cout << "Yes\n";
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