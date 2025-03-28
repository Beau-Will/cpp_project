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
	int l,n,m;
	
	while(std::cin >> l >> n >> m){
		
		std::vector<int> a(n+2);
		
		int diff = -1;
		
		a[0] = 0;
		for(int i = 1;i<=n;++i){
			std::cin >> a[i];
		}
		a[n+1] = l;
		
		std::sort(all(a));
		
		for(int i = 1;i<=n+1;++i){
			diff = std::max(diff,a[i]-a[i-1]);
		}
		
		
		auto check = [&](int x)->bool{
			int cnt = 0;
			int cur = 0;
			for(int i = 1;i<=n;++i){
				if(x>=a[i]-a[cur]&&x<a[i+1]-a[cur]){
					++cnt;
					cur = i;
				}
			}
			++cnt;
			return cnt<=m;
		};
		
		int low = diff,high = int(1e5);
		while(low<high){
			int mid = (low+high)/2;
			
			if(check(mid)){
				high = mid;
			}else{
				low = mid+1;
			}
		}
		std::cout << low << '\n';
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