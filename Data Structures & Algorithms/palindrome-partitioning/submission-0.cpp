class Solution {
public:
    bool ispalindrome(string s,int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }

    void doingpartitions(string s,int idx,vector<vector<string>>&ans,vector<string>&path){
        if(idx==s.length())
        ans.push_back(path);

        for(int i=idx;i<s.length();i++){
            if(ispalindrome(s,idx,i)){
                path.push_back(s.substr(idx,i-idx+1));
                doingpartitions(s,i+1,ans,path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        doingpartitions(s,0,ans,path);
        return ans;
        
    }
};
