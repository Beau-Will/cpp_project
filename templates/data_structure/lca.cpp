#include <bits/stdc++.h>

using i64 = long long;

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int n;
	std::cin >> n;
	
	std::vector<std::vector<int>> adj(n+1);
	for(int i = 1; i < n; ++i){
		int u,v;
		std::cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	std::vector<int> par(n + 1), dfn(n + 1), dep(n + 1);
	std::vector f(20, std::vector<int>(n + 1));
	int timer = 0;
	auto dfs = [&](auto& dfs, int u) -> void {
		dfn[u] = timer += 1;
		f[0][u] = par[u];
		for (int i = 1; i < 20; i += 1) f[i][u] = f[i - 1][f[i - 1][u]];
		for (auto& v : adj[u]) {
		  if (v == par[u]) continue;
		  par[v] = u;
		  dep[v] = dep[u] + 1;
		  dfs(dfs, v);
		}
	};
	dfs(dfs, dep[1] = 1);
	auto lca = [&](int u, int v) {
		if (dep[u] < dep[v]) std::swap(u, v);
		for (int i = 19; i >= 0; i -= 1)
			if (dep[f[i][u]] >= dep[v]) u = f[i][u];
		if (u == v) return u;
		for (int i = 19; i >= 0; i -= 1) {
			if (f[i][u] != f[i][v]) u = f[i][u], v = f[i][v];
		};
		return f[0][u];
	};
	
	return 0;
}