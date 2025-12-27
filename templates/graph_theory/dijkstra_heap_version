int n,m;
std::vector<int> dist(N,INF);
std::vector<bool> vis(N,false);
std::vector<std::vector<pii>> edges(N);

void dijkstra(){
	dist[1] = 0;
	std::priority_queue<pii,std::vector<pii>,std::greater<pii>> heap;
	heap.push(0,1);
	while(!heap.empty()){
		auto t = heap.top();
		heap.pop();
		int u = t.second,distance = t.first;
		if(vis[u]) continue;
		vis[u] = true;
		for(auto &[v,w]:edges[u]){
			if(dist[v]>distance+w){
				dist[v] = distance+w;
				heap.push(dist[v],v);
			}
		}
	}
}
