#include <bits/stdc++.h>

//using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int N = 200005,inf = 1000000000;
constexpr int P1 = 1000000007,P2 = 998244353;
constexpr int P = 131;

void solve(){
	int n;
	std::cin >> n;
	
	std::vector<std::string> a(n+1);
	for(int i = 1; i <= n; ++i){
		std::cin >> a[i];
	} 
	
	int k;
	std::cin >> k;
	
	std::string s;
	getline(std::cin,s);
	getline(std::cin,s);
	
	std::vector<u64> p(5001);
	for(int i = 1; i <= 5000; ++i){
		p[i] = p[i-1]*P;
	}
	
	auto hash1 = std::vector(n+1,std::vector<u64>(101));
	for(int i = 1; i <= n; ++i){
		int len = a[i].size();
		a[i] = " "+a[i];
		for(int j = 1; j <= len; ++j){
			hash1[i][j] = hash1[i][j-1]*P+a[i][j];
		}
	}
	
	int len = s.size();
	s = " "+s;
	
	std::vector<u64> hash2(5001);
	for(int i = 1; i <= len; ++i){
		hash2[i] = hash2[i-1]*P+s[i];
	}
	
	auto is_same = [&](int i,int l1,int r1,int l2,int r2){
		u64 t1 = hash1[i][r1]-hash1[i][l1-1]*p[r1-l1+1];
		u64 t2 = hash2[r2]-hash2[l2-1]*p[r2-l2+1];
		return t1==t2;
	};
	
	int cnt = 0;
	for(int i = 1; i <= len; ++i){
		for(int j = 1; j <= n; ++j){
			if(is_same(j,1,a[j].size()-1,1,a[j].size()-1)){
				s.replace(i,a[j].size()-1,a[j].substr(1));
				++cnt;
			}
		}
	}
	
	if(cnt>=k){
		std::cout << cnt << "\n";
		std::cout << "He Xie Ni Quan Jia!\n";
	}else{
		std::cout << s.substr(1) << "\n";
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
