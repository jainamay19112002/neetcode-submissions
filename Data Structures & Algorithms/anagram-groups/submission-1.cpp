class Solution {
public:
   /* giving tle error
    bool isanagram(string &s, string&t){
        if(s.length()!=t.length())
        return false;

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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>>ans;
        vector<bool>isused(n,false);

        for(int i=0;i<n;i++){
            if(isused[i])
            continue;

            vector<string>groups;
            for(int j=i;j<n;j++){
                if(!isused[j] && isanagram(strs[i],strs[j])){
                    groups.push_back(strs[j]);
                    isused[j]=true;
                }
            }
            ans.push_back(groups);
        }
        return ans;
        
    }
    */

     vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>> mp;

        for(auto it:strs) {
            string temp=it;
            sort(temp.begin(),temp.end());

            mp[temp].push_back(it);
        }

        for(auto it:mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
