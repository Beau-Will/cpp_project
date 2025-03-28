#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

std::string s,t;

void solve(){
	// std::cin >> s >> t;
	std::getline(std::cin,s);
	std::getline(std::cin,t);
	for(int i = 0;i<s.size();++i){
		if(s[i]>='A'&&s[i]<='Z'){
			s[i] = 'a'+(s[i]-'A');
		}
	}
	int cnt = 0;
	for(int i = 0;i<s.size();++i){
		if(s[i]>='a'&&s[i]<='z'){
			if(s[i]+(t[cnt%t.size()]^48)<='z'){
				s[i] += (t[cnt%t.size()]^48);
			}else{
				s[i] = 'a'+(s[i]+((t[cnt%t.size()]-'z')^48))-1;
			}
			++cnt;
		}
	}
	std::cout << s << '\n';
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