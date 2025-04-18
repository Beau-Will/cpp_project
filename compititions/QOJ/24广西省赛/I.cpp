#include <bits/stdc++.h>
using namespace std;
#define int long long 
using i64 = long long;
const int N = 2e5 + 10;

int n, m, c[N], d[N], ans;
vector<int> adj[N];
vector<pair<int, int>> a[N];
bool vis[N];
bool flag = true;

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		adj[y].push_back(x);
		adj[z].push_back(x);
		a[x].push_back({y,z});
		d[x]++, d[x]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (d[i] == 0) q.push(i), c[i] = 1;
	}
	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		//if (vis[u]) continue;
		vis[u] = 1;
		for(auto [y,z]:a[u]){
			c[u] = max(c[u],c[y]+c[z]);
		}
		for (auto v : adj[u]) {
			if(--d[v]==0) q.push(v);
		}
	}
	for(int i = 1; i <= n; ++i){
		if(d[i]!=0){
			flag=false;
		}
	}
	if(!flag){
		std::cout << "-1\n";
		return;
	}
	//for (int i = 1; i <= n; i++) {
		//cout << c[i] << " \n"[i == n];
	//}
	
	for (int i = 1; i <= n; i++){
		ans += c[i];
		if(ans>1e9){
			std::cout << "-1\n";
			return;
		}
	}
	std::cout << ans << "\n";
	//if (ans > 1e9) cout << -1 << '\n';
	//else cout << ans << '\n';
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  while(t--){
    solve();
  }

  return 0;
}