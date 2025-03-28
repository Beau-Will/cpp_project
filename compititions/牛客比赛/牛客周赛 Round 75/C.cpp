#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5+5,INF = 0x3f3f3f3f,P = 1e9+7;

/*
1 2 3
3 2 1
2 1 3 ×
*/

std::vector<int> fac(N);

void pre_process(){
	fac[1] = 1;
	for(int i = 2;i<=1e5;++i){
		fac[i] = i64(fac[i-1])*i%P;
	}
}

void solve(){
	int n;std::cin >> n;
	if(n&1){//有且仅有奇数开头这一种情况
		std::cout << i64(fac[n/2+1])*fac[n/2]%P << '\n';
	}else{
		std::cout << (i64(fac[n/2])*fac[n/2]%P)*2%P << '\n';
	}
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	pre_process();
	
	int t = 1;
	// std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}