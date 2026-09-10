class Solution {
public:   
    vector<int>dp;
        int recur(int idx,vector<int>&cost){
            if(idx>=cost.size()){
                return 0;
            }

            if(dp[idx]!=-1)
            return dp[idx];

            dp[idx]=cost[idx]+min(recur(idx+1,cost),recur(idx+2,cost));

            return dp[idx];


    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        dp.assign(n,-1);
       return min(recur(0,cost),recur(1,cost));
        
    }
};
