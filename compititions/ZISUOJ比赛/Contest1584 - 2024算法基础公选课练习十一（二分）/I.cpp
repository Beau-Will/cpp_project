#include <iostream>
using namespace std;
int n, m, i,lbound, ubound, mid, count;
int len[100];  // 绳子长度
int main()
{
    cin >> n;
    count = 0;
    for (i = 0; i < n; i++)
    {
        cin >> len[i];
        count = count+len[i];
    }
    cin >> m;
    if(m>count)
    {
        cout << "Failed" <<endl;
        return 0;
    }
    lbound = 1;
    ubound = 1000000;
    while (lbound<ubound)
    {
        mid = (lbound+ubound+1)/2;
        count = 0;
        for (i = 0; i < n; i++)
            count += len[i]/mid;
        if (count < m)
            ubound = mid - 1;
        else
            lbound = mid;
    }
    cout << lbound << endl;
    return 0;
}