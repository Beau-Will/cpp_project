// Problem: 1or0
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/100253/E
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5+5;
std::string s;

struct Node{
	i64 l,r,len,cnt1,res;
}tr[N*4];

#define ls u<<1
#define rs u<<1|1

void pushup(Node &root,Node &lroot,Node &rroot){
	root.l = lroot.l;
	root.r = rroot.r;
	root.len = root.r-root.l+1;
	root.cnt1 = lroot.cnt1+rroot.cnt1;
	root.res = lroot.res+lroot.cnt1*rroot.len+rroot.res;
}

void pushup(int u){
	pushup(tr[u],tr[ls],tr[rs]);
}

void build(int u,int l,int r){
	tr[u].l = l,tr[u].r = r,tr[u].len = r-l+1;
	if(l==r){
		tr[u].cnt1 = (s[l]=='1');
		tr[u].res = (s[l]=='1');
		// std::cout << tr[u].cnt1 << ' ' << tr[u].res << '\n';
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
	if(r<=mid){
		return query(ls,l,r);
	}else if(l>mid){
		return query(rs,l,r);
	}else{
		Node ans;
		auto t1 = query(ls,l,r);
		auto t2 = query(rs,l,r);
		// pushup(ans,t1,t2);
		// ans.l = l,ans.r = r;
		// ans.cnt1 = t1.cnt1+t2.cnt1;
		// ans.res = t1.res+t1.cnt1*t2.len+t2.res;
		pushup(ans,t1,t2);
		return ans;
	}
}

void solve(){
	int n;std::cin >> n;
	std::cin >> s;
	s = " "+s;
	// std::cout << s << '\n';
	build(1,1,n);
	int q;std::cin >> q;
	while(q--){
		int l,r;std::cin >> l >> r;
		auto t = query(1,l,r);
		std::cout << t.res << '\n';
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