class Solution {
public:
    void subSet(vector<int> &nums, int idx, set<vector<int>> &ans, vector<int> &ds){
        if(idx>=nums.size()){
            ans.insert(ds);
            return;
        }
        ds.push_back(nums[idx]);
        subSet(nums,idx+1,ans,ds);
        ds.pop_back();
        subSet(nums,idx+1,ans,ds);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<int> ds;
        subSet(nums,0,ans,ds);
        vector<vector<int>> final;
        for(auto it: ans){
            final.push_back(it);
        }
        return final;
    }
};
