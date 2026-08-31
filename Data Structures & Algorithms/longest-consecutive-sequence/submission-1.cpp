class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
        return 0;
        
        unordered_set<int>st;
        for(auto it:nums){
            st.insert(it);
        }

        int longestlen=1;

        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int len=1;
                int curr=it;
            
            while(st.find(curr+1)!=st.end()){
                len++;
                curr++;
            }
            longestlen=max(longestlen,len);
        }
    }
        return longestlen;
        
    }
};
