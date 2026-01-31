// Problem: 数独数组
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/100253/B
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;std::cin >> n;
	if(n<9){
		std::cout << "NO\n";
		return;
	}
	
	std::vector<int> a(n);
	for(int i = 0;i<n;++i){
		std::cin >> a[i];
	}
	
	std::vector<int> cnt(10);
	for(int i = 0;i<n;++i){
		++cnt[a[i]];
	}
	int t = n/9;
	for(int i = 1;i<=9;++i){
		if(cnt[i]<t){
			std::cout << "NO\n";
			return;
		}else if(cnt[i]>t+1){
            std::cout << "NO\n";
            return;
        }
	}
	std::cout << "YES\n";
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