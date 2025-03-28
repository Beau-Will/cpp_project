// Problem: B. Gorilla and the Exam
// Contest: Codeforces - Hello 2025
// URL: https://codeforces.com/contest/2057/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int t = 1;
	std::cin >> t;
	for(int ti = 0;ti<t;++ti){
		int n,k;std::cin >> n >> k;
		
		std::vector<int> a(n);
		for(int i = 0;i<n;++i){
			std::cin >> a[i];
		}
		
		std::map<int,int> cnt;
		for(int i = 0;i<n;++i){
			++cnt[a[i]];
		}
		
		std::vector<std::pair<int,int>> v;
		// std::copy(cnt.begin(),cnt.end(),v.begin());
		for(const auto &[x,y]:cnt){
			v.emplace_back(x,y);
		}
		
		std::sort(v.begin(),v.end(),[&](const std::pair<int,int> &t1,const std::pair<int,int> &t2)->bool{
			return t1.second<t2.second;
		});
		// std::cout << "---\n";
		// for(auto &[x,y]:v){
			// std::cout << "[x,y]" << x << ',' << y << '\n';
		// }
		
		for(auto &[x,y]:v){
			if(y<=k&&k!=0){
				k-=y;
				y = 0;
			}
		}
		
		// std::cout << "***\n";
		// for(auto &[x,y]:v){
			// std::cout << "[x,y]" << x << ',' << y << '\n';
		// }
		
		int ans = 0;
		for(const auto &[x,y]:v){
			ans += (y!=0);
		}
		
		std::cout << (ans==0?1:ans) << '\n';
	}
	
	return 0;
}