#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s;
  std::cin >> s;

  int c = s.size()-1;
  int a = s[0]-'0';
  int b = 0;

  if(s.size() > 1){
    b = s[1]-'0';
  }
  if(s.size() > 2){
    if((s[2]-'0') >= 5){
      b++;
    }
  }
  if(b == 10){
    b = 0;
    a++;
  }
  if(a == 10){
    a = 1;
    c++;
  }

  std::cout << a << "." << b << "*10^" << c << "\n";
}