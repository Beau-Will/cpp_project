// Problem: 小苯的数字集合
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/104637/D
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int x,y;
	std::cin >> x >> y;
	
	if((x^y)==0){
		std::cout << 1 << "\n";
		return;
	}
	if((x&y)==0){
		std::cout << 1 << "\n";
		return;
	}
	
	int tmp1 = x,tmp2 = y;
	int tmp3 = x&y;
	if((tmp1^tmp3)==0){
		std::cout << 2 << "\n";
		return;
	}
	if((tmp2^tmp3)==0){
		std::cout << 2 << "\n";
		return;
	}
	if((tmp1&tmp3)==0){
		std::cout << 2 << "\n";
		return;
	}
	if((tmp2&tmp3)==0){
		std::cout << 2 << "\n";
		return;
	}
	
	tmp3 = tmp1 | tmp2;
	if((tmp1^tmp3)==0){
		std::cout << 2 << "\n";
		return;
	}
	if((tmp2^tmp3)==0){
		std::cout << 2 << "\n";
		return;
	}
	if((tmp1&tmp3)==0){
		std::cout << 2 << "\n";
		return;
	}
	if((tmp2&tmp3)==0){
		std::cout << 2 << "\n";
		return;
	}
	
	tmp3 = tmp1 ^ tmp2;
	if((tmp1^tmp3)==0){
		std::cout << 2 << "\n";
		return;
	}
	if((tmp2^tmp3)==0){
		std::cout << 2 << "\n";
		return;
	}
	if((tmp1&tmp3)==0){
		std::cout << 2 << "\n";
		return;
	}
	if((tmp2&tmp3)==0){
		std::cout << 2 << "\n";
		return;
	}
	
	tmp3 = std::gcd(tmp1,tmp2);
	if((tmp1^tmp3)==0){
		std::cout << 2 << "\n";
		return;
	}
	if((tmp2^tmp3)==0){
		std::cout << 2 << "\n";
		return;
	}
	if((tmp1&tmp3)==0){
		std::cout << 2 << "\n";
		return;
	}
	if((tmp2&tmp3)==0){
		std::cout << 2 << "\n";
		return;
	}
	
	std::cout << 3 << "\n";
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