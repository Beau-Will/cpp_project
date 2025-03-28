// Problem: D. Equalization
// Contest: Codeforces - Educational Codeforces Round 176 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2075/problem/D
// Memory Limit: 256 MB
// Time Limit: 3500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	i64 x,y;std::cin >> x >> y;
	
	std::vector<i64> xi,yi;
	xi.push_back(x);
	yi.push_back(y);
	int tmp = x;
	while(tmp){
		tmp /= 2;
		xi.push_back(tmp);
	}
	tmp = y;
	while(tmp){
		tmp /= 2;
		yi.push_back(tmp);
	}
	
	i64 ans = 1e18;
	for(int i = 0;i<xi.size();++i){
		int idx = std::lower_bound(yi.begin(),yi.end(),xi[i],std::greater<i64>())-yi.begin();
		if(yi[idx]!=xi[i]) continue;
		// std::cout << "i,idx:" << i << "," << idx << "\n";
		// std::cout << "xi[" << i << "]:" << xi[i] << "\n";
		// std::cout << "yi[" << idx << "]:" << yi[idx] << "\n";
		
		// i64 t = std::pow(2LL,i)+std::pow(2LL,idx);
		
		i64 t = 0;
		
		if(i==0){
			if(idx==0){
				t = 0;
			}else{
				t = std::pow(2LL,idx);
			}
		}else{
			if(idx==0){
				
			}
		}
		
		
		ans = std::min(ans,t);
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