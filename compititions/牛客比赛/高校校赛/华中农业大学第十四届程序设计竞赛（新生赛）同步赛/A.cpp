// Problem: 大一也是一年级
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95480/A
// Memory Limit: 2048 MB
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

void solve(){
	int a,b;std::cin >> a >> b;
	if(a>b){
		std::cout << ">\n";
	}else if(a==b){
		std::cout << "=\n";
	}else{
		std::cout << "<\n";
	}
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