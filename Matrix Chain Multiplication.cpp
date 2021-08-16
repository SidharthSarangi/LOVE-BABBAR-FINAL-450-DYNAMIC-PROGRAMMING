// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
int dp[501][501] ;    
public:
    int solve(int arr[] , int i , int j )
    {
        if(i==j)
        {   
            
            return dp[i][j]=0 ;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j] ;
        }
        int finalAns = INT_MAX ;
        for(int k=i ; k<j ; k++)
        {
            int tempAns = solve(arr, i , k) + solve(arr , k+1 , j) + arr[i-1]*arr[k]*arr[j];
            finalAns = min(finalAns, tempAns) ;
        }
        
        return dp[i][j]=finalAns ;
    }
    int matrixMultiplication(int N, int arr[])
    {   
        memset(dp, -1 , sizeof(dp)) ;
        int ans = solve(arr, 1, N-1) ;
        return ans ;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends