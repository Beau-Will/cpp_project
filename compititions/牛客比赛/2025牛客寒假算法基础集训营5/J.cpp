// Problem: 小L的汽车行驶问题
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95337/J
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;
//0 1 2分别代表油门、刹车、离合
void solve(){
	int n;std::cin >> n;
	
	std::string s;std::cin >> s;
	i64 ans = 0,cur = 0;
	for(int i = 0;i<n;++i){
		if(s[i]=='0'){
			cur += 10;
			ans += cur;
		}else if(s[i]=='1'){
			cur -= 5;
			cur = std::max(0LL,cur);
			ans += cur;
		}else if(s[i]=='2'){
			ans += std::max(0LL,cur-10);
		}
	}
	std::cout << ans << "\n";
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