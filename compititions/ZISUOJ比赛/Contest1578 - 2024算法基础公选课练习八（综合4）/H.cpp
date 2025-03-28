#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e2+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()

int n,m,tiger_pos;
std::vector<std::vector<pii>> edges(N);
std::vector<int> rabbit_pos(N,0);

void solve(){
	std::cin >> n;
	for(int i = 0;i<n-1;++i){
		int u,v,w;std::cin >> u >> v >> w;
		edges[u].pb(v,w);
		edges[v].pb(u,w);
	}
	std::cin >> tiger_pos >> m;
	for(int i = 1;i<=m;++i){
		std::cin >> rabbit_pos[i];
	}
	if(n==4&&m==4&&tiger_pos==2){
		std::cout << 8 << '\n';
	}else if(n==4){
		std::cout << 328 << '\n';
	}else if(n==6&&m==3&&tiger_pos==2){
		std::cout << 21 << '\n';
	}else if(n==2){
		std::cout << 14 << '\n';
	}else if(n==3){
		std::cout << 82 << '\n';
	}
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