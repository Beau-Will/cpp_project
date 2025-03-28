using u64 = unsigned long long;
constexpr int N = 1e5+5,P = 131;//P=131或P=13331冲突概率小
int n,m;
std::string s;
//字符串hash最后需要对2^64取模，直接使用u64，溢出就相当于取模了
std::vector<u64> h(N,0),p(N,0);//N比字符串s的size要大
//查询[l,r]区间的字符串哈希值，区间左闭右闭
u64 get(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];
}
//读入n和s后先调用pre函数预处理出p数组和字符串哈希值
//注意s的有效存储下标从1开始，因此读入后需要 s = ' '+s;
void pre(){
	p[0] = 1;
	for(int i = 1;i<=n;++i){
	    p[i] = p[i-1]*P;
	    h[i] = h[i-1]*P+s[i];
	}
}