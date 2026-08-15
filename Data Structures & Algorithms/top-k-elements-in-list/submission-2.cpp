class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        int l=k;
        while(l){
            int t=pq.top().second;
            pq.pop();
            ans.push_back(t);
            l--;
        }
       
    return ans;
    }
};
