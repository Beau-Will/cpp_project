// Problem: C - Operate 1
// Contest: AtCoder - AtCoder Beginner Contest 386
// URL: https://atcoder.jp/contests/abc386/tasks/abc386_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define push_back emplace_back
#define push emplace
#define all(v) v.begin(),v.end()

void solve(){
	int k;std::cin >> k;
	std::string s,t;std::cin >> s >> t;
	if(s==t){
		std::cout << "Yes\n";
		return;
	}
	if(s.size()<t.size()){
		if(t.size()-s.size()>1){
			std::cout << "No\n";
			return;
		}
		bool flag = false;
		bool isok = false;
		for(int i = 0,j = 0;i<s.size()&&j<t.size();++i,++j){
			if(s[i]!=t[j]&&!flag){
				++j;
				flag = true;
			}else if(s[i]!=t[j]){
				isok = true;
				break;
			}
		}
		std::cout << (isok?"No\n":"Yes\n");
	}else if(s.size()>t.size()){
		if(s.size()-t.size()>1){
			std::cout << "No\n";
			return;
		}
		bool flag = false;
		bool isok = false;
		for(int i = 0,j = 0;i<t.size()&&j<s.size();++i,++j){
			if(t[i]!=s[j]&&!flag){
				++j;
				flag = true;
			}else if(t[i]!=s[j]){
				isok = true;
				break;
			}
		}
		std::cout << (isok?"No\n":"Yes\n");
	}else{
		int cnt = 0;
		for(int i = 0;i<s.size();++i){
			if(s[i]!=t[i]){
				++cnt;
			}
		}
		std::cout << (cnt<=1?"Yes\n":"No\n");
	}
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