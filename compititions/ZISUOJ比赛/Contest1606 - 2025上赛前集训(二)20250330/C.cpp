#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1000000000;

void solve(){
	int n;
	std::cin >> n;
	
	std::vector<int> a(n+1);
	for(int i = 1; i <= n; ++i){
		std::cin >> a[i];
	}
	
	std::sort(a.begin()+1,a.end());
	
	int ans = *std::min_element(a.begin()+1,a.end());
	int sum = 0;
	for(int i = 1; i <= n-1; ++i){
		sum -= a[i]+sum;
		ans = std::max(ans,a[i+1]+sum);
	}
	
	std::cout << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
	std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}