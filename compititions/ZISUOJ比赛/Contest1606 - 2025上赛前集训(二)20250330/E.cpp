#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,k;
	std::cin >> n >> k;
	
	std::string s;
	std::cin >> s;
	
	int sum = 0;
	bool flag = false;
	for(int i = 0; i < n; ++i){
		if(flag){
			if(s[i]=='W'){
				sum += 2;
			}else{
				flag = false;
			}
		}else{
			if(s[i]=='W'){
				sum += 1;
				flag = true;
			}
		}
	}
	
	// std::cout << "sum:" << sum << "\n";
	
	std::map<int,int> map;
	flag = false;
	int cnt = 0;
	int idx1 = s.find_first_of('W');
	int idx2 = s.find_last_of('W');
	// if(idx1==std::string::npos){
		// std::cout << sum << "\n";
		// return;
	// }
	for(int i = idx1; i <= idx2; ++i){
		if(flag){
			if(s[i]=='L'){
				++cnt;
			}else{
				flag = false;
				++map[cnt];
				cnt = 0;
			}
		}else{
			if(s[i]=='L'){
				flag = true;
				++cnt;
			}
		}
	}
	if(flag){
		++map[cnt];
	}
	int ans = sum;
	for(auto &ele:map){
		// std::cout << ele.first << " " << ele.second << "\n";
		int t = std::min(ele.second,k/ele.first);
		ans += (ele.first*2+1)*t;
		k -= t*ele.first;
		
		if(k<ele.first){
			ans += 2*k;
			k = 0;
			break;
		}
	}
	
	cnt = 0;
	flag = false;
	for(int i = 0; i < n; ++i){
		if(s[i]=='L'){
			++cnt;
		}else{
			flag = true;
			break;
		}
	}
	if(k){
		if(flag){
			ans += 2*std::min(k,cnt);
		}else{
			ans += 2*std::min(k,cnt)-1;
		}
		k -= std::min(k,cnt);
	}
	
	// std::cout << ans << "\n";
	
	cnt = 0;
	flag = false;
	for(int i = n-1; i >= 0; --i){
		if(s[i]=='L'){
			++cnt;
		}else{
			flag = true;
			break;
		}
	}
	if(k){
		if(flag){
			ans += 2*std::min(k,cnt);
		}else{
			ans += 2*std::min(k,cnt)-1;
		}
		k = 0;
	}
	// std::cout << ans << "\n";
	
	std::cout << ans << "\n";
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