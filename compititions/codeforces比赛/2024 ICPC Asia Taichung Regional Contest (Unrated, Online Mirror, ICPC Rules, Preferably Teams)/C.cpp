// Problem: C. Cube
// Contest: Codeforces - 2024 ICPC Asia Taichung Regional Contest (Unrated, Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/contest/2041/problem/C
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;

int n;
i64 g[15][15][15];
// bool vis[15][15][15];
bool visx[15],visy[15],visz[15];
i64 ans = INF;
i64 dp[15][15][15];
// i64 t;

// void dfs(int u,i64 sum){
	// if(u==n){
		// ans = std::min(ans,sum);
		// return;
	// }
	// if(sum>ans) return;
	// if(sum>t) return;
	// for(int i = 1;i<=n;++i){
		// if(visx[i]) continue;
		// for(int j = 1;j<=n;++j){
			// if(visy[j]) continue;
			// for(int k = 1;k<=n;++k){
				// if(visz[k]) continue;
				// // if(!visx[i]&&!visy[j]&&!visz[k]){
					// visx[i] = true;
					// visy[j] = true;
					// visz[k] = true;
					// dfs(u+1,sum+g[i][j][k]);
					// visx[i] = false;
					// visy[j] = false;
					// visz[k] = false;
				// // }
			// }
		// }
	// }
// }
void solve(){
	std::cin >> n;
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=n;++j){
			for(int k = 1;k<=n;++k){
				std::cin >> g[i][j][k];
			}
		}
	}
	memset(dp,0x3f,sizeof dp);
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=n;++j){
			for(int k = 1;k<=n;++k){
				dp[i][j][k] = std::min(dp[i][j][k],dp[i][j][k-]);
			}
		}
	}
	// for(int i = 1;i<=n;++i) t+=g[i][i][i];
	// dfs(0,0);
	// std::cout << ans << '\n';
	
}
int main(){
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;
  for(int ti = 0;ti<t;++ti) {
      solve();
  }
	
  return 0;
}