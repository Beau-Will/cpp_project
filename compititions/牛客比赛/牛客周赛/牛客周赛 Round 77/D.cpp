// Problem: 隐匿社交网络
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/100253/D
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;std::cin >> n;
	
	std::vector<i64> w(n);
	for(int i = 0;i<n;++i){
		std::cin >> w[i];
	}
	
	std::vector<int> cnt(70);
	for(int i = 0;i<n;++i){
		for(int j = 0;j<63;++j){
			if(w[i]&(1LL<<j)){
				++cnt[j];
			}
		}
	}
	int ans = -1,idx = -1;
	for(int i = 0;i<63;++i){
		// ans = std::max(ans,cnt[i]);
		if(cnt[i]>ans){
			ans = cnt[i];
			idx = i;
		}
	}
	// std::cout << ans << '\n';
	i64 max = 0,max_idx = -1;
	for(int i = 0;i<n;++i){
		if((w[i]&(1LL<<idx))&&w[i]>max){
			max = w[i];
			max_idx = max;
		}
	}
	// std::cout << max << '\n';
	int res = 0;
	for(int i = 0;i<n;++i){
		if(w[i]&max){
			++res;
		}
	}
	std::cout << res << '\n';
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