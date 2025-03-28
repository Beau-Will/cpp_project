// Problem: Onewan的疑惑
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/99785/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	i64 n;std::cin >> n;
	// std::cout << n << '\n';
	//19260817+114514
	i64 t = 19260817+114514+1;
	if(n>=t){
		std::cout << t << '\n';
	}else{
		std::cout << n << '\n';
	}
	// std::cout << std::max(n-t,n) << '\n';
	
	return 0;
}