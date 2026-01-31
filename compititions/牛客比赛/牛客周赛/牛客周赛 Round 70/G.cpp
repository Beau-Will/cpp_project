// Problem: 小苯的树上操作
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/97017/G
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 2e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

int n;
std::vector<int> w(N,0);

void solve(){
	std::cin >> n;
	for(int i = 1;i<=n;++i) std::cin >> w[i];
	std::vector<std::vector<int>> edges(n+5);
	for(int i = 0;i<n-1;++i){
		int u,v;std::cin >> u >> v;
		edges[u].pb(v);
		edges[v].pb(u);
	}
	bool flag = true;
	for(int i = 1;i<=n;++i){
		if(w[i]>0){
			flag = false;
			break;
		}
	}
	if(flag){
		std::cout << 0 << '\n';
		return;
	}
	i64 ans = 0;
	for(int i = 1;i<=n;++i){
		if(w[i]>0) ans+=w[i];
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