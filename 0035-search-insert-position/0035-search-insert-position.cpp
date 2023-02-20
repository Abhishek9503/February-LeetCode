class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        if(target<nums[0]) return 0;
        if(target>nums[n-1]) return n;
        
        int low=0,high=n-1, mid=-1, ans;
         while(low<=high){
             
             mid=(low+high)/2;
             
             if(target==nums[mid]){
                 return mid;
                 
             }
             else if(target>nums[mid]){
                 low=mid+1;
             }
             else{
                 ans=mid;
                 high=mid-1;
             }
             
         }
        return ans;
    }
};