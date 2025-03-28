// Problem: 明日DISCO
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/97439/C
// Memory Limit: 512 MB
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

/*
0 0 0 0 0
0 2 -1 0 0
0 1 0 0 0
0 0 0 0 0
0 0 0 0 0

*/

int n;
std::vector<std::vector<int>> g(505,std::vector<int>(505));

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool bfs(int x,int y){
	bool flag = g[x][y]>0;//flag为true表示g[x][y]是正数
	for(int i = 0;i<4;++i){
		int u = x+dx[i],v = y+dy[i];
		if(u<1||u>n||v<1||v>n) continue;
		if(flag&&g[u][v]>0) return true;
		if(!flag&&g[u][v]<0) return true;
	}
	return false;
}

void solve(){
	std::cin >> n;
	for(int i = 0;i<=n;++i){
		g[i][0] = 0;
		g[i][n] = 0;
	}
	for(int i = 0;i<=n;++i){
		g[0][i] = 0;
		g[n][i] = 0;
	}
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=n;++j){
			std::cin >> g[i][j];
		}
	}
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=n;++j){
			if(g[i][j]!=0){
				if(bfs(i,j)){
					std::cout << "NO\n";
					return;
				}
			}
		}
	}
	std::cout << "YES\n";
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