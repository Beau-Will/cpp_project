// Problem: D. Drunken Maze
// Contest: Codeforces - 2024 ICPC Asia Taichung Regional Contest (Unrated, Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/contest/2041/problem/D
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int,int>;
constexpr int N = 1e4+5,M = 1e6+5,INF = 0x3f3f3f3f;

char g[N][N];
bool vis[N][N];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
// int dist[N][N];
int n,m;
int sx,sy,ex,ey;
struct Node{
	int x,y,s;
	int tag;
	int cnt;
}t,t1;

void bfs(){
	// memset(dist,0x3f,sizeof dist);
	std::queue<Node> q;
	t.x = sx,t.y = sy,t.s = 0,t.tag = -1,t.cnt = 0;
	q.emplace(t);
	vis[sx][sy] = true;
	int ans = INF;
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		// if(t.x==sx&&t.y==sy&&t.s>100) break;
		if(t.x==ex&&t.y==ey){
			// std::cout << t.s << '\n';
			ans = std::min(ans,t.s);
			// return;
		}
		// dist[t.x][t.y] = t.s;
		// std::cout << t.x << ' ' << t.y << ' ' << t.s << '\n';
		for(int i = 0;i<4;++i){
			// if(t.tag==i&&t.cnt==3) continue;
			int u = t.x+dx[i],v = t.y+dy[i];
			if(u<1||u>n||v<1||v>m||g[u][v]=='#'||vis[u][v]) continue;
			vis[u][v] = true;
			if(t.tag==i&&t.cnt==3){
				t1.s=t.s+3,t1.tag = i,t1.cnt = 2;
			}else if(t.tag==i){
				t1.s=t.s+1,t1.tag = i,t1.cnt = t.cnt+1;
			}else{
				t1.s=t.s+1,t1.tag = i,t1.cnt = 1;
			}
			t1.x = u,t1.y = v;
			q.emplace(t1);
			// if(t.tag==i){
				// t1.cnt=t.cnt+1,t1.s=t.s+1,t1.tag=t.tag;
			// }else{
				// t1.cnt = 0,t1.tag = i,t1.s=t.s+1;
			// }
			// t1.x = u,t1.y = v;
			// q.emplace(t1);
		}
	}
	// for(int i = 1;i<=n;++i){
		// for(int j = 1;j<=m;++j){
			// std::cout << dist[i][j] << " \n"[j==m];
		// }
	// }
	std::cout << (ans==INF?-1:ans) << '\n';
}
void solve(){
	std::cin >> n >> m;
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			std::cin >> g[i][j];
			if(g[i][j]=='S'){
				sx = i,sy = j;
			}else if(g[i][j]=='T'){
				ex = i,ey = j;
			}
		}
	}
	bfs();
}
int main(){
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;
  for(int ti = 0;ti<t;++ti) {
      solve();
  }
	
  return 0;
}