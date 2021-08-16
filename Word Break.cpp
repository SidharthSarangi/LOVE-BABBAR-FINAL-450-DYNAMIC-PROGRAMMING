
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
bool solve(map<string,int>& m , string A)
{
    
    int size = A.length() ;
    
    if(size==0)
    {
        return true;
    }
    
    for(int i=1; i<=size ; i++)
    {
        //string temp= A.substr(0,i);
        if(m.find(A.substr(0,i))!=m.end() && solve(m, A.substr(i, size-i)) )
        {
           return true;
        }
    }
    
    return false;
}

int wordBreak(string A, vector<string> &B)
{
    map<string,int>m;
    for(int i=0;i<B.size();i++){
        m[B[i]]++;
    }

   return solve(m,A);
    
}
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends