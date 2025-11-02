#include <bits/stdc++.h>

//kmp

/*

*/

using i64 = long long;

void get_next(std::string &s,std::vector<int> &next){
  int i = 1,j = 0;
  next[1] = 0;
  while(i<s.size()){
    if(j==0 || s[i]==s[j]){
      ++i,++j;
      next[i] = j;
    }else{
      j = next[j];
    }
  }
}

int kmp(std::string &s,std::string &t,std::vector<int> &next){
  int i = 1,j = 1;
  while(i<=s.size() && j<=t.size()){
    if(j==0 || s[i]==t[j]){
      ++i,++j;
    }else{
      j = next[j];
    }
  }
  if(j>t.size()){
    return i-t.size();
  }
  return 0;
}

int main(){
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::string s,t;
  std::cin >> s >> t;

  std::vector<int> next(t.size());

  get_next(t,next);

  std::cout << kmp(s,t,next) << "\n";

  return 0;
}