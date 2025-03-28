// Problem: A. The Bento Box Adventure
// Contest: Codeforces - 2024 ICPC Asia Taichung Regional Contest (Unrated, Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/contest/2041/problem/A
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;

void solve(){
	std::string s;
	for(int i = 0;i<4;++i){
		char c;std::cin >> c;
		s+=c;
	}
	for(int i = 0;i<5;++i){
		if(s.find((i+1)^48)==std::string::npos){
			std::cout << i+1 << '\n';
			return;
		}
	}
}
int main(){
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;
  for(int ti = 0;ti<t;++ti) {
      solve();
  }
	
  return 0;
}