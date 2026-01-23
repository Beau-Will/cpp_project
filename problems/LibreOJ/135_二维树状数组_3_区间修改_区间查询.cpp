#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

// 二维差分树状数组（支持区间修改、区间查询）
template<typename T>
struct RangeFenwick2D {
  int n,m;
  std::vector<std::vector<T>> tr1,tr2,tr3,tr4;

  RangeFenwick2D(int n_,int m_):n(n_),m(m_){
    tr1.assign(n+2,std::vector<T>(m+2,0));
    tr2.assign(n+2,std::vector<T>(m+2,0));
    tr3.assign(n+2,std::vector<T>(m+2,0));
    tr4.assign(n+2,std::vector<T>(m+2,0));
  }

  int lowbit(int x){
    return x & -x;
  }

  void add(std::vector<std::vector<T>>& tr,int x,int y,T v){
    for(int i = x; i <= n; i += lowbit(i)){
      for(int j = y; j <= m; j += lowbit(j)){
        tr[i][j] += v;
      }
    }
  }

  T query(const std::vector<std::vector<T>>& tr,int x,int y){
    T res = T();
    for(int i = x; i > 0; i -= lowbit(i)){
      for(int j = y; j > 0; j -= lowbit(j)){
        res += tr[i][j];
      }
    }
    return res;
  }

  // 二维差分：给子矩阵(x1,y1)到(x2,y2)的所有元素增加v
  void modify(int x1,int y1,int x2,int y2,T v){
    add(tr1,x1,y1,v);
    add(tr1,x1,y2+1,-v);
    add(tr1,x2+1,y1,-v);
    add(tr1,x2+1,y2+1,v);

    add(tr2,x1,y1,v*(x1-1));
    add(tr2,x1,y2+1,-v*(x1-1));
    add(tr2,x2+1,y1,-v*x2);
    add(tr2,x2+1,y2+1,v*x2);

    add(tr3,x1,y1,v*(y1-1));
    add(tr3,x1,y2+1,-v*y2);
    add(tr3,x2+1,y1,-v*(y1-1));
    add(tr3,x2+1,y2+1,v*y2);

    add(tr4,x1,y1,v*(x1-1)*(y1-1));
    add(tr4,x1,y2+1,-v*(x1-1)*y2);
    add(tr4,x2+1,y1,-v*x2*(y1-1));
    add(tr4,x2+1,y2+1,v*x2*y2);
  }

  // 查询前缀和：(1,1)到(x,y)的子矩阵和
  T query(int x,int y){
    return query(tr1,x,y)*x*y-query(tr2,x,y)*y-query(tr3,x,y)*x+query(tr4,x,y);
  }

  // 查询子矩阵和：(x1,y1)到(x2,y2)
  T query(int x1,int y1,int x2,int y2){
    return query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1);
  }
};

using RangeBIT2D = RangeFenwick2D<i64>;

void solve(){
  int n,m;
  std::cin >> n >> m;

  RangeBIT2D fen(n,m);

  int op,a,b,c,d,x;
  while(std::cin >> op >> a >> b >> c >> d){
    if(op == 1){
      std::cin >> x;

      fen.modify(a,b,c,d,x);
    }else{
      std::cout << fen.query(a,b,c,d) << "\n";
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