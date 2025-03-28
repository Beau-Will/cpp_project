// Problem: D. Digital string maximization
// Contest: Codeforces - Codeforces Round 991 (Div. 3)
// URL: https://codeforces.com/contest/2050/problem/D
// Memory Limit: 256 MB
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

void solve(){
	std::string s;std::cin >> s;
	int len = s.size();
	s = ' '+s;
	for(int i = 2;i<=len;++i){
		if(s[i]=='0') continue;
		int idx = -1,tmp = -1;
		for(int j = std::max(1,i-8);j<i;++j){
			int d = i-j;
			if(s[i]-d>s[j]){
				idx = j;
				tmp = s[i]-d;
				break;
			}
		}
		if(idx==-1) continue;
		for(int j = i;j>idx;--j){
			s[j] = s[j-1];
		}
		s[idx] = tmp;
	}
	std::cout << s.substr(1) << '\n';
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