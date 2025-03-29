// Problem: D - Diagonal Separation
// Contest: AtCoder - AtCoder Beginner Contest 386
// URL: https://atcoder.jp/contests/abc386/tasks/abc386_d
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
#define push_back emplace_back
#define push emplace
#define all(v) v.begin(),v.end()


void solve(){
	int n,m;std::cin >> n >> m;
	
	std::vector<std::array<int,3>> a;
	for(int i = 0;i<m;++i){
		int x,y;std::string color;
		std::cin >> x >> y >> color;
		std::array<int,3> t = {x,y,color=="W"};
		a.emplace_back(t);
	}
	std::sort(all(a));
	std::vector<int> pre(m+1,INF);
	std::vector<int> suf(m+1,0);
	for(int i = 0;i<m;++i){
		pre[i+1] = pre[i];
		if(a[i][2]){
			pre[i+1] = std::min(pre[i+1],a[i][1]);
		}
	}
	for(int i = m-1;i>=0;--i){
		suf[i] = suf[i+1];
		if(!a[i][2]){
			suf[i] = std::max(suf[i],a[i][1]);
		}
	}
	for(int i = 0;i<m;++i){
		if(pre[i+1]<=suf[i]){
			std::cout << "No\n";
			return;
		}
	}
	std::cout << "Yes\n";
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