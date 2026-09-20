class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
          int n=grid.size();
         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
         greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));

        pq.push({grid[0][0],{0,0}});
        dist[0][0]=grid[0][0];

        int dx[]={0,-1,0,1};
        int dy[]={-1,0,1,0};

        while(!pq.empty()){
            int time=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();

            if(time>dist[r][c])
             continue;

            if(r==n-1 && c==n-1)
            return time;

            for(int k=0;k<4;k++){
                int nr=r+dx[k];
                int nc=c+dy[k];

                if(nr<0 ||nr>=n ||nc<0 ||nc>=n)
                continue;

                int newtime=max(dist[r][c],grid[nr][nc]);

                if(newtime<dist[nr][nc]){
                dist[nr][nc]=newtime;
                pq.push({newtime,{nr,nc}});
                }
            }
        }
  return -1;      
    
        
    }
};
