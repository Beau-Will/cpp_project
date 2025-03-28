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
	
	int n;std::cin >> n;
	
	std::vector<int> a(n);
	for(int i = 0;i<n;++i){
		std::cin >> a[i];
	}
	
	std::sort(all(a));
	
	int m;std::cin >> m;
	while(m--){
		int query;std::cin >> query;
		if(std::binary_search(all(a),query)){
			std::cout << query << '\n';
		}else{
			if(std::lower_bound(all(a),query)==a.end()){
				std::cout << a.back() << '\n';
			}else if(std::lower_bound(all(a),query)==a.begin()){
				std::cout << a.front() << '\n';
			}else{
				int front = a[std::lower_bound(all(a),query)-a.begin()-1];
				int back = a[std::lower_bound(all(a),query)-a.begin()];
				if(std::abs(query-front)<=std::abs(query-back)){
					std::cout << front << '\n';
				}else{
					std::cout << back << '\n';
				}
			}
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