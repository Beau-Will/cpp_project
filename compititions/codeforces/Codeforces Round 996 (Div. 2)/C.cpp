// Problem: C. The Trail
// Contest: Codeforces - Codeforces Round 996 (Div. 2)
// URL: https://codeforces.com/contest/2055/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,m;std::cin >> n >> m;
	std::string s;
	std::vector<std::vector<i64>> g(n,std::vector<i64>(m));
	
	std::cin >> s;
	for(int i = 0;i<n;++i){
		for(int j = 0;j<m;++j){
			std::cin >> g[i][j];
		}
	}
	
	int x = 0,y = 0;
	for(int i = 0;i<s.size();++i){
		i64 sum = 0;
		if(s[i]=='D'){
			for(int i = 0;i<m;++i){
				sum += g[x][i];
			}
			g[x][y] = -sum;
			++x;
		}else{
			for(int i = 0;i<n;++i){
				sum += g[i][y];
			}
			g[x][y] = -sum;
			++y;
		}
	}
	i64 sum = 0;
	for(int i = 0;i<m;++i){
		sum += g[n-1][i];
	}
	g[n-1][m-1] = -sum;
	
	for(int i = 0;i<n;++i){
		for(int j = 0;j<m;++j){
			std::cout << g[i][j] << " \n"[j==m-1];
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