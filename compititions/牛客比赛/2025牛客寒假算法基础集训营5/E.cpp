// Problem: 小L的井字棋
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95337/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	std::vector<std::string> a(3);
	for(int i = 0;i<3;++i){
		std::cin >> a[i];
	}
	
	int cnt_XO = 0;
	for(int i = 0;i<3;++i){
		for(int j = 0;j<3;++j){
			if(a[i][j]!='G'){
				++cnt_XO;
			}
		}
	}
	if(cnt_XO<=4){
		std::cout << "Yes\n";
		return;
	}
	// std::cout << "--\n";
	
	for(int i = 0;i<3;++i){
		int cnt_X=0,cnt_G=0;
		for(int j = 0;j<3;++j){
			if(a[i][j]=='X'){
				++cnt_X;
			}else if(a[i][j]=='G'){
				++cnt_G;
			}
		}
		if(cnt_X==1&&cnt_G==2||cnt_X==2&&cnt_G==1){
			std::cout << "Yes\n";
			return;
		}
	}
	for(int j = 0;j<3;++j){
		int cnt_X=0,cnt_G=0;
		for(int i = 0;i<3;++i){
			if(a[i][j]=='X'){
				++cnt_X;
			}else if(a[i][j]=='G'){
				++cnt_G;
			}
		}
		if(cnt_X==1&&cnt_G==2||cnt_X==2&&cnt_G==1){
			std::cout << "Yes\n";
			return;
		}
	}
	// std::cout << "--\n";
	int cnt_X=0,cnt_G=0;
	for(int i = 0;i<3;++i){
		for(int j = 0;j<3;++j){
			if(i==j){
				if(a[i][j]=='X'){
					++cnt_X;
				}else if(a[i][j]=='G'){
					++cnt_G;
				}
			}
		}
	}
	if(cnt_X==1&&cnt_G==2||cnt_X==2&&cnt_G==1){
		std::cout << "Yes\n";
		return;
	}
	
	cnt_X=0,cnt_G=0;
	for(int i = 0;i<3;++i){
		for(int j = 0;j<3;++j){
			if(i+j==2){
				if(a[i][j]=='X'){
					++cnt_X;
				}else if(a[i][j]=='G'){
					++cnt_G;
				}
			}
		}
	}
	if(cnt_X==1&&cnt_G==2||cnt_X==2&&cnt_G==1){
		std::cout << "Yes\n";
		return;
	}
	
	std::cout << "No\n";
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