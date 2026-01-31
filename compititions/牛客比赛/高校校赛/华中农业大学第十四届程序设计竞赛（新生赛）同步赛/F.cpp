// Problem: 命题？组题，AC 啦！
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95480/F
// Memory Limit: 2048 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e6+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

std::vector<int> a(N,0);

void solve(){
	
	int n;std::cin >> n;
	
	for(int i = 1;i<=n;++i){
		std::cin >> a[i];
	}
	
	int ans1 = 0,ans2 = n;
	std::set<int> set;
	for(int i = 1;i<=n;++i){
		if(set.find(a[i])==set.end()){
			set.insert(a[i]);
		}else{
			set.clear();
			set.insert(a[i]);
			++ans1;
		}
	}
	if(set.size()){
		set.clear();
		++ans1;
	}
	std::cout << ans1 << ' ' << ans2 << '\n';
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