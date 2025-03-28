// Problem: F - Rotated Inversions
// Contest: AtCoder - AtCoder Beginner Contest 396
// URL: https://atcoder.jp/contests/abc396/tasks/abc396_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,m;
	std::cin >> n >> m;
	
	std::vector<int> a(n);
	for(int i = 0; i < n; ++i){
		std::cin >> a[i];
	}
	
	auto b = a;
	std::vector<int> tmp(n);
	i64 res = 0;
	
	auto merge_sort = [&](auto &&self,std::vector<int> &arr,int l,int r)->void{
		if(l>=r) return;
		int mid = (l+r)>>1;
		self(self,arr,l,mid);
		self(self,arr,mid+1,r);
		int k = 0,i = l,j = mid+1;
		while(i<=mid&&j<=r){
			if(arr[i]<=arr[j]){
				tmp[k++] = arr[i++];
			}else{
				tmp[k++] = arr[j++];
				res += mid-i+1;
			}
		}
		while(i<=mid){
			tmp[k++] = arr[i++];
		}
		while(j<=r){
			tmp[k++] = arr[j++];
		}
		for(int i = l,j = 0; i <= r; ++i,++j){
			arr[i] = tmp[j];
		}
	};
	
	merge_sort(merge_sort,b,0,n-1);
	
	std::vector<std::vector<int>> adj(2e5);
	std::vector<i64> ans(m);
	
	for(int i = 0; i < n; ++i){
		adj[a[i]].push_back(i);
	}
	
	ans[0] = res;
	for(int i = 1; i < m; ++i){
		ans[i] = ans[i-1];
		for(auto &j:adj[m-i]){
			ans[i] += -n+1+j+j;
		}
	}
	
	for(int i = 0; i < m; ++i){
		std::cout << ans[i] << "\n";
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