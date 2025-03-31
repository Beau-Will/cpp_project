#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	std::vector<int> a(4);
	for(int i = 0; i < 4; ++i){
		std::cin >> a[i];
	}
	
	std::sort(a.begin(),a.end());
	
	std::vector<int> ans;
	do{
		// for(int i = 0; i < 4; ++i){
			// std::cout << a[i] << " \n"[i+1==4];
		// }
		if(a.front()==0){
			continue;
		}
		int sum = 0;
		for(int i = 0; i < 4; ++i){
			if(a[i]>=10){
				sum = sum*100+a[i];
			}else{
				sum = sum*10+a[i];
			}
		}
		ans.push_back(sum);
	}while(std::next_permutation(a.begin(),a.end()));
	
	std::sort(ans.begin(),ans.end());
	ans.erase(std::unique(ans.begin(),ans.end()),ans.end());
	
	std::sort(ans.begin(),ans.end(),std::greater<int>());
	for(int i = 0; i < ans.size(); ++i){
		std::cout << ans[i] << "\n";
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
	//std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}