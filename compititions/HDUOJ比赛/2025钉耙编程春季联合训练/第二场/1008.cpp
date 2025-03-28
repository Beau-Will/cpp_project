#include<bits/stdc++.h>

using namespace std;
using i128 = __int128;
using u64 = unsigned long long;

#define cc(x) cout << fixed << setprecision(x)
#define int long long

const int N = 2e5 + 10;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> deg(3 * n + 1);
	vector<set<int>> adj(3 * n + 1);
	map<pair<int, int>, int> mp;
	int flag = 1;
	for (int i = 1; i <= m; i ++) {
		int x, y, col;
		cin >> x >> y >> col;
		if(mp.count({x, y}) && mp[{x, y}] != col) {
			flag = 0;
		}
		int a = (y + 1) / 2, b = n + n - x + 1, c = 2 * n + (x * 2 - y + 1) / 2;
		int ok = 0;
		if(a == col) {
			if(!adj[b].count(a)) adj[b].insert(a), deg[a] ++;
			if(!adj[c].count(a)) adj[c].insert(a), deg[a] ++;
			ok = 1;
		}
		else if(b == col) {
			if(!adj[a].count(b)) adj[a].insert(b), deg[b] ++;
			if(!adj[c].count(b)) adj[c].insert(b), deg[b] ++;
			ok = 1;
		}
		else if(c == col){
			if(!adj[b].count(c)) adj[b].insert(c), deg[c] ++;
			if(!adj[a].count(c)) adj[a].insert(c), deg[c] ++;
			ok = 1;
		}
		if(!ok) flag = 0;
	}
	if(!flag) {
		cout << "No\n";
		return;
	}

	queue<int> q;
	for (int i = 1; i <= 3 * n; i ++) {
		if(deg[i] == 0 && adj[i].size()) q.push(i);
	}

	while(q.size()) {
		auto u = q.front();
		q.pop();
		for (auto v : adj[u]) {
			if(--deg[v] == 0) q.push(v);
		}
	}
	for (int i = 1; i <= 3 * n; i ++) {
		if(deg[i]) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
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