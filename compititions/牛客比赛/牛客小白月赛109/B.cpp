// Problem: 菲菲姐的游戏
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/99785/B
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int n,m,k;std::cin >> n >> m >> k;
	
	std::vector<int> a(n+1);
	for(int i = 1;i<=n;++i){
		std::cin >> a[i];
	}
	
	std::vector<int> pre(n+1),suf(n+2);
	for(int i = 1;i<=n;++i){
		pre[i] = std::max(pre[i-1],a[i]);
	}
	for(int i = n;i>=1;--i){
		suf[i] = std::max(suf[i+1],a[i]);
	}
	
	bool flag = false;
	for(int i = 1;i<=n-1;++i){
		if(pre[i]>suf[i+1]){
			flag = true;
			break;
		}
	}
	std::cout << (flag?"Yes":"No") << '\n';
	
	return 0;
}