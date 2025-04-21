#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int cnt = 0;
    bool has_mid = false;
    bool head = (a[0] <= k);
    bool tail = (a.back() <= k);

    for (int i = 0; i < n; ++i) {
        if (a[i] <= k) {
            cnt++;
            if (i > 0 && i < n - 1) {
                has_mid = true;
            }
        }
    }

    if (cnt >= 1) {
        if (has_mid) {
            cout << "YES\n";
            return;
        }
        if (cnt >= 2 && (head || tail)) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}