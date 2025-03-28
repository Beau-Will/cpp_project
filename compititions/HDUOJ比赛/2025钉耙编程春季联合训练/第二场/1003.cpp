#include<bits/stdc++.h>

using namespace std;
using i128 = __int128;
using u64 = unsigned long long;


#define cc(x) cout << fixed << setprecision(x)
#define int long long

const int N = 1e6 + 10;




void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) cin >> a[i];

	vector<vector<int>> g(N);
	
	for (int i = 1; i <= n; i ++) {
		g[a[i]].push_back(i);
	}

	map<int, int> mp;
	vector<int> f(n + 1);
	vector<int> suf(n + 2);
	for (int i = n; i >= 1; i --) {
		f[i] = mp.size();
		if(a[i]) mp[a[i]] = 1;
		suf[i] = suf[i + 1] + (a[i] == 0);
	}

	int ans = 0;
	for (int i = 1; i < N; i ++) {
		for (int j = 1; j < g[i].size(); j ++) {
			if(suf[g[i][0] + 1] - suf[g[i][j]]) {
				ans += f[g[i][j]];
				break;
			}
		}
	}
	cout << ans << '\n';



}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}