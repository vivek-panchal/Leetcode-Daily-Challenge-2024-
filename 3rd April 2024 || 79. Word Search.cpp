class Solution {
public:
   bool solve(int i,int j,vector<vector<char>>& board, string word,int index, int n,int m){
       if(index==word.length()){
           return true;
       }
       if(i<0 || i==n || j<0 || j==m || board[i][j] != word[index]){
           return false;
       }

       char temp=board[i][j];
       board[i][j]='#';

       bool op1=solve(i+1,j,board,word,index+1,n,m);
       bool op2=solve(i-1,j,board,word,index+1,n,m);
       bool op3=solve(i,j+1,board,word,index+1,n,m);
       bool op4=solve(i,j-1,board,word,index+1,n,m);

       board[i][j]=temp;

       return op1 || op2 || op3 || op4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(solve(i,j,board,word,0,n,m)) return true;
                }
            }
        }
        return false;
    }
};
