// Problem: 密码
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/contest/problem?cid=1150&pid=1006
// Memory Limit: 524288 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;std::cin >> n;
	
	std::vector<int> a(n),b(n),c(n);
	for(int i = 0;i<n;++i){
		std::cin >> a[i] >> b[i] >> c[i];
	}
	
	std::vector<std::set<int>> v(n);
	for(int i = 0;i<n;++i){
		if((c[i]-b[i])%a[i]==0){
			int t = (c[i]-b[i])/a[i];
			if(t>=0) v[i].insert(t);
		}
		if((c[i]-a[i])%b[i]==0){
			int t = (c[i]-a[i])/b[i];
			if(t>=0) v[i].insert(t);
		}
		if((b[i]-a[i])%c[i]==0){
			int t = (b[i]-a[i])/c[i];
			if(t>=0) v[i].insert(t);
		}
		if((b[i]-c[i])%a[i]==0){
			int t = (b[i]-c[i])/a[i];
			if(t>=0) v[i].insert(t);
		}
		if((a[i]-b[i])%c[i]==0){
			int t = (a[i]-b[i])/c[i];
			if(t>=0)v[i].insert(t);
		}
		if((a[i]-c[i])%b[i]==0){
			int t = (a[i]-c[i])/b[i];
			if(t>=0) v[i].insert(t);
		}
	}
	
	int ans = -1;
	for(const auto &x:v[0]){
		bool flag = true;
		for(int i = 1;i<n;++i){
			if(v[i].count(x)==0){
				flag = false;
				break;
			}
		}
		if(flag){
			ans = x;
			break;
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