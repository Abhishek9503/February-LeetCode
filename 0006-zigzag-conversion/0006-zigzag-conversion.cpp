class Solution {
public:
    string convert(string s, int numRows) {
          vector<string> v(numRows, "");
        int i =0;
        int n = s.length();
        while(i<n){
            
            for(int j =0; j<numRows && i<n; j++ ){
                v[j].push_back(s[i++]);
            }
            
            for(int j =numRows-2; j>=1 && i<n; j--){
                v[j].push_back(s[i++]);
            }
        }
        
        string res ="";
        for(auto i : v){
            res+=i;
        }
        return res;
        
    }
};