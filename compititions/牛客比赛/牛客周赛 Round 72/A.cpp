// Problem: 小红的01串（一）
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/98256/A
// Memory Limit: 512 MB
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
#define push_back emplace_back
#define push emplace
#define all(v) v.begin(),v.end()

void solve(){
	std::string s;
	std::cin >> s;
	int cnt = 0;
	for(int i = 1;i<s.size();++i){
		if(s[i]!=s[i-1]){
			++cnt;
		}
	}
	std::cout << cnt << '\n';
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