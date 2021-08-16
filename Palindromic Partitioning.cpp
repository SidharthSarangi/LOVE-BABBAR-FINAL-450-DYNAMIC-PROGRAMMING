// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    int palindromicPartition(string str)
    {   
       
    int n = str.length();
    int C[n][n];
    bool P[n][n];
 
    int i, j, k, L; 
 
    
    for (i=0; i<n; i++)
    {
        P[i][i] = true;
        C[i][i] = 0;
    }
 
    for (L=2; L<=n; L++)
    {
        for (i=0; i<n-L+1; i++)
        {
            j = i+L-1; 
 
            if (L == 2)
                P[i][j] = (str[i] == str[j]);
            else
                P[i][j] = (str[i] == str[j]) && P[i+1][j-1];
 
          
            if (P[i][j] == true)
                C[i][j] = 0;
            else
            {
                C[i][j] = INT_MAX;
                for (k=i; k<=j-1; k++)
                    C[i][j] = min (C[i][j], C[i][k] + C[k+1][j]+1);
            }
        }
    }
 
    return C[0][n-1];
        
    }
};


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends