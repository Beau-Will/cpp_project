// Problem: 普通DISCO-1
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/97439/E
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 5e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

int n;
std::vector<std::vector<int>> edges(N);
int maxdepth = 0,leaf = 0;

void dfs(int index,int fa, int depth) {
    if(edges[index].size() == 1&&fa!=-1) {
        if(maxdepth < depth) {
        	maxdepth = depth;
        	leaf = index;
        }
        return ;
    }
    for(auto &v:edges[index]){
    	if(v==index) continue;
        dfs(v,index,depth + 1);
    }
}

void solve(){
	std::cin >> n;
	for(int i = 0;i<n-1;++i){
		int u,v;std::cin >> u >> v;
		edges[u].pb(v);
		edges[v].pb(u);
	}
	dfs(1,-1,1);
	dfs(leaf,-1,1);
	std::cout << maxdepth << '\n';
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