//dp数组要根据实际情况决定用几维的数组，b数组用来保存数字位
int dp[len][状态],b[10];

int dfs(int pos,int state,bool is_max){//可以根据需要，添加state参数的数量
	if(pos==0) return 1;
	if(!is_max&&dp[pos][state]!=-1) return dp[pos][state];
	int ed = is_max?b[pos]:9;//如果前面放满了就只能循环到b[pos]，否则循环到9
	int ans = 0;
	for(int i = 0;i<=ed;++i){
		if(满足某种条件){
			ans += dfs(pos-1,state,is_max&&i==ed);//最后一个参数，前面都放满，本位又最大
		}
	}
	if(!is_max) dp[pos][state] = ans;
	return ans;
}