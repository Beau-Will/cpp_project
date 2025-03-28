// Problem: B - Full House 3
// Contest: AtCoder - UNIQUE VISION Programming Contest 2025 Spring (AtCoder Beginner Contest 398)
// URL: https://atcoder.jp/contests/abc398/tasks/abc398_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	std::vector<int> a(7);
	for(int i = 0; i < 7; ++i){
		std::cin >> a[i];
	}
	
	for(int i = 0; i < (1<<7); ++i){
		if(__builtin_popcount(i)!=5){
			continue;
		}
		
		std::unordered_map<int,int> cnt;
		for(int j = 0; j < 7; ++j){
			if((i>>j)&1){
				++cnt[a[j]];
			}
		}
		if(cnt.size()!=2){
			continue;
		}

		if(cnt.begin()->second==2||cnt.begin()->second==3){
			std::cout << "Yes\n";
			return;
		}
	}
	
	std::cout << "No\n";
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int t = 1;
	//std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}