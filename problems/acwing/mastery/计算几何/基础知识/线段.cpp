#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

// 默认精度
constexpr double EPS = 1e-8;

// 通用符号函数模板
template<typename T>
constexpr int sgn(T x,
                  typename std::enable_if < !std::is_floating_point<T>::value >::type* =
                    nullptr) {
  // 整型版本：精确比较
  return (x > T(0)) ? 1 : ((x < T(0)) ? -1 : 0);
}

// 浮点型符号函数模板（带默认精度）
template<typename T>
constexpr int sgn(T x, double eps = EPS,
                  typename std::enable_if<std::is_floating_point<T>::value>::type* = nullptr) {
  // 浮点型版本：考虑精度误差
  if (x > eps) return 1;
  if (x < -eps) return -1;
  return 0;
}

// 浮点型符号函数模板（指定精度）
template<typename T>
constexpr int sgn(T x, T eps,
                  typename std::enable_if<std::is_floating_point<T>::value>::type* = nullptr) {
  // 浮点型版本：使用相同类型的eps
  if (x > eps) return 1;
  if (x < -eps) return -1;
  return 0;
}

// 使用SFINAE的另一种实现方式（更现代）
template<typename T>
constexpr auto sgn2(const T& x, double eps = EPS) ->
typename std::enable_if<std::is_arithmetic<T>::value, int>::type {
  if constexpr (std::is_floating_point<T>::value) {
    if (x > eps) return 1;
    if (x < -eps) return -1;
    return 0;
  } else {
    // 整型版本
    return (x > T(0)) ? 1 : ((x < T(0)) ? -1 : 0);
  }
}

// 计算几何中常用的比较函数（基于sgn）
template<typename T>
constexpr bool eq(T a, T b, double eps = EPS) {
  if constexpr (std::is_floating_point<T>::value) {
    return std::abs(a - b) < eps;
  } else {
    return a == b;
  }
}

template<typename T>
constexpr bool lt(T a, T b, double eps = EPS) {
  if constexpr (std::is_floating_point<T>::value) {
    return a < b - eps;
  } else {
    return a < b;
  }
}

template<typename T>
constexpr bool le(T a, T b, double eps = EPS) {
  if constexpr (std::is_floating_point<T>::value) {
    return a < b + eps;
  } else {
    return a <= b;
  }
}

template<typename T>
constexpr bool gt(T a, T b, double eps = EPS) {
  return lt(b, a, eps);
}

template<typename T>
constexpr bool ge(T a, T b, double eps = EPS) {
  return le(b, a, eps);
}

// 在Point结构体中添加符号函数支持
template<class T>
struct Point {
  T x, y;

  // 构造函数
  constexpr Point() : x(0), y(0) {}
  constexpr Point(T x_, T y_) : x(x_), y(y_) {}

  // 拷贝构造函数
  constexpr Point(const Point& p) : x(p.x), y(p.y) {}

  // 从其他类型Point转换的构造函数
  template<class U>
  constexpr explicit Point(const Point<U>& p) : x(static_cast<T>(p.x)),
    y(static_cast<T>(p.y)) {}

  // 赋值运算符
  constexpr Point& operator=(const Point& p) {
    if (this != &p) {
      x = p.x;
      y = p.y;
    }
    return *this;
  }

  // 比较运算符
  constexpr bool operator==(const Point& p) const {
    if constexpr (std::is_floating_point<T>::value) {
      return eq(x, p.x) && eq(y, p.y);
    } else {
      return x == p.x && y == p.y;
    }
  }

  constexpr bool operator!=(const Point& p) const {
    return !(*this == p);
  }

  constexpr bool operator<(const Point& p) const {
    if constexpr (std::is_floating_point<T>::value) {
      return lt(x, p.x) || (eq(x, p.x) && lt(y, p.y));
    } else {
      return x < p.x || (x == p.x && y < p.y);
    }
  }

  constexpr bool operator<=(const Point& p) const {
    return !(p < *this);
  }

  constexpr bool operator>(const Point& p) const {
    return p < *this;
  }

  constexpr bool operator>=(const Point& p) const {
    return !(*this < p);
  }

  // 算术运算符
  constexpr Point operator+(const Point& p) const {
    return Point(x + p.x, y + p.y);
  }

  constexpr Point operator-(const Point& p) const {
    return Point(x - p.x, y - p.y);
  }

  // 数乘数除
  template<class U>
  constexpr Point operator*(U scalar) const {
    return Point(x * scalar, y * scalar);
  }

  template<class U>
  constexpr Point operator/(U scalar) const {
    // 避免除以0
    if (scalar == 0) {
      throw std::runtime_error("Division by zero");
    }
    return Point(x / scalar, y / scalar);
  }

  // 点乘（数乘的另一种形式）
  constexpr T operator*(const Point& p) const {
    return dot(p);
  }

  // 复合赋值运算符
  constexpr Point& operator+=(const Point& p) {
    x += p.x;
    y += p.y;
    return *this;
  }

  constexpr Point& operator-=(const Point& p) {
    x -= p.x;
    y -= p.y;
    return *this;
  }

  template<class U>
  constexpr Point& operator*=(U scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
  }

  template<class U>
  constexpr Point& operator/=(U scalar) {
    if (scalar == 0) {
      throw std::runtime_error("Division by zero");
    }
    x /= scalar;
    y /= scalar;
    return *this;
  }

  // 一元运算符
  constexpr Point operator+() const {
    return *this;
  }

  constexpr Point operator-() const {
    return Point(-x, -y);
  }

  // 点积（内积）
  constexpr T dot(const Point& p) const {
    return x * p.x + y * p.y;
  }

  // 叉积（外积，返回标量）
  constexpr T cross(const Point& p) const {
    return x * p.y - y * p.x;
  }

  // 向量的模长平方（避免开方提高性能）
  constexpr T len2() const {
    return x * x + y * y;
  }

  // 向量的模长
  double len() const {
    return std::sqrt(static_cast<double>(len2()));
  }

  // 单位向量（返回浮点类型）
  Point<double> unit() const {
    double l = len();
    if (l == 0) return Point<double>(0, 0);
    return Point<double>(x / l, y / l);
  }

  // 点到原点的距离
  double dist() const {
    return len();
  }

  // 两点间距离
  double dist(const Point& p) const {
    return (*this - p).len();
  }

  // 两点间距离平方
  constexpr T dist2(const Point& p) const {
    return (*this - p).len2();
  }

  // 旋转（绕原点逆时针旋转角度theta，弧度制）
  Point<double> rotate(double theta) const {
    double cos_theta = cos(theta);
    double sin_theta = sin(theta);
    return Point<double>(
             x * cos_theta - y * sin_theta,
             x * sin_theta + y * cos_theta
           );
  }

  // 旋转（绕点p逆时针旋转角度theta）
  Point<double> rotate(const Point& p, double theta) const {
    Point<double> translated = Point<double>(*this) - Point<double>(p);
    Point<double> rotated = translated.rotate(theta);
    return rotated + Point<double>(p);
  }

  // 法向量（逆时针旋转90度）
  constexpr Point perpendicular() const {
    return Point(-y, x);
  }

  // 归一化（原地修改，返回模长）
  double normalize() {
    double l = len();
    if (l > 0) {
      x /= l;
      y /= l;
    }
    return l;
  }

  // 判断点是否在原点
  constexpr bool is_zero() const {
    return x == 0 && y == 0;
  }

  // 判断向量是否平行（共线）
  constexpr bool is_parallel(const Point& p) const {
    return cross(p) == 0;
  }

  // 判断向量是否垂直
  constexpr bool is_perpendicular(const Point& p) const {
    return dot(p) == 0;
  }

  // 计算与另一向量的夹角（弧度）
  double angle(const Point& p) const {
    if (is_zero() || p.is_zero()) {
      throw std::runtime_error("Cannot compute angle with zero vector");
    }
    double cos_theta = dot(p) / (len() * p.len());
    // 处理浮点精度误差
    cos_theta = std::max(-1.0, std::min(1.0, cos_theta));
    return std::acos(cos_theta);
  }

  // 投影：该向量在另一向量上的投影向量
  Point<double> project(const Point& p) const {
    if (p.is_zero()) {
      throw std::runtime_error("Cannot project onto zero vector");
    }
    double scalar = static_cast<double>(dot(p)) / p.len2();
    return Point<double>(p) * scalar;
  }

  // 反射：该向量关于另一向量的反射向量
  Point<double> reflect(const Point& p) const {
    Point<double> proj = project(p);
    return proj * 2.0 - Point<double>(*this);
  }

  // 输出点坐标
  void print() const {
    std::cout << "(" << x << ", " << y << ")";
  }

  // 判断点是否近似相等
  constexpr bool approx_equal(const Point& p, double eps = EPS) const {
    return eq(x, p.x, eps) && eq(y, p.y, eps);
  }

  // 判断向量是否近似平行
  constexpr bool is_parallel_approx(const Point& p, double eps = EPS) const {
    return eq(cross(p), T(0), eps);
  }

  // 判断向量是否近似垂直
  constexpr bool is_perpendicular_approx(const Point& p, double eps = EPS) const {
    return eq(dot(p), T(0), eps);
  }

  // 友元函数：输入输出运算符
  friend std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
  }

  friend std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
  }
};

// 全局函数：数乘（支持左侧数乘）
template<class T, class U>
constexpr Point<T> operator*(U scalar, const Point<T>& p) {
  return p * scalar;
}

// 类型别名
using Pointi32 = Point<int>;
using Pointi64 = Point<i64>;
using Pointf32 = Point<float>;
using Pointf64 = Point<double>;

// 几何关系判断函数
template<class T>
constexpr bool collinear(const Point<T>& a, const Point<T>& b,
                         const Point<T>& c) {
  return (b - a).cross(c - a) == 0;
}

template<class T>
constexpr bool clockwise(const Point<T>& a, const Point<T>& b,
                         const Point<T>& c) {
  return (b - a).cross(c - a) < 0;
}

template<class T>
constexpr bool counter_clockwise(const Point<T>& a, const Point<T>& b,
                                 const Point<T>& c) {
  return (b - a).cross(c - a) > 0;
}

template<class T>
constexpr T signed_area(const Point<T>& a, const Point<T>& b,
                        const Point<T>& c) {
  return (b - a).cross(c - a);
}

template<class T>
T area(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
  return std::abs(signed_area(a, b, c));
}

// 如果需要三角形面积（带符号，有向面积）
template<class T>
double signed_triangle_area(const Point<T>& a, const Point<T>& b,
                            const Point<T>& c) {
  return static_cast<double>(signed_area(a, b, c)) / 2.0;
}

// 如果需要三角形面积（绝对值）
template<class T>
double triangle_area(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
  return std::abs(signed_triangle_area(a, b, c));
}

// 使用sgn判断三点方向
template<class T>
constexpr int orientation(const Point<T>& A, const Point<T>& B,
                          const Point<T>& C) {
  T cross_val = (B - A).cross(C - A);
  return sgn(cross_val);
}

// 判断点C在向量AB的哪一侧
template<class T>
constexpr int side_of_line(const Point<T>& A, const Point<T>& B,
                           const Point<T>& C) {
  return orientation(A, B, C);
}

void solve(){
  int n;
  std::cin >> n;

  std::vector<Pointf64> a(n), b(n), p;
  for(int i = 0; i < n; i++){
    std::cin >> a[i] >> b[i];
    p.push_back(a[i]);
    p.push_back(b[i]);
  }

  for(int i = 0; i < p.size(); i++){
    for(int j = i + 1; j < p.size(); j++){
      if(!sgn(p[i].x - p[j].x) && !sgn(p[i].y - p[j].y)){
        continue;
      }

      bool isok = true;
      for(int k = 0; k < n; k++){
        if(sgn(signed_area(p[i], p[j], a[k])) * sgn(signed_area(p[i], p[j], b[k])) > 0){
          isok = false;
          break;
        }
      }

      if(isok){
        std::cout << "Yes!\n";
        return;
      }
    }
  }

  std::cout << "No!\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}