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
	auto a = std::vector(10,std::vector<int>(10));
	for(int i = 1; i <= 9; ++i){
		for(int j = 1; j <= 9; ++j){
			std::cin >> a[i][j];
		}
	}
	
	auto check = [&](const std::set<int> &set){
		if(set.size()!=9){
			return false;
		}
		int min = *set.begin();
		int max = *set.rbegin();
		if(min!=1||max!=9){
			return false;
		}
		return true;
	};
	
	for(int i = 1; i <= 9; ++i){
		std::set<int> set;
		for(int j = 1; j <= 9; ++j){
			set.insert(a[i][j]);
		}
		if(!check(set)){
			std::cout << "0\n";
			return;
		}
	}
	
	for(int j = 1; j <= 9; ++j){
		std::set<int> set;
		for(int i = 1; i <= 9; ++i){
			set.insert(a[i][j]);
		}
		if(!check(set)){
			std::cout << "0\n";
			return;
		}
	}
	
	std::vector<int> st1 = {0,1,1,1,4,4,4,7,7,7};
	std::vector<int> st2 = {0,1,4,7,1,4,7,1,4,7};
	for(int k = 1; k <= 9; ++k){
		std::set<int> set;
		for(int i = st1[k]; i < st1[k]+3; ++i){
			for(int j = st2[k]; j < st2[k]+3; ++j){
				set.insert(a[i][j]);
			}
		}
		if(!check(set)){
			std::cout << "0\n";
			return;
		}
	}
	
	std::cout << "1\n";
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
