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
	int T,S,t;
	std::cin >> T >> S >> t;
	
	if(T>35&&S==1 || S==0 &&t >= 33){
		std::cout << "Bu Tie\n";
		std::cout << T << "\n";
	}else{
		if(S==0){
			if(T>35&&t>=33){
				std::cout << "Shi Nei\n";
				std::cout << T << "\n";
			}else{
				std::cout << "Shu Shi\n";
				std::cout << t << "\n";
			}
				
		}else{
			if(T<35||t<35){
				std::cout << "Bu Re\n";
				std::cout << t << "\n";
			}
		}
	}
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
