bool search(vector<vector<char>>& board,int x,int y,string word,int index,int m,int n){
      if(index==word.length()){
          return true;
      }
      if (x<0 || y<0 || x==m || y==n || board[x][y]!=word[index] || board[x][y]=='!'){
          return false;
      }
      char c=board[x][y];
      board[x][y]='!';
      bool top=search(board,x-1,y,word,index+1,m,n);
      bool right=search(board,x,y+1,word,index+1,m,n);
      bool down=search(board,x+1,y,word,index+1,m,n);
      bool left=search(board,x,y-1,word,index+1,m,n);
      board[x][y]=c;
      return (top || right || down || left);
  }
  bool exist(vector<vector<char>>& board, string word) {
      int m=board.size();
      int n=board[0].size();
      int index=0;
      for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
              if (board[i][j]==word[index]){
                  if (search(board,i,j,word,index,m,n)){
                      return true;
                  }
              }
          }
      }
      return false;
  }
