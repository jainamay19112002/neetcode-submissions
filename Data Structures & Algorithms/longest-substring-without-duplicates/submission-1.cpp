class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int>mp;
        int l=0;
        int maxlen=0;

        for(int r=0;r<n;r++){
            mp[s[r]]++;

            while(mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
        
    }
};
