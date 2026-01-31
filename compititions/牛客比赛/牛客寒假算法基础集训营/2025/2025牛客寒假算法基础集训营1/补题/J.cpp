// Problem: 硝基甲苯之袭
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95323/J
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;std::cin >> n;
	
	std::vector<int> a(n);
	for(int i = 0;i<n;++i){
		std::cin >> a[i];
	}
	
	std::vector<int> cnt(1e6+5);
	for(int i = 0;i<n;++i){
		++cnt[a[i]];
	}
	
	i64 ans = 0;
	for(int i = 0;i<n;++i){
		for(int j = 1;j<=a[i]/j;++j){
			if(a[i]%j==0){
				int ai = a[i];
				int gcd = j;
				int aj = ai^gcd;
				if(gcd==std::gcd(ai,aj)){
					ans += cnt[aj];
				}
				if(j!=a[i]/j){
					gcd = ai/j;
					aj = ai^gcd;
					if(gcd==std::gcd(ai,aj)){
						ans += cnt[aj];
					}
				}
			}
		}
	}
	
	std::cout << ans/2 << "\n";
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