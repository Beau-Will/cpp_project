#include <bits/stdc++.h>

using i64 = long long;
using namespace std;
const int N = 1e5 + 10;
#define int long long
using pii = std::pair<int,int>;

int n, a[N], c[N];

bool check(int x) {
	multiset<int> st1, st2;
	for (int i = 1; i <= n; i++) {
		if (c[i] == 1) st1.insert(a[i]);
		else st2.insert(a[i]);
		if (st1.size() && st2.size()) {
			if (c[i] == 1) {
				int p = *st1.begin();
				auto t = st2.lower_bound(x - p);
				if(t==st2.end()){
					return false;
				}else{
					st2.erase(t);
					st1.erase(st1.begin());
				}
			}else{
				int p = *st2.begin();
				auto t = st1.lower_bound(x - p);
				if(t==st1.end()){
					return false;
				}else{
					st1.erase(t);
					st2.erase(st2.begin());
				}
			}
		}
	}
	return true;
}

void solve(){
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
	for (int i = 1; i <= n; i++) cin >> c[i];
	int l = 0, r = sum;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << '\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int t = 1;
//	cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
