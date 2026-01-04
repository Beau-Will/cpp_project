#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  std::vector<i64> odd(1),even(1);
  for(int i = 0; i < n; i++){
    if(a[i] & 1){
      odd.push_back(a[i]);
    }else{
      even.push_back(a[i]);
    }
  }

  std::sort(odd.begin()+1,odd.end(),std::greater<i64>());
  std::sort(even.begin()+1,even.end(),std::greater<i64>());

  if(odd.size()-1 == 0){
    for(int i = 0; i < n; i++){
      std::cout << 0 << " \n"[i+1==n];
    }
    return;
  }

  int maxOdd = odd[1];
  if(even.size()-1 == 0){
    for(int i = 0; i < n; i++){
      if(i & 1){
        std::cout << 0 << " \n"[i+1==n];
      }else{
        std::cout << maxOdd << " \n"[i+1==n];
      }
    }
    return;
  }

  if(odd.size()-1 == 1){
    std::cout << maxOdd << " ";
    i64 sum = 0;
    for(int i = 1; i < even.size(); i++){
      sum += even[i];
      std::cout << maxOdd+sum << " \n"[i+1==even.size()];
    }
    return;
  }

  if(even.size()-1 == 1){
    std::cout << maxOdd << " ";
    std::cout << maxOdd+even[1] << " ";
    for(int i = 2; i < odd.size(); i++){
      if(i & 1){
        std::cout << maxOdd+even[1] << " \n"[i+1==odd.size()];
      }else{
        if(odd.size()-1-i >= 1){
          std::cout << maxOdd << " \n"[i+1==odd.size()];
        }else{
          std::cout << 0 << " \n"[i+1==odd.size()];
        }
      }
    }
    return;
  }

  std::cout << maxOdd << " ";
  i64 sum1 = 0,sum2 = 0;
  for(int i = 1; i < even.size(); i++){
    sum1 += even[i];
    if(i+1 != even.size()){
      sum2 += even[i];
    }
    std::cout << maxOdd+sum1 << " ";
  }
  for(int i = 2; i < odd.size(); i++){
    if(i & 1){
      std::cout << maxOdd+sum1 << " \n"[i+1==odd.size()];
    }else{
      if(i+1 == odd.size()){
        std::cout << "0\n";
      }else{
        std::cout << maxOdd+sum2 << " ";
      }
    }
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;
  for(; T--;){
    solve();
  }

  return 0;
}