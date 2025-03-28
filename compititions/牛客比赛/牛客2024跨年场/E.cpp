// Problem: 华灯初上
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/98985/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using i64 = long long;

std::string s;
std::vector<std::string> a(9);
std::vector<int> cnt(9,0);
int ans1 = 10,ans2 = 10;

std::vector<int> b(9,0);

void dfs1(int u){
	if(u==9){
		std::vector<int> cur(9,0);
		int res = 0;
		for(int i = 0;i<9;++i){
			if(b[i]==1){
				++res;
				if(s[i]=='0'){
					for(int j = 0;j<9;++j){
						cur[j]+=(a[i][j]=='1');
					}
				}
			}else{
				if(s[i]=='1'){
					for(int j = 0;j<9;++j){
						cur[j]+=(a[i][j]=='1');
					}
				}
			}
		}
		for(int i = 0;i<9;++i){
			if(cur[i]!=cnt[i]||cur[i]==0){
				return;
			}
		}
		ans1 = std::min(ans1,res);
		return;
	}
	b[u] = 0;
	dfs1(u+1);
	b[u] = 1;
	dfs1(u+1);
}

void dfs2(int u){
	if(u==9){
		std::vector<int> cur(9,0);
		int res = 0;
		for(int i = 0;i<9;++i){
			if(b[i]==1){
				++res;
				if(s[i]=='0'){
					for(int j = 0;j<9;++j){
						cur[j]+=(a[i][j]=='1');
					}
				}
			}else{
				if(s[i]=='1'){
					for(int j = 0;j<9;++j){
						cur[j]+=(a[i][j]=='1');
					}
				}
			}
		}
		for(int i = 0;i<9;++i){
			if(cnt[i]==0) continue;
			if(cur[i]==cnt[i]){
				return;
			}
		}
		ans2 = std::min(ans2,res);
		return;
	}
	b[u] = 0;
	dfs2(u+1);
	b[u] = 1;
	dfs2(u+1);
}

void solve(){
	
	std::cin >> s;
	
	for(int i = 0;i<9;++i){
		std::cin >> a[i];
	}
	
	cnt.assign(9,0);
	
	for(int i = 0;i<9;++i){
		for(int j = 0;j<9;++j){
			if(a[i][j]=='1'){
				++cnt[j];
			}
		}
	}
	
	ans1 = 10;
	b.assign(9,0);
	dfs1(0);
	
	ans2 = 10;
	b.assign(9,0);
	dfs2(0);
	
	std::cout << (ans1==10?-1:ans1) << ' ' << ans2 << '\n';
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int tt = 1;
	std::cin >> tt;
	for(int ti = 0;ti<tt;++ti){
		solve();
	}
	
	return 0;
}