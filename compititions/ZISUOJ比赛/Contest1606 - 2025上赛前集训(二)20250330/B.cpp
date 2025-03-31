#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	std::string a;
	std::cin >> a;
	
	bool flag = false;
	for(int i = 0; i < (1<<3); ++i){
		int cnt = __builtin_popcount(i);
		if(cnt==0||cnt==3){
			continue;
		}
		std::vector<char> id;
		for(int j = 0; j < 3; ++j){//A B C
			if(i >> j & 1){//0是(,1是)
				id.push_back(')');
			}else{
				id.push_back('(');
			}
		}
		std::string b(a.size(),'?');
		for(int j = 0; j < a.size(); ++j){
			if(a[j]=='A'){
				b[j] = id[0];
			}else if(a[j]=='B'){
				b[j] = id[1];
			}else{
				b[j] = id[2];
			}
		}
		auto check = [&]()->bool{
			std::vector<char> stk;
			for(int k = 0; k < b.size(); ++k){
				if(stk.size()){
					if(b[k]==')'){
						stk.pop_back();
					}else{
						stk.push_back(b[i]);
					}
				}else{
					if(b[k]=='('){
						stk.push_back(b[i]);
					}else{
						return false;
					}
				}
			}
			return stk.empty();
		};
		if(check()){
			flag = true;
			break;
		}
	}
	
	std::cout << (flag?"YES\n":"NO\n");
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
	std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}