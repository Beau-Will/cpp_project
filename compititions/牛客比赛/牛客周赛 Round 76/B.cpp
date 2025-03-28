// Problem: 串串香
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/99990/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int n;std::cin >> n;
	std::string s;std::cin >> s;
	std::vector<int> cnt(26);
	for(int i = 0;i<s.size();++i){
		++cnt[s[i]-'a'];
	}
	int max = 0,maxidx = -1;
	for(int i = 0;i<cnt.size();++i){
		if(cnt[i]>max){
			max = cnt[i];
			maxidx = i;
		}
	}
	
	char ans = 'a'+maxidx;
	std::cout << ans << '\n';
	
	return 0;
}