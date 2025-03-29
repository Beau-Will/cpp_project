// Problem: C - Uniqueness
// Contest: AtCoder - UNIQUE VISION Programming Contest 2025 Spring (AtCoder Beginner Contest 398)
// URL: https://atcoder.jp/contests/abc398/tasks/abc398_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	for(int i = 0; i < n; ++i){
		std::cin >> a[i];
	}
	
	std::map<int,std::vector<int>> adj;
	for(int i = 0; i < n; ++i){
		adj[a[i]].push_back(i+1);
	}
	
	int max = 0,ans = -1;
	for(auto &[u,v]:adj){
		if(v.size()!=1){
			continue;
		}
		if(u>max){
			max = u;
			ans = v.front();
		}
	}
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