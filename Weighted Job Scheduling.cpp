#include <iostream>
#include <algorithm>
using namespace std;

struct Job
{
	int start, finish, profit;
};

bool jobComparataor(Job s1, Job s2)
{
	return (s1.finish < s2.finish);
}

int findMaxProfitRec(Job arr[], int n)
{
	
    int dp[n]  ;
    dp[0] = arr[0].profit ;
    for(int i=1 ; i<n ; i++)
    {
        int including = arr[i].profit ;
        int nonConflictingIndex = -1 ;
        for(int j=i-1 ; j>=0 ; j--)
        {
            if(arr[j].finish <= arr[i].start )
            {
                nonConflictingIndex = j ;
                break ;
            }
        }
        if(nonConflictingIndex !=-1)
        {
            including += dp[nonConflictingIndex] ;
        }
      
        dp[i] = max(including , dp[i-1]) ;
    }
    return dp[n-1] ;
}

int findMaxProfit(Job arr[], int n)
{
	// Sort jobs according to finish time
	sort(arr, arr+n, jobComparataor);

	return findMaxProfitRec(arr, n);
}

// Driver program
int main()
{
	Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "The optimal profit is " << findMaxProfit(arr, n);
	return 0;
}
