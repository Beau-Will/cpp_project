// Problem: 学 DP 导致的
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/contest/problem?cid=1151&pid=1004
// Memory Limit: 65536 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	std::string s,k;std::cin >> s >> k;

	std::string t;
	if(k.size()>2){
		for(int i = 0;i<26;++i){
			t += s;
		}
	}else{
		int k1 = std::stoi(k);
		for(int i = 0;i<std::min(k1,26);++i){
			t += s;
		}
	}
	
	// std::cout << t << "\n";
	
	int ans = 0;
	std::vector<int> dp(t.size()+5);
	
	for(int i = 0;i<t.size();++i){
		dp[i] = 1;
		for(int j = 0;j<i;++j){
			if(t[j]<t[i]){
				dp[i] = std::max(dp[i],dp[j]+1);
			}
		}
	}
	
	for(int i = 0;i<t.size();++i){
		ans = std::max(ans,dp[i]);
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