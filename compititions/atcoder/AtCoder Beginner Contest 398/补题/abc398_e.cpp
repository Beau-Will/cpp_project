// Problem: E - Tree Game
// Contest: AtCoder - UNIQUE VISION Programming Contest 2025 Spring (AtCoder Beginner Contest 398)
// URL: https://atcoder.jp/contests/abc398/tasks/abc398_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;
	std::cin >> n;
	
	std::vector adj(n+1,std::vector<int>(n+1));
	for(int i = 1; i < n; ++i){
		int u,v;
		std::cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	
	std::vector<int> col(n+1);
	auto dfs = [&](auto &&self,int u,int fa)->void{
		for(int v = 1; v <= n; ++v){
			if(v==fa||!adj[u][v]){
				continue;
			}
			col[v] = col[u]^1;
			self(self,v,u);
		}
	};
	
	dfs(dfs,1,0);
	
	std::set<std::pair<int,int>> set;
	for(int i = 1; i <= n; ++i){
		for(int j = i+1; j <= n; ++j){
			if(!adj[i][j]&&col[i]!=col[j]){
				set.insert({i,j});
			}
		}
	}
	
	std::cout << ((set.size()&1)?"First":"Second") << std::endl;
	
	while(true){
		if(set.size()&1){
			std::cout << set.begin()->first << " " << set.begin()->second << std::endl;
			set.erase(set.begin());
		}else{
			int u,v;
			std::cin >> u >> v;
			if(u==-1&&v==-1){
				break;
			}
			set.erase({u,v});
		}
	}
}

int main(){
	// std::cin.tie(nullptr)->sync_with_stdio(false);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
	//std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}