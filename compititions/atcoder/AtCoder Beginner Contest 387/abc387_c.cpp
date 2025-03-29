// Problem: C - Snake Numbers
// Contest: AtCoder - AtCoder Beginner Contest 387
// URL: https://atcoder.jp/contests/abc387/tasks/abc387_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

/*
10 100
2 C(2,1) 
*/

/*
abc defg
if(b>=a||c>=a) 0
else a*C(a-1-b,1)*C(a-1-c,1)
(a+1)2*C(a+1,1)
...
(9)2*C(a+1,1)


def
d00 def
1*(d-e)*(d-f)
*/

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	std::string l,r;std::cin >> l >> r;
	
	i64 ans = 0;
	
	if(l.size()==r.size()){
		for(char c = l[0];c<='9'&&c<=r[0];++c){
			
		}
	}
	
	for(char c = l[0];c<='9';++c){
		int t = c^48;
		if(c==l[0]){
			i64 tmp = 1;
			bool flag  = true;
			for(int i = 1;i<l.size();++i){
				if(l[i]>=c){
					flag = false;
					break;
				}
				tmp *= t-1-(l[i]^48);
			}
			if(flag) ans+=tmp;
		}else{
			ans += t*(l.size()-1);
		}
	}
	
	
	return 0;
}