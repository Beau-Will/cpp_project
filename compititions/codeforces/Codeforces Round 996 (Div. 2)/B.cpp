// Problem: B. Crafting
// Contest: Codeforces - Codeforces Round 996 (Div. 2)
// URL: https://codeforces.com/contest/2055/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;std::cin >> n;
	
	constexpr int INF = 0x3f3f3f3f;
	
	struct Node{
		int a,b;
	};
	
	std::vector<Node> v(n);
	for(int i = 0;i<n;++i){
		std::cin >> v[i].a;
	}
	for(int i = 0;i<n;++i){
		std::cin >> v[i].b;
	}
	
	int sum = 0,cnt = 0,min_diff = INF;
	
	for(int i = 0;i<n;++i){
		int t = v[i].a-v[i].b;
		if(t>=0){
			min_diff = std::min(min_diff,t);
		}else{
			++cnt;
			sum = -t;
		}
	}
	
	if(cnt>1){
		std::cout << "NO\n";
		return;
	}
	
	std::cout << (min_diff>=sum?"YES\n":"NO\n");
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