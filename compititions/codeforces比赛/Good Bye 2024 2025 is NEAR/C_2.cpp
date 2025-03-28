#include <bits/stdc++.h>

using i64 = long long;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
	std::cin >> t;
	std::vector<i64> ans;
	while(t--){
		i64 n,k;std::cin >> n >> k;
		i64 res = 0;
		if(k==1){
			res = (1LL+n)*n/2;
			ans.emplace_back(res);
			continue;
		}
		if(k%2==1){
			i64 tmp = n;
			while(tmp>=k){
				tmp/=2;
			}
			
		}
		// i64 tmp = n,tt = 0;
		// while(tmp>=k){
			// if(tmp%2==1){
				// res+=((tmp/2)+1)*std::pow(4,tt++);
			// }
			// tmp/=2;
		// }
		std::vector<std::pair<i64,i64>> segs;
		segs.emplace_back(1,n);
		// std::vector<i64> query;
		// if(n==55){
			// std::cout << "---" << '\n';
		// }
		while(!segs.empty()){
			auto [l,r] = segs.back();
			segs.pop_back();
			if(l>r) continue;
			auto len = r-l+1;
			auto mid = (l+r)/2;
			if(len<k) continue;
			if(len&1){
				res+=mid;
				// if(n==55){
					// query.emplace_back(mid);
					// // std::cout << mid << '\n';
				// }
				segs.emplace_back(l,mid-1);
				segs.emplace_back(mid+1,r);
			}else{
				segs.emplace_back(l,mid);
				segs.emplace_back(mid+1,r);
			}
		}
		// if(n==55){
			// std::sort(query.begin(),query.end());
			// for(int i = 0;i<query.size();++i){
				// std::cout << query[i] << '\n';
			// }
			// std::cout << "---" << '\n';
		// }
		ans.emplace_back(res);
	}
	for(int i = 0;i<ans.size();++i){
		std::cout << ans[i] << '\n';
	}
	
	return 0;
}