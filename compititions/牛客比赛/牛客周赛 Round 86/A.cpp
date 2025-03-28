// Problem: 小苯跑外卖
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/104637/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int x,y;
	std::cin >> x >> y;
	std::cout << (y+x-1)/x << "\n";
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int t = 1;
	//std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}