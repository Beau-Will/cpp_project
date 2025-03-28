// Problem: 学博弈论导致的
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/contest/problem?cid=1151&pid=1006
// Memory Limit: 65536 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int r,b,m;std::cin >> r >> b >> m;
	if((r%4==0)&&(b%2==0)){
		std::cout << "Bob\n";
		return;
	}
	if((r%4==2)&&(b%2==1)){
		std::cout << "Bob\n";
		return;
	}
	std::cout << "Alice\n";
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