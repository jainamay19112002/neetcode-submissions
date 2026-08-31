class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(auto s:strs){
            ans.append(to_string(s.size()));
            ans.push_back('#');
            ans.append(s);
        }
        return ans;

    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int len=stoi(s.substr(i,j-i));
            i=j+1;
            j=i+len;
            ans.push_back(s.substr(i,len));
            i=j;
        }
        return ans;

    }
};
