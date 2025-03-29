// Problem: A. Tender Carpenter
// Contest: Codeforces - Good Bye 2024: 2025 is NEAR
// URL: https://codeforces.com/contest/2053/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define push_back emplace_back
#define push emplace
#define all(v) v.begin(),v.end()

void solve(){
	int n;std::cin >> n;
	
	std::vector<int> a(n);
	for(int i = 0;i<n;++i){
		std::cin >> a[i];
	}
	
	for(int i = 0;i<n-1;++i){
		if(a[i+1]>a[i]/2&&a[i+1]<a[i]*2||a[i]>a[i+1]/2&&a[i]<a[i+1]*2){
			std::cout << "YES\n";
			return;
		}
	}
	std::cout << "NO\n";
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int tt = 1;
	std::cin >> tt;
	for(int ti = 0;ti<tt;++ti){
		solve();
	}
	
	return 0;
}