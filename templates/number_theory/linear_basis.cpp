//线性基构造（不是最简线性基）
std::vector<i64> d(63);
for(int i = 0;i<n;++i){
	int x = a[i];
	for(int j = 62;j>=0;--j){
		if(x&(1LL<<j)){
			if(d[j]==0){
				d[j] = x;
				break;
			}else{
				x ^= d[j];
			}
		}
	}
}
//化成最简线性基（改造线性基）
for(int i = 0;i<62;++i){
	for(int j = i-1;j>=0;--j){
		if(d[i]&&(1LL<<j)){
			d[i]^=d[j];
		}
	}
}
//判断x是否可以由线性基异或得到
auto check = [&](i64 x){
	for(int i = 62;i>=0;--i){
		if(x&(1LL<<i)){
			if(d[i]==0){
				return false;
			}else{
				x ^= d[i];
			}
		}
	}
	return x==0;
};
//求异或最大值
i64 ans = 0;
for(int i = 62;i>=0;--i){
	if((ans&(1LL<<i))==0&&d[i]){
		ans ^= d[i];
	}
}
//求异或最小值
i64 ans = 0;
int cnt = 0;
for(int i = 0;i<=62;++i){
	if(d[i]){
		++cnt;
	}
}
if(cnt<n){
	ans = 0;
}else{
	for(int i = 0;i<=62;++i){
		if(d[i]){
			ans = d[i];
			break;
		}
	}
}
//求异或第k小的值
//必须先将线性基化成最简线性基
int k;//查询第k小
i64 ans = 0;
int cnt = 0;
for(int i = 0;i<=62;++i){
	if(d[i]){
		++cnt;
	}
}

auto query = [&](){
	i64 res = 0;
	for(int i = 0;i<=62;++i){
		if(((k>>i)&1)&&d[i]){
			res ^= d[i];
		}
	}
	return res;
};

if(cnt<n&&k==1){//特殊情况特判
	ans = 0;
}else{
	if(cnt<n){//能产生0，k需要-1
		--k;
	}
	if(max_knum<k){//线性基能产生的最大元素个数小于k
		ans = -1;
	}else{
		ans = query();//一般情况
	}
}
