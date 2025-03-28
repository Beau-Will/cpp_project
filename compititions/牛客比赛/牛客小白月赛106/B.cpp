// Problem: 末日DISCO
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/97439/B
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
#define all(v) v.begin(),v.end()
#define push emplace


/*
1 2 3 4
1 5 6 7
2 5 8 9
3 6 8 10
*/

// std::vector<int> cnt(10005,0);
std::vector<std::vector<int>> ans(505);
void solve(){
	int n;std::cin >> n;
	int cur = 1;
	for(int i = 1;i<=n;++i){
		int d = i-2;
		if(d>=0){
			// for(int k = 1;k<=i-1;++k){
				// std::cout << "ans[k][d]:" << ans[k][d] << '\n';
			// }
			for(int k = 1;k<=i-1;++k){
				ans[i].pb(ans[k][d]);
			}
		}
		// std::cout << "ans[i].size():" << ans[i].size() << '\n';
		int size = ans[i].size();
		for(int j = 1;j<=n-size;++j){
			ans[i].pb(cur);
			// std::cout << "cur:" << cur << '\n';
			++cur;
		}
		// std::cout << "******\n";
		// for(int j = 1;j<=n;++j){
			// std::cout << ans[i][j] << " \n"[j==n];
		// }
	}
	for(int i = 1;i<=n;++i){
		for(int j = 0;j<ans[i].size();++j){
			std::cout << ans[i][j] << " \n"[j==ans[i].size()-1];
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