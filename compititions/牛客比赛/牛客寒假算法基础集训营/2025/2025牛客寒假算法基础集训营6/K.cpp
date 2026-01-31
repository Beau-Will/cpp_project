// Problem: 鸡翻题
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95338/K
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int x,y;std::cin >> x >> y;
	if(y%2==0){
		std::cout << "NO\n";
		return;
	}
	if(y==1){
		std::cout << (x&1?"NO\n":"YES\n");
		return;
	}
	int t = y/2;
	if(std::abs(t-x)%2==0){
		std::cout << "YES\n";
	}else{
		std::cout << "NO\n";
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