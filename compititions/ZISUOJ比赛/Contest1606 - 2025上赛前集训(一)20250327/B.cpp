#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,q;
	std::cin >> n >> q;
	
	std::vector<int> a(n+1);
	for(int i = 1; i <= n; ++i){
		std::cin >> a[i];
	}
	
	std::vector<i64> pre(n+1);
	for(int i = 1; i <= n; ++i){
		pre[i] = pre[i-1]+a[i];
	}
	
	bool isOdd = pre[n]&1;
	
	while(q--){
		int l,r,k;
		std::cin >> l >> r >> k;
		
		if(((pre[r]-pre[l-1])&1) == ((k*(r-l+1))&1)){
			std::cout << (isOdd?"YES\n":"NO\n");
		}else{
			std::cout << (isOdd?"NO\n":"YES\n");
		}
	}
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