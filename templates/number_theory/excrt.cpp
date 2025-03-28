i64 exgcd(i64 a,i64 b,i64 &x,i64 &y)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	i64 d = exgcd(b,a%b,x,y);
	int tmp = x;
	x = y;
	y = tmp-y*(a/b);
	return d;
}
i64 ksc(i64 a,i64 b,i64 mod)
{
	return (a*b-(i64)((long double)a/mod*b)*mod+mod)%mod;
}
i64 excrt(i64 b[],i64 m[],i64 n)
{
	i64 ans = b[1],M = m[1],d,x,y;
	for(int i = 2;i <= n;i++)
	{
		d = exgcd(M,m[i],x,y);
		i64 c = ((b[i]-ans)%m[i]+m[i])%m[i];
		if(c%d) return -1; // 无解 
		x = ksc(c/d,x,m[i]/d);//x = c/d*x%(m[i]/d);
		ans += M*x;
		M = M/d*m[i];
		ans = (ans%M+M)%M;
	}
	return (ans%M+M)%M;
}