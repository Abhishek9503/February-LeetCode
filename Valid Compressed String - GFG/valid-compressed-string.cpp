//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        
           int i=0;//for T
        int j=0;// for S
        
        while(i<T.size() and j<S.size())
        {
            if(T[i]>='0' and T[i]<='9')
            {
                int count=0;
                
                while(i<T.size() and (T[i]>='0' and T[i]<='9'))
                {
                    count=count*10+(T[i]-'0');
                    i++;
                }
                j=j+count;
            }
            else if(T[i]!=S[j])
            {
                return false;
            }
            else
            {
                i++;
                j++;
            }
            
        }
        
        if(i==T.size() and j==S.size())
        {
            return true;
        }
        
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends