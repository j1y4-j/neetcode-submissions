class Solution {
public:
    int maxSum(int idx,vector<int> &nums,vector<int> &dp){
        if(idx<0) return 0;
        if(idx==0) return dp[idx]=nums[0];
        if(dp[idx]!=-1) return dp[idx];
        int pick=maxSum(idx-2,nums,dp)+nums[idx];
        int not_pick=maxSum(idx-1,nums,dp);
        return dp[idx]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        maxSum(n-1,nums,dp);
        return dp[n-1];
    }
};
