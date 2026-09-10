class Solution {
public:
   int solvingtheprblm(vector<int>& nums) {
        int n=nums.size();

        if(n==1)
        return nums[0];

        vector<int>dp(n);
        
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);

        for(int i=2;i<n;i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
        
    }
    int rob(vector<int>& nums){
        int n=nums.size();

        if(n==1)
        return nums[0];

        vector<int>temp1(nums.begin(),nums.end()-1);
        vector<int>temp2(nums.begin()+1,nums.end());
        
       int a=solvingtheprblm(temp1);
       int b=solvingtheprblm(temp2);
       return max(a,b);
    }
};
