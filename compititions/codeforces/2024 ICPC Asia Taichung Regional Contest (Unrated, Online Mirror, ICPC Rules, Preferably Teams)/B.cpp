// Problem: B. Bowling Frame
// Contest: Codeforces - 2024 ICPC Asia Taichung Regional Contest (Unrated, Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/contest/2041/problem/B
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<i64,i64>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;

std::vector<i64> pre(N,0);
std::vector<pii> ans(N);

void solve(){
	i64 a,b;std::cin >> a >> b;
	i64 sum = a+b;
	for(i64 i = 1;i<=100000;++i){
		if(sum<pre[i]){
			std::cout << i-1 << '\n';
			return;
		}
	}
	// if(a>b) std::swap(a,b);
	// i64 res = 0;
	// for(i64 i = 1;i<=100000;++i){
		// if(a<ans[i].first||b<ans[i].second){
			// res = i-1;
			// break;
		// }
	// }
	// for(i64 i = 1;i<=100000;++i){
		// if(b<pre[i]){
			// res = std::max(res,i-1);
			// break;
		// }
	// }
	// std::cout << res << '\n';
}
int main(){
  std::cin.tie(nullptr)->sync_with_stdio(false);

	for(int i = 1;i<=1e5;++i){
		pre[i] = pre[i-1]+i;
		ans[i].second = (pre[i]+1)/2;
		ans[i].first = pre[i]/2;
	}

  int t = 1;
  std::cin >> t;
  for(int ti = 0;ti<t;++ti) {
      solve();
  }
	
  return 0;
}