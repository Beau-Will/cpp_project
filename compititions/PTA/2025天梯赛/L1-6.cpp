#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1000000000;
constexpr int P = 131,N = 100000;
constexpr int P1 = 1000000007,P2 = 998244353;
constexpr i64 inf2 = 1000000000000000000;

void solve(){
	int n,q;
	std::cin >> n >> q;
	
	std::string s;
	for(int i = 0; i < n; ++i){
		int x;
		std::cin >> x;
		s += 'a'+x-1;
	}
	
	while(q--){
		int op;
		std::cin >> op;
		
		if(op==1){
			int k1;
			std::cin >> k1;
			
			std::string t1;
			for(int i = 0; i < k1; ++i){
				int x;
				std::cin >> x;
				t1 += 'a'+x-1;
			}
			
			int k2;
			std::cin >> k2;
			std::string t2;
			for(int i = 0; i < k2; ++i){
				int x;
				std::cin >> x;
				t2 += 'a'+x-1;
			}
			
			int pos;
			if((pos=s.find(t1))!=std::string::npos){
				s.replace(pos,t1.size(),t2);
			}
		}else if(op==2){
//			bool flag = true;
			for(int i = 0; i < s.size()-1; ++i){
				int x1 = s[i]-'a'+1;
				int x2 = s[i+1]-'a'+1;
				if((x1+x2)%2==0){
					std::string tmp1 = s.substr(0,i+1);
					std::string tmp2 = s.substr(i+1);
					tmp1 = tmp1 + char('a'+(x1+x2)/2-1);
					tmp1 += tmp2;
					s = tmp1;
//					flag = false;
//					break;
					++i;
				}
				
			}
//			if(flag){
//				std::cout << q << "\n";
//				
//				std::string tmp;
//				
//				for(int i = 0; i < s.size()-1; ++i){
//					int x1 = s[i]-'a'+1;
//					int x2 = s[i+1]-'a'+1;
//					tmp += 'a'+(x1+x2)/2-1;					
//				}
//				
//				std::string s2;
//				for(int i = 0; i < s.size()-1; ++i){
//					s2 += s[i];
//					s2 += tmp[i];
//				}
//				s2 += s[s.size()-1];
//				
//				s = s2;
//			}
		}else if(op==3){
			int l,r;
			std::cin >> l >> r;
			--l;
			--r;
//			std::cout << "q:" << q << "\n";
//			std::cout << "l,r:" << l << " " << r << "\n";

//			std::cout << "---\n";
//			
//			for(int i = l; i <= r; ++i){
//				std::cout << s[i]-'a'+1 << " \n"[i==r];
//			}
//			
//			std::cout << "---\n";
			
			std::reverse(s.begin()+l,s.begin()+r+1);
			
//			for(int i = l; i <= r; ++i){
//				std::cout << s[i]-'a'+1 << " \n"[i==r];
//			}
//			
//			std::cout << "---\n";
		}
		
//		if(q==1){
//			for(int i = 0; i < s.size(); ++i){
//				std::cout << s[i]-'a'+1 << " \n"[i+1==s.size()];
//			}
//			std::cout << s.size() << "\n";
//		}
			
	}
	
	for(int i = 0; i < s.size(); ++i){
		std::cout << s[i]-'a'+1 << " \n"[i+1==s.size()];
	}
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
