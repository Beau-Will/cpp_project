#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
using pci = std::pair<char,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

int n;
std::string s;
std::set<std::vector<pci>> set;

void solve(){
	std::cin >> n;
	for(int i = 0;i<n;++i){
		std::cin >> s;
		std::vector<int> cnt(35,0);
		for(int j = 0;j<s.size();++j){
			++cnt[s[j]-'A'];
		}
		std::vector<pci> ans;
		for(int i = 0;i<26;++i){
			if(cnt[i]){
				ans.pb('A'+i,cnt[i]);
			}
		}
		set.insert(ans);
	}
	std::cout << set.size() << '\n';
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