#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,m;
	std::cin >> n >> m;
	
	std::vector<int> a(n),b(m);
	for(int i = 0; i < n; ++i){
		std::cin >> a[i];
	}
	
	for(int i = 0; i < m; ++i){
		std::cin >> b[i];
	}
	
	for(int i = 0; i < m; ++i){
		int min = 1000000001,minidx = -1;
		for(int j = 0; j < n; ++j){
			if(a[j]<min){
				min = a[j];
				minidx = j;
			}
		}
		a[minidx] = b[i];
	}
	
	std::cout << std::accumulate(a.begin(),a.end(),0LL) << "\n";
} 

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
	std::cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}