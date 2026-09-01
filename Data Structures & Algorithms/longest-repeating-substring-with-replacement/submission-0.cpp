class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        unordered_map<char,int>mp;
        int l=0;
        int maxilen=0,maxifreq=0;

        for(int r=0;r<n;r++){
            mp[s[r]]++;

            maxifreq=max(maxifreq,mp[s[r]]);

            while((r-l+1)-maxifreq>k){
                mp[s[l]]--;
                l++;
            }
            maxilen=max(maxilen,r-l+1);
        }
        return maxilen;
        
    }
};
