// Problem: C - Game on Permutation
// Contest: Virtual Judge - 25上ACM综合训练(一)
// URL: https://vjudge.net/contest/704285#problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1'000'000'000;

void solve(){
	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	for(int i = 0; i < n; ++i){
		std::cin >> a[i];
	}
	
	int min = a[0],max = inf;
	int ans = 0;
	for(int i = 1; i < n; ++i){
		min = std::min(min,a[i]);
		if(a[i] > min && a[i] < max){
			++ans;
			max = a[i];
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