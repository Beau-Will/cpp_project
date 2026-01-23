#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

/*
二维差分树状数组（支持区间修改、单点查询）
1-based索引
*/
template<typename T>
struct RangePointFenwick2D {
  int n,m;
  std::vector<std::vector<T>> tr;

  // 构造函数，初始化n行m列的二维树状数组
  RangePointFenwick2D(int n_,int m_):n(n_),m(m_),tr(n_+2,std::vector<T>(m_+2,0)){}

  int lowbit(int x){
    return x & -x;
  }

  // 内部：在位置(x,y)增加v
  void add(int x,int y,T v){
    for(int i = x; i <= n; i += lowbit(i)){
      for(int j = y; j <= m; j += lowbit(j)){
        tr[i][j] += v;
      }
    }
  }

  // 内部：查询前缀和(1,1)到(x,y)
  T query(int x,int y){
    T res = T();
    for(int i = x; i > 0; i -= lowbit(i)){
      for(int j = y; j > 0; j -= lowbit(j)){
        res += tr[i][j];
      }
    }
    return res;
  }

  // 区间修改：给子矩阵(x1,y1)到(x2,y2)的所有元素增加v
  void modify(int x1,int y1,int x2,int y2,T v){
    add(x1,y1,v);
    add(x1,y2+1,-v);
    add(x2+1,y1,-v);
    add(x2+1,y2+1,v);
  }
};

using RangePointBIT2D = RangePointFenwick2D<i64>;

void solve(){
  int n,m;
  std::cin >> n >> m;

  RangePointBIT2D fen(n,m);

  int op,a,b,c,d,k,x,y;
  while(std::cin >> op){
    if(op == 1){
      std::cin >> a >> b >> c >> d >> k;

      fen.modify(a,b,c,d,k);
    }else{
      std::cin >> x >> y;

      std::cout << fen.query(x,y) << "\n";
    }
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for(; T--;){
    solve();
  }
}