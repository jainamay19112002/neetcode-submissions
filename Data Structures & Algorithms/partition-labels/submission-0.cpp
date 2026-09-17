class Solution {
public:
    vector<int> partitionLabels(string s) {
          int n=s.length();
        vector<int>ans;
        vector<int>storinglastposition(26);

        for(int i=0;i<n;i++){
            storinglastposition[s[i]-'a']=i;
        }

        int startidx=0;
        int endidx=0;

        for(int i=0;i<n;i++){
            endidx=max(endidx,storinglastposition[s[i]-'a']);
            if(i==endidx){
            ans.push_back(endidx-startidx+1);
            startidx=i+1;
        }
    }
    return ans;
        
        
    }
};
