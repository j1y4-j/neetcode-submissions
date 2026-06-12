class Solution {
public:
  
   
    void solve(int n,int col, vector<string> &board , vector<int> &lowerd, vector<int> &upperd,vector<int> &leftro,vector<vector<string>> &ans){
            if(col==n){
                ans.push_back(board);
                 return;
            }
            for(int row=0;row<n;row++){
                if(!upperd[row+col] && !lowerd[(n-1)+(col-row)] && !leftro[row]){
                     board[row][col]='Q'; 
                     lowerd[(n-1) + (col-row)]=1;
                     leftro[row]=1;
                     upperd[row+col]=1;
                     solve(n,col+1,board,lowerd,upperd,leftro,ans);
                     leftro[row]=0;
                     lowerd[(n-1) + (col-row)]=0;
                     upperd[row+col]=0;
                     board[row][col]='.';
                }
            }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        vector<int> lowerDiag(2*n-1,0);
        vector<int> upperDiag(2*n-1,0);
        vector<int> leftRow(n,0);
        solve(n,0,board,lowerDiag,upperDiag,leftRow,ans);
        return ans;

    }
};
