class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();

        int prefix=1;
        int prefixmaxi=nums[0];
        for(int i=0;i<n;i++){
            if(prefix==0)
            prefix=1;

            prefix=prefix*nums[i];
            prefixmaxi=max(prefixmaxi,prefix);
        }

        int suffix=1;
        int suffixmaxi=nums[n-1];
        for(int i=n-1;i>=0;i--){
            if(suffix==0)
            suffix=1;

            suffix=suffix*nums[i];
            suffixmaxi=max(suffixmaxi,suffix);
        }

        return max(prefixmaxi,suffixmaxi);


        
    }
};
