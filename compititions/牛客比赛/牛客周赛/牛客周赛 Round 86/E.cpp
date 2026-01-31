// Problem: 小苯的Polygon
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/104637/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1'000'000'000;

void solve(){
	int n;
	std::cin >> n;
	
	std::vector<int> a(n+1);
	for(int i = 1; i <= n; ++i){
		std::cin >> a[i];
	}
	
	std::sort(a.begin()+1,a.end());
	
	std::vector<int> pre(n+1);
	
	for(int i = 1; i <= n; ++i){
		pre[i] = pre[i-1]+a[i];
	}
	
	if(a.back()*2>=pre[n]){
		std::cout << "-1\n";
		return;
	}
	
	int ans = inf;
	//1 2 3 4
	for(int i = 3; i <= n; ++i){
		//最长边a[i]
		//[1,i-1]选取至少两个数，使得这些数之和严格大于a[i]
		if(pre[i-1]<=a[i]){
			continue;
		}
		ans = std::min(ans,pre[i]);
		for(int j = 2; j <= i-1; ++j){
			
		}
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