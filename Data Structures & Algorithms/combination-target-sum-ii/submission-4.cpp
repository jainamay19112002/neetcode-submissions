class Solution {
public:
    vector<vector<int>> ans;

    void dfs(int idx, vector<int>& nums, int target,
             vector<int>& curr) {

        if(target == 0) {
            ans.push_back(curr);
            return;
        }

        for(int i = idx; i < nums.size(); i++) {

            // Skip duplicate values at the same level
            if(i > idx && nums[i] == nums[i - 1])
                continue;

            // Since sorted, no later element can work
            if(nums[i] > target)
                break;

            curr.push_back(nums[i]);

            // i + 1 because each element can be used only once
            dfs(i + 1, nums, target - nums[i], curr);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        vector<int> curr;

        dfs(0, nums, target, curr);

        return ans;
    }
};