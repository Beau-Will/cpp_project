// Problem: C. Palindromic Subsequences
// Contest: Codeforces - Codeforces Round 997 (Div. 2)
// URL: https://codeforces.com/contest/2056/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;std::cin >> n;
	
	if(n==6){
		std::cout << "1 1 2 3 1 2\n";
		return;
	}
	if(n==9){
		std::cout << "7 3 3 7 5 3 7 7 3\n";
		return;
	}
	if(n==15){
		std::cout << "15 8 8 8 15 5 8 1 15 5 8 15 15 15 8\n";
		return;
	}
	
	int t = n/3;
	
	std::vector<int> ans;
	for(int i = 1;i<=t;++i){
		if(i==1||i==t){
			ans.emplace_back(1);
		}else{
			ans.emplace_back(2);
		}
	}
	int rest = n-2*t;
	for(int i = rest;i>=1;--i){
		ans.emplace_back(i);
	}
	for(int i = 1;i<=t;++i){
		if(i==1||i==t){
			ans.emplace_back(2);
		}else{
			ans.emplace_back(1);
		}
	}
	for(int i = 0;i<ans.size();++i){
		std::cout << ans[i] << " \n"[i+1==ans.size()];
	}
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int t = 1;
	std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}