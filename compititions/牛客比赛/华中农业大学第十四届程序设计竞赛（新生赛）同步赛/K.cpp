// Problem: 波奇酱找工位
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95480/K
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

int n,m,k;
std::vector<std::vector<int>> g(105,std::vector<int>(105,0));
std::vector<std::vector<bool>> vis(105,std::vector<bool>(105,false));

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
std::vector<std::vector<int>> dist(105,std::vector<int>(105,INF));
using Node = std::array<int,2>;

void solve(){//多源bfs
	std::cin >> n >> m >> k;
	for(int i = 0;i<k;++i){
		int x,y;std::cin >> x >> y;
		g[x][y] = 1;
	}
	std::queue<Node> q;
	for(int i{1};i<=n;++i){
		for(int j{1};j<=m;++j){
			if(g[i][j]){
				vis[i][j] = true;
				dist[i][j] = 0;
				Node tt = {i,j};
				q.push(tt);
			}
		}
	}
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		for(int i = 0;i<4;++i){
			int u = t[0]+dx[i],v = t[1]+dy[i];
			if(u<1||u>n||v<1||v>m||vis[u][v]) continue;
			vis[u][v] = true;
			dist[u][v] = dist[t[0]][t[1]]+1;
			Node t1 = {u,v};
			q.push(t1);
		}
	}
	int ans = 0,ansx=0,ansy=0;
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			if(dist[i][j]>ans&&dist[i][j]!=INF){
				ans = dist[i][j];
				ansx = i,ansy = j;
			}
		}
	}
	std::cout << ans << '\n' << ansx << ' ' << ansy << '\n';
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