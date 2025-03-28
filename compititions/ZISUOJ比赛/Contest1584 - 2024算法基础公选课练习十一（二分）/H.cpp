#include <cstdio>
int n, k, len[10000]; 
int isok(int t)
{
	int num = 0, i;
	for (i = 0; i < n; i++)
	{
		if (num >= k) 
			break; 
		num = num+len[i]/t;
	}
	if (k>num) 
		return 1; 
	else 
		return 0;
}
int main() 
{
	int i, left, right, mid; 
	scanf("%d%d", &n, &k); 
	right = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &(len[i]));
		if (right < len[i]) 
		right = len[i];
	}
	right++;
    left = 0;
	while (left+1 < right)
	{
		mid = (left + right) / 2;
		if (isok(mid))
			right = mid; 
		else 
			left = mid;
	}
	printf ("%d\n", left); 
	return 0;
}