#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        int n= s.length() ;
        if(n<=1 )
        return s;
        
        int max_length= 1;
        int st=0 , end= 0 ;
        //odd length
        for(int i=0 ; i<n-1 ; i++)
        {
            int l=i , r=i ;
            while(l>=0 && r<n )
                {
                    if(s[l]==s[r])
                    {
                        l-- ;
                        r++ ;
                    }
                else
                    break;
            }
            int length = r- l -1;
            if(length > max_length)
            {
                max_length = length  ;
                st = l+1; 
                end= r-1 ;
            }
        }
        
        //even length
         for(int i=0 ; i<n-1 ; i++)
        {
            int l=i , r=i+1 ;
            while(l>=0 && r<n )
                {
                    if(s[l]==s[r])
                    {
                        l-- ;
                        r++ ;
                    }
                else
                    break;
            }
            int length = r- l -1;
            if(length > max_length)
            {
                max_length = length  ;
                st = l+1; 
                end= r-1 ;
            }
        }
        
         return s.substr(st, max_length) ;   
    }
};


int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
