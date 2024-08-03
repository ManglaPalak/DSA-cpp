void addSolution(vector<vector<int>> &board,vector<vector<string>> &ans,int n){
      vector<string> temp;
      for(int i=0;i<n;i++){
          string op="";
          for(int j=0;j<n;j++){
              if (board[i][j]==1){
                  op.push_back('Q');
              }
              else{
                  op.push_back('.');
              }
          }
          temp.push_back(op);
      }
      ans.push_back(temp);
  }
  bool isSafe(int row, int col, int n, vector<vector<int>> &board){
      int x=row;
      int y=col;
      while(y>=0){
          if (board[x][y]==1){
              return false;
          }
          y--;
      }

      x=row;
      y=col;
      while(y>=0 && x>=0){
          if (board[x][y]==1){
              return false;
          }
          x--;
          y--;
      }
      x=row;
      y=col;
      while(y>=0 && x<n){
          if (board[x][y]==1){
              return false;
          }
          x++;
          y--;
      }
      return true;
  }
  void solve(int col,int n,vector<vector<int>> &board,vector<vector<string>> &ans){
      if (col==n){
          addSolution(board,ans,n);
          return;
      }
      for(int row=0;row<n;row++){
          if(isSafe(row,col,n,board)){
              board[row][col]=1;
              solve(col+1,n,board,ans);
              board[row][col]=0;
          }
      }
  }
  vector<vector<string>> solveNQueens(int n) {
      vector<vector<int>> board(n,vector<int>(n,0));
      vector<vector<string>> ans;
      solve(0,n,board,ans);
      return ans;
  }
