// Problem: B - Koxia and Whiteboards
// Contest: Virtual Judge - 25上ACM综合训练(一)
// URL: https://vjudge.net/contest/704285#problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1'000'000'000;

void solve(){
	int n,m;
	std::cin >> n >> m;
	
	std::vector<int> a(n+1),b(m+1);
	for(int i = 1; i <= n; ++i){
		std::cin >> a[i];
	}
	for(int i = 1; i <= m; ++i){
		std::cin >> b[i];
	}
	
	for(int i = 1; i <= m; ++i){
		int min = inf+1,minidx = 1;
		for(int j = 1; j <= n; ++j){
			if(a[j] < min){
				min = a[j];
				minidx = j;
			}
		}
		a[minidx] = b[i];
	}
	
	std::cout << std::accumulate(a.begin()+1,a.end(),0LL) << "\n";
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