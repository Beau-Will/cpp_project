// Problem: 什么是好的数组？
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/99073/B
// Memory Limit: 512 MB
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
	int n;std::cin >> n;
	
	std::vector<int> a(n);
	for(int i = 0;i<n;++i){
		std::cin >> a[i];
	}
	
	std::sort(all(a));
	
	// for(int i = 0;i<n;++i){
		// std::cout << a[i] << " \n"[i==n-1];
	// }
	
	if(a[0]==1||n==2){
		std::cout << "Yes\n";
		return;
	}
	
	std::vector<int> vis(n,false);
	int t1 = a[0],cnt_false = 0;
	for(int i = 0;i<n;++i){
		if(vis[i]) continue;
		if(a[i]%t1==0) vis[i] = true;
		cnt_false += (vis[i]?0:1);
	}
	if(cnt_false<=1){
		std::cout << "Yes\n";
		return;
	}
	
	int t2,idx;
	for(int i = 0;i<n;++i){
		if(!vis[i]){
			idx = i;
			t2 = a[i];
			break;
		}
	}
	
	int cnt_false2 = 0;
	for(int i = idx;i<n;++i){
		if(vis[i]) continue;
		if(a[i]%t2==0) vis[i] = true;
		cnt_false2 += (vis[i]?0:1);
	}
	
	std::cout << (cnt_false2?"No":"Yes") << '\n';
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int tt = 1;
	std::cin >> tt;
	for(int ti = 0;ti<tt;++ti){
		solve();
	}
	
	return 0;
}