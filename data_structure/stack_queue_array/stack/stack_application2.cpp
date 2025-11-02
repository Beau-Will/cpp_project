#include <bits/stdc++.h>

//中缀表达式转后缀表达式

/*
样例：
A+B*(C-D)-E/F
结果：
ABCD-*+EF/-
*/

int main(){
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::string s;
  std::cin >> s;

  //定义优先级
  std::unordered_map<char, int> pri;
  pri['+'] = 0;
  pri['-'] = 0;
  pri['*'] = 1;
  pri['/'] = 1;
  pri['('] = 2;
  pri[')'] = 2;

  std::stack<char> stk;
  std::string ans;

  for(const auto &c:s){
    //处理字母和数字
    if(c!='+'&&c!='-'&&c!='*'&&c!='/'&&c!='('&&c!=')'){
      ans += c;
    //处理符号
    }else{
      if(stk.empty()){
        stk.push(c);
      }else{
        //栈顶元素优先级小于等于当前元素优先级且当前元素不是右括号
        if(pri[c]>=pri[stk.top()] && c!=')'){
          stk.push(c);
        //当前元素是右括号
        }else if(c == ')'){
          //一直弹出栈顶元素，直到栈顶为左括号
          while(!stk.empty()&&stk.top() != '('){
            ans += stk.top();
            stk.pop();
          }
          //弹出左括号
          if(!stk.empty()){
            stk.pop();
          }
        //栈顶元素优先级大于当前元素优先级
        }else{
          //栈顶元素为左括号
          if(stk.top()=='('){
            stk.push(c);
          //栈顶元素为其他运算字符
          }else{
            //弹出栈顶元素直到栈为空或栈顶元素优先级大于当前元素优先级
            while(!stk.empty()&&pri[c]<=pri[stk.top()]){
              ans += stk.top();
              stk.pop();
            }
            //不要忘记将当前元素入栈
            stk.push(c);
          }
        }
      }
    }
  }

  //弹出栈内剩余元素
  while(!stk.empty()){
    ans += stk.top();
    stk.pop();
  }

  std::cout << ans << "\n";

  return 0;
}