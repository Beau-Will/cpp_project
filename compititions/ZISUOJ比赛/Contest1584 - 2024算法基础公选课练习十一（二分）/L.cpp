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
	
	int n,l;std::cin >> n >> l;
	
	std::vector<int> a(n+1,0);
	
	for(int i = 1;i<=n;++i){
		std::cin >> a[i];
	}
	
	std::sort(a.begin()+1,a.end());
	
	std::vector<i64> pre(n+1,0);
	for(int i = 1;i<=n;++i){
		pre[i] = pre[i-1]+a[i];
	}
	
	// for(int i = 1;i<=n;++i){
		// std::cout << pre[i] << " \n"[i==n];
// 		
	// }
	
	std::cout << (pre[10]-pre[4])*1000/6 << '\n';
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