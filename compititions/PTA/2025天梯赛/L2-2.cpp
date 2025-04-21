#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1000000000;
constexpr int P = 131,N = 100000;
constexpr int P1 = 1000000007,P2 = 998244353;
constexpr i64 inf2 = 1000000000000000000;

struct Node{
	int x1,y1;
	int x2,y2;
	int x3,y3;
	
	bool operator < (const Node &t) const{
		if(y1!=t.y1){
			return y1 < t.y1;
		}
		if(x1!=t.x1){
			return x1 < t.x1;
		}
		if(y2!=t.y2){
			return y2 < t.y2;
		}
		if(x2!=t.x2){
			return x2 < t.x2;
		}
		if(y3!=t.y3){
			return y3 < t.y3;
		}
		return x3 < t.x3;
	}
};

void solve(){
	int n;
	std::cin >> n;
	
	std::vector<std::pair<int,int>> p(n);
	for(int i = 0; i < n; ++i){
		std::cin >> p[i].first >> p[i].second;
	}
	
	std::vector<std::vector<int>> map(3);
	for(int i = 0; i < n; ++i){
		map[p[i].second].push_back(p[i].first);
	}
	
	for(int i = 0; i < 3; ++i){
		std::sort(map[i].begin(),map[i].end());
		map[i].erase(std::unique(map[i].begin(),map[i].end()),map[i].end());
	}
	
	std::vector<bool> vis(2000002);
	for(int i = 0; i < map[2].size(); ++i){
		vis[map[2][i]+1000000] = true;
	}
	
//	std::vector<Node> ans;
	
//	std::set<std::array<std::pair<int,int>,3>> ans;
	
	std::vector<std::array<std::pair<int,int>,3>> ans;
	
	for(int i = 0; i < map[0].size(); ++i){
		int x1 = map[0][i],y1 = 0;
		for(int j = 0; j < map[1].size(); ++j){
			int x2 = map[1][j],y2 = 1;
			
			int diff = x2-x1;
//			auto it = std::lower_bound(map[2].begin(),map[2].end(),x2+diff);
			if(vis[x2+diff+1000000]){//*it==x2+diff){
//				ans.push_back({x1,y1,x2,y2,*it,2});
				std::array<std::pair<int,int>,3> t;
				t[0] = {x1,y1};
				t[1] = {x2,y2};
				t[2] = {x2+diff,2};
				
				ans.push_back(t);
//				ans.insert(t);
//				std::cout << "[" << x1 << ", " << 0 << "]" << "[" << x2 << ", " << 1 << "]" << "[" << *it << ", " << 2 << "]" << "\n";
//				++ans;
			}
			
//			int cnt = std::upper_bound(map[2].begin(),map[2].end(),x2+diff)-
//					  std::lower_bound(map[2].begin(),map[2].end(),x2+diff);
//			ans += cnt;
		}
	}
	
	std::sort(ans.begin(),ans.end());
//	std::sort(ans.begin(),ans.end(),[&](auto &t1,auto &t2){
//		if(t1[0].first!=t2[0].first){
//			return t1[0].first < t2[0].first;
//		}
//		if(t1[1].first!=t2[1].first){
//			return t1[1].first < t2[1].first;
//		}
//		return t1[2].first < t2[2].first;
//	});
	
	ans.erase(std::unique(ans.begin(),ans.end()),ans.end());
	
	
	for(auto &t:ans){
		int x1 = t[0].first,y1 = t[0].second;
		int x2 = t[1].first,y2 = t[1].second;
		int x3 = t[2].first,y3 = t[2].second;
		
		std::cout << "[" << x1 << ", " << y1 << "] " << "[" << x2 << ", " << y2 << "] " << "[" << x3 << ", " << y3 << "]" << "\n";
	}
	
//	for(auto [[x1,y1],[x2,y2],[x3,y3]]:ans){
//		std::cout << "1\n";
//	}
	
//	std::sort(ans.begin(),ans.end());
//	
//	ans.erase(std::unique(ans.begin(),ans.end()),ans.end());
	
//	for(int i = 0; i < ans.size(); ++i){
//		std::cout << "[" << ans[i].x1 << ", " << ans[i].y1 << "] " << "[" << ans[i].x2 << ", " << ans[i].y2 << "] " << "[" << ans[i].x3 << ", " << ans[i].y3 << "]" << "\n";
//	}
//	std::cout << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
//	std::cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
