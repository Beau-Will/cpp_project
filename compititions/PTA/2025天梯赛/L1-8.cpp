#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1000000000;
constexpr int P = 131,N = 100000;
constexpr int P1 = 1000000007,P2 = 998244353;
constexpr i64 inf2 = 1000000000000000000;

void solve(){
	int n,m,k;
	std::cin >> n >> m >> k;
	
	auto a = std::vector(n+1,std::vector<int>(m+1));
	
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			std::cin >> a[i][j];
		}
	}
	
	auto vis = std::vector(n+1,std::vector<bool>(m+1));
	
	while(k--){
		int max = -inf1,max_x = -1,max_y = -1;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				if(vis[i][j]){
					continue;
				}
				if(a[i][j]>max){
					max = a[i][j];
					max_x = i,max_y = j;
				}
			}
		}
		for(int i = 1; i <= m; ++i){
			vis[max_x][i] = true;
		}
		for(int i = 1; i <= n; ++i){
			vis[i][max_y] = true;
		}
	}
	
	for(int i = 1; i <= n; ++i){
		bool flag = false;
		for(int j = 1; j <= m; ++j){
			if(vis[i][j]){
				continue;
			}
			if(!flag){
				std::cout << a[i][j];
				flag = true;
			}else{
				std::cout << " " << a[i][j];
			}
		}
		if(flag) std::cout << "\n";
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
//	std::cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
