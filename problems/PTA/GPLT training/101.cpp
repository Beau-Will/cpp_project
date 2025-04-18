#include <bits/stdc++.h>

//using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int N = 200005,inf = 1000000000;
constexpr int P1 = 1000000007,P2 = 998244353;

void solve(){
	int n;
	std::cin >> n;
	
	std::cin.ignore();
	std::vector<std::string> a(n);
	for(int i = 0; i < n; ++i){
		getline(std::cin,a[i]);
	} 
	
	int k;
	std::cin >> k;
	
	std::string s;
	std::cin.ignore();
	getline(std::cin,s);
	
	std::string tmp1 = "---";
	std::string tmp2 = "<censored>";
	
	int cnt = 0;
	
	for(int i = 0; i < n; ++i){
		int idx = 0;
		while((idx=s.find(a[i],idx))!=std::string::npos){
			s.replace(idx,a[i].size(),tmp1);
			++cnt;
		}
	}
	
	if(cnt>=k){
		std::cout << cnt << "\n";
		std::cout << "He Xie Ni Quan Jia!\n";
	}else{
		int idx = 0;
		while((idx=s.find(tmp1,idx))!=std::string::npos){
			s.replace(idx,tmp1.size(),tmp2);
		}
		std::cout << s << "\n";
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
//	std::cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
