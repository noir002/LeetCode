class Solution {
public:
    int n = 9;
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board){
        int i,j;
        bool found = false;
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(board[i][j] == '.'){
                   found = true;
                   break;
                }
            }
            if(found) break;
        }
        if(!found) return true;      

        for(int x=1; x<=n; x++){
            if(isSafe(i,j,x, board)){
                board[i][j] = char(x+'0');
                if(solve(board))
                   return true;

                board[i][j] = '.'; 
            }
        }
        return false;
    }
    bool isSafe(int i, int j, int x, vector<vector<char>>& board){
        for(int k=0; k<n; k++)
            if(board[k][j] == char(x+'0')  || board[i][k] == char(x+'0')) return false; 
        
        int s = sqrt(n);
        int rs = i-i%s;     
        int cs = j-j%s;     

        for(int u=0; u<s; u++){
            for(int v=0; v<s; v++){
                if(board[u+rs][v+cs] == char(x+'0')) return false;
            }
        }

        return true;
    }
};