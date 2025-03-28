// Problem: A. Line Breaks
// Contest: Codeforces - Codeforces Round 991 (Div. 3)
// URL: https://codeforces.com/contest/2050/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

void solve(){
	int n,m;std::cin >> n >> m;
	int cnt = 0,cur_len = 0;
	for(int i = 1;i<=n;++i){
		std::string s;std::cin >> s;
		cur_len+=s.size();
		if(cur_len<=m) ++cnt;
	}
	std::cout << cnt << '\n';
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