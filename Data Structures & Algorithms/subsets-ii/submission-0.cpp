class Solution {
public:
     void backtrack(vector<int>&nums,int start,vector<int>&track,vector<vector<int>>&res){
        res.push_back(track);
        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i]==nums[i-1])
            continue;
            track.push_back(nums[i]);
            backtrack(nums,i+1,track,res);
            track.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>track;
        backtrack(nums,0,track,res);
        return res;
    }
};
