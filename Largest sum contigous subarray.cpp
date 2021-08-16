#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int a[], int n){
        
        int maxSum = INT_MIN;
        int maxSumtillNow =0 ;
      
        for(int i=0 ; i<n ; i++)
        {
            maxSumtillNow = max(maxSumtillNow+a[i] , a[i]) ;
            maxSum = max(maxSum , maxSumtillNow) ;
        }
        
        return maxSum ;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends