class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>>pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }

        while(pq.size()>1){
            int p1=pq.top();
            pq.pop();

            int p2=pq.top();
            pq.pop();

            int diff=p1-p2;

            if(p1==p2)
            pq.push(diff);

            if(p2<p1){
                pq.push(diff);
            }
        }
        return pq.top();
        
    }
};
