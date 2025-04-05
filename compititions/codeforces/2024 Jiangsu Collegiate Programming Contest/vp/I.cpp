#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
#define int long long

void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<int> c(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> c[i];
	priority_queue<int, vector<int>, greater<int>> q1;//0
	priority_queue<int> q2;//1
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (c[i] == 0) q1.push(a[i]);
		else q2.push(a[i]);
		if (q1.size() == q2.size()) {
			while (!q1.empty()) {
				int sum = q1.top() + q2.top();
				q1.pop();
				q2.pop();
				ans.push_back(sum);
			}
		}
	}
	if (ans.empty()) {
		while (!q1.empty()) q1.pop();
		while (!q2.empty()) q2.pop();
		for (int i = 1; i <= n; i++) {
			if (c[i] == 0) q1.push(a[i]);
			else q2.push(a[i]);
			while (!q1.empty() && !q2.empty()) {
				int sum = q1.top() + q2.top();
				q1.pop();
				q2.pop();
				ans.push_back(sum);
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans[0] << '\n';
}

signed main(){
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
