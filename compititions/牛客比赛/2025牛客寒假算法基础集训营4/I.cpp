// Problem: Tokitsukaze and Pajama Party
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95336/I
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;std::cin >> n;
	std::string s;std::cin >> s;
	
	s = " "+s;
	
	std::vector<int> pre(n+1);
	for(int i = 1;i<=n;++i){
		pre[i] = pre[i-1]+(s[i]=='u');
	}
	
	
	std::string t = "uwawauwa";
	i64 ans = 0;
	for(int i = 3;i<=n;++i){
		bool flag = true;
		for(int j = 0;j<t.size();++j){
			if(s[i+j]!=t[j]){
				flag = false;
				break;
			}
		}
		if(flag){
			ans += pre[i-2];
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