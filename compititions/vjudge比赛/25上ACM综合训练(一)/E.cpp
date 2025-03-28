// Problem: E - Tenzing and His Animal Friends
// Contest: Virtual Judge - 25上ACM综合训练(一)
// URL: https://vjudge.net/contest/704285#problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1'000'000'000'000'000'000;

void solve(){
	int n,m;
	std::cin >> n >> m;
	
	std::vector<int> u(m),v(m),y(m);
	std::vector dist(n,std::vector<i64>(n,inf*2));
	for(int i = 0; i < m; ++i){
		std::cin >> u[i] >> v[i] >> y[i];
		--u[i],--v[i];
		dist[u[i]][v[i]] = y[i];
		dist[v[i]][u[i]] = y[i];
	}
	
	for(int i = 0; i < n; ++i){
		dist[i][i] = 0;
	}
	
	auto floyd = [&](){
		for(int k = 0; k < n; ++k){
			for(int i = 0; i < n; ++i){
				for(int j = 0; j < n; ++j){
					dist[i][j] = std::min(dist[i][j],dist[i][k]+dist[k][j]);
				}
			}
		}
	};
	
	floyd();
	
	if(dist[0][n-1]>inf){
		std::cout << "inf\n";
		return;
	}
	
	std::vector<int> id(n);
	std::iota(id.begin(),id.end(),0);
	
	std::sort(id.begin()+1,id.end(),[&](auto &t1,auto &t2){
		return dist[0][t1] < dist[0][t2];
	});
	
	std::vector<std::tuple<std::string,i64>> ans;
	std::string s(n,'0');
	
	for(int i = 0; i < n-1; ++i){
		int x = id[i],y = id[i+1];
		s[x] = '1';
		ans.push_back({s,dist[0][y]-dist[0][x]});
		if(y==n-1){
			break;
		}
	}
	
	std::cout << dist[0][n-1] << " " << ans.size() << "\n";
	for(auto &[s,dis]:ans){
		std::cout << s << " " << dis << "\n";
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
	//std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}