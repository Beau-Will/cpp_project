// Problem: E. Three Strings
// Contest: Codeforces - Codeforces Round 991 (Div. 3)
// URL: https://codeforces.com/contest/2050/problem/E
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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

void solve(){
	std::string a,b,c;
	std::cin >> a >> b >> c;
	int n = a.size(),m = b.size();
	
	std::vector<std::vector<int>> dp(n+1,std::vector<int>(m+1,INF));
	dp[0][0] = 0;
	for(int i = 0;i<=n;++i){
		for(int j = 0;j<=m;++j){
			if(i<n){
				dp[i+1][j] = std::min(dp[i+1][j],dp[i][j]+int(c[i+j]!=a[i]));
			}
			if(j<m){
				dp[i][j+1] = std::min(dp[i][j+1],dp[i][j]+int(c[i+j]!=b[j]));
			}
		}
	}
	std::cout << dp[n][m] << '\n';
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