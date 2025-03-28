// Problem: 猪猪养成计划1
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/99785/C
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int n,q;std::cin >> n >> q;

	std::vector<int> ans(n+2);
	int cnt = 1;
	std::set<int> set;
	
	for(int i = 0;i<=n+1;++i){
		set.insert(i);
	}
	
	for(int i = 0;i<q;++i){
		int op,l,r,x;std::cin >> op;
		if(op==1){
			std::cin >> l >> r;
			int x = *set.lower_bound(l);
			while(x<=r){
				ans[x] = cnt++;
				set.erase(x);
				x = *set.lower_bound(x);
			}
		}else{
			std::cin >> x;
			std::cout << ans[x] << '\n';
		}
	}
	
	return 0;
}