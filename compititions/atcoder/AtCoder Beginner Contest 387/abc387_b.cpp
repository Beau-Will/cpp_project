// Problem: B - 9x9 Sum
// Contest: AtCoder - AtCoder Beginner Contest 387
// URL: https://atcoder.jp/contests/abc387/tasks/abc387_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	std::vector<std::vector<int>> a(10,std::vector<int>(10));
	
	for(int i = 1;i<=9;++i){
		for(int j = 1;j<=9;++j){
			a[i][j] = i*j;
		}
	}
	int x;std::cin >> x;
	i64 ans = 0;
	for(int i = 1;i<=9;++i){
		for(int j = 1;j<=9;++j){
			if(a[i][j]!=x){
				ans+=a[i][j];
			}
		}
	}
	
	std::cout << ans << '\n';
	
	return 0;
}