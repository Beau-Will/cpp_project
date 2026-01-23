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