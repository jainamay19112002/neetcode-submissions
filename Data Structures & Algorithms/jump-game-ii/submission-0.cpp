class Solution {
public:
     int jump(vector<int>& nums) {
        int n=nums.size();
        int cntjumps=0;
        int rangeend=0;
        int howfaricango=0;

        for(int i=0;i<n-1;i++){
            howfaricango=max(howfaricango,i+nums[i]);
            if(i==rangeend){
                cntjumps++;
                rangeend=howfaricango;
            }
        }
        return cntjumps;

    }
};
