// Problem: B - Ticket Gate Log
// Contest: AtCoder - OMRON Corporation Programming Contest 2025 (AtCoder Beginner Contest 397)
// URL: https://atcoder.jp/contests/abc397/tasks/abc397_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	std::string s;std::cin >> s;
	
	int ans = 0;
	for(int i = 0;i<s.size()-1;++i){
		if(s[i]==s[i+1]){
			++ans;
		}
	}
	if(s.front()!='i'){
		++ans;
	}
	if(s.back()!='o'){
		++ans;
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