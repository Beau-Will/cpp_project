// Problem: 小红的01串（三）
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/98256/C
// Memory Limit: 512 MB
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
	int a,b,k;std::cin >> a >> b >> k;
	if(k+1>a+b){
		std::cout << "-1\n";
		return;
	}
	std::string ans;
	int cnt1 = 0,cnt0 = 0;
	for(int i = 1;i<=k;++i){
		if(i&1){
			ans+='1';
			++cnt1;
		}else{
			ans+='0';
			++cnt0;
		}
		if(cnt0>a||cnt1>b){
			std::cout << "-1\n";
			return;
		}
	}
	if(ans.back()=='0'){
		for(int i = 1;i<=a-cnt0;++i){
			ans+='0';
		}
		for(int i = 1;i<=b-cnt1;++i){
			ans+='1';
		}
	}else{
		for(int i = 1;i<=b-cnt1;++i){
			ans+='1';
		}
		for(int i = 1;i<=a-cnt0;++i){
			ans+='0';
		}
	}
	auto check = [&](std::string str)->bool{
		int cnt = 0;
		for(int i = 1;i<str.size();++i){
			if(str[i]!=str[i-1]) ++cnt;
		}
		return cnt==k;
	};
	if(check(ans)){
		std::cout << ans << '\n';
		return;
	}
	ans = "";
	cnt1 = 0,cnt0 =0;
	for(int i = 1;i<=k;++i){
		if(i&1){
			ans+='0';
			++cnt0;
		}else{
			ans+='1';
			++cnt1;
		}
		if(cnt0>a||cnt1>b){
			std::cout << "-1\n";
			return;
		}
	}
	if(ans.back()=='0'){
		for(int i = 1;i<=a-cnt0;++i){
			ans+='0';
		}
		for(int i = 1;i<=b-cnt1;++i){
			ans+='1';
		}
	}else{
		for(int i = 1;i<=b-cnt1;++i){
			ans+='1';
		}
		for(int i = 1;i<=a-cnt0;++i){
			ans+='0';
		}
	}
	if(check(ans)){
		std::cout << ans << '\n';
	}else{
		std::cout << "-1\n";
	}
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int tt = 1;
	std::cin >> tt;
	for(int ti = 0;ti<tt;++ti){
		solve();
	}
	
	return 0;
}