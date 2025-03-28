// Problem: 小苯晨跑
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/97017/A
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
	int a,b,c,d;std::cin >> a >> b >> c >> d;
	std::set<int> set;
	set.insert(a);
	set.insert(b);
	set.insert(c);
	set.insert(d);
	std::cout << (set.size()==1?"NO\n":"YES\n");
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