#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e4+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

int n,k;



void solve(){
	std::cin >> n;
	std::vector<pii> a(n);
	for(int i = 0;i<n;++i){
		std::cin >> a[i].second;
		a[i].first = std::abs(a[i].second);
	}
	
	std::sort(all(a));
	
	std::cin >> k;
	for(int i = 0;i<k;++i){
		int x;
		std::cin >> x;
		pii query = {std::abs(x),x};
		if(std::binary_search(all(a),query)){
			std::cout << std::lower_bound(all(a),query)-a.begin()+1 << '\n';
		}else{
			std::cout << -1 << '\n';
		}
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