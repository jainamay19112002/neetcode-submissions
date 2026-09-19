class Solution {
public:
 int bfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};

        q.push({i,j});
        vis[i][j]=1;
        int area=0;

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            area++;

            for(int k=0;k<4;k++){
                int nr=x+delrow[k];
                int nc=y+delcol[k];

                if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                    
                }
            }

        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
    int m = grid[0].size();

    if(n == 0)
        return 0;

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int maxi = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            if(!vis[i][j] && grid[i][j]==1) {

                int area = bfs(i, j, vis, grid);

                maxi = max(maxi, area);
            }
        }
    }

    return maxi;
        
    }
};
