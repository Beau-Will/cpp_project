// Problem: 一气贯通之刃
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95323/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;std::cin >> n;
	
	std::vector<std::vector<int>> adj(n);
	for(int i = 0;i<n-1;++i){
		int u,v;std::cin >> u >> v;
		--u,--v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	
	std::vector<int> ans;
	bool flag = true;
	for(int i = 0;i<n;++i){
		if(adj[i].size()==1){
			ans.emplace_back(i+1);
		}else if(adj[i].size()>2){
			flag = false;
		}
	}
	if(!flag){
		std::cout << "-1\n";
	}else{
		if(ans.size()!=2){
			std::cout << "-1\n";
		}else{
			std::cout << ans.front() << ' ' << ans.back() << '\n';
		}
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