class Solution {
public:
    void dfs(int r, int c, vector<vector<char>> &board){
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c]!='O') return;
        board[r][c]='B';
        dfs(r+1,c,board);
        dfs(r-1,c,board);
        dfs(r,c+1,board);
        dfs(r,c-1,board);
        return;
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        // mark boundary O's as B and traverse all those O's that connect the boundary O's and make it B
        //mark everything else as  X
        for(int i=0;i<m;i++){
            for(int j=0; j<n; j++){
                if((!i || !j || i==m-1 || j==n-1 ) && board[i][j]=='O'){

                    dfs(i,j,board);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O'){

                    board[i][j]='X';
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='B') board[i][j]='O';
            }
        }
    }
};
