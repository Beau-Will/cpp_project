// Problem: B - Calculator
// Contest: AtCoder - AtCoder Beginner Contest 386
// URL: https://atcoder.jp/contests/abc386/tasks/abc386_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
	std::string s;std::cin >> s;
	int ans = 0;
	bool flag = false;
	int idx = -1;
	for(int i = 0;i<s.size();++i){
		if(s[i]!='0'){
			if(flag){
				flag = false;
				ans+=(i-idx+1)/2;
			}
			++ans;
		}else{
			if(!flag){
				flag = true;
				idx = i;
			}
		}
	}
	if(flag){
		flag = false;
		ans+=(s.size()+1-idx)/2;
	}
	std::cout << ans << '\n';
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int tt = 1;
	// std::cin >> tt;
	for(int ti = 0;ti<tt;++ti){
		solve();
	}
	
	return 0;
}