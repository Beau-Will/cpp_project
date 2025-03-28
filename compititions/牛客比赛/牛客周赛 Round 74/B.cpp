// Problem: 球格模型（简单版）
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/99458/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define push_back emplace_back
#define push emplace
#define all(v) v.begin(),v.end()

/*
n>=m
1 0 0
0 1 0
0 0 1
1 0 0
1 0 0 

n<m
1 0 0 1 1
0 1 0 0 0
0 0 1 0 0
*/
void solve(){
	int n,m,k;std::cin >> n >> m >> k;
	std::vector<std::vector<int>> ans(n+1,std::vector<int>(m+1));
	int cnt = k;
	if(n>=m){
		if(k<n){
			std::cout << -1 << '\n';
			return;
		}
		for(int i = 1;i<=n;++i){
			for(int j = 1;j<=m;++j){
				if(i==j){
					ans[i][j] = 1;
					--cnt;
				}
				else{
					if(i>m&&j==1){
						ans[i][j] = 1;
						--cnt;
					}else{
						ans[i][j] = 0;
					}
				}
			}
		}
	}else{
		if(k<m){
			std::cout << -1 << '\n';
			return;
		}
		for(int i = 1;i<=n;++i){
			for(int j = 1;j<=m;++j){
				if(i==j){
					ans[i][j] = 1;
					--cnt;
				}
				else{
					if(j>n&&i==1){
						ans[i][j] = 1;
						--cnt;
					}else{
						ans[i][j] = 0;
					}
				}
			}
		}
	}
	if(cnt){
		ans[n][m] += cnt;
	}
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			std::cout << ans[i][j] << " \n"[j==m];
		}
	}
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