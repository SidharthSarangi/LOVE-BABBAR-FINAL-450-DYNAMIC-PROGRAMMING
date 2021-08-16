#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}

// } Driver Code Ends


int LCSof3 (string s1, string s2, string s3, int x, int y, int z)
{
    int dp[x+1][y+1][z+1] ;
       
        memset(dp, 0 , sizeof(dp)) ;
        
        for(int i=1 ; i<=x;  i++)
        {
            for(int j=1  ; j<=y ; j++)
            {   
                for(int k=1; k<=z; k++)
                {
                     if(s1[i-1]==s2[j-1] && s1[i-1]==s3[k-1] )
                   {
                        dp[i][j][k] = 1 + dp[i-1][j-1][k-1] ;
                   }
                  else
                  {
                        dp[i][j][k] = max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]) ;
                  }
                }
               
            }
        }
        
        return dp[x][y][z] ;
        
}