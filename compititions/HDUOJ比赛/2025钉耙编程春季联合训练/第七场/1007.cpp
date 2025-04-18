#include<bits/stdc++.h>

using namespace std;
using i128 = __int128;
using u64 = unsigned long long;


#define cc(x) cout << fixed << setprecision(x)
#define int long long

const int N = 2e5 + 10, M = N * 2;

struct Node {
	int v, w, ne;
} e[M];
int idx = 1, h[N];

void add(int a, int b, int c) {
	e[++idx] = {b, c, h[a]};
	h[a] = idx;
}

int n;
void init() {
	for (int i = 1; i <= n; i ++) h[i] = 0;
	idx = 1;
}

void solve() {

	init();
	cin >> n;

	for (int i = 1; i < n; i ++) {
		int u, v, p, q;
		cin >> u >> v >> p >> q;
		add(u, v, p);
		add(v, u, q);
	}

	int s, t;
	cin >> s >> t;
	vector<int> son(n + 1);
	vector<int> dp(n + 1);
	auto dfs1 = [&](auto && self, int u, int fa) -> void {
		if (u == t) son[u] = u;


		for (int i = h[u]; i; i = e[i].ne) {
			int v = e[i].v;
			if (v == fa) continue;
			self(self, v, u);
			int w = e[i].w, rw = e[i ^ 1].w;
			dp[u] += max(0ll, dp[v] + w + rw);
			if (son[v]) son[u] = v;
		}
	};

	dfs1(dfs1, s, 0);

	int ans = 0;
	auto dfs2 = [&](auto && self, int u, int fa) -> void {
		for (int i = h[u]; i; i = e[i].ne) {
			int v = e[i].v;
			if (v == son[u] || v == fa) continue;
			int w = e[i].w, rw = e[i ^ 1].w;
			ans += max(0ll, dp[v] + w + rw);
		}
		// cout << u << ' ' << ans << '\n';
		if (son[u] == u) return;
		for (int i = h[u]; i; i = e[i].ne) {
			int v = e[i].v;
			if (v == son[u]) {
				int w = e[i].w, rw = e[i ^ 1].w;
				ans += w;
				self(self, v, u);
			}
		}
	};

	dfs2(dfs2, s, 0);
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