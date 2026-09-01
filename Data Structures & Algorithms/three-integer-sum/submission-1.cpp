class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       /* tle error bcoz of O(n^3)
        int n=nums.size();
        set<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        ans.insert({nums[i],nums[j],nums[k]});
                    }
                }
            }
        }
        return vector<vector<int>>(ans.begin(),ans.end());   
    }
    */
    int n=nums.size();
    vector<vector<int>>res;
    sort(nums.begin(),nums.end());

    for(int i=0;i<n;i++){
        if(nums[i]>0)
        break;

        if(i>0 && nums[i]==nums[i-1])
        continue;

        int left=i+1;
        int right=n-1;

        while(left<right){
            int sum=nums[i]+nums[left]+nums[right];
            if(sum>0){
                right--;
            }
            else if(sum<0){
                left++;
            }
            else{
                res.push_back({nums[i],nums[left],nums[right]});
                left++;
                right--;

                while(left<right && nums[left]==nums[left-1]){
                    left++;
                }
            }
        }
    }
    return res;
    }

};
