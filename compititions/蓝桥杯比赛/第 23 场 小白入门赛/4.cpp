// Problem: 4. 掩体计划【算法赛】
// Contest: Lanqiao
// URL: https://www.lanqiao.cn/problems/20053/learning/?contest_id=224
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

int n,m;
std::vector<std::vector<int>> edges(N);
std::vector<int> f(N);
std::vector<int> bomb;

void bfs(){
	std::queue<int> q;
	q.emplace(1);
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		if(edges[t].size()>1){
			++f[t];
		}
		for(const auto&to:edges[t]){
			if(!f[to]){
				f[to] = f[t];
				q.emplace(to);
			}
		}
	}
}

void solve(){
	std::cin >> n;
	for(int i = 0;i<n-1;++i){
		int u,v;std::cin >> u >> v;
		edges[u].pb(v);
		// edges[v].pb(u);
	}
	std::cin >> m;
	while(m--){
		int t;std::cin >> t;
		bomb.pb(t);
	}
	bfs();
	int ans = INF;
	for(const auto &b:bomb){
		ans = std::min(ans,f[b]);
	}
	std::cout << ans << '\n';
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