// CPP program to find minimum removals
// to make max-min <= K
#include <bits/stdc++.h>
using namespace std;

#define MAX 100
int dp[MAX][MAX];

int countRemovals(int a[], int i, int j, int k)
{
	
	if (i >= j)
		return 0;

	else if ((a[j] - a[i]) <= k)
		return 0;

	else if (dp[i][j] != -1)
		return dp[i][j];

	
	else if ((a[j] - a[i]) > k) {
		dp[i][j] = 1 + min(countRemovals(a, i + 1, j, k),
						countRemovals(a, i, j - 1, k));
	}
	return dp[i][j];
}

int removals(int a[], int n, int k)
{

	sort(a, a + n);

	memset(dp, -1, sizeof(dp));

	if (n == 1)
		return 0;
	else
		return countRemovals(a, 0, n - 1, k);
}

// Driver Code
int main()
{
	int a[] = { 1, 3, 4, 9, 10, 11, 12, 17, 20 };
	int n = sizeof(a) / sizeof(a[0]);
	int k = 4;
	cout << removals(a, n, k);
	return 0;
}
