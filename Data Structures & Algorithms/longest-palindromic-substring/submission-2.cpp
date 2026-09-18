class Solution {
public:
    string expanding(string&s,int left,int right){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);

    }
    string longestPalindrome(string s) {
        int n=s.length();
        string ans="";

        for(int i=0;i<n;i++){
            string p1=expanding(s,i,i);
            string p2=expanding(s,i,i+1);

            if(p1.size()>ans.size())
            ans=p1;

            if(p2.size()>ans.size())
            ans=p2;
        }
        return ans;
        
    }
};
