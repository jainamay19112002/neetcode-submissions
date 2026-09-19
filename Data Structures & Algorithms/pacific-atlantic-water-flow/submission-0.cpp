class Solution {
public:
    void bfs(queue<pair<int,int>>& q,vector<vector<int>>& vis,vector<vector<int>>& heights){
        int n = heights.size();
        int m = heights[0].size();

         int dx[]={-1,1,0,0};
         int dy[]={0,0,1,-1};

        while(!q.empty()){
            auto curr= q.front();
            q.pop();

            int r=curr.first;
            int c=curr.second;

            for(int k=0;k<4;k++){
                int nr=r+dx[k];
                int nc=c+dy[k];

                if(nr<0||nc<0||nr>=n||nc>=m || vis[nr][nc] || heights[nr][nc]<heights[r][c])
                    continue;
    
                vis[nr][nc] =1;
                q.push({nr,nc});
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>>pacificside(n,vector<int>(m,0));
        vector<vector<int>>atlanticside(n,vector<int>(m,0));

        queue<pair<int,int>>qpacific;
        queue<pair<int,int>>qatlantic;
       
       //---------pacific side--------------------
        for(int j=0;j<m;j++){
            pacificside[0][j]=1;
            qpacific.push({0,j});
        }

        for(int i=0;i<n;i++){
            pacificside[i][0]=1;
            qpacific.push({i,0});
        }

        //-----atlantic side----------------------

        for(int j=0;j<m;j++){
            atlanticside[n-1][j]=1;
            qatlantic.push({n-1,j});
        }

        for(int i=0;i<n;i++){
            atlanticside[i][m-1]=1;
            qatlantic.push({i,m-1});
        }

        bfs(qpacific,pacificside,heights);
        bfs(qatlantic,atlanticside,heights);
        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacificside[i][j] && atlanticside[i][j])
                ans.push_back({i,j});

            }
        }
        return ans;
        
    }
};
