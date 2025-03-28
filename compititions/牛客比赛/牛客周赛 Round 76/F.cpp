// Problem: 同位序列
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/99990/F
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int n;std::cin >> n;
	
	struct Node{
		int val,cnt;
	};
	
	std::vector<Node> a(n);
	for(int i = 0;i<n;++i){
		std::cin >> a[i].val;
		a[i].cnt =  __builtin_popcount(a[i].val);
	}
	
	std::sort(a.begin(),a.end(),[&](const Node &t1,const Node &t2)->bool{
		if(t1.cnt!=t2.cnt) return t1.cnt<t2.cnt;
		return t1.val < t2.val;
	});
	
	int ans = 0;
	int ans_st = -1,ans_ed = -1;
	int j = 0;
	for(int i = 0;i<n;++i){
		while(j<n&&a[i].cnt==a[j].cnt){
			++j;
		}
		// ans = std::max(ans,j-i);
		if(j-i>ans){
			ans = j-i;
			ans_st = i,ans_ed = j;
		}
		i = j;
	}
	
	std::cout << ans << '\n';
	for(int i = ans_st;i<ans_ed;++i){
		std::cout << a[i].val << " \n"[i==ans_ed-1];
	}
	
	// int ans = 0;
	// for(int i = 0;i<n;++i){
		// int x = a[i];
		// int loc = -1;
		// bool flag = false;
		// for(int j = 0;j<=30;++j){
			// if((x>>j&1)&&!flag){
				// flag = true;
				// loc = j;
			// }else if(x>>j&1){
				// continue;
			// }else{
				// x-=lowbit;
				// x+=1<<j;
			// }
		// }
// 		
	// }
	
	return 0;
}