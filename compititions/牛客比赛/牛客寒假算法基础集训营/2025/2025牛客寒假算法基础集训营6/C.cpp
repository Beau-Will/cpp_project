// Problem: 数列之和
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95338/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;
using pii = std::pair<i64,i64>;

constexpr int N = 1e6+5;

std::vector<i64> a;


void pre(){
	i64 cur = 4;
	while(cur<=2e18){
		a.push_back(cur);
		cur *= 2;
	}
}

void solve(){
	i64 k;std::cin >> k;
	i64 cnt = 0,idx = -1;
	for(int i = 0;i<a.size();++i){
		if(a[i]<=2*k){
			++cnt;
			idx = i;
		}else{
			break;
		}
	}
	if(2*k+2*cnt>=a[idx+1]){
		std::cout << 2*k+2*cnt+2 << "\n";
	}else{
		std::cout << 2*k+2*cnt << "\n";
	}
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	pre();
	
	int t = 1;
	std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}