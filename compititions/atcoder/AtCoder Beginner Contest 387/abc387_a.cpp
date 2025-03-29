// Problem: A - Happy New Year 2025
// Contest: AtCoder - AtCoder Beginner Contest 387
// URL: https://atcoder.jp/contests/abc387/tasks/abc387_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	i64 a,b;std::cin >> a >> b;
	std::cout << (a+b)*(a+b) << '\n';
	
	return 0;
}