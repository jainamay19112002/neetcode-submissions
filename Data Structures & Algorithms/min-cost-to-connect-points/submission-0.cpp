class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
    int n=points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        vector<int>mincost(n,INT_MAX);
        vector<int>vis(n,false);

        mincost[0]=0;
        pq.push({0,0});

        int minimumcostofpoints=0;

        while(!pq.empty()){
            auto [cost,idx]=pq.top();
            pq.pop();

            if(vis[idx])
            continue;

            vis[idx]=true;
            minimumcostofpoints+=cost;

            for(int i=0;i<n;i++){
                if(vis[i])
                continue;

                int newcost=(abs(points[idx][0]-points[i][0])+abs(points[idx][1]-points[i][1]));
                if(newcost<mincost[i]){
                mincost[i]=newcost;
                pq.push({newcost,i});
                }
            }
        }
        return minimumcostofpoints;



        
    }
};
