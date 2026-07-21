class Solution {
public:
    bool dfsCycle(int node, vector<int> &vis, vector<vector<int>> &adj,vector<int> &state){
        state[node]=1;
        for(auto it:adj[node]){
            if(state[it]==0){
                if(dfsCycle(it,vis,adj,state)) return true;
            }
            else if(state[it]==1) return true;
        }
        state[node]=2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
    
        vector<vector<int>> adj(n);
        vector<int> state(n,0); // 3 states, 0(not visited), 1(visited once), 2(completed and going back)
        for(auto it:p){
            adj[it[0]].push_back(it[1]);
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(dfsCycle(i,vis,adj,state)) return false;
        }
        return true;
    }
};
