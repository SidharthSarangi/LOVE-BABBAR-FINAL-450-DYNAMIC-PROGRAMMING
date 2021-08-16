// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
 int dp[501][501] ;   
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        
        
        for(int i=0 ; i<N; i++)
        {
            for(int j=0 ; j<N; j++)
            {
                if(i==0)
                {
                    dp[i][j] = Matrix[i][j] ;
                }
                else if(j==0 && i!=0)
                {
                    dp[i][j] = Matrix[i][j] + max(dp[i-1][j] , dp[i-1][j+1]) ;
                }
                else if(j==N-1 && i!=0 )
                {
                    dp[i][j] = Matrix[i][j] + max(dp[i-1][j] , dp[i-1][j-1]) ;
                }
                else 
                {
                    dp[i][j] = Matrix[i][j] + max(dp[i-1][j] , max(dp[i-1][j-1],dp[i-1][j+1]));
                }
            }
        }
        
        int maxi= 0 ;
        for(int i=0 ; i<N ; i++)
        {
            maxi = max(maxi , dp[N-1][i]) ;
        }
        return maxi  ;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends