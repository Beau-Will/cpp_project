#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 1e3+5,M = 1e5+5,INF = 0x3f3f3f3f;
int g[N][N],dist[N];
bool vis[N];

void dijkstra() {
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    for(int i = 0;i<1000;i++) {
        int t = -1;
        for(int j = 1;j<=1000;j++) {
            if(!vis[j]&&(t==-1||dist[j]<dist[t])) t = j;
        }
        vis[t] = true;
        for(int j = 1;j<=1000;j++) {
            dist[j] = std::min(dist[j],dist[t]+g[t][j]);
        }
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

	int t = 1;std::cin >> t;
	for(int i = 1;i<=1000;++i){
		for(int j = 1;j<=1000;++j){
			g[i][j] = g[j][i] = i^j;
		}
	}

    dijkstra();

    
    for(int i = 1;i<=1000;++i){
    	int sum = 0;
    	for(int j = 1;j<=i;++j){
    		if(j==1) continue;
    		sum ^= dist[j];
    	}
    	std::cout << "i S:" << i << ' ' << sum << '\n';
    }

    
    return 0;
}
