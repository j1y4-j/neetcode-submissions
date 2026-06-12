class Solution {
public:
    void subFunc(vector<int> &nums,int idx, vector<vector<int>> &ans, vector<int> &ds){
        if(idx>=nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]);
        subFunc(nums,idx+1,ans,ds);
        ds.pop_back();
        subFunc(nums,idx+1,ans,ds);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        subFunc(nums,0,ans,ds);
        return ans;
    }
};
