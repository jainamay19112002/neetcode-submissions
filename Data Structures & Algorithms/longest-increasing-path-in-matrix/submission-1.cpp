class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};

        vector<vector<int>>indegreecalcu(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<4;k++){
                    int nr=i+dx[k];
                    int nc=j+dy[k];

                    if(nr>=0 && nc>=0 && nr<n && nc<m && matrix[nr][nc]>matrix[i][j]){
                    indegreecalcu[nr][nc]++;
                    }
                }
            }
        }

        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(indegreecalcu[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        int cntlevel=0;
        while(!q.empty()){
            int size=q.size();
            cntlevel++;

            while(size--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();

                for(int k=0;k<4;k++){
                    int nr=r+dx[k];
                    int nc=c+dy[k];

                    if(nr>=0 && nc>=0 && nr<n && nc<m && matrix[nr][nc]>matrix[r][c]){
                        indegreecalcu[nr][nc]--;
                        if(indegreecalcu[nr][nc]==0)
                        q.push({nr,nc});
                    }
                }
            }
        }
        return cntlevel;
        
    }
};
