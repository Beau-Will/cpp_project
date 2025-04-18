#include <bits/stdc++.h>

//using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int N = 200005,inf = 1000000000;
constexpr int P1 = 1000000007,P2 = 998244353;
constexpr int P = 131;

void solve(){
	int n;
	std::cin >> n;
	
	std::vector<double> a(n);
	for(int i = 0; i < n; ++i){
		std::cin >> a[i];
	}
	
	std::vector<int> cnt(n);
	int idx,num;
	while(std::cin >> idx >> num){
		if(idx==0){
			break;
		}
		--idx;
		cnt[idx] += num;
	}
	
	for(int i = 0; i < n; ++i){
		std::cout << cnt[i] << "\n";
	}
	double ans = 0;
	for(int i = 0; i < n; ++i){
		ans += cnt[i]*a[i];
	}
	
	std::cout << std::fixed << std::setprecision(2) << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
//	std::cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
