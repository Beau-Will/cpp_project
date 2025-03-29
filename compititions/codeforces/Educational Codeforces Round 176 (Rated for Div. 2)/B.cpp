// Problem: B. Array Recoloring
// Contest: Codeforces - Educational Codeforces Round 176 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2075/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,k;std::cin >> n >> k;
	
	std::vector<int> a(n);
	for(int i = 0;i<n;++i){
		std::cin >> a[i];
	}
	
	i64 ans = 0;
	
	if(k==1){
		ans = std::max(ans,1LL*a.front()+a.back());
		// std::cout << "ans1:" << ans << "\n";
		int max = 0,maxidx = -1;
		for(int i = 0;i<n;++i){
			if(a[i]>max){
				max = a[i];
				maxidx = i;
			}
		}
		if(maxidx!=0) ans = std::max(ans,1LL*max+a.front());
		else{
			int max2 = 0;
			for(int i = 1;i<n;++i){
				max2 = std::max(max2,a[i]);
			}
			ans = std::max(ans,1LL*max+max2);
		}
		if(maxidx!=n-1) ans = std::max(ans,1LL*max+a.back());
		else{
			int max2 = 0;
			for(int i = 0;i<n-1;++i){
				max2 = std::max(max2,a[i]);
			}
			ans = std::max(ans,1LL*max+max2);
		}
	}else{
		std::sort(a.begin(),a.end(),std::greater<int>());
		for(int i = 0;i<k+1;++i){
			ans += a[i];
		}
	}
	
	std::cout << ans << "\n";
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