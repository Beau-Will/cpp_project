#include<bits/stdc++.h>

using namespace std;
using i128 = __int128;
using u64 = unsigned long long;


#define cc(x) cout << fixed << setprecision(x)
#define int long long

const int N = 2e5 + 10;

struct node{
    int x, y, tim, op;
    bool operator<(const node &o) const{
        return tim > o.tim;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> t(n, vector<int>(m));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> t[i][j];
        }
    }

    vector<vector<int>> d(n, vector<int>(m));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> d[i][j];
        }
    }

    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

    vector vis(n, vector(m, vector<int>(4)));
    priority_queue<node> q;
    q.push({0, 0, 0, 2});
    while(q.size()) {
        auto [x, y, tim, op] = q.top();
        q.pop();

        if(vis[x][y][op]) continue;
        vis[x][y][op] = 1;
        if(x == n - 1 && y == m - 1 && op == 0) {
            cout << tim + t[n - 1][m - 1] << '\n';
            return;
        }
        for (int i = 0; i < 4; i ++) {
            int tx = x + dx[i], ty = y + dy[i];
            if(i != op) q.push({x, y, tim + d[x][y], i});
            if(tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
            if(i == op) q.push({tx, ty, tim + t[x][y], op});
        }
    }
    
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