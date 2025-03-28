// Problem: 小苯过马路
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/97017/B
// Memory Limit: 512 MB
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
	int x,y,k,t;std::string light;//x是红灯时长，y是绿灯时长
	std::cin >> x >> y >> k >> t >> light;
	if(light=="G"){//当前是绿灯
		if(t<=k){
			std::cout << t << '\n';
		}else{
			std::cout << k+x+t << '\n';
		}
	}else{//当前是红灯
		std::cout << k+t << '\n';
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