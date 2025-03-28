#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 3e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

int n,m;
i64 g[N][15];
i64 dp[N];
int per[15];
i64 ans = 0,ans_i=1,ans_j=1;

void dfs(int i,int j,int u){
	if(u==m+1){
		i64 sum1 = INF,sum2 = INF;
		for(int k = 1;k<=m;++k){
			if(per[k]){
				sum2 = std::min(sum2,g[j][k]);
			}else{
				sum1 = std::min(sum1,g[i][k]);
			}
		}
		i64 t = std::min(sum1,sum2);
		if(t>ans){
			ans = t;
			ans_i = i,ans_j = j;
		}
		return;
	}
	per[u] = 0;
	dfs(i,j,u+1);
	per[u] = 1;
	dfs(i,j,u+1);
}

void solve(){

	std::cin >> n >> m;
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			std::cin >> g[i][j];
		}
	}
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=n;++j){
			dfs(i,j,1);
		}
	}
	std::cout << ans_i << ' ' << ans_j << '\n';
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int tt = 1;
	// std::cin >> tt;
	for(int ti = 0;ti<tt;++ti){
		solve();
	}
	
	return 0;
}