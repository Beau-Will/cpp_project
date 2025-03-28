#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 2e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

std::vector<int> a(N,0);
void solve(){
	int n;std::cin >> n;
	for(int i = 1;i<=n;++i) std::cin >> a[i];
	std::priority_queue<i64,std::vector<i64>,std::greater<i64>> heap;
	for(int i = 1;i<=n;++i) heap.push(a[i]);
	i64 sum = 0;
	while(heap.size()>1){
		auto t1 = heap.top();heap.pop();
		auto t2 = heap.top();heap.pop();
		// std::cout << "t1 t2:" << t1 << ' ' << t2 << '\n';
		t1+=t2;
		sum+=t1;
		heap.push(t1);
	}
	std::cout << sum << '\n';
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