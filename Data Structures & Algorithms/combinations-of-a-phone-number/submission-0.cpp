class Solution {
public:
    void backtrack(int idx,string digits,vector<string>&ans,string currpath,vector<string>&mp){
        if(idx==digits.size()){
            ans.push_back(currpath);
            return;
        }

        string let=mp[digits[idx]-'0'];

        for(char ch:let){
            currpath.push_back(ch);
            backtrack(idx+1,digits,ans,currpath,mp);
            currpath.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        
        if(digits.empty())
        return {};

        vector<string>mp={"","","abc","def"
                            ,"ghi","jkl","mno"
                            ,"pqrs","tuv","wxyz"};

        string currpath;
        backtrack(0,digits,ans,currpath,mp); 
        return ans;       
    }
};
