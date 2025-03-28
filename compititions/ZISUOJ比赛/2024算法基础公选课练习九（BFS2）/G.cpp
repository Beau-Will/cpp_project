#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e2+5,M = 1e6+5,INF = 0x3f3f3f3f;
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
}t,t1;

std::vector<std::vector<char>> g(N,std::vector<char>(N));
std::vector<std::vector<bool>> vis(N,std::vector<bool>(N,false));

int n,m,sx,sy,ex,ey;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(){
	std::priority_queue<Node> pq;
	t.x=sx,t.y=sy,t.s=0;
	pq.push(t);
	vis[sx][sy] = true;
	while(!pq.empty()){
		auto t = pq.top();
		pq.pop();
		// std::cout << "t.x,t.y,t.s:" << t.x << ' ' << t.y << ' ' << t.s << '\n';
		if(t.x==ex&&t.y==ey){
			std::cout << t.s << '\n';
			return;
		}
		for(int i = 0;i<4;++i){
			int u = t.x+dx[i],v = t.y+dy[i];
			if(u<1||u>n||v<1||v>m||vis[u][v]) continue;
			vis[u][v] = true;
			t1.x = u,t1.y = v;
			if(g[u][v]=='1'){
				t1.s=t.s+1+5;
			}else if(g[u][v]=='2'){
				t1.s=t.s+1+10;
			}else if(g[u][v]=='3'){
				t1.s=t.s+1+30;
			}else{
				t1.s=t.s+1;
			}
			pq.push(t1);
		}
	}
}

void solve(){
	std::cin >> n >> m;
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			std::cin >> g[i][j];
			if(g[i][j]=='C'){
				sx=i,sy=j;
			}else if(g[i][j]=='X'){
				ex=i,ey=j;
			}
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