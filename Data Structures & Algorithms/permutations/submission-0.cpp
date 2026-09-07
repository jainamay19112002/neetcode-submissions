class Solution {
public:
    void usingbacktrack(vector<int>&nums,vector<vector<int>>&ans,vector<int>&curr,vector<bool>&isused){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
        }

        for(int i=0;i<nums.size();i++){
            if(isused[i])
            continue;

            isused[i]=true;
            curr.push_back(nums[i]);
            usingbacktrack(nums,ans,curr,isused);
            
            curr.pop_back();
            isused[i]=false;
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        vector<bool>isused(nums.size(),false);

        usingbacktrack(nums,ans,curr,isused);
        return ans;
        
    }
};
