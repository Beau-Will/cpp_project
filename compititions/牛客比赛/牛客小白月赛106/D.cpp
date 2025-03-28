// Problem: 太阳系DISCO
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/97439/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std::pair<int,int>;
constexpr int N = 2e5+5,M = 1e6+5,INF = 0x3f3f3f3f;
#define pb emplace_back
#define all(v) v.begin(),v.end()
#define push emplace

i64 n,k,a,b,x,y;

using Node = std::array<i64,3>;
std::vector<bool> vis(N,false);

void bfs(){
	std::queue<Node> q;
	Node tt;
	tt[0] = a,tt[1] = 0,tt[2] = 0;//tt[2]表示使用了跳到对面的次数
	vis[a] = true;
	q.push(tt);
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		if(t[0]==b){
			std::cout << t[1] << '\n';
			return;
		}
		for(int i = 0;i<3;++i){
			Node t1;
			if(i==0){//顺时针走
				if(t[0]+x>n){
					t1[0] = x-n+t[0];
				}else{
					t1[0] = t[0]+x;
				}
				t1[2] = t[2];
			}else if(i==1){//逆时针走
				if(t[0]-y<1){
					t1[0] = n+t[0]-y;
				}else{
					t1[0] = t[0]-y;
				}
				t1[2] = t[2];
			}else if(t[2]<k){//i==2，跳到对面
				i64 d = n/2;
				if(t[0]+d>n){
					t1[0] = d-n+t[0];
				}else{
					t1[0] = t[0]+d;
				}
				t1[2] = t[2]+1;
			}
			if(vis[t1[0]]) continue;
			vis[t1[0]] = true;
			t1[1] = t[1]+1;
			q.push(t1);
		}
	}
	std::cout << "-1" << '\n';
}

void solve(){
	std::cin >> n >> k >> a >> b >> x >> y;
	
	bfs();
	
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int tt = 1;
	// std::cin >> tt;
	for(int ti = 0;ti<tt;++ti){
		solve();
	}
	
	return 0;
}