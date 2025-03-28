#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e2+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

int n,m;
int k,sx,sy,ex,ey;

char g[N][N];
bool vis[N][N];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

struct Node{
	int x,y,s;
}t,t1;

void bfs(){
	memset(vis,false,sizeof vis);
	t.x = sx,t.y = sy,t.s = -1;
	std::queue<Node> q;
	q.push(t);
	vis[sx][sy] = true;
	auto check = [&](int u,int v)->bool{
		return u>=1&&u<=n&&v>=1&&v<=m&&g[u][v]=='.';
	};
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		if(t.s>k) break;
		if(t.x==ex&&t.y==ey&&t.s<=k){
			std::cout << "yes" << '\n';
			return;
		}
		for(int i = 0;i<4;++i){
			int u = t.x+dx[i],v = t.y+dy[i];
			while(check(u,v)){
				if(!vis[u][v]){
					t1.x = u;
					t1.y = v;
					t1.s = t.s+1;
					q.push(t1);
					vis[u][v] = true;
				}
				u+=dx[i];
				v+=dy[i];
			}
		}
	}
	std::cout << "no" << '\n';
}

void solve(){
	std::cin >> n >> m;
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			std::cin >> g[i][j];
		}
	}
	std::cin >> k >> sy >> sx >> ey >> ex;
	bfs();
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int tt = 1;
	std::cin >> tt;
	for(int ti = 0;ti<tt;++ti){
		solve();
	}
	
	return 0;
}