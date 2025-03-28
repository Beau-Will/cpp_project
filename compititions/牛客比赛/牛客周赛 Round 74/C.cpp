// Problem: 小数字
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/99458/C
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
#define push_back emplace_back
#define push emplace
#define all(v) v.begin(),v.end()

void solve(){
	i64 n,m;std::cin >> n >> m;
	while(m>0&&n>=2){
		--m;
		if(n>=4){
			n = std::ceil(std::sqrt(n));
		}else{
			n = (n+1)/2;
		}
	}
	n-=m;
	std::cout << n << '\n';
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