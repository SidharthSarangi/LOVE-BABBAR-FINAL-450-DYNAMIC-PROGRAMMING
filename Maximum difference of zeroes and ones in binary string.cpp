#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    int n= S.length() ;
	    vector<int> v; 
	    int countZero=0 ;
	    for(int i=0 ; i<n ; i++)
	    {
	        if(S[i]=='1')
	        {
	            v.push_back(-1) ;
	        }
	        else 
	        {   
	            v.push_back(1) ;
	            countZero++ ;
	        }
	    }
	    int maxTillNow= 0 ;
	    int maxSum = INT_MIN ;
	    for(int i=0 ; i<n ; i++)
	    {
	        maxTillNow = max(maxTillNow + v[i] , v[i]) ;
	        maxSum = max(maxSum , maxTillNow) ;
	    }
	    
	    if(countZero==0)
	    {
	        return -1; 
	    }
	    return maxSum ;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends