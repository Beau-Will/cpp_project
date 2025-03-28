// Problem: 宝石手串
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/97443/B
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

int n;
std::string s;

void solve(){
	std::cin >> n >> s;
	int len = s.size();
	std::map<char,int> map;
	for(int i = 0;i<len;++i){
		++map[s[i]];
	}
	bool flag = false;
	for(auto &[u,v]:map){
		if(v>1){
			flag = true;
			break;
		}
	}
	if(!flag){
		std::cout << -1 << '\n';
		return;
	}
	s = s+s;
	int ans = INF;
	for(char c = 'a';c<='z';++c){
		int d = INF,last_c = -1;
		for(int i = 0;i<s.size();++i){
			if(s[i]==c){
				if(last_c!=-1){
					d = std::min(d,i-last_c-1);
				}
				last_c = i;
			}
		}
		ans = std::min(ans,d);
	}
	std::cout << (ans==INF?-1:ans) << '\n';
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