#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

void solve(){
	int n;
	cin >> n;
	
	int sum = 0;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int cnt = 0;
	int maxn = *max_element(a.begin(),a.end());
	for(int i = 0; i < n; ++i){
		if(maxn==a[i]){
			++cnt;
		}
	}
	
	cout << ((cnt&1)?"Alice":"Bob") << "\n";
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
