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
	int a,b;
	std::cin >> a >> b;
	
	std::vector<int> cnt(b-a+1);
	for(int i = a; i <= b; ++i){
		int isok = 0;
		int t = i;
		while(t>=10){
			int mul = 1;
			while(t){
				mul *= t%10;
				t/=10;
			}
			t = mul;
			++isok;
		}
		cnt[i-a] = isok;
	}
	
	int max = *std::max_element(cnt.begin(),cnt.end());
	int k = cnt.size()-1;
	for(int i = cnt.size()-1; i >= 0; --i){
		if(cnt[i]==max){
			k = i;
			break;
		}
	}
	std::cout << max << "\n";
	for(int i = 0; i < cnt.size(); ++i){
		if(cnt[i]==max){
			std::cout << a+i << " \n"[i==k];
		}
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
