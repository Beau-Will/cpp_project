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
	
	int n,m;std::cin >> n >> m;
	
	std::vector<i64> a(n);
	
	for(int i = 0;i<n;++i){
		std::cin >> a[i];
	}
	
	std::sort(all(a));
	
	i64 low = 0,high = i64(1e9);
	
	auto check = [&](i64 x) ->bool{
		i64 cnt = 1,last = a[0];
		for(int i = 1;i<n;++i){
			if(a[i]-last>=x){
				++cnt;
				last = a[i];
			}
			// std::cout << "a[i],last:" << a[i] << ' ' << last << '\n';
		}
		// std::cout << "---\n";
		return cnt>=m;
	};
	
	while(low<high){
		i64 mid = (low+high+1)/2;
		if(check(mid)){
			low = mid;
		}else{
			high = mid-1;
		}
	}
	
	std::cout << low << '\n';
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