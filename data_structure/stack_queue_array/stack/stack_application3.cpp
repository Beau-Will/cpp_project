#include <bits/stdc++.h>

//使用栈实现递归

/*
计算斐波那契数列
F(n) = F(n-1)+F(n-2) ,n>1
F(n) = 1 ,n=1
F(n) = 0 ,n=0

正常写递归应该是这样的:
i64 F(int n){
  if(n==0){
    return 0LL;
  }
  if(n==1){
    return 1LL;
  }
  return F(n-1)+F(n-2);
}

拓展（自己思考）：
考虑使用记忆化搜索剪枝
std::vector<i64> f(MAXN,-1);//MAXN开的足够大

int F(int n){
  if(f[n]!=-1){
    return f[n];
  }
  if(n==0){
    return f[0] = 0;
  }
  if(n==1){
    return f[1] = 1;
  }
  return f[n] = F(n-1)+F(n-2);
}
*/

using i64 = long long;

int main(){
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  std::cin >> n;

  if(n==0){
    std::cout << "0\n";
    return 0;
  }

  if(n==1){
    std::cout << "1\n";
    return 0;
  }

  std::stack<i64> stk;
  stk.push(0);
  stk.push(1);

  for(int i = 2; i <= n; ++i){
    //取出F(n-1)
    i64 Fn_1 = stk.top();
    stk.pop();
    //取出F(n-2)
    i64 Fn_2 = stk.top();
    stk.pop();

    //F(n-1)就是原来的F(n-2)
    stk.push(Fn_1);
    //F(n)就是原来的F(n-1)+F(n-2)
    stk.push(Fn_1+Fn_2);
  }

  std::cout << stk.top() << "\n";

  return 0;
}