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
	int n,m;
	std::cin >> n >> m;
	
	auto a = std::vector(n+1,std::vector<int>(m+1));
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			std::cin >> a[i][j];
		}
	}
	
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
//			auto dist = std::vector(n+1,std::vector<int>(m+1,inf1));
//			dist[i][j] = 0;
			i64 sum = 0;
			for(int i2 = 1; i2 <= n; ++i2){
				for(int j2 = 1; j2 <= m; ++j2){
//					dist[i][j] = ;
					sum += std::max(std::abs(i2-i),std::abs(j2-j));
				}
			}
			std::cout << sum*a[i][j] << " \n"[j==m];
		}
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
