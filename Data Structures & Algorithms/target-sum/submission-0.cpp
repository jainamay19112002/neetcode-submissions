class Solution {
public:
    int subsetsum(vector<int>&nums,int target){
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }

        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalsum=0;

        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }

        if(abs(target)>totalsum)
        return 0;

        if((totalsum+target)%2!=0)
        return 0;

        int require=(totalsum+target)/2;

        return subsetsum(nums,require);

        
    }
};
