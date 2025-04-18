#include <bits/stdc++.h>

//using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int N = 200005,inf = 1000000000;
constexpr int P1 = 1000000007,P2 = 998244353;
constexpr int P = 131;

void solve(){
	int n;
	std::cin >> n;
	
	std::vector<std::vector<int>> a(n);
	for(int i = 0; i < n; ++i){
		int m = 0;
		std::cin >> m;
		a[i].resize(m);
		for(int j = 0; j < m; ++j){
			std::cin >> a[i][j];
		}
		std::sort(a[i].begin(),a[i].end());
		a[i].erase(std::unique(a[i].begin(),a[i].end()),a[i].end());
	}
	
	int q;
	std::cin >> q;
	while(q--){
		int x,y;
		std::cin >> x >> y;
		--x;
		--y;
		std::vector<int> ans1,ans2;
		std::set_intersection(a[x].begin(),a[x].end(),a[y].begin(),a[y].end(),std::back_inserter(ans1));
		std::set_union(a[x].begin(),a[x].end(),a[y].begin(),a[y].end(),std::back_inserter(ans2));
		
		double ans = 100.0*ans1.size()/ans2.size();
		std::cout << std::fixed << std::setprecision(2) << ans << "%\n";
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
