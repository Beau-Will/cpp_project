// Problem: G - Flip Row or Col
// Contest: AtCoder - AtCoder Beginner Contest 396
// URL: https://atcoder.jp/contests/abc396/tasks/abc396_g
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1'000'000'000;

void solve(){
	int n,m;
	std::cin >> n >> m;
	
	std::vector<std::string> g(n);
	for(int i = 0; i < n; ++i){
		std::cin >> g[i];
	}
	
	std::vector<int> a(n);
	for(int i = 0; i < n; ++i){
		int t = 0;
		for(int j = 0; j < m; ++j){
			if(g[i][m-1-j]=='1'){
				t |= 1<<j;
			}
		}
		a[i] = t;
	}
	
	std::vector<std::vector<int>> dp(1<<m,std::vector<int>(m+1));
	
	for(int i = 0; i < n; ++i){
		++dp[a[i]][0];
	}
	
	for(int i = 0; i < m; ++i){
		for(int j = m; j > 0; --j){
			for(int k = 0; k < (1<<m); ++k){
				dp[k^(1<<i)][j] += dp[k][j-1];
			}
		}
	}
	
	int ans = inf;
	for(int i = 0; i < (1<<m); ++i){
		int res = 0;
		
		for(int j = 0; j <= m; ++j){
			res += dp[i][j] * std::min(j,m-j);
		}

		ans = std::min(ans,res);
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