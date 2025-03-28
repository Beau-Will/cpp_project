// Problem: 小苯的数字消除
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/104637/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;
	std::cin >> n;
	
	std::string s;
	std::cin >> s;
	
	std::vector<char> stk;
	for(int i = 0; i < n; ++i){
		if(stk.size()==0){
			stk.push_back(s[i]);
		}else{
			auto t = stk.back();
			if(t==s[i]){
				stk.pop_back();
				continue;
			}else{
				stk.push_back(s[i]);
			}
		}
	}
	
	std::cout << stk.size()/2 << "\n";
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