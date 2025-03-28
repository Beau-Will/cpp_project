// Problem: 构造A+B
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/97443/A
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
/*
1 5
2 4
3 3
4 2
5 1
*/
void solve(){
	int n,k;std::cin >> n >> k;
	std::cout << (k<=n-1?"YES\n":"NO\n");
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int tt = 1;
	// std::cin >> tt;
	for(int ti = 0;ti<tt;++ti){
		solve();
	}
	
	return 0;
}