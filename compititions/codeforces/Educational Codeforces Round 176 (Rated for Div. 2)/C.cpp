// Problem: C. Two Colors
// Contest: Codeforces - Educational Codeforces Round 176 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2075/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,m;std::cin >> n >> m;
	
	std::vector<int> a(m+1);
	for(int i = 1;i<=m;++i){
		std::cin >> a[i];
	}
	
	std::sort(a.begin()+1,a.end());
	
	std::vector<i64> suf(m+2);
	for(int i = m;i>=1;--i){
		suf[i] = suf[i+1]+std::min(a[i],n-1);
	}
	
	i64 ans = 0;
	for(int i = 1;i<=m-1;++i){
		int x = n-a[i];
		int idx1 = std::lower_bound(a.begin()+i+1,a.end(),x)-a.begin();
		//[idx,m]
		ans += 1LL*(m+1-idx1)*std::min(a[i],n-1);
		ans -= 1LL*(m+1-idx1)*(n-1);
		
		ans += 1LL*suf[idx1];
		
		// int idx2 = std::lower_bound(a.begin()+idx1,a.end(),n-1)-a.begin();
	}
	
	ans *= 2;
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