#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e3+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

int n,m;
int dist[N][N];
bool vis[N][N];
char g[N][N];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(){
	memset(dist,0x3f,sizeof dist);
	std::queue<pii> q;
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			if(g[i][j]=='0'){
				q.push(i,j);
				dist[i][j] = 0;
				vis[i][j] = true;
			}
		}
	}
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		for(int i = 0;i<4;++i){
			int u = t.first+dx[i],v = t.second+dy[i];
			if(u<1||u>n||v<1||v>m||vis[u][v]) continue;
			vis[u][v] = true;
			dist[u][v] = dist[t.first][t.second]+1;
			q.push(u,v);
		}
	}
}

void solve(){
	std::cin >> n >> m;
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			std::cin >> g[i][j];
		}
	}
	bfs();
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			std::cout << dist[i][j] << " \n"[j==m];
		}
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