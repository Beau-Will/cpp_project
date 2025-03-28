#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e6 + 10, mod = 1e9 + 7, M = 25;
int a[N], b[N];
int n, m, k;

int qmi(int a, int b) {
	int ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b /= 2;
	}
	return ans % mod;
}

void solve(int T) {
	cin >> n;
	n ++;
	if(n == 2) {
		cout << 0 << '\n';
		return;
	}
	m = n;
	m /= 2;
	int r = m * 2;
	cout << (2 + r) * m % mod * qmi(2ll, mod - 2) % mod << '\n'; 
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T = 1;
	cin >> T;
	for(int i = 1; i <= T; i ++) {
		solve(i);
	}
}