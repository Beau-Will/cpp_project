// Problem: 树
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/99073/A
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
#define push_back emplace_back
#define push emplace
#define all(v) v.begin(),v.end()

std::vector<std::vector<pii>> edges;
std::vector<int> a;

void solve(){
	int n;std::cin >> n;
	
	edges.resize(n+1);
	a.resize(n+1);
	for(int i = 0;i<n-1;++i){
		int u,v,w;std::cin >> u >> v >> w;
		edges[u].emplace_back(v,w);
		edges[v].emplace_back(u,w);
	}
	
	int min = INF,minidx = -1;
	
	for(int i = 1;i<=n;++i){
		int tmp = 0;
		int &u = i;
		for(const auto &[v,w]:edges[u]){
			tmp = std::max(tmp,w);
		}
		a[u] = tmp;
		if(tmp<min){
			min = tmp;
			minidx = u;
		}
	}
	
	std::cout << minidx << '\n';
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