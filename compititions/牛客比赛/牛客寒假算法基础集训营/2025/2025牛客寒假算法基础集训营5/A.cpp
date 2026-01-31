// Problem: 小L的三则运算
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95337/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	i64 x;
	std::string op;
	std::cin >> x >> op;
	if(op=="+"){
		std::cout << x-1 << " " << 1 << "\n";
	}else if(op=="*"){
		std::cout << x << " " << 1 << "\n";
	}else if(op=="-"){
		std::cout << x+1 << " " << 1 << "\n";
	}
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