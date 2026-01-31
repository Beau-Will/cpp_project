// Problem: 小红的gcd
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/99990/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int n;std::cin >> n;
	
	std::vector<int> a(n);
	for(int i = 0;i<n;++i){
		std::cin >> a[i];
	}
	
	int gcd = a[0];
	for(int i = 1;i<n;++i){
		gcd = std::__gcd(gcd,a[i]);
	}
	
	std::cout << 1LL*gcd*n << '\n';
	
	return 0;
}