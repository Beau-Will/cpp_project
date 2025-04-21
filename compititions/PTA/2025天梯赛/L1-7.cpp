#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1000000000;
constexpr int P = 131,N = 100000;
constexpr int P1 = 1000000007,P2 = 998244353;
constexpr i64 inf2 = 1000000000000000000;

void solve(){
	int n;
	std::cin >> n;
	
	for(int i = 30; i >= 1; --i){
		i64 t = 0;
		for(int j = 1;;++j){
			t += std::pow(j,i);
			if(t==n){
				bool flag = false;
				for(int k = 1; k <= j; ++k){
					if(!flag){
						std::cout << k << "^" << i;
						flag = true;
					}else{
						std::cout << "+" << k << "^" << i;
					}
				}
				std::cout << "\n";
				return;
			}else if(t>n){
				break;
			}
		}
	}
	
	std::cout << "Impossible for " << n << ".\n";
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
