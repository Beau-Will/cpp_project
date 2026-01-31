// Problem: 复制鸡
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95338/A
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
	
	int ans = 0,cur = -1;
	for(int i = 0;i<n;++i){
		if(a[i]!=cur){
			++ans;
			cur = a[i];
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