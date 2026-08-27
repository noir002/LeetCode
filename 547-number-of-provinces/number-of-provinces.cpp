class Solution {
public:


    void dfs(vector<vector<int>>& lsit, int n, vector<bool>&vis){
        vis[n] = true;

        for(int child: lsit[n]){
            if(!vis[child])
            dfs(lsit,child, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>lsit(n,vector<int>(n));
        vector<bool>vis(n,false);
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j] == 1){
                    lsit[i].push_back(j);
                    
                }
            }
        }
        int count = 0;

        for(int i = 0; i<n ; i++){
            if(!vis[i]){
                dfs(lsit, i, vis);
                count++;
            }
        }

        return count;






        
    }
};