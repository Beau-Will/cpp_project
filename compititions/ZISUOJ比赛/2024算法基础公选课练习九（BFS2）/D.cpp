#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e2+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace
int n;

int sx,sy,ex,ey;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char g[N][N];
bool vis[N][N];

struct Node{
	int x,y,s;
	bool operator <(const Node &t) const{
		return s>t.s;
	}
}t,t1;

void bfs(){
	memset(vis,false,sizeof vis);
	std::priority_queue<Node> pq;
	t.x = sx,t.y = sy,t.s = 0;
	vis[sx][sy] = true;
	pq.push(t);
	while(!pq.empty()){
		auto t = pq.top();
		pq.pop();
		if(t.x==ex&&t.y==ey){
			std::cout << t.s << '\n';
			return;
		}
		for(int i = 0;i<4;++i){
			int u = t.x+dx[i],v = t.y+dy[i];
			if(u<1||u>n||v<1||v>n||vis[u][v]||g[u][v]=='#') continue;
			if(g[u][v]=='.'){
				t1.x = u,t1.y = v,t1.s = t.s+1;
			}else{
				t1.x = u,t1.y = v,t1.s = t.s+(g[u][v]-'0')+1;
			}
			vis[u][v] = true;
			pq.push(t1);
		}
	}
	std::cout << -1 << '\n';
}

void solve(){
	while(std::cin >> n){
		for(int i = 1;i<=n;++i){
			for(int j = 1;j<=n;++j){
				std::cin >> g[i][j];
			}
		}
		sx = 1,sy = 1,ex = n,ey = n;
		bfs();
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