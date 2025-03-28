// Problem: 铁刀磨成针
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95338/J
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 1e3+5,INF = 0x3f3f3f3f;

int dp[2*N][2*N];//表示进行了i句，当前攻击力为j可以获得的最大攻击力之和

void solve(){
	int n,x,y;std::cin >> n >> x >> y;
	int ed = std::min(n,x+(y-1));
	for(int i = 0;i<2*N;++i){
		dp[0][i] = -INF;
		if(i==x) dp[0][i] = x;
	}
	for(int i = 1;i<=ed;++i){
		for(int j = 0;j<=x+y;++j){
			
		}
	}
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int t = 1;
	std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}