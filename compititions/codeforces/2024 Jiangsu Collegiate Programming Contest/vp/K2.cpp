#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

multiset<int> st;
std::vector<int> a;

void dfs(){
	if(st.upper_bound(1)==st.end()){
		
		if(st.size()&1){
			cout << "Alice\n";
		}else{
			cout << "Bob\n";
		}
		return;
	}
	
	for(auto &ele:st){
		cout << ele << " ";
	}
	cout << "\n";
	auto x = --st.end();
	st.erase(x);
	for(int i = (*x)-1; i >= 1; --i){
		auto st2 = st;
		for(int j = 1; j <= i; ++j){
			st.insert(j);
		}
		dfs();
		st = st2;
	}
}

void solve(){
	int n;
	std::cin >> n;
	
	
	for(int i = 0; i < n; ++i){
		int x;
		std::cin >> x;
		a.push_back(x);
		st.insert(x);
	}
	
	dfs();
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
