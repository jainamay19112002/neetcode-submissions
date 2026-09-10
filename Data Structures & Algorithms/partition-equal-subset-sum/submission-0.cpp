class Solution {
public:
     bool isasubsetsum(vector<int>&nums,int target){
        int n=nums.size();
        vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;

        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }

        if((totalsum%2)!=0)
        return false;

        return isasubsetsum(nums,totalsum/2);
        
    }
};
