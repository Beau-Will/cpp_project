#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int m, q;
  std::cin >> m >> q;

  std::vector<int> a(m + 1);
  int cnt = 0;

  for(int qi = 0; qi < q; qi++){
    int op, num;
    std::cin >> op >> num;

    for(const auto& j : {num - 3, num + 3}){
      if(j > m || j < 1){
        continue;
      }
      if(op == 1){
        if(a[j] == 0){
          cnt++;
        }
        a[j]++;
      }else{
        if(a[j] == 1){
          cnt--;
        }
        a[j]--;
      }
    }

    std::cout << cnt << "\n";
  }

  return 0;
}