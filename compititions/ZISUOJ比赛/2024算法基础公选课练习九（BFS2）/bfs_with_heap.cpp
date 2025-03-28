#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e3+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

struct Node{
	int x,y;
	int s;
	Node(){}
	Node(int x,int y,int s):x(x),y(y),s(s){}
	bool operator<(const Node &t)const{
		return s>t.s;
	}
};

std::vector<std::vector<char>> g(N,std::vector<char>(N));
std::vector<std::vector<bool>> vis(N,std::vector<bool>(N,false));

int n,m,sx,sy,ex,ey;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(){
	std::priority_queue<Node> heap;
	heap.push(sx,sy,0);
	vis[sx][sy] = true;
	while(!heap.empty()){
		auto t = heap.top();
		heap.pop();
		if(t.x==ex&&t.y==ey){
			std::cout << t.s << '\n';
		}
		for(int i = 0;i<4;++i){
			int u = t.x+dx[i],v = t.y+dy[i];
			if(u<1||u>n||v<1||v>m||vis[u][v]) continue;
			vis[u][v] = true;
			heap.push(u,v,t.s+1);
		}
	}
	std::cout << -1 << '\n';
}

void solve(){
	std::cin >> n >> m;
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			std::cin >> g[i][j];
		}
	}
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