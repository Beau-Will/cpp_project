// Problem: D - Bonfire
// Contest: AtCoder - UNIQUE VISION Programming Contest 2025 Spring (AtCoder Beginner Contest 398)
// URL: https://atcoder.jp/contests/abc398/tasks/abc398_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,r,c;
	std::cin >> n >> r >> c;
	
	std::string s;
	std::cin >> s;
	s = " "+s;
	
	std::vector<std::pair<int,int>> pre(n+1,{0,0});
	std::set<std::pair<int,int>> set;
	
	for(int i = 1; i <= n; ++i){
		pre[i] = pre[i-1];
		if(s[i]=='N'){
			--(pre[i].first);
		}else if(s[i]=='E'){
			++(pre[i].second);
		}else if(s[i]=='W'){
			--(pre[i].second);
		}else{//s[i]=='S'
			++(pre[i].first);
		}
	}
	
	set.insert({0,0});
	
	std::string ans(n,'0');
	for(int i = 1; i <= n; ++i){
		set.insert(pre[i]);
		
		if(set.count({pre[i].first-r,pre[i].second-c})){
			ans[i-1] = '1';
		}
	}
	
	std::cout << ans << "\n";
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