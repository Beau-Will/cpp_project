// Problem: B. Rakhsh's Revival
// Contest: Codeforces - Rayan Programming Contest 2024 - Selection (Codeforces Round 989, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2034/problem/B
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

void solve(){
	i64 n,m,k;std::cin >> n >> m >> k;
	std::string s;std::cin >> s;
	std::string target;
	std::string rep;
	for(int i = 0;i<m;++i){
		target+='0';
		// rep+='1';
	}
	for(int i = 0;i<k;++i){
		rep+='1';
	}
	int ans = 0;
	int pos = 0;
	while((pos=s.find(target,pos))!=std::string::npos){
		s.replace(pos+m-1,k,rep);
		++ans;
	}
	std::cout << ans << '\n';
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