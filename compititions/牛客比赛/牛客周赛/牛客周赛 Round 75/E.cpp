#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,C,m;std::cin >> n >> C >> m;
	
	std::vector<int> cost(n+1),a(n+1);
	
	for(int i = 1;i<=n;++i){
		std::cin >> cost[i] >> a[i];
	}
	
	std::vector<std::array<int,3>> v(m+1);
	
	for(int i = 1;i<=m;++i){
		std::cin >> v[i][0] >> v[i][1] >> v[i][2];
	}
	
	if(m==0){
		i64 ans = 0;
		std::vector<std::vector<i64>> dp(C+1,std::vector<i64>(5,0));
		
		for(int i = 1;i<=n;++i){
			for(int j = C;j>=cost[i];--j){
				for(int k = 4;k>=1;--k){
					dp[j][k] = std::max(dp[j][k],dp[j-cost[i]][k-1]+a[i]);
				}
			}
		}
		
		for(int i = 0;i<=C;++i){
			for(int j = 0;j<=4;++j){
				ans = std::max(ans,dp[i][j]);
			}
		}
		
		std::cout << ans << '\n';
		return;
	}
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int t = 1;
	// std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}