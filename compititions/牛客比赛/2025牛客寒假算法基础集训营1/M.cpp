// Problem: 数值膨胀之美
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95323/M
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5+5;



void solve(){
	int n;std::cin >> n;
	
	std::vector<int> a(n+1);
	for(int i = 1;i<=n;++i){
		std::cin >> a[i];
	}
	
	std::vector<std::vector<int>> st1(n+1,std::vector<int>(std::floor(std::log2(n))+1,0));
	std::vector<std::vector<int>> st2(n+1,std::vector<int>(std::floor(std::log2(n))+1,0));
	
	for(int i = 1;i<=n;++i){
		st1[i][0] = a[i];
		st2[i][0] = a[i];
	}
	
	for(int j = 1;(1<<j)<=n;++j){
		for(int i = 1;i+(1<<j)-1<=n;++i){
			st1[i][j] = std::max(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
		}
	}
	
	for(int j = 1;(1<<j)<=n;++j){
		for(int i = 1;i+(1<<j)-1<=n;++i){
			st2[i][j] = std::min(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
		}
	}
	
	auto query = [&](int l,int r)->std::pair<int,int>{
		std::pair<int,int> res;
		int k = std::floor(std::log2(r-l+1));
		// std::cout << std::max(st[l][k],st[r-(1<<k)+1][k]) << '\n';
		res.first = std::max(st1[l][k],st1[r-(1<<k)+1][k]);
		res.second = std::min(st2[l][k],st2[r-(1<<k)+1][k]);
		return res;
	};
	
	auto tmp = query(1,n);
	int ans = INT_MAX;
	
	int min = 0x3f3f3f3f,minidx = -1;
	for(int i = 1;i<=n;++i){
		if(a[i]<min){
			min = a[i];
			minidx = i;
		}
	}
	
	for(int i = 1;i<=minidx;++i){
		//[l,r] = [i,minidx]
		auto tmp1 = query(i,minidx);
		int min_t = tmp1.second*2;
		int max_t = tmp1.first*2;
		if(i>1){
			auto tmp2 = query(1,i-1);
			min_t = std::min(min_t,tmp2.second);
			max_t = std::max(max_t,tmp2.first);
		}
		if(minidx<n){
			auto tmp3 = query(minidx+1,n);
			min_t = std::min(min_t,tmp3.second);
			max_t = std::max(max_t,tmp3.first);
		}
		ans = std::min(ans,max_t-min_t);
	}
	
	for(int i = minidx;i<=n;++i){
		//[l,r] = [minidx,i]
		auto tmp1 = query(minidx,i);
		int min_t = tmp1.second*2;
		int max_t = tmp1.first*2;
		if(minidx>1){
			auto tmp2 = query(1,minidx-1);
			min_t = std::min(min_t,tmp2.second);
			max_t = std::max(max_t,tmp2.first);
		}
		if(i<n){
			auto tmp3 = query(i+1,n);
			min_t = std::min(min_t,tmp3.second);
			max_t = std::max(max_t,tmp3.first);
		}
		ans = std::min(ans,max_t-min_t);
	}
	
	std::cout << ans << '\n';
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