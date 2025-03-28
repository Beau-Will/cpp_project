int n,m;
std::vector<int> dist(N,INF);
std::vector<bool> vis(N,false);
std::vector<std::vector<int>> g(N,std::vector<int>(N,INF));

void dijkstra(){
	dist[1] = 0;
	for(int i = 1;i<=n;++i){
		int t = -1;
		for(int j = 1;j<=n;++j){
			if(!vis[j]&&(t==-1||dist[j]<dist[t])) t = j;
		}
		vis[t] = true;
		for(int j = 1;j<=n;++j){
			dist[j] = std::min(dist[j],dist[t]+g[t][j]);
		}
	}
}
