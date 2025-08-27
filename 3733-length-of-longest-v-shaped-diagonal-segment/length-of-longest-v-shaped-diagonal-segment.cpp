class Solution {
public:
    int n,m;
    int dp[505][505][6][2];
    int f(vector<vector<int>>&grid,int i,int j,int dir,bool flag){
        if(dp[i][j][dir+1][flag]!=-1) return dp[i][j][dir+1][flag];
        int ans = 0;
        if(grid[i][j]==1){
            if(i+1<n and j+1<m and grid[i+1][j+1]==2) ans = max(ans,1+f(grid,i+1,j+1,1,false));
            if(i+1<n and j-1>=0 and grid[i+1][j-1]==2) ans = max(ans,1+f(grid,i+1,j-1,2,false));
            if(i-1>=0 and j+1<m and grid[i-1][j+1]==2) ans = max(ans,1+f(grid,i-1,j+1,3,false));
            if(i-1>=0 and j-1>=0 and grid[i-1][j-1]==2) ans = max(ans,1+f(grid,i-1,j-1,4,false));
        } 
        if(grid[i][j]==2){
            if(dir==1){
                if(i+1<n and j+1<m and grid[i+1][j+1]==0) ans = max(ans,1+f(grid,i+1,j+1,1,flag));
                if(flag==false and i+1<n and j-1>=0 and grid[i+1][j-1]==0) ans = max(ans,1+f(grid,i+1,j-1,2,true));
            }
            if(dir==2){
                if(i+1<n and j-1>=0 and grid[i+1][j-1]==0) ans = max(ans,1+f(grid,i+1,j-1,2,flag));
                if(flag==false and i-1>=0 and j-1>=0 and grid[i-1][j-1]==0) ans = max(ans,1+f(grid,i-1,j-1,4,true));
            }
            if(dir==3){
                if(i-1>=0 and j+1<m and grid[i-1][j+1]==0) ans = max(ans,1+f(grid,i-1,j+1,3,flag));
                if(flag==false and i+1<n and j+1<m and grid[i+1][j+1]==0) ans = max(ans,1+f(grid,i+1,j+1,1,true));
            }
            if(dir==4){
                if(i-1>=0 and j-1>=0 and grid[i-1][j-1]==0) ans = max(ans,1+f(grid,i-1,j-1,4,flag));
                if(flag==false and i-1>=0 and j+1<m and grid[i-1][j+1]==0) ans = max(ans,1+f(grid,i-1,j+1,3,true));
            }
        }
        if(grid[i][j]==0){
            if(dir==1){
                if(i+1<n and j+1<m and grid[i+1][j+1]==2) ans = max(ans,1+f(grid,i+1,j+1,1,flag));
                if(flag==false and i+1<n and j-1>=0 and grid[i+1][j-1]==2) ans = max(ans,1+f(grid,i+1,j-1,2,true));
            }
            if(dir==2){
                if(i+1<n and j-1>=0 and grid[i+1][j-1]==2) ans = max(ans,1+f(grid,i+1,j-1,2,flag));
                if(flag==false and i-1>=0 and j-1>=0 and grid[i-1][j-1]==2) ans = max(ans,1+f(grid,i-1,j-1,4,true));
            }
            if(dir==3){
                if(i-1>=0 and j+1<m and grid[i-1][j+1]==2) ans = max(ans,1+f(grid,i-1,j+1,3,flag));
                if(flag==false and i+1<n and j+1<m and grid[i+1][j+1]==2) ans = max(ans,1+f(grid,i+1,j+1,1,true));
            }
            if(dir==4){
                if(i-1>=0 and j-1>=0 and grid[i-1][j-1]==2) ans = max(ans,1+f(grid,i-1,j-1,4,flag));
                if(flag==false and i-1>=0 and j+1<m and grid[i-1][j+1]==2) ans = max(ans,1+f(grid,i-1,j+1,3,true));
            }
        }
        return dp[i][j][dir+1][flag] = ans;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        n = grid.size();
        m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans = max(ans,1+f(grid,i,j,-1,false));
                }
            }
        }
        return ans;
    }
};