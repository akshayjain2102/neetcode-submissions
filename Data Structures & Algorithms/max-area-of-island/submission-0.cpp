class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& vis,int n,int m,int& res){
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j] != 1) return;
        vis[i][j] = 1;
        res++;
        dfs(i-1,j,grid,vis,n,m,res);//top
        dfs(i,j+1,grid,vis,n,m,res);//right
        dfs(i+1,j,grid,vis,n,m,res);//down
        dfs(i,j-1,grid,vis,n,m,res);//left
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    int res = 0;
                    dfs(i,j,grid,vis,n,m,res);
                    ans = max(res,ans);
                }
            }
        }
        return ans;
    }
};
