class DisjointSet{
    public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findParent(int u){
        if(parent[u]==u) return u;
        return parent[u]=findParent(parent[u]);
    }
    void unionBysize(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv) return;
        if(size[pu]>size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
         for(auto it:edges){
            int u=it[0];
            int v=it[1];
            ds.unionBysize(u,v);
          
         }
           int c=0;
            for(int i=0;i<n;i++){
                if(ds.findParent(i)==i) c++;
            }
            return c;
    }
};
