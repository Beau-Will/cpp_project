#include <bits/stdc++.h>

//using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int N = 200005,inf = 1000000000;
constexpr int P1 = 1000000007,P2 = 998244353;
constexpr int P = 131;

struct Node{
	std::string s1;
	int num;
	std::string s2;
};

void solve(){
	std::string s;
	int n;
	std::cin >> s >> n;
	
	std::vector<Node> a(n);
	for(int i = 0; i < n; ++i){
		std::cin >> a[i].s1 >> a[i].num >> a[i].s2;
	}
	
	std::map<std::string,int> nxt;
	for(int i = 0; i < n; ++i){
		nxt[a[i].s1] = i;
	}
	
	std::set<int> set;
	std::vector<Node> ans1,ans2;
	
	std::string cur = s;
	while(cur!="-1"){
		int idx = nxt[cur];
		if(set.count(std::abs(a[idx].num))){
			ans2.push_back(a[idx]);
		}else{
			set.insert(std::abs(a[idx].num));
			ans1.push_back(a[idx]);
		}
		cur = a[idx].s2;
	}
	
	for(int i = 0; i < ans1.size(); ++i){
		std::cout << ans1[i].s1 << " " << ans1[i].num << " " << (i+1==ans1.size()?"-1":ans1[i+1].s1) << "\n";
	}
	
	for(int i = 0; i < ans2.size(); ++i){
		std::cout << ans2[i].s1 << " " << ans2[i].num << " " << (i+1==ans2.size()?"-1":ans2[i+1].s1) << "\n";
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
