class Solution {
public:
        void dfs(vector<vector<int>> &heights,int r, int c, int prevHeight, set<pair<int,int>> &visited){
                int rows=heights.size();
                int cols=heights[0].size();
                if(r<0 || c<0 || r>=rows || c>=cols) return;
                if(visited.find({r,c})!=visited.end() )return;
                if(heights[r][c]<prevHeight) return;
                visited.insert({r,c});
                dfs(heights,r+1,c,heights[r][c],visited);
                dfs(heights,r-1,c,heights[r][c],visited);
                dfs(heights,r,c+1,heights[r][c],visited);
                dfs(heights,r,c-1,heights[r][c],visited);



        }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r=heights.size();
        int c=heights[0].size();
        vector<vector<int>> ans;
    

       set<pair<int,int>> pacVis;
       set<pair<int,int>> atVis;
       for(int col=0;col<c;col++){
            dfs(heights,0,col,heights[0][col],pacVis);// for pacific
            dfs(heights,r-1,col,heights[r-1][col],atVis);// for atlantic
       }

       for(int ro=0;ro<r;ro++){
            dfs(heights,ro,0,heights[ro][0],pacVis);// for pacific
            dfs(heights,ro,c-1,heights[ro][c-1],atVis);// for atlantic
       }
       for(auto it : pacVis){
        if(atVis.find(it)!=atVis.end()){
            ans.push_back({it.first,it.second});
        }
       }

        return ans;
    }
};
