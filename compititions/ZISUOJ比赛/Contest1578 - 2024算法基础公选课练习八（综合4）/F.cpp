#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 2e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()

int n,m;

struct DSU {
    int _n;
    std::vector<int> _fa,_size,_max,_min;
    DSU(){}
    DSU(int n){
        init(n);
    }
    void init(int n) {
        _fa.resize(n);
        _max.resize(n);
        _min.resize(n);
        std::iota(_fa.begin(),_fa.end(),0);
        std::iota(_max.begin(),_max.end(),0);
        std::iota(_min.begin(),_min.end(),0);
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
            _size[fx] += _size[fy];
            _fa[fy] = fx;
            _min[fx] = std::min(_min[fx],_min[fy]);
            _max[fx] = std::max(_max[fx],_max[fy]);
            return true;
        }
        return false;
    }
};

std::vector<bool> vis(N,false);

void solve(){
	std::cin >> n >> m;
	DSU dsu(n+5);
	for(int i = 0;i<m;++i){
		int u,v;std::cin >> u >> v;
		dsu.merge(u,v);
	}
	int cur_fa = 0,cur_min = 0,cur_max = 0;
	int ans = 0;
	for(int i = 1;i<=n;++i){
		if(vis[i]) continue;
		cur_fa = dsu.find(i);
		cur_min = dsu._min[cur_fa];
		cur_max = dsu._max[cur_fa];
		for(int j = cur_min;j<=cur_max;++j){
			if(!vis[j]){
				int j_fa = dsu.find(j);
				if(cur_fa!=j_fa){
					dsu.merge(cur_fa,j_fa);
					++ans;
					cur_max = dsu._max[cur_fa];
				}
				vis[j] = true;
			}
		}
	}
	std::cout << ans << '\n';
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int tt = 1;
	// std::cin >> tt;
	for(int ti = 0;ti<tt;++ti){
		solve();
	}
	
	return 0;
}