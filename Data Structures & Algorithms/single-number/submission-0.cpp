class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int xoring=0;
        for(int i=0;i<n;i++){
            xoring=xoring^nums[i];
        }
        return xoring;
        
    }
};
