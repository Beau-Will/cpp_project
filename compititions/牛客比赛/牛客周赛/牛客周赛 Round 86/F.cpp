// Problem: 小苯的线性dp
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/104637/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1'000'000'000;

void solve(){
	int n;
	std::cin >> n;
	
	std::vector<int> a(n+1);
	std::vector<int> pre_max(n+1),pre_min(n+1,inf);
	
	for(int i = 1; i <= n; ++i){
		std::cin >> a[i];
	}
	for(int i = 1; i <= n; ++i){
		pre_max[i] = std::max(pre_max[i-1],a[i]);
		pre_min[i] = std::min(pre_min[i-1],a[i]);
	}
	
	std::vector<std::vector<int>> dp(n+1,std::vector<int>(n+1));

	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= i-1; ++j){
			if(j==0){
				dp[i][j] = pre_max[i]-pre_min[i];
			}else{
				// dp[i][j] =
			}
		}
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