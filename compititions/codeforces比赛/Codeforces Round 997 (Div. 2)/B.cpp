// Problem: B. Find the Permutation
// Contest: Codeforces - Codeforces Round 997 (Div. 2)
// URL: https://codeforces.com/contest/2056/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;std::cin >> n;
	
	std::vector<std::vector<char>> g(n+1,std::vector<char>(n+1));
	std::vector<bool> vis(n+1);
	std::vector<int> ans;
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=n;++j){
			std::cin >> g[i][j];
		}
	}
	
	for(int i = 1;i<=n;++i){
		for(int j = n;j>=1;--j){
			if(g[i][j]=='1'){
				if(!vis[j]){
					vis[j] = true;
					ans.emplace_back(j);
				}
			}
		}
		if(!vis[i]){
			vis[i] = true;
			ans.emplace_back(i);
		}
	}
	
	std::reverse(ans.begin(),ans.end());
	
	for(int i = 0;i<ans.size();++i){
		std::cout << ans[i] << " \n"[i+1==ans.size()];
	}
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int t = 1;
	std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}