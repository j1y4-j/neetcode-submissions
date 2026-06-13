class Solution {
public:
int INF = 2147483647;

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==0){
                        q.push({{i,j},0});
                        vis[i][j]=1;
                    }
                    
                }
            }
            while(!q.empty()){
                int r= q.front().first.first;
                int c= q.front().first.second;
                int steps = q.front().second;
                q.pop();
                grid[r][c]=steps;
                int di[4]={1,0,-1,0};
                int dj[4]={0,1,0,-1};
                for(int i=0;i<4;i++){
                    int nr=r+di[i];
                    int nc=c+dj[i];
                    if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]!=-1 &&  !vis[nr][nc]){
                        vis[nr][nc]=1;
                        q.push({{nr,nc},steps+1});
                    }
                }
            }

    }
};
