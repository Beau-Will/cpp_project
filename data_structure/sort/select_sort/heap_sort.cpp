#include <bits/stdc++.h>

void heap_adjust(std::vector<int> &heap,int u,int siz){
    int t = u;
    if((u<<1) <= siz && heap[u<<1] < heap[t]){
        t = u<<1;
    }
    if((u<<1|1) <= siz && heap[u<<1|1] < heap[t]){
        t = u<<1|1;
    }
    
    if(u^t){
        std::swap(heap[u],heap[t]);
        heap_adjust(heap,t,siz);
    }
}

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(false);
    
    int n,m;
    std::cin >> n >> m;
    
    std::vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        std::cin >> a[i];
    }
    
    int size = n;
    
    for(int i = n/2; i >= 1; i--){
        heap_adjust(a,i,size);
    }
    
    for(int i = 0; i < m; i++){
        std::cout << a[1] << " \n"[i+1==m];
        a[1] = a[size--];
        heap_adjust(a,1,size);
    }
    
    return 0;
}