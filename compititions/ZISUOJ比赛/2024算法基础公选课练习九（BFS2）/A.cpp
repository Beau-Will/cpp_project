#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 2e6+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

int n;
std::vector<int> a(N,0);
std::vector<int> dist(N,0);
std::vector<bool> vis(N,false);

void bfs(){
	std::queue<int> q;
	vis[1] = true;
	q.push(1);
	while(!q.empty()){
		auto t = q.front();q.pop();
		int y=t+1;
		if(y<=n&&!vis[y]){
			q.push(y);
			vis[y] = true;
			dist[y] = dist[t]+1;
		}
		y=t-1;
		if(y>=1&&!vis[y]){
			q.push(y);
			vis[y] = true;
			dist[y] = dist[t]+1;
		}
		y = a[t];
		if(!vis[y]){
			q.push(y);
			vis[y] = true;
			dist[y] = dist[t]+1;
		}
	}
}

void solve(){
	std::cin >> n;
	for(int i = 1;i<=n;++i) std::cin >> a[i];
	// for(int i = 1;i<=n;++i){
		// dist[i] = i-1;
	// }
	bfs();
	for(int i = 1;i<=n;++i){
		std::cout << dist[i] << " \n"[i==n];
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