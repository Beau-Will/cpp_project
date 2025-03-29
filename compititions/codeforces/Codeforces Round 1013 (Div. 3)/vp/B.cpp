// Problem: B. Team Training
// Contest: Codeforces - Codeforces Round 1013 (Div. 3)
// URL: https://codeforces.com/contest/2091/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,x;
	std::cin >> n >> x;
	
	std::vector<int> a(n);
	for(int i = 0; i < n; ++i){
		std::cin >> a[i];
	}
	
	std::sort(a.rbegin(),a.rend());
	
	int sum = 0,base = a[0],cnt = 0,ans = 0;
	for(int i = 0; i < n; ++i){
		++cnt;
		base = a[i];
		sum = base*cnt;
		if(sum>=x){
			++ans;
			cnt = 0;
		}
	}
	
	std::cout << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
	std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}