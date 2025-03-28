#include <bits/stdc++.h>

using i64 = long long;

/*
123
1100

11

12345
110011

1234567
11001100

114514
115500

124514
220011

114514
115500
*/

void solve(){
	std::string s;std::cin >> s;
	if(s.size()&1){
		std::string ans = "11";
		int cnt = 0;
		for(int i = 0;i<s.size()-1;++i){
			if(cnt%4==0||cnt%4==1){
				ans+="0";
			}else{
				ans+="1";
			}
			++cnt;
		}
		std::cout << ans << '\n';
	}else{
		bool flag = false;
		bool isok = false;
		for(int i = 1;i<s.size();i+=2){
			if(flag){
				if(s[i-3]=='0'&&s[i-2]=='0'){
					s[i-1]='1',s[i]='1';
				}else{
					s[i-1]='0',s[i]='0';
				}
			}else{
				if(s[i-1]==s[i]){
					if(i>=3&&s[i-3]==s[i-1]&&s[i-2]==s[i]){
						if(s[i-3]!='9'){
							s[i-1]=s[i-1]+1;
							s[i]=s[i]+1;
						}else{
							if(i>=5){
								s[i-5] = s[i-4] = s[i-4]+1;
								s[i-3] = s[i-2] = '0';
								s[i-1] = s[i] = '1';
							}else{
								isok = true;
								break;
							}
						}
					}
				}else if(s[i-1]<s[i]){
					if(s[i]<s[i-1]+1){
						s[i-1] = s[i];
					}else{
						s[i-1] = s[i-1]+1;
					}
					flag = true;
				}else if(s[i-1]>s[i]){
					s[i] = s[i-1];
					flag = true;
				}
			}
		}
		if(isok){
			int len = s.size()+1;
			std::string ans = "11";
			int cnt = 0;
			for(int i = 0;i<len-1;++i){
				if(cnt%4==0||cnt%4==1){
					ans+="0";
				}else{
					ans+="1";
				}
				++cnt;
			}
			std::cout << ans << '\n';
			return;
		}
		std::cout << s << '\n';
	}
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int t = 1;
	// std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}