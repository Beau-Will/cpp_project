#include<bits/stdc++.h>
using i64 = long long;

i64 n,m;
std::vector<i64> a;
std::vector<i64> pre_sum;

void solve(){
	std::cin >> n >> m;
	
	a.resize(n+1);
	pre_sum.resize(n+1);
	
	for(int i = 1;i<=n;++i){
		std::cin >> a[i];
	}
	
	std::sort(a.begin()+1,a.end(),std::greater<i64>());
	
	for(int i = 1;i<=n;++i){
		pre_sum[i] = pre_sum[i-1]+a[i];
	}
	
	i64 ans = 0;
	//二分枚举第m大的数
	i64 low = 2*a[n],high = 2*a[1];
	while(low<high){
		i64 mid = (low+high)/2;
		//check begin
		i64 sum = 0,cnt = 0;
		for(int i = 1;i<=n;++i){
			//用lower_bound先初步找到第一个大于等于mid-a[i]的下标
			int idx = std::lower_bound(a.begin()+1,a.end(),mid-a[i],std::greater<i64>())-a.begin();
			int tmp = idx;
			for(;idx>=1;--idx){//找第一个严格大于mid-a[i]的数
				if(a[idx]!=a[tmp]){
					break;
				}
			}
			cnt+=idx;
			sum+=idx*a[i]+pre_sum[idx];
		}
		//check end
		if(cnt<m){//最后一次进入到这算出的ans就是答案
			ans = sum+(m-cnt)*mid;
			high = mid;
		}else{
			low = mid+1;
		}
	}
	
	std::cout << ans << '\n';
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