// Problem: C. Trip to the Olympiad
// Contest: Codeforces - Hello 2025
// URL: https://codeforces.com/contest/2057/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int tt = 1;
	std::cin >> tt;
	for(int ti = 0;ti<tt;++ti){
		int l,r;std::cin >> l >> r;
		
		std::vector<int> a = {l,l+1,l+2,r-2,r-1,r};
		for(int i = l+3;i<=std::min(r,l+64);++i){
			a.emplace_back(i);
		}
		for(int i = r-3;i>=std::max(r-64,l);--i){
			a.emplace_back(i);
		}
		
		std::sort(a.begin(),a.end());
		a.erase(std::unique(a.begin(),a.end()),a.end());
		
		int ans = -1;
		int t1,t2,t3;
		for(int i = 0;i<a.size();++i){
			for(int j = i+1;j<a.size();++j){
				for(int k = j+1;k<a.size();++k){
					int x = a[i],y = a[j],z = a[k];
					int t = (x^y)+(x^z)+(y^z);
					if(t>ans){
						ans = t;
						t1 = x,t2 = y,t3 = z;
					}
				}
			}
		}
		// std::cout << t1 << ' ' << t2 << ' ' << t3 << '\n';
		std::cout << ans << '\n';
	}
	
	
	return 0;
}