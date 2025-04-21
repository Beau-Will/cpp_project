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
	std::string s;
	std::cin >> s;
	
	std::vector<int> w(26);
	for(int i = 0; i < 26; ++i){
		std::cin >> w[i];
	}
	
	int ans = 0;
	std::vector<int> cnt(26);
	for(int i = 0; i < s.size(); ++i){
		++cnt[s[i]-'a'];
	}
	
	for(int i = 0; i < 26; ++i){
		std::cout << cnt[i] << " \n"[i+1==26];
	}
	
	for(int i = 0; i < 26; ++i){
		ans += w[i]*cnt[i];
	}
	
	std::cout << ans << "\n";
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
