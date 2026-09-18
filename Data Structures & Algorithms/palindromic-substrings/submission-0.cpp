class Solution {
public:
     int expand(string&s,int left,int right){
        int localcount=0;
        while(left>=0 && right<s.size() && s[left]==s[right]){
            localcount++;
            left--;
            right++;
        }
        return localcount;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int finalcount=0;

        for(int i=0;i<n;i++){
            finalcount+=expand(s,i,i);
            finalcount+=expand(s,i,i+1);
        }
        return finalcount;
        
    }
};
