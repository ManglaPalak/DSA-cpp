bool isSafe(vector<vector<char>>& board,int row,int col,char val){
    //row check
    //col check
    //3*3 matrix
    for(int i=0;i<9;i++){
        if (board[row][i]==val){
            return false;
        }
        if (board[i][col]==val){
            return false;
        }
        if (board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>>& board){
    for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){
            if (board[row][col]=='.'){
                for(char i='1';i<='9';i++){
                    if(isSafe(board,row,col,i)){
                        board[row][col]=i;
                        if (solve(board)){
                            return true;
                        }
                        else{
                            board[row][col]='.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}
