class Solution {
public:
    void backtrack(int openbracket,int closebracket,int n,vector<string>&ans,string s){
        if(openbracket==closebracket && openbracket==n){
            ans.push_back(s);
        }

        if(openbracket<n){
            s+='(';
            backtrack(openbracket+1,closebracket,n,ans,s);
            s.pop_back();
        }

        if(closebracket<openbracket){
            s+=')';
            backtrack(openbracket,closebracket+1,n,ans,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        backtrack(0,0,n,ans,s);
        return ans;
        
    }
};
