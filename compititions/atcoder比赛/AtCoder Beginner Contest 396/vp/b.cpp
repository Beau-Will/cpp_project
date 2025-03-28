// Problem: B - Card Pile
// Contest: AtCoder - AtCoder Beginner Contest 396
// URL: https://atcoder.jp/contests/abc396/tasks/abc396_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int q;
	std::cin >> q;
	
	std::vector<int> a(100);
	
	while(q--){
		int op;std::cin >> op;
		
		if(op==1){
			int x;
			std::cin >> x;
			a.push_back(x);
		}else{
			std::cout << a.back() << "\n";
			a.pop_back();
		}
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