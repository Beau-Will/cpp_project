#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	std::string s;
	std::cin >> s;
	
	std::string ans;
	for(int i = 0; i < s.size(); ++i){
		if(s[i]>='0'&&s[i]<='9'){
			ans += s[i];
		}
	}
	
	bool flag = true;
	for(int i = 0; i < ans.size(); ++i){
		if(flag&&ans[i]=='0'){
			continue;
		}else{
			flag = false;
		}
		std::cout << ans[i];
	}
	
	std::cout << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
	// std::cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}