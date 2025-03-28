#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()

void solve(){
	std::vector<char> ans;
	std::string s;std::cin >> s;
	for(char c = 'a';c<='z';++c){
		bool flag = false;
		int cnt = 0;
		for(int i = 0;i<s.size();++i){
			if(s[i]==c){
				if(!flag) flag = true;
				++cnt;
			}else{
				if(cnt&1){
					ans.pb(c);
					break;
				}
				flag = false;
				cnt = 0;
			}
		}
		if(flag&&cnt&1){
			ans.pb(c);
		}
	}
	std::sort(all(ans));
	ans.erase(std::unique(all(ans)),ans.end());
	for(const auto &c:ans) std::cout << c;
	std::cout << '\n';
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int tt = 1;
	std::cin >> tt;
	for(int ti = 0;ti<tt;++ti){
		solve();
	}
	
	return 0;
}