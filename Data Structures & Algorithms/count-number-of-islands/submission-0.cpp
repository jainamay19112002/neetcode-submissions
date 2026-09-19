class Solution {
public:
    void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};

        q.push({i,j});
        vis[i][j]=1;

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int nr=x+delrow[k];
                int nc=y+delcol[k];

                if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]=='1'){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                    
                }
            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;

        if(n==0)
        return 0;

        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
        
    }
};
