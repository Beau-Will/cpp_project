// Problem: 小苯的Polygon
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/104637/E
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
	for(int i = 1; i <= n; ++i){
		std::cin >> a[i];
	}
	
	std::sort(a.begin()+1,a.end());
	
	int max = a.back();
	std::vector<int> dp(max*n+1);
	int ans = inf;
	
	dp[0] = 1;
	for(int i = 1; i <= n; ++i){
		for(int j = a[i]+1; j <= max*n; ++j){
			if(dp[j]){
				ans = std::min(ans,j+a[i]);
			}
		}
		for(int j = max*n; j >= a[i]; --j){
			dp[j] += dp[j-a[i]];
		}
	}
	
	std::cout << (ans==inf?-1:ans) << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
	std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}