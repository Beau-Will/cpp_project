#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
/*
qwertyuiop
asdfghjkl;
zxcvbnm,./ 
*/
void solve(){
	std::string line1 = "qwertyuiop";
	std::string line2 = "asdfghjkl;";
	std::string line3 = "zxcvbnm,./";
	std::string dir;std::cin >> dir;
	std::string s;std::cin >> s;
	std::string ans;
	if(dir=="R"){
		for(const auto& c:s){
			int pos;
			if((pos =line1.find(c))!=std::string::npos){
				if(pos!=0){
					ans+=line1[pos-1];
				}else{
					ans+=line1[pos];
				}
			}else if((pos =line2.find(c))!=std::string::npos){
				if(pos!=0){
					ans+=line2[pos-1];
				}else{
					ans+=line2[pos];
				}
			}else if((pos =line3.find(c))!=std::string::npos){
				if(pos!=0){
					ans+=line3[pos-1];
				}else{
					ans+=line3[pos];
				}
			}
			
		}
	}else{//dir=="L"
		for(const auto& c:s){
			int pos;
			if((pos =line1.find(c))!=std::string::npos){
				if(pos!=line1.size()-1){
					ans+=line1[pos+1];
				}else{
					ans+=line1[pos];
				}
			}else if((pos =line2.find(c))!=std::string::npos){
				if(pos!=line2.size()-1){
					ans+=line2[pos+1];
				}else{
					ans+=line2[pos];
				}
			}else if((pos =line3.find(c))!=std::string::npos){
				if(pos!=line3.size()-1){
					ans+=line3[pos+1];
				}else{
					ans+=line3[pos];
				}
			}
			
		}
	}
	std::cout << ans << '\n';
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int tt = 1;
	// std::cin >> tt;
	for(int ti = 0;ti<tt;++ti){
		solve();
	}
	
	return 0;
}