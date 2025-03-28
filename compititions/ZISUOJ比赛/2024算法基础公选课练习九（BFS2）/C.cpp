#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e2+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

int n,m,sx,sy,ex,ey;
std::vector<std::vector<int>> g(N,std::vector<int>(N));
std::vector<std::vector<bool>> vis(N,std::vector<bool>(N,false));
struct Node{
	int x,y,s;
}t,t1;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
void bfs(){
	std::queue<Node> q;
	t.x = sx,t.y = sy,t.s = -1;
	q.push(t);
	vis[sx][sy] = true;
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		if(t.x==ex&&t.y==ey){
			std::cout << t.s << '\n';
			return;
		}
		for(int i = 0;i<4;++i){
			int u = t.x+dx[i],v = t.y+dy[i];
			if(u<1||u>n||v<1||v>m||vis[u][v]||g[u][v]==1) continue;
			vis[u][v] = true;
			t1.x = u,t1.y = v,t1.s = t.s+1;
			q.push(t1);
			while(u+dx[i]>=1&&u+dx[i]<=n&&v+dy[i]>=1&&v+dy[i]<=m&&!vis[u+dx[i]][v+dy[i]]&&g[u+dx[i]][v+dy[i]]==0){
				vis[u][v] = true;
				t1.x = u+dx[i],t1.y = v+dy[i],t1.s=t.s+1;
				q.push(t1);
				u+=dx[i],v+=dy[i];
			}
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
	std::cin >> sx >> sy >> ex >> ey;
	bfs();
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