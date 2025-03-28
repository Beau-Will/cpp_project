// Problem: G - Flip Row or Col
// Contest: AtCoder - AtCoder Beginner Contest 396
// URL: https://atcoder.jp/contests/abc396/tasks/abc396_g
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,m;
	std::cin >> n >> m;
	
	std::vector<std::string> g(n);
	for(int i = 0; i < n; ++i){
		std::cin >> g[i];
	}
	
	std::vector<std::vector<int>> a(n,std::vector<int>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(g[i][j]=='1'){
				a[i][j] = 1;
			}
		}
	}
	
	std::vector<int> row0(n),row1(n),col0(m),col1(m);
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(a[i][j]==0){
				++row0[i];
				++col0[j];
			}else{
				++row1[i];
				++col1[j];
			}
		}
	}
	
	for(int i = 0; i < (1<<m); ++i){
		for(int j = 0; j < m; ++j){
			if((i>>j)&1){//表示j列取反了
				
			}
		}
	}
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int t = 1;
	//std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}