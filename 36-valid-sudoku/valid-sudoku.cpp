class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char,int>>rmp(9);
        vector<unordered_map<char,int>>cmp(9);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    rmp[i][board[i][j]]++;
                    cmp[j][board[i][j]]++;
                    if(rmp[i][board[i][j]]>1 |cmp[j][board[i][j]]>1 )
                    return false;
                }
            }
        }
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    //check in sub matrix
                    int r=3*(i/3);
                    int c=3*(j/3);
                    for(int x=r;x<r+3;x++)
                    {
                        for(int y=c;y<c+3;y++)
                        {
                            if(x!=i && y!=j)
                            {
                                if(board[i][j]==board[x][y])
                                return false;
                            }
                        }
                    }
                }
            }
        }

        
        return true;
    }
};