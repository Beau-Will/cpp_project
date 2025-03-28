#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int l,r;std::cin >> l >> r;
	int len = r-l+1;
	if(len&1){
		if(l%2==0){
			std::cout << len/2+1 << '\n';
		}else{
			std::cout << len/2 << '\n';
		}
	}else{
		std::cout << len/2 << '\n';
	}
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int t = 1;
	// std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}