#include <bits/stdc++.h>

using i64 = long long;

/*
8
1 1 1 1 1 1 1 1

0 1 1 0 1 1 0 1

0 0 1 0 1 0 0 1

0 0 0 0 1 0 0 1

0 0 0 0 0 0 0 1

0 0 0 0 0 0 0 0

*/

void solve(){
	int n;
	std::cin >> n;
	
	std::vector<int> a(n+1,1);
	
	auto check = [&](){
		for(int i = 1; i <= n; ++i){
			if(a[i]){
				return true;
			}
		}
		return false;
	};
	
	int last = -1,cnt = 0;
	while(check()){
		int t = 0;
		for(int i = 1; i <= n; ++i){
			if(a[i]){
				++t;
				if(t%3==1){
					last = i;
					a[i] = 0;
				}
			}
		}
		
		++cnt;
	}
	
	std::cout << cnt << " " << last << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
	// std::cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}