#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x){
	static char ch;x = 0;ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x*10+ch-'0',ch = getchar();
}
inline void write(int x){if(x>9) write(x/10);putchar(x%10+'0');}
const int N = 2005,M = 2005;
int n,m,ax[N],ay[N],bx[M],by[M],ans = 2000000,mx[1000005];
int main(){
	int i,j;
	read(n),read(m);
	for(int i = 1;i<=n;++i) read(ax[i]),read(ay[i]);
	for(int i = 1;i<=m;++i) read(bx[i]),read(by[i]);
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			if(ax[i]<=bx[j]&&ay[i]<=by[j]){
				mx[bx[j]-ax[i]] = max(mx[bx[j]-ax[i]],by[j]-ay[i]+1);
			}
		}
	}
	for(int i = 1000000;i;--i) mx[i-1] = max(mx[i-1],mx[i]);
	for(int i = 0;i<=1000000;++i) ans = min(ans,i+mx[i]);
	cout << ans << '\n';
	return 0;
}