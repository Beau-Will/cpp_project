#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1000000000;
constexpr int P = 131,N = 100000;
constexpr int P1 = 1000000007,P2 = 998244353;
constexpr i64 inf2 = 1000000000000000000;

void solve(){
	std::string s;
	std::cin >> s;
	
	std::vector<char> stk1;
	std::vector<std::string> stk2;
	std::string tmp;
	for(int i = 0; i < s.size(); ++i){
		if(s[i]=='('){
			if(tmp.size()!=0){
				stk2.push_back(tmp);
				tmp = "";
			}
			stk1.push_back(s[i]);
		}else{
			if(s[i]==')'){
				if(tmp.size()!=0){
					stk2.push_back(tmp);
					tmp = "";
				}
				std::cout << stk2.back() << "\n";
				stk2.pop_back();
			}else{
				tmp += s[i];
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
//	std::cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
