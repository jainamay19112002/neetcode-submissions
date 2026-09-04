class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size()-1;
        int ans=0;

        for(int bit=0;bit<32;bit++){
            int cntspecial=0;
            int cntnormal=0;

            for(int i=0;i<=n;i++){
                if(i&(1<<bit))
                cntnormal++;
            }

            for(auto it:nums){
                if(it&(1<<bit))
                cntspecial++;
            }

            if(cntspecial>cntnormal){
                ans|=(1<<bit);
            }
        }
        return ans;
        
    }
};
