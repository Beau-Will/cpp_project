// Problem: 小红走网格
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/100253/C
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int x,y,a,b,c,d;std::cin >> x >> y >> a >> b >> c >> d;
	int gcd_ab = std::__gcd(a,b);
	int gcd_cd = std::__gcd(c,d);
	// std::cout << gcd_ab << ' ' << gcd_cd << '\n';
	if(x%gcd_cd!=0||y%gcd_ab!=0){
		std::cout << "NO\n";
	}else{
		std::cout << "YES\n";
	}
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