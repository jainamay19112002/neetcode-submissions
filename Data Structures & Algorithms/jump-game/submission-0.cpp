class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int howfaricango=0;

        for(int i=0;i<n;i++){
            if(i>howfaricango)
            return false;

            howfaricango=max(howfaricango,i+nums[i]);

            if(howfaricango>=n-1)
            return true;
        }
        return false;
        
    }
};
