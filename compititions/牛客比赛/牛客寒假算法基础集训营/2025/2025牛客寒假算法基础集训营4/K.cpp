// Problem: Tokitsukaze and Shawarma
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95336/K
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int x,y,z,a,b,c;
	std::cin >> x >> y >> z >> a >> b >> c;
	std::cout << std::max({x*a,y*b,z*c}) << "\n";
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