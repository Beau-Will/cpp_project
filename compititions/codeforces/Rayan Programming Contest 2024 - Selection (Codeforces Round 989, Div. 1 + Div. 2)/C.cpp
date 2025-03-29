// Problem: C. Trapped in the Witch's Labyrinth
// Contest: Codeforces - Rayan Programming Contest 2024 - Selection (Codeforces Round 989, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2034/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e3+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()

char g[N][N];
bool vis[N][N];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int n,m;
using Node = std::array<int,2>;

void bfs(){
	std::queue<Node> q;
	for(int i = 1;i<=m;++i){
		if(vis[1][i]){
			q.push({1,i});
		}
		if(vis[n][i]){
			q.push({n,i});
		}
	}
	for(int i = 1;i<=n;++i){
		if(vis[i][1]){
			q.push({i,1});
		}
		if(vis[i][m]){
			q.push({i,m});
		}
	}
	/*int dx[] = {0,0,-1,1};
	int dy[] = {-1,1,0,0};*/
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		for(int i = 0;i<4;++i){
			int u = t[0]+dx[i],v = t[1]+dy[i];
			if(u<1||u>n||v<1||v>m) continue;
			if(vis[u][v]) continue;
			if(i==0&&g[u][v]=='R') {
				vis[u][v] = true;
				q.push({u,v});
			}else if(i==1&&g[u][v]=='L') {
				vis[u][v] = true;
				q.push({u,v});
			}else if(i==2&&g[u][v]=='D'){
				vis[u][v] = true;
				q.push({u,v});
			}else if(i==3&&g[u][v]=='U'){
				vis[u][v] = true;
				q.push({u,v});
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
	for(int i = 1;i<=m;++i){
		if(g[1][i]=='U'){
			vis[1][i] = true;
		}
		if(g[n][i]=='D'){
			vis[n][i] = true;
		}
	}
	for(int i = 1;i<=n;++i){
		if(g[i][1]=='L'){
			vis[i][1] = true;
		}
		if(g[i][m]=='R'){
			vis[i][m] = true;
		}
	}
	bfs();
	/*for(int i = 1;i<=m;++i){
		if(vis[1][i]){
			bfs(1,i);
		}
		if(vis[n][i]){
			bfs(n,i);
		}
	}
	for(int i = 1;i<=n;++i){
		if(vis[i][1]){
			bfs(i,1);
		}
		if(vis[i][m]){
			bfs(i,m);
		}
	}*/
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			if(g[i][j]=='?'){
				bool flag = false;
				for(int k = 0;k<4;++k){
					int u = i+dx[k],v = j+dy[k];
					if(u<1||u>n||v<1||v>m) continue;
					if(!vis[u][v]){
						flag = true;
						break;
					}
				}
				if(!flag) vis[i][j] = true;
			}
		}
	}
	
	int ans = n*m;
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			if(vis[i][j]) --ans;
		}
	}
	// for(int i = 1;i<=n;++i){
		// for(int j = 1;j<=m;++j){
			// std::cout << "vis[i][j]:" << vis[i][j] << " \n"[j==m];
		// }
	// }
	
	std::cout << ans << '\n';
	
	//恢复
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			vis[i][j] = false;
		}
	}
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