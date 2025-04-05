#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	
	vector<double> a(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	vector<double> pre(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
	
	for (int i = k; i <= n; i++) {
		double ans = pre[i] - pre[i - k];
		ans /= k;
		bool f = true;
		if (ans >= 1024) {
			ans /= 1024;
			f = false;
		}
		if (f) cout << fixed << setprecision(10) << ans << " KiBps\n";
		else cout << fixed << setprecision(10) << ans << " MiBps\n";
	}
}

int main(){
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
