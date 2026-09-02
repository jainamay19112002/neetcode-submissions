class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xoring=0,xoring2=0;
        for(int i=0;i<=n;i++){
            xoring=xoring^i;
        }

        for(int i=0;i<n;i++){
            xoring=xoring^nums[i];
        }
        return xoring;
        
    }
};
