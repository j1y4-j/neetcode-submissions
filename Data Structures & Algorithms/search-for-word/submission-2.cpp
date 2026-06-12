class Solution {
public:
    bool dfs(int idx,vector<vector<int>> &vis,vector<vector<char>> &board,int r,int c,string word){
        if(idx==word.size()) return true;
        if(r<0 || c<0  || r>=board.size() || c>=board[r].size() || vis[r][c] || board[r][c]!=word[idx]) return false;
        vis[r][c]=1;
        bool ans= dfs(idx+1,vis,board,r,c+1,word) || dfs(idx+1,vis,board,r,c-1,word) || dfs(idx+1,vis,board,r-1,c,word) || dfs(idx+1,vis,board,r+1,c,word);
        vis[r][c]=0;
        return ans;


    
        }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(dfs(0,vis,board,i,j,word)) return true;
            }
        }
        return false;
    }
};
