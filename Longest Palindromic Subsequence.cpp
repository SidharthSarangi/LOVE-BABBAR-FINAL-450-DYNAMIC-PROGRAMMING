//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int lcs(string s1 , string s2 , int x , int y)
    {
        int dp[x+1][y+1] ;
        for(int i=0 ; i<=x ; i++)
        {
            for(int j=0 ; j<=y ; j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0 ;
                }
                else if(s1[i-1]==s2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1] ;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) ;
                }
            }
        }

        return dp[x][y] ;
    }
    int longestPalinSubseq(string A) {
        string rev = string(A.rbegin(),A.rend());
        int finalAns = lcs(A, rev , A.length() , rev.length()) ;
        return finalAns ;
    }
};


int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
