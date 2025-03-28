std::string a,b;
int n,m;
std::vector<int> p(N);

void pre(){//预处理查找next数组
	p[1] = 0;
	int j = 0;
	for(int i = 1;i<m;++i){
		while(j>0&&b[j+1]!=b[i+1]) j = p[j];
		if(b[j+1]==b[i+1]) ++j;
		p[i+1] = j;
	}
}

int kmp(){
	pre();
	int ans = 0,j = 0;
	for(int i = 0;i<n;++i){
		while(j>0&&b[j+1]!=a[i+1]){
			j = p[j];
		}
		if(b[j+1]==a[i+1]) ++j;
		if(j==m){
			std::cout << i-m+2 << '\n';
			++ans;
			j = p[j];//可重叠继续寻找匹配
			// j = 0;//不可重叠继续寻找匹配
		}
	}
	return ans;
}