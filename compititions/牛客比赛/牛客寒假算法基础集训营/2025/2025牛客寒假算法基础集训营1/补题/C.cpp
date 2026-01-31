// Problem: 兢兢业业之移
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95323/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;std::cin >> n;
	
	std::vector<std::string> a(n);
	for(int i = 0;i<n;++i){
		std::cin >> a[i];
	}
	
	std::vector<std::array<int,4>> ans;
	
	auto work = [&](int i1,int j1,int i2,int j2){
		std::swap(a[i1][j1],a[i2][j2]);
		ans.push_back({i1+1,j1+1,i2+1,j2+1});
	};
	
	auto move = [&](int i,int j,int x,int y){
		auto movex = [&](){
			while(i<x){
				work(i,j,i+1,j);
				++i;
			}
			while(i>x){
				work(i,j,i-1,j);
				--i;
			}
		};
		auto movey = [&](){
			while(j<y){
				work(i,j,i,j+1);
				++j;
			}
			while(j>y){
				work(i,j,i,j-1);
				--j;
			}
		};
		if(i>=x){
			movey();
			movex();
		}else{
			movex();
			movey();
		}
	};
	
	int x = 0,y = 0;
	for(int i = 0;i<n;++i){
		for(int j = 0;j<n;++j){
			while(a[i][j]=='1'){
				move(i,j,x,y);
				a[x][y] = '2';
				++y;
				if(y==n/2){
					++x;
					y = 0;
				}
			}
		}
	}
	
	std::cout << ans.size() << "\n";
	for(auto &[i1,j1,i2,j2]:ans){
		std::cout << i1 << " " << j1 << " " << i2 << " " << j2 << "\n";
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