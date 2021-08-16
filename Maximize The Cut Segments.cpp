#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{   
    public:

    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int dp[3+1][n+1] ;
        for(int i=1 ; i<=n ; i++)
        {
            dp[0][i]=INT_MIN ;
        }
        for(int i=0 ; i<=3 ; i++)
        {
            dp[i][0] =0 ;
        }
        
        int arr[3] ;
        arr[0] =x ; arr[1]=y  ; arr[2]=z ;
        for(int i=1 ; i<=3 ; i++)
        {
            for(int j=1; j<=n ; j++)
            {
               if(arr[i-1]>j)
               dp[i][j]= dp[i-1][j] ;
               else
               dp[i][j]= max(1+dp[i][j-arr[i-1]],dp[i-1][j]);
            }
        }
        if(dp[3][n]<0)
        return 0 ;
        
        return dp[3][n] ;
        
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends