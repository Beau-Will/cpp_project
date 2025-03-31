#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	std::string s;
	std::cin >> s;
	
	std::set<std::string> set;
	for(int i = 0; i < s.size(); ++i){
		for(int j = 1; j <= s.size()-i; ++j){
			if(s[i]>='A'&&s[i]<='Z'){
				set.insert(s.substr(i,j));
			}else{
				bool flag = false;
				for(int k = i; k <= i+j-1; ++k){
					if(s[k]>='A'&&s[k]<='Z'){ 
						flag = true;
					}
				}
				if(!flag){
					set.insert(s.substr(i,j));
				}
			}
		}
	}
	
	for(auto &ele:set){
		std::cout << ele << "\n";
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
	//std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}