// Problem: 井然有序之窗
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95323/H
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

struct Node{
	int l,r;
	int idx;
};

void solve(){
	int n;std::cin >> n;
	
	std::vector<Node> a(n+1);
	for(int i = 1;i<=n;++i){
		std::cin >> a[i].l >> a[i].r;
		a[i].idx = i;
	}
	
	std::sort(a.begin()+1,a.end(),[&](auto t1,auto t2)->bool{
		// int len1 = t1.r-t1.l+1;
		// int len2 = t2.r-t2.l+1;
		// if(len1!=len2) return len1 < len2;
		// return t1.l < t2.l;
// 		return t1.l < t2.l || (t1.l==t2.l&&t1.r<t2.r);
        return t1.r < t2.r || (t1.r==t2.r&&t1.l<t2.l);
	});
	
	// std::cout << "after sorted:\n";
// 	
	// for(int i = 1;i<=n;++i){
		// std::cout << "[l,r]:" << a[i].l << ',' << a[i].r << '\n';
	// }
	
	std::vector<int> ans(n+1,-1);
	// std::vector<bool> vis(n+1,false);
	std::set<int> set;
	for(int i = 1;i<=n;++i){
		set.insert(i);
	}
	
	for(int i = 1;i<=n;++i){
		bool isok = false;
		int x = *set.lower_bound(a[i].l);
		if(x>a[i].r){
			std::cout << -1 << '\n';
			return;
		}
		ans[a[i].idx] = x;
		set.erase(x);
	}
	
	for(int i = 1;i<=n;++i){
		std::cout << ans[i] << " \n"[i==n];
	}
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