// Problem: Tokitsukaze and Dragon's Breath
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95336/E
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,m;std::cin >> n >> m;
	
	std::vector<std::vector<int>> a(n+1,std::vector<int>(m+1));
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			std::cin >> a[i][j];
		}
	}
	
	std::vector<i64> deg(n+m+1);
	int idx = 1;
	for(int i = n;i>=1;--i){
		//起点为[i,1]
		int x = i,y = 1;
		i64 sum = 0;
		while(x>=1&&x<=n&&y>=1&&y<=m){
			sum += a[x][y];
			++x,++y;
		}
		deg[idx] = sum;
		++idx;
	}
	for(int i = 2;i<=m;++i){
		//起点为[1,i]
		int x = 1,y = i;
		i64 sum = 0;
		while(x>=1&&x<=n&&y>=1&&y<=m){
			sum += a[x][y];
			++x,++y;
		}
		deg[idx] = sum;
		++idx;
	}
	// std::cout << "idx:" << idx << "\n";
	
	std::vector<i64> ideg(n+m+1);
	int idx2 = 1;
	for(int i = n;i>=1;--i){
		//起点为[i,m]
		int x = i,y = m;
		i64 sum = 0;
		while(x>=1&&x<=n&&y>=1&&y<=m){
			sum += a[x][y];
			++x,--y;
		}
		
		ideg[idx2] = sum;
		++idx2;
	}
	for(int i = m-1;i>=1;--i){
		//起点为[1,i]
		int x = 1,y = i;
		i64 sum = 0;
		while(x>=1&&x<=n&&y>=1&&y<=m){
			sum += a[x][y];
			++x,--y;
		}
		
		ideg[idx2] = sum;
		++idx2;
	}
	
	// std::cout << "idx2:" << idx2 << "\n";
	
	std::map<std::pair<int,int>,int> map1,map2;
	idx = 1;
	for(int i = n;i>=1;--i){
		//起点为[i,1]
		map1[{i,1}] = idx++;
	}
	for(int i = 2;i<=m;++i){
		//起点为[1,i]
		map1[{1,i}] = idx++;
	}
	
	idx2 = 1;
	for(int i = n;i>=1;--i){
		//起点为[i,m]
		map2[{i,m}] = idx2++;
	}
	for(int i = m-1;i>=1;--i){
		//起点为[1,i]
		map2[{1,i}] = idx2++;
	}
	
	// for(int i = 1;i<=n+m-1;++i){
		// std::cout << "ideg[" << i << "]:" << ideg[i] << "\n";
	// }
	
	// std::cout << "idx1,idx2:" << idx << "," << idx2 << "\n";
	
	//开始暴力找答案
	i64 ans = 0;
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			int min1 = std::min(i-1,j-1);
			int x1 = i-min1,y1 = j-min1;
			
			
			int min2 = std::min(i-1,m-j);
			int x2 = i-min2,y2 = j+min2;
			
			i64 sum = deg[map1[{x1,y1}]]+ideg[map2[{x2,y2}]]-a[i][j];
			
			// if(sum==46){
				// std::cout << min2 << "\n";
				// std::cout << "i,j:" << i << "," << j << "\n";
				// std::cout << "deg[map1[{x1,y1}]]:" << deg[map1[{x1,y1}]] << "\n";
				// std::cout << "ideg[map2[{x2,y2}]]:" << ideg[map2[{x2,y2}]] << "\n";
			// }
			
			ans = std::max(ans,sum);
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