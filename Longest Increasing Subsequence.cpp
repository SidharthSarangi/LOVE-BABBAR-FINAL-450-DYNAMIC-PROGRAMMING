#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //  TIME COMPLEXITY - O(N^2)
    
    // int longestSubsequence(int n, int a[])
    // {
    //     int dp[n]  ;
    //     dp[0] = 1 ;
    //     for(int i=1 ; i<n ; i++)
    //     {
    //         dp[i] = 1;
    //         for(int j=0 ; j<i ; j++)
    //         {
    //             if(a[j]<a[i] && dp[i]<=dp[j])
    //             {
    //                 dp[i] = 1+ dp[j] ;
    //             }
    //         }
    //     }
        
    //     return *max_element(dp , dp+n) ;
    // }
    
    
    // TIME COMPLEXITY - O(NLOGN)
    int binarySearch(vector<int>& dp , int l , int r , int key)
    {
       while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (dp[m] >= key)
            r = m;
        else
            l = m;
    }
 
    return r;
    }
    int longestSubsequence(int n , int arr[])
    {
        vector<int> dp ;
        dp.push_back(arr[0]) ;
        
        for(int i=1 ; i<n ; i++)
        {
            if(dp[dp.size()-1] < arr[i] )
            {
                dp.push_back(arr[i]) ;
            }
            else 
            {
                int index = binarySearch(dp , -1, dp.size()-1 , arr[i]) ;
                dp[index] = arr[i] ;
            }
        }
        return dp.size() ;
    }
    
        
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends