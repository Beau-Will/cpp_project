#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

template<typename T>
struct Point{
  T x, y;

  Point(){}
  Point(T a, T b): x(a), y(b){}

  T cross(const Point& other){
    return x * other.y - y * other.x;
  }

  friend std::istream& operator >> (std::istream& in, Point& p){
    in >> p.x >> p.y;
    return in;
  }
  friend std::ostream& operator << (std::ostream& out, Point& p){
    out << p.x << p.y;
    return out;
  }
};

using Pointf64 = Point<double>;

constexpr double eps = 1E-10;

/*
A: (xa, ya)
B: (xb, yb)
O: (x, 0)

OA = (xa - x, ya)
OB = (xb - x, yb)

S(OAB)  = OA.cross(OB) / 2
4       = (xa - x) * yb - ya * (xb - x)
        = xa * yb - x * yb - ya * xb + ya * x
=>
4 - xa * yb + ya * xb = -x * yb + ya * x
即(ya - yb) * x = 4 - xa * yb + ya * xb
x = (4 - xa * yb + ya * xb) / (ya - yb)
即 x = (4 - A.cross(B)) / (A.y - B.y)
*/

void solve(){
  Pointf64 A, B, O;
  std::cin >> A >> B;

  if(std::abs(A.y - B.y) < eps){
    if(std::abs(4. - std::abs(A.cross(B))) < eps){
      std::cout << std::fixed << std::setprecision(9) << 0. << "\n";
    }else{
      std::cout << "no answer\n";
    }
  }else{
    std::cout << std::fixed << std::setprecision(9) << (4. - A.cross(B)) / (A.y - B.y) << "\n";
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}