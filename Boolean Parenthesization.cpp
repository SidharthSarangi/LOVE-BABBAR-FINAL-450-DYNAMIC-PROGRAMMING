// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    int dp[201][201][2] ;
    #define mod 1003
public:

    int parenthesis_count(string s, int i,int j, int isTrue)
{
    
    if (i > j)
        return 0;
    if (i == j) {
        if (isTrue == 1)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }
 
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    int ans = 0;
    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        
        // int leftT = parenthesis_count(s, i, k - 1, 1);
        // int rightT = parenthesis_count(s, k + 1, j, 1);
        // int leftF = parenthesis_count(s, i, k - 1, 0);
        // int rightF = parenthesis_count(s, k + 1, j, 0);
        int leftF, leftT, rightT, rightF;
        if (dp[i][k - 1][1] == -1)
        {
            leftT = parenthesis_count(s, i, k - 1, 1);
        } // Count no. of T in left partition
        else {
            leftT = dp[i][k - 1][1];
        }
 
        if (dp[k + 1][j][1] == -1)
        {
            rightT = parenthesis_count(s, k + 1, j, 1);
        } // Count no. of T in right partition
        else
        {
            rightT = dp[k + 1][j][1];
        }
 
        if (dp[i][k - 1][0] == -1)
        {
            // Count no. of F in left partition
            leftF = parenthesis_count(s, i, k - 1, 0);
        }
        else
        {
            leftF = dp[i][k - 1][0];
        }
 
        if (dp[k + 1][j][0] == -1)
        {
            // Count no. of F in right partition
            rightF = parenthesis_count(s, k + 1, j, 0);
        }
        else
        {
            rightF = dp[k + 1][j][0];
        }
 
        
        if (s[k] == '&')
        {
            if (isTrue == 1)
                ans += (leftT * rightT)%mod;
            else
                ans += ((leftF * rightF)%mod + (leftT * rightF)%mod + (leftF * rightT)%mod)%mod;
        }
        else if (s[k] == '|')
        {
            if (isTrue == 1)
                ans += ((leftT * rightT)%mod + (leftT * rightF)%mod + (leftF * rightT)%mod)%mod;
            else
                ans += (leftF * rightF)%mod;
        }
        else if (s[k] == '^')
        {
            if (isTrue == 1)
                ans += ((leftF * rightT)%mod + (leftT * rightF)%mod)%mod;
            else
                ans += ((leftT * rightT)%mod + (leftF * rightF)%mod)%mod;
        }
        dp[i][j][isTrue] = ans%mod;
    }
    return ans%mod;
}
    int countWays(int N, string S){
        memset(dp,-1, sizeof(dp)) ;
        int finalAns = parenthesis_count(S , 0 , N-1, 1) ;
        return finalAns ;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends