#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1000000000;
constexpr int P = 131,N = 100000;
constexpr int P1 = 1000000007,P2 = 998244353;
constexpr i64 inf2 = 1000000000000000000;

//struct Node1{
//	int h,m,s;
//	
//	bool operator < (const &Node1 t) const{
//		if(h!=t.h){
//			return h < t.h;
//		}
//		if(m!=t.m){
//			return m < t.m;
//		}
//		return s < t.s;
//	} 
//};
//
//struct Node{
//	int h1,m1,s1;
//	int h2,m2,s2;
//};

struct Node{
	int h,m,s;
	
	bool operator < (const Node& t) const{
		if(h!=t.h){
			return h < t.h;
		}
		if(m!=t.m){
			return m < t.m;
		}
		return s < t.s;
	}
	
	bool operator <= (const Node& t) const{
//		if(h!=t.h){
//			return h < t.h;
//		}
//		if(m!=t.m){
//			return m < t.m;
//		}
//		return s < t.s;
		return h <= t.h && m <= t.m && s <= t.s;
	}
	bool operator >= (const Node& t) const{
//		if(h!=t.h){
//			return h < t.h;
//		}
//		if(m!=t.m){
//			return m < t.m;
//		}
//		return s < t.s;
		return h >= t.h && m >= t.m && s >= t.s;
	}
};

void solve(){
	int n;
	std::cin >> n;
	
//	std::vector<std::pair<std::string,std::string>> a(n);
	std::vector<std::pair<Node,Node>> a(n);
	for(int i = 0; i < n; ++i){
		std::string s1,s2;
		std::cin >> s1 >> s2;
		a[i].first.h = s1.substr(0,2);
		a[i].first.m = s1.substr(3,2);
		a[i].first.s = s1.substr(6,2);
		a[i].second.h = s2.substr(0,2);
		a[i].second.m = s2.substr(3,2);
		a[i].second.s = s2.substr(6,2);
//		std::cin >> a[i].first >> a[i].second;
	}
	
	std::sort(a.begin(),a.end());//,[&](auto &t1,auto &t2){
//		Node t11 = t1.first,t12 = t1.second;
//		Node t21 = t2.first,t22 = t2.second;
//		if(t12.h!=t22.h){
//			return t12.h<t22.h;
//		}
//		if(t12.m!=t22.m){
//			return t12.m<t22.m;
//		}
//		if(t12.s!=t12.s){
//			return t12.s<t22.s;
//		}
//		if(t11.h!=t21.h){
//			return t11.h<t21.h;
//		}
//		if(t11.m!==t21.m){
//			return t11.m<t21.m;
//		}
//		return t11.s < t21.s;
//		if(t1.second)
//		if(t1.second!=t2.second){
//			return t1.second < t2.second;
//		}
//		return t1.first < t2.first;
//	});
	
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int res = 1;
		for(int j = 0; j < n; ++j){
			if(i==j){
				continue;
			}
//			if(a[j].first>=a[i].second || a[j].second <= a[i].first){
//				std::cout << "i,j:" << i << "," << j << "\n";
//				++res;
//			}
			if(a[j].first>=a[i].second || a[j].second <= a[i].first){
				++res;
			}
		}
		ans = std::max(ans,res);
	}
	
	std::cout << ans << "\n";
	
//	std::vector<std::string> v;
//	for(int i = 0; i < n; ++i){
//		v.push_back(a[i].first);
//		v.push_back(a[i].second);
//	}
//	
//	std::sort(v.begin(),v.end());
////	v.erase(std::unique(v.begin(),v.end()),v.end());
//
//	std::vector<int> b(v.size());
//	int tt = 0,last = -1;
//	for(int i = 0; i < v.size(); ++i){
//		if(last==-1||last==v[i]){
//			b[i] = tt;
//		}else{
//			b[i] = ++tt;
//		}
//	}
//	
//	auto query = [&](std::string &s){
//		return std::lower_bound(v.begin(),v.end(),s)-v.begin();
//	};
//	
//	for(int i = 0; i < n; ++i){
//		int idx1 = query(a[i].first);
//		int idx2 = query(a[i].second);
//		
//		int t1 = b[idx1];
//		int t2 = b[idx2];
//		
//	}
	
	
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
//	std::cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
