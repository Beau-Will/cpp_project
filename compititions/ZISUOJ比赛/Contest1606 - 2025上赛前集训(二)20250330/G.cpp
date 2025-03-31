#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;
	std::cin >> n;
	
	std::vector<std::string> a(n+1);
	for(int i = 1; i <= n; ++i){
		std::cin >> a[i];
	}
	
	std::vector<std::array<std::pair<int,char>,2>> ans;
	
	auto check = [&](){
		for(int i = 1; i <= n; ++i){
			if(a[i][0]+a[i][1]+a[i][2]-'w'-'i'-'n'!=0){
				return false;
			}
		}
		return true;
	};
	
	while(!check()){
		for(int i = 1; i <= n; ++i){
			if(a[i][0]+a[i][1]+a[i][2]-'w'-'i'-'n'!=0){
				std::map<char,int> cnt;
				++cnt[a[i][0]];
				++cnt[a[i][1]];
				++cnt[a[i][2]];
				std::pair<int,char> t1;
				int pos1 = -1;
				for(auto &ele:cnt){
					if(ele.second>1){
						t1 = {i,ele.first};
					}
				}
				if(a[i][0]==t1.second){
					pos1 = 0;
				}else if(a[i][1]==t1.second){
					pos1 = 1;
				}else{
					pos1 = 2;
				}
				// std::pair<int,char> t2;
				// if(cnt['w']==0){
					// t2 = {i,'w'};
				// }else if(cnt['i']==0){
					// t2 = {i,'i'};
				// }else{
					// t2 = {i,'n'};
				// }
				for(int j = i+1; j <= n; ++j){
					if(a[j][0]+a[j][1]+a[j][2]-'w'-'i'-'n'!=0){
						std::map<char,int> cnt2;
						++cnt2[a[j][0]];
						++cnt2[a[j][1]];
						++cnt2[a[j][2]];
						if(cnt2[t1.second]==0){
							
							std::pair<int,char> t2;
							if(cnt2['w']>1){
								t2 = {j,'w'};
							}else if(cnt2['i']>1){
								t2 = {j,'i'};
							}else{
								t2 = {j,'n'};
							}
							std::array<std::pair<int,char>,2> ansi;
							ansi[0] = t1;
							ansi[1] = t2;
							
							ans.push_back(ansi);
							
							int pos2 = -1;
							
							if(a[j][0]==t2.second){
								pos2 = 0;
							}else if(a[j][1]==t2.second){
								pos2 = 1;
							}else if(a[j][2]==t2.second){
								pos2 = 2;
							}
							std::swap(a[i][pos1],a[j][pos2]);
						}
					}
				}
			}
		}
	}
	
	std::cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); ++i){
		for(int j = 0; j < 2; ++j){
			std::cout << ans[i][j].first << " " << ans[i][j].second << " \n"[j==1];
		}
	}
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