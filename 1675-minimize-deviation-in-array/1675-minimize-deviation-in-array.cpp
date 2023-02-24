class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>pq;
        int ans=INT_MAX, mini=INT_MAX;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2) nums[i]*=2;
            pq.push(nums[i]);
            mini=min(mini,nums[i]);
        }
        
        while(1)
        {
            int curr=pq.top();
            pq.pop();
            ans=min(ans,curr-mini);
            if(curr%2) break;
            curr/=2;
            mini=min(mini,curr);
            pq.push(curr);
        }
        return ans;
    }
};