class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adjli(n+1);
        vector<int>dist(n+1,INT_MAX);

        for(auto it:times){
            int ui=it[0];
            int vi=it[1];
            int wi=it[2];

            adjli[ui].push_back({vi,wi});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        dist[k]=0;

        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();

            for(auto[v,wt]:adjli[u]){
                if(dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
                }
            }

        }
        int ans=*max_element(dist.begin()+1,dist.end());
        if(ans==INT_MAX){
            return -1;
        }
        else{
            return ans;
        }

        
    }
};
