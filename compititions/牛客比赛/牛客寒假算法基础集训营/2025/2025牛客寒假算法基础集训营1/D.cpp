// Problem: 双生双宿之决
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95323/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;std::cin >> n;
	std::vector<int> a(n);
	std::unordered_map<int,int> map;
	for(int i = 0;i<n;++i){
		std::cin >> a[i];
		++map[a[i]];
	}
	if(n&1){
		std::cout << "No\n";
		return;
	}
	if(map.size()!=2){
		std::cout << "No\n";
		return;
	}
	auto [u1,v1] = *map.begin();
	auto [u2,v2] = *(++map.begin());
	std::cout << (v1==v2?"Yes":"No") << '\n';
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