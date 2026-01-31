// Problem: 奇偶调整
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/99990/D
// Memory Limit: 1024 MB
// Time Limit: 8000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int n,m,k;std::cin >> n >> m >> k;
	
	std::vector<int> a(n);
	for(int i = 0;i<n;++i){
		std::cin >> a[i];
	}
	
	i64 ans = 0;
	
	std::priority_queue<int> q;
	for(int i = 0;i<n;++i){
		q.emplace(a[i]);
	}
	
	while(!q.empty()){
		auto t = q.top();
		q.pop();
		if(t&1){
			if(k){
				--k;
				--t;
				q.emplace(t);
			}else{
				ans += t;
			}
		}else{
			if(m){
				--m;
				t/=2;
				q.emplace(t);
			}else{
				ans += t;
			}
		}
	}
	std::cout << ans << '\n';
	
	return 0;
}