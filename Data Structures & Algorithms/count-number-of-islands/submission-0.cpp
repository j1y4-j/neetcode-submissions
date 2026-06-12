class Solution {
public:
    int dfs(int r,int c, vector<vector<char>> &grid){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]=='0') return 0;
        grid[r][c]='0';
        dfs(r,c+1,grid);
        dfs(r,c-1,grid);
        dfs(r-1,c,grid);
        dfs(r+1,c,grid);

        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        // vector<vector<int>> vis(r,vector<int>(c,0));
    int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                    if(grid[i][j]=='1'){
                        count+=dfs(i,j,grid);
                    }
            }
        }
        return count;
    }
};
