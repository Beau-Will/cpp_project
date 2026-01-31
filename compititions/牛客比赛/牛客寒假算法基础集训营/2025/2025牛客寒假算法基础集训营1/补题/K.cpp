// Problem: 硝基甲苯之魇
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95323/K
// Memory Limit: 512 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5+5;

int a[N];
int pre[N];

#define ls u<<1
#define rs u<<1|1

struct Node{
	int l,r;
	int gcd;
}tr[N<<2];

void pushup(Node &u,Node &l,Node &r){
	u.gcd = std::gcd(l.gcd,r.gcd);
}

void pushup(int u){
	pushup(tr[u],tr[ls],tr[rs]);
}

void build(int u,int l,int r){
	tr[u].l = l,tr[u].r = r;
	if(l==r){
		tr[u].gcd = a[l];
		return;
	}
	int mid = (l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(u);
}

Node query(int u,int l,int r){
	if(tr[u].l>=l&&tr[u].r<=r){
		return tr[u];
	}
	int mid = (tr[u].l+tr[u].r)>>1;
	if(mid<l){
		return query(rs,l,r);
	}else if(mid>=r){
		return query(ls,l,r);
	}else{
		Node ans;
		ans.l = l,ans.r = r;
		auto left = query(ls,l,r);
		auto right = query(rs,l,r);
		pushup(ans,left,right);
		return ans;
	}
}

void solve(){
	int n;std::cin >> n;
	
	std::map<int,std::vector<int>> map;
	map[0].push_back(0);
	
	for(int i = 1;i<=n;++i){
		std::cin >> a[i];
		pre[i] = pre[i-1]^a[i];
		map[pre[i]].push_back(i);
	}
	
	build(1,1,n);
	
	i64 ans = 0;
	for(int i = 1;i<=n;++i){
		int j = i-1;
		while(j>=1){
			//[l,j]
			int gcd = query(1,j,i).gcd;
			int low = 1,high = j;
			while(low<high){
				int mid = (low+high)>>1;
				int tmp = query(1,mid,i).gcd;
				if(tmp==gcd){
					high = mid;
				}else{
					low = mid+1;
				}
			}
			auto &v = map[gcd^pre[i]];
			int lo = std::lower_bound(v.begin(),v.end(),j-1)-v.begin();
			int hi = std::lower_bound(v.begin(),v.end(),i)-v.begin();
			ans += hi - lo;
			j = low - 1;
		}
	}
	std::cout << ans << "\n";
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int t = 1;
	std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}