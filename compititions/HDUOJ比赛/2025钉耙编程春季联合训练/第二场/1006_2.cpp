#include <bits/stdc++.h>
using namespace std;

bool isLosing(int r, int b) {
    return (r == 0 && b % 2 == 0) || (b == 0 && r % 4 == 0);
}

string solve(int r, int b, int m) {
    if (m == 0) {
        return isLosing(r, b) ? "Bob" : "Alice";
    } else {
        bool possible = false;
        if (isLosing(r, b + 1)) {
            possible = true;
        }
        if (isLosing(r + 1, b)) {
            possible = true;
        }
        if (isLosing(r + 1, b + 1)) {
            possible = true;
        }
        return possible ? "Alice" : "Bob";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int r, b, m;
        cin >> r >> b >> m;
        cout << solve(r, b, m) << '\n';
    }
    return 0;
}