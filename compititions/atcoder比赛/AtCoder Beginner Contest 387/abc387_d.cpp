// Problem: D - Snaky Walk
// Contest: AtCoder - AtCoder Beginner Contest 387
// URL: https://atcoder.jp/contests/abc387/tasks/abc387_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e3+5,INF = 0x3f3f3f3f;

char g[N][N];
bool vis[N][N][2];
int dist[N][N][2];
int n,m,sx,sy,tx,ty;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

struct Node{
	int x,y,dir;
};

bool check(int x,int y,int d){
	if(x<1||x>n||y<1||y>m) return false;
	if(vis[x][y][d]||g[x][y]=='#') return false;
	return true;
}

void bfs(){
	memset(dist,0x3f,sizeof dist);

	std::queue<Node> q;
	q.push({sx,sy,0});
	q.push({sx,sy,1});
	vis[sx][sy][0] = vis[sx][sy][1] = true;
	dist[sx][sy][0] = dist[sx][sy][1] = 0;
	while(!q.empty()){
		auto t = q.front();
		int x = t.x,y = t.y,dir = t.dir;
		q.pop();
		if(x==tx&&y==ty){
			std::cout << dist[x][y][dir] << '\n';
			return;
		}
		for(int i = 2*dir;i<2+2*dir;++i){
			int u = x+dx[i],v = y+dy[i];
			if(check(u,v,!dir)){
				vis[u][v][!dir] = true;
				dist[u][v][!dir] = dist[x][y][dir]+1;
				q.push({u,v,!dir});
			}
		}
	}
	std::cout << -1 << '\n';
}

void solve(){
	std::cin >> n >> m;
	
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			std::cin >> g[i][j];
			if(g[i][j]=='S'){
				sx = i,sy = j;
			}else if(g[i][j]=='G'){
				tx = i,ty = j;
			}
		}
	}
	
	bfs();
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int tt = 1;
	// std::cin >> tt;
	while(tt--){
		solve();
	}
	
	return 0;
}