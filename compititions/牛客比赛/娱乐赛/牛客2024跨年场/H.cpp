// Problem: 2025 图
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/98985/H
// Memory Limit: 1024 MB
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

struct DSU {
    int _n;
    std::vector<int> _fa,_size;
    DSU(){}
    DSU(int n){
        init(n);
    }
    void init(int n) {
        _fa.resize(n);
        std::iota(_fa.begin(),_fa.end(),0);
        _size.assign(n,1);
    }
    int find(int x) {
        if(x!=_fa[x]) {
            _fa[x] = find(_fa[x]);
        }
        return _fa[x];
    }
    bool same(int x,int y) {
        return find(x)==find(y);
    }
    bool merge(int x,int y) {
        int fx = find(x);
        int fy = find(y);
        if(fx!=fy) {
            _size[fx]+=_size[fy];
            _fa[fy] = fx;
            return true;
        }
        return false;
    }
};

void solve(){
	//22 node ,19 edges
	
	std::vector<std::vector<int>> adj(22);
	std::vector<int> indegrees(22,0);
	DSU dsu(22);
	
	for(int i = 0;i<19;++i){
		int u,v;std::cin >> u >> v;
		--u,--v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
		++indegrees[u],++indegrees[v];
		dsu.merge(u,v);
	}
	
	std::set<int> set;
	
	int cnt1 = 0,cnt2 = 0;
	bool flag = false;
	
	for(int i = 0;i<22;++i){
		if(indegrees[i]==1){
			++cnt1;
		}else if(indegrees[i]==2){
			++cnt2;
		}else{
			flag = true;
		}
		set.insert(dsu.find(i));
	}
	
	if(cnt1!=6||cnt2!=16||set.size()!=4||flag){
		std::cout << 2024 << '\n';
		return;
	}
	
	std::queue<int> q;
	std::vector<int> ans;
	std::vector<bool> vis(22,false);
	
	for(int i = 0;i<22;++i){
		if(indegrees[i]==1){
			q.emplace(i);
			ans.emplace_back(i);
			vis[i] = true;
		}
	}
	// std::cout << ans.size() << '\n';
	
	while(!q.empty()){
		auto u = q.front();
		q.pop();
		// ans.emplace_back(u);
		for(const auto &v:adj[u]){
			if(--indegrees[v]==1){
				if(!vis[v]){
					q.emplace(v);
					ans.emplace_back(v);
					vis[v] = true;
				}
			}
		}
	}
	
	// std::cout << ans.size() << '\n';
	
	std::cout << (ans.size()!=18?2024:2025) << '\n';
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