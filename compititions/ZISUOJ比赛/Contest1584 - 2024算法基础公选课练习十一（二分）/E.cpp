#include <iostream> 
using namespace std; 
#define MAXN 1000000 
int n, B, A, M[MAXN], C[MAXN], l, r, ans, mid; 
bool check(int nn) 
{ 
    int count = 0, i, j; 
    i = n-nn+1; 
    j = 1; 
    while (i <= n) 
	{ 
        if (C[j]>M[i]) 
            count += C[j] - M[i]; 
        i++; 
        j++; 
    } 
    return count<=A;   
}
void sort(int a[], int l, int r)
{ 
    int i = l, j = r, x = a[(l + r) / 2], y; 
    while (i <= j) 
	{ 
        while (a[i] < x) i++; 
        while (a[j] > x) j--; 
        if (i <= j) 
		{ 
            y = a[i]; a[i] = a[j]; a[j] = y; 
            i++; j--; 
        } 
    } 
    if (i < r) sort(a, i, r); 
    if (l < j) sort(a, l, j); 
} 
int main() 
{ 
    int i; 
    cin >> n >> B >> A; 
    for (i = 1; i <= n; i++) 
        cin >> M[i]; 
    for (i = 1; i <= B; i++) 
        cin >> C[i];
    sort(M, 1, n); 
    sort(C, 1, B); 
    
    l = 0; 
    r = n; 
    while (l <= r) 
    { 
        mid = (l + r) / 2; 
        if (check(mid)) 
	{   
            ans = mid; 
            l = mid + 1; 
        } else
            r = mid - 1;
    } 
    cout << ans << endl; 
    return 0; 
}