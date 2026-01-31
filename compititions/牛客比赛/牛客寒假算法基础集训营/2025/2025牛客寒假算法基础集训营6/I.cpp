// Problem: 小鸡的排列构造的checker
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95338/I
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5+5;

int a[N];

#define ls u<<1
#define rs u<<1|1

struct Node{
	int l,r;
	std::vector<int> v;
}tr[N<<2];

void pushup(Node &u,Node &l,Node &r){
	std::vector<int> tmp;
	int i = 0,j = 0;
	while(i<l.v.size()){
		while(j<r.v.size()&&l.v[i]>=r.v[j]){
			tmp.emplace_back(r.v[j++]);
		}
		tmp.emplace_back(l.v[i++]);
	}
	while(j<r.v.size()){
		tmp.emplace_back(r.v[j++]);
	}
	u.v = tmp;
}

void pushup(int u){
	pushup(tr[u],tr[ls],tr[rs]);
}

void build(int u,int l,int r){
	tr[u].l = l,tr[u].r = r;
	if(l==r){
		tr[u].v.emplace_back(a[l]);
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
		Node left = query(ls,l,r);
		Node right = query(rs,l,r);
		Node ans;
		ans.l = l,ans.r = r;
		pushup(ans,left,right);
		return ans;
	}
}

void solve(){
	int n,q;std::cin >> n >> q;
	for(int i = 1;i<=n;++i){
		std::cin >> a[i];
	}
	build(1,1,n);
	while(q--){
		int l,r,k;std::cin >> l >> r >> k;
		int t = a[k];
		auto res = query(1,l,r);
		// for(int i = 0;i<res.v.size();++i){
			// std::cout << res.v[i] << " \n"[i==res.v.size()-1];
		// }
		int idx = std::lower_bound(res.v.begin(),res.v.end(),t)-res.v.begin();
		std::cout << l+idx << "\n";
	}
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