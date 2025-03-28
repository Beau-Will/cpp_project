#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

int n,m;
std::vector<std::vector<int>> reverse_edges(N);
std::vector<int> dp(N,0);

int get_longest_path(int u){//表示以u为起点返回的最长路的值
	if(dp[u]>0) return dp[u];
	for(auto &v:reverse_edges[u]){
		dp[u] = std::max(dp[u],get_longest_path(v)+1);
	}
	return dp[u];
}

void solve(){
	std::cin >> n >> m;
	while(m--){
		int u,v;std::cin >> u >> v;
		reverse_edges[v].pb(u);//反向建边
	}
	std::cout << get_longest_path(n) << '\n';
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