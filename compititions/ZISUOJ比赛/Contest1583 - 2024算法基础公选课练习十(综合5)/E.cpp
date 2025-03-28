#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 1e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

bool canSumToX(int x) {
    for (int i = 0; i < 11; ++i) {
        int val = i * 111;
        if (x >= val && (x - val) % 11 == 0) {
            return true;
        }
    }
    return false;
}

void solve(){
	int x;std::cin >> x;

    std::cout << (canSumToX(x)?"YES\n":"NO\n");
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