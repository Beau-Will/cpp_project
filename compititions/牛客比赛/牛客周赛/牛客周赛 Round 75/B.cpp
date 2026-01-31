#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	std::string s;
	std::cin >> s;
	std::unordered_map<char,int> map1,map2;
	int max1 = 0,max2 = 0;
	for(int i = 0;i<s.size()/2;++i){
		++map1[s[i]];
	}
	for(int i = s.size()/2;i<s.size();++i){
		++map2[s[i]];
	}
	for(const auto &[u,v]:map1){
		max1 = std::max(max1,v);
	}
	for(const auto &[u,v]:map2){
		max2 = std::max(max2,v);
	}
	std::cout << (s.size()/2-max1)+(s.size()/2-max2) << '\n';
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int t = 1;
	// std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}