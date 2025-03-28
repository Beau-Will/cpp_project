// Problem: 2. 存储晶体【算法赛】
// Contest: Lanqiao - 第 23 场 小白入门赛
// URL: https://www.lanqiao.cn/problems/20056/learning/?contest_id=224
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

void solve(){
	int a,b;std::cin >> a >> b;
	int n;std::cin >> n;
	while(n--){
		int c;std::cin >> c;
		std::cout << (c*c<=a*a+b*b?"YES\n":"NO\n");
	}
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