class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
         int n=queries.size();
        int n2=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>>vq;

        for(int i=0;i<n;i++){
            vq.push_back({queries[i],i});
        }
        sort(vq.begin(),vq.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        vector<int>ans(n,-1);
        int i=0;
        for(auto it:vq){
            int query=it.first;
            int idx=it.second;

            while(i<n2 && intervals[i][0]<=query){
                int start=intervals[i][0];
                int end=intervals[i][1];
                int len=end-start+1;

                pq.push({len,end});
                i++;
            }

            while(!pq.empty() && pq.top().second<query){
                pq.pop();
            }

            if(!pq.empty()){
                ans[idx]=pq.top().first;
            }
        }
        return ans;
        
    }
};
