// Problem: F - ABCBA
// Contest: AtCoder - UNIQUE VISION Programming Contest 2025 Spring (AtCoder Beginner Contest 398)
// URL: https://atcoder.jp/contests/abc398/tasks/abc398_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 131;

void solve(){
	std::string s;
	std::cin >> s;
	
	std::string t = s;
	std::reverse(t.begin(),t.end());
	
	int n = s.size();
	
	s = " "+s;
	t = " "+t;
	
	std::vector<u64> p(n+5),s_hash(n+5),t_hash(n+5);
	
	p[0] = 1;
	for(int i = 1;i<=n;++i){
      s_hash[i] = s_hash[i-1]*P+s[i];
      t_hash[i] = t_hash[i-1]*P+t[i];
      p[i] = p[i-1]*P;
  }
	
	int sam = 0;
	for(int i = 1;i<=s.size();++i){
		//s:[n+1-i,n]
		//t:[1,i]
		int sl = n+1-i,sr = n;
		int tl = 1,tr = i;
		u64 querys = s_hash[sr]-s_hash[sl-1]*p[sr-sl+1];
		u64 queryt = t_hash[tr]-t_hash[tl-1]*p[tr-tl+1];
		
		if(querys==queryt){
			sam = std::max(sam,i);
		}
	}
	
	std::string ans;
	for(int i = n-sam;i>=1;--i){
		ans += s[i];
	}
	
	s += ans;
	
	std::cout << s.substr(1) << "\n";
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