#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    i64 N;cin >> N;
    for (i64 a = 1; a * a * a <= 4 * N; ++a) {
        if (N % a != 0) continue;
        i64 b = N / a;
        i64 C = 4 * b - a * a;
        if (C < 0) continue;
        i64 D = 3 * C;
        i64 s = sqrt(D);
        if (s * s != D) continue;
        i64 numerator = s - 3 * a;
        if (numerator < 0 || numerator % 6 != 0) continue;
        i64 y = numerator / 6;
        if (y <= 0) continue;
        i64 x = a + y;
        cout << x << " " << y << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}