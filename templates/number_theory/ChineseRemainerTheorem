int n;
std::vector<int> a,m;
//有n个同余方程，都有x = ai (mod mi)，求x
//要求模数两两互质
int exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x = a,y = 0;
		return a;
	}
	int d = exgcd(b,a%b,x,y);
	int tmp = x;
	x = y;
	y = tmp-(a/b)*y;
	return d;
}

int ChineseRemainerTheorem(){
	int ans = 0;
	int M = 1;
	for(int i = 0;i<n;++i){
		M *= m[i];
	}
	for(int i = 0;i<n;++i){
		int Mi = M/m[i];
		int xi,yi;
		int gcd = exgcd(Mi,m[i],xi,yi);
		ans = (ans+Mi*xi*a[i])%M;
	}
	return (ans+M)%M;
}
