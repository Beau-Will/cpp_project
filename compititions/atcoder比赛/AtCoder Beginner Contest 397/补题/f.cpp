// Problem: F - Variety Split Hard
// Contest: AtCoder - OMRON Corporation Programming Contest 2025 (AtCoder Beginner Contest 397)
// URL: https://atcoder.jp/contests/abc397/tasks/abc397_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;std::cin >> n;
	
	std::vector<int> a(n+1);
	for(int i = 1;i<=n;++i){
		std::cin >> a[i];
	}
	
	std::vector<int> pre(n+1),suf(n+2);
	std::vector<int> vis(n+1),last(n+1);
	
	for(int i = 1;i<=n;++i){
		last[i] = vis[a[i]];
		pre[i] = pre[i-1];
		if(!vis[a[i]]){
			++pre[i];
		}
		vis[a[i]] = i;
	}
	
	vis.assign(vis.size(),0);
	
	for(int i = n;i>=1;--i){
		suf[i] = suf[i+1];
		if(!vis[a[i]]){
			++suf[i];
		}
		vis[a[i]] = i;
	}
	
	std::vector<int> tr((n+1)<<2),tag((n+1)<<2);
	
	auto add = [&](auto &&self,int l,int r,int u,int ml,int mr,int x)->void{
		if(ml<=l&&mr>=r){
			tr[u] += x;
			tag[u] += x;
			return;
		}
		
		tag[u<<1] += tag[u],tr[u<<1] += tag[u];
		tag[u<<1|1] += tag[u],tr[u<<1|1] += tag[u];
		tag[u] = 0;
		
		int mid = (l+r)>>1;
		if(ml<=mid){
			self(self,l,mid,u<<1,ml,mr,x);
		}
		if(mr>mid){
			self(self,mid+1,r,u<<1|1,ml,mr,x);
		}
		tr[u] = std::max(tr[u<<1],tr[u<<1|1]);
	};
	
	int ans = 0;
	
	for(int i = 1;i<=n-1;++i){
		ans = std::max(ans,suf[i+1]+tr[1]);
		add(add,1,n,1,i,i,pre[i]);
		add(add,1,n,1,last[i+1],i,1);
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