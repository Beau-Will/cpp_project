// Problem: 拯救奶龙
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95480/J
// Memory Limit: 2048 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 2e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

int n;

void solve(){
	std::cin >> n;
	std::vector<int> a(n),v(n),c(n);
	std::vector<int> ans(n,-1);
	for(int i = 0;i<n;++i){
		std::cin >> v[i];
	}
	for(int i = 0;i<n;++i){
		std::cin >> c[i];
	}
	for(int i = 0;i<n;++i){
		std::cin >> a[i];
	}
	
	std::priority_queue<pii,std::vector<pii>,std::greater<pii>> pq;
	std::priority_queue<pii,std::vector<pii>,std::greater<pii>> deleted;
	
	int idx = n-1;
	for(int i = n-1;i>=0;--i){
		while(idx>=i){
			pq.push(c[idx],v[idx]);
			--idx;
		}
		while(!deleted.empty()){
			auto t = deleted.top();
			pq.push(t);
			deleted.pop();
		}
		while(!pq.empty()&&pq.top().second<a[i]){
			auto t = pq.top();
			deleted.push(t);
			pq.pop();
		}
		if(!pq.empty()) ans[i] = pq.top().first;
	}
	for(int i = 0;i<n;++i) std::cout << ans[i] << " \n"[i==n-1];
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