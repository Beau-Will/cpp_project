#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1'000'000'000;

void solve(){
	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	for(int i = 0; i < n; ++i){
		std::cin >> a[i];
	}
	
	int min = a[0],max = inf;
	int ans = 0;
	for(int i = 1; i < n; ++i){
		min = std::min(min,a[i]);
		if(a[i] > min && a[i] < max){
			++ans;
			max = a[i];
		}
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