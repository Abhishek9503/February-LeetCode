//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
           vector<int> updateQuery(int N,int Q,vector<vector<int>> &U)
        {
            // code here
            vector<int> ans;
            unordered_map<int,vector<int>> add,rem;
            for(auto x:U){
                add[x[0]-1].push_back(x[2]);
                rem[x[1]].push_back(x[2]);
            }
            vector<int> arr(32,0);
            for(int i=0;i<N;i++){
                if(add.find(i)!=add.end()){
                    for(auto x:add[i]){
                        int j=0;
                        while(x){
                            if(x&1){
                                arr[j]++;
                            }
                            x>>=1;
                            j++;
                        }
                    }
                }
                if(rem.find(i)!=rem.end()){
                    for(auto x:rem[i]){
                        int j=0;
                        while(x){
                            if(x&1){
                                arr[j]--;
                            }
                            x>>=1;
                            j++;
                        }
                    }
                }
                int num =0;
                for(int j=0;j<32;j++){
                    if(arr[j]){
                        num+=pow(2,j);
                    }
                }
                ans.push_back(num);
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends