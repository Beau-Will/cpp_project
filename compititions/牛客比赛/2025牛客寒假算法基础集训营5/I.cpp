// Problem: 小L的数学题
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95337/I
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

std::vector<i64> f;

void solve(){
	i64 n,m;
	std::cin >> n >> m;
	if(n!=0&&m!=0&&m%n==0){
		std::cout << "Yes\n";
		return;
	}
	if(n==0&&m!=0||n!=0&&m==0){
		std::cout << "No\n";
		return;
	}
	if(n==0&&m==0){
		std::cout << "Yes\n";
		return;
	}
	std::cout << (std::binary_search(f.begin(),f.end(),n)?"No":"Yes") << "\n";
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	f.push_back(0);
	i64 cur = 1;
	while(cur<=i64(1e9)){
		f.push_back(cur);
		cur*=2;
	}
	
	int t = 1;
	std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}