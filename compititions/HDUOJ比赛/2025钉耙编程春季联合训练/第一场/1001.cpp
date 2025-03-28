// Problem: 签到
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/contest/problem?cid=1150&pid=1001
// Memory Limit: 524288 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;std::cin >> n;
	std::string target;std::cin >> target;
	
	std::vector<std::string> v(n);
	bool flag = false;
	for(int i = 0;i<n;++i){
		std::cin >> v[i];
		if(v[i]==target){
			flag = true;
		}
	}
	
	if(!flag){
		std::cout << -1 << "\n";
		return;
	}
	
	for(int i = 0;i<n;++i){
		if(v[i]==target){
			std::cout << i+1 << "\n";
			return;
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