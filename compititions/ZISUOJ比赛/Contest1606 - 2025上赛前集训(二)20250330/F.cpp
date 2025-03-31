#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1000000;

void solve(){
	int n;
	std::cin >> n;
	
	std::vector<int> a(n+1);
	for(int i = 1; i <= n; ++i){
		std::cin >> a[i];
	}
	//ai1+ai2+ai3-(r-l)
	//ai2+(ai1+l)+(ai3-r)
	std::vector<int> pre(n+1,-inf),suf(n+2,-inf);
	for(int i = 1; i <= n; ++i){
		pre[i] = std::max(pre[i-1],a[i]+i);
	}
	for(int i = n; i >= 1; --i){
		suf[i] = std::max(suf[i+1],a[i]-i);
	}
	int ans = 0;
	for(int i = 2; i <= n-1; ++i){
		ans = std::max(ans,a[i]+pre[i-1]+suf[i+1]);
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