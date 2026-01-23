/*
下标1base的二维树状数组
支持单点修改、子矩阵求和
*/
template<typename T>
struct Fenwick2D {
  int n,m;
  std::vector<std::vector<T>> tr;

  // 构造函数，初始化n行m列的二维树状数组
  Fenwick2D(int n_,int m_):n(n_),m(m_),tr(n_+1,std::vector<T>(m_+1,0)){}

  int lowbit(int x){
    return x & -x;
  }

  // 单点修改：在位置(x,y)增加v
  void modify(int x,int y,T v){
    for(int i = x; i <= n; i += lowbit(i)){
      for(int j = y; j <= m; j += lowbit(j)){
        tr[i][j] += v;
      }
    }
  }

  // 二维前缀和：查询(1,1)到(x,y)的子矩阵和
  T query(int x,int y){
    T res = T();
    for(int i = x; i > 0; i -= lowbit(i)){
      for(int j = y; j > 0; j -= lowbit(j)){
        res += tr[i][j];
      }
    }
    return res;
  }

  // 子矩阵查询：查询(x1,y1)到(x2,y2)的子矩阵和
  T query(int x1,int y1,int x2,int y2){
    return query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1);
  }

  // 获取某个位置的值（假设进行了单点修改，没有重复修改的话）
  T get(int x,int y){
    return query(x,y)-query(x-1,y)-query(x,y-1)+query(x-1,y-1);
  }
};

using BIT2D = Fenwick2D<i64>;