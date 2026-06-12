class Solution {
public:
    void solve(int idx,vector<int> &nums,vector<vector<int>> &ans, vector<int> &ds,int tar){
            if(idx==nums.size()){
                if(tar==0) {
                    ans.push_back(ds);
                }
                return;
            }
            if(tar>=nums[idx]){
                ds.push_back(nums[idx]);
                solve(idx,nums,ans,ds,tar-nums[idx]); // pick same
                ds.pop_back();
            }
            // not pick same
            solve(idx+1,nums,ans,ds,tar);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,nums,ans,ds,target);
        return ans;
    }
};
