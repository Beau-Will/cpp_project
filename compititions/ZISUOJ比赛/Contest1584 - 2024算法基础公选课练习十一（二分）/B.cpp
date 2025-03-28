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
	
	int ans = 0;
	for(int i = 0;i<n-2;++i){
		for(int j = i+1;j<n-1;++j){
			int query = -a[i]-a[j];
			if(std::binary_search(a.begin()+j+1,a.end(),query)){
				int end_idx = std::upper_bound(a.begin()+1+j,a.end(),query)-a.begin();
				int start_idx = std::lower_bound(a.begin()+1+j,a.end(),query)-a.begin();
				ans += end_idx-start_idx;
			}
		}
	}
	std::cout << ans << '\n';
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