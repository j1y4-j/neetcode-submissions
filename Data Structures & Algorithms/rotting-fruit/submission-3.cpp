class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int maxi=0;
        int r=grid.size();
        int c=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){   
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==0) vis[i][j]=1;
            }
        }
        while(!q.empty()){
            int ro=q.front().first.first;
            int co=q.front().first.second;
            int mins=q.front().second;
            q.pop();
            maxi=max(maxi,mins);
            int di[4]={1,0,-1,0};
            int dj[4]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nro=ro+di[i];
                int nco=co+dj[i];
                if(nro>=0 && nco>=0 && nro<r && nco<c && !vis[nro][nco]){
                    q.push({{nro,nco},mins+1});
                    vis[nro][nco]=1;
                }
            }
        }
            for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){   
               if(vis[i][j]==0) return -1;
            }
        }
        return maxi;
      
    }
};
