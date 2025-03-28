// Problem: 学历史导致的
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/contest/problem?cid=1151&pid=1002
// Memory Limit: 524288 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

std::vector<std::string> tiangan = {"jia","yi","bing", "ding", "wu", "ji", "geng", "xin", "ren", "gui"};
std::vector<std::string> dizhi = {"zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you","xu", "hai"};
std::vector<std::string> tiangan_new,dizhi_new,a;

void solve(){
	
	std::string s;std::cin >> s;

	for(int i = 0;i<a.size();++i){
		if(s==a[i]){
			std::cout << i+1984 << "\n";
			return;
		}
	}
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	
	for(int i = 0;i<10;++i){
		for(int j = 0;j<tiangan.size();++j){
			tiangan_new.push_back(tiangan[j]);
		}
		for(int j = 0;j<dizhi.size();++j){
			dizhi_new.push_back(dizhi[j]);
		}
	}
	
	for(int i = 0;i<60;++i){
		a.push_back(tiangan_new[i]+dizhi_new[i]);
	}
	
	int t = 1;
	std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}