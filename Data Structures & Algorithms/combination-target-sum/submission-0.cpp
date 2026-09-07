class Solution {
public: 
    void dfs(int idx,vector<vector<int>>&ans,vector<int>&pushing,vector<int>&nums,int target){
        if(idx>=nums.size()){
            if(target==0){
            ans.push_back(pushing);
        }
        return;
        }
        if(nums[idx]<=target){
        pushing.push_back(nums[idx]);
        dfs(idx,ans,pushing,nums,target-nums[idx]);
        pushing.pop_back();
        }
        dfs(idx+1,ans,pushing,nums,target);


    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>pushing;
        dfs(0,ans,pushing,nums,target);
        return ans;
        
    }
};
