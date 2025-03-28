// Problem: 小苯的字符串染色
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/97017/C
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
#define all(v) v.begin(),v.end()
#define push emplace
/*
白黑白黑
0101
*/
void solve(){
	int n;std::cin >> n;
	std::string s;std::cin >> s;
	std::vector<pii> ans;
	for(int i = 0;i<n;++i){
		if(s[i]=='1'){
			ans.pb(i+1,i+1);
		}
	}
	std::cout << ans.size() << '\n';
	for(const auto &[u,v]:ans) std::cout << u << ' ' << v << '\n';
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