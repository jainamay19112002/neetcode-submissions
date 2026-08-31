class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1=s.length();
        int n2=t.length();

        unordered_map<char,int>mp;

        for(auto it:s){
            mp[it]++;
        }

        for(auto it:t){
            mp[it]--;
        }

        for(auto i:mp){
            if(i.second!=0)
            return false;
        }
        return true;
        
    }
};
