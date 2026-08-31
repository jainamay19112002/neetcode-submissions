class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        vector<int>prefixprod(n,1),suffixprod(n,1);

        for(int i=1;i<n;i++){
            prefixprod[i]=prefixprod[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suffixprod[i]=suffixprod[i+1]*nums[i+1];
        }

        for(int i=0;i<n;i++){
            ans[i]=prefixprod[i]*suffixprod[i];
        }
        return ans;

    }
};
