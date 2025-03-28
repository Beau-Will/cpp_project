// Problem: 预知
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/99458/D
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
	int n;std::cin >> n;
	
	std::vector<i64> a(n);
	for(int i = 0;i<n;++i){
		std::cin >> a[i];
	}
	
	if(n==1){
		std::cout << -1 << '\n';
		return;
	}
	
	i64 max = 0,maxidx = -1;
	for(int i = 0;i<n;++i){
		if(a[i]>max){
			max = a[i];
			maxidx = i;
		}
	}
	
	std::set<i64> set;
	a[maxidx] = 1;
	for(int i = 0;i<n;++i){
		set.insert(a[i]);
	}
	
	if(set.size()==1){
		std::cout << max-1 << '\n';
		return;
	}
	std::cout << max << '\n';
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