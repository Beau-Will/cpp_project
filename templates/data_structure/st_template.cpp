template <typename T>
class ST{
public:
    const int n;
    std::vector<std::vector<T>> st;
    ST(int n = 0, std::vector<T> &a = {}) : n(n){
        st = std::vector(n + 1, std::vector<T>(22 + 1));
        build(n, a);
    }
 
    T get(const T &x, const T &y){
        return gcd(x, y);
    }
 
    void build(int n, std::vector<T> &a){
        for(int i = 1; i <= n; i++){
            st[i][0] = a[i];
        }
        for(int j = 1, t = 2; t <= n; j++, t <<= 1){
            for(int i = 1; i <= n; i++){
                if(i + t - 1 > n) break;
                st[i][j] = get(st[i][j - 1], st[i + (t >> 1)][j - 1]);
            }
        }
    }
 
    T find(int l, int r){
        int t = log(r - l + 1) / log(2);
        return get(st[l][t], st[r - (1 << t) + 1][t]);
    }
};