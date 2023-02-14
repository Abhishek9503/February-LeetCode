class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0;
        int n = a.size();
        int m = b.size();
        int i=n-1, j=(m-1);
        string ans;
        while(i>=0 || j>=0){
            int tmp = 0;
            if(i >= 0){
                tmp += (c + a[i]-48);
                i--;
                c =  0;
            }
            if(j >= 0){
                tmp += (c + b[j]-48);
                j--;
                c = 0;
            }
            if(tmp == 1){
                ans += '1';
                c = 0;
            }
            else if(tmp == 3){
                ans += '1';
                c = 1;
            } else if(tmp == 2){
                ans += '0';
                c = 1;
            } else {
                ans += '0';
                c = 0;
            }
        }
        // if(ans == "0") return ;
        ans += c+48;
        while(ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        if(ans.size() == 0) return "0";
        return ans;
    }
};