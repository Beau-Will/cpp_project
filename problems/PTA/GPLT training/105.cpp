#include <bits/stdc++.h>

//using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int N = 200005,inf = 1000000000;
constexpr int P1 = 1000000007,P2 = 998244353;
constexpr int P = 131;

void solve(){
	int n,m,s,t;
	std::cin >> n >> m >> s >> t;
	
	std::vector<int> w(n);
	for(int i = 0; i < n; ++i){
		std::cin >> w[i];
	}
	
	auto adj = std::vector(n,std::vector<std::pair<int,int>>());
	for(int i = 0; i < m; ++i){
		int x,y,z;
		std::cin >> x >> y >> z;
		adj[x].push_back({y,z});
		adj[y].push_back({x,z});
	}
	
	std::vector<bool> vis(n);
	std::vector<int> dist(n,inf);
	
	std::vector<int> prev(n);
	std::vector<int> cnt(n);
	std::vector<int> sum(n);
	
	auto dijkstra = [&](){
		std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> pq;
		
		dist[s] = 0;
		prev[s] = -1;
		cnt[s] = 1;
		sum[s] = w[s];
		pq.push({0,s});
		
		while(!pq.empty()){
			auto [w1,u] = pq.top();
			pq.pop();
			if(vis[u]){
				continue;
			}
			vis[u] = true;
			for(auto [v,w2]:adj[u]){
				if(dist[v]>dist[u]+w2){
					sum[v] = sum[u]+w[v];
					prev[v] = u;
					cnt[v] = cnt[u];
					dist[v] = dist[u]+w2;
					pq.push({dist[v],v});
				}else if(dist[v]==w1+w2){
					cnt[v] += cnt[u];
					if(sum[u]+w[v]>sum[v]){
						sum[v] = sum[u]+w[v];
						prev[v] = u;
					}
				}
			}
		}
	};
	
	dijkstra();
	
	std::vector<int> ans;
	int tmp = t;
	while(tmp!=-1){
		ans.push_back(tmp);
		tmp = prev[tmp];
	}
	
	std::cout << cnt[t] << " " << sum[t] << "\n";
	for(int i = ans.size()-1; i >= 0; --i){
		std::cout << ans[i] << " \n"[i==0];
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
//	std::cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
