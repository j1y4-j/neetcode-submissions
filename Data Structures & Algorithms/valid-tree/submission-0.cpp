class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>> &adj,vector<int> &vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                if(dfs(it,node,adj,vis)) return true;
            }
            else if(it!=parent) return true;
            
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false; 
        // a tree has to be fully connected too
        vector<vector<int>> adj(n);
       vector<int> vis(n,0);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(dfs(i,-1,adj,vis)) return false;
            }
            
        }
        return true;
    }
};
