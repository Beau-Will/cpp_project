#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()

void solve(){
	std::string s;std::cin >> s;
	std::stack<char> stack;
	bool flag = false;
	for(const auto& c:s){
		if(!stack.empty()&&stack.top()==c){
			flag = !flag;
			stack.pop();
		}else{
			stack.emplace(c);
		}
	}
	std::cout << (flag?"Yes":"No") << '\n';
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int tt = 1;
	// std::cin >> tt;
	for(int ti = 0;ti<tt;++ti){
		solve();
	}
	
	return 0;
}