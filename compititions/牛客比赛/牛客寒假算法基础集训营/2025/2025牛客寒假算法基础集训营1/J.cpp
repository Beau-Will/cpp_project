// Problem: 硝基甲苯之袭
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95323/J
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

std::unordered_map<int,int> cnt;

void solve(){
	int n;std::cin >> n;
	
	std::vector<i64> a(n);
	for(int i = 0;i<n;++i){
		std::cin >> a[i];
	}
	for(int i = 0;i<n;++i){
		++cnt[a[i]];
	}
	
	i64 ans = 0;
	
	for(int z = 1;z<=int(2e5)/2;++z){
		for(int x = z;x<=int(2e5);x+=z){
			int y = x-z;
			if((x^y)==z){
				ans += 1LL*cnt[x]*cnt[y];
			}
		}
	}
	
	std::cout << ans << '\n';
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	// pre();
	
	int t = 1;
	//std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}