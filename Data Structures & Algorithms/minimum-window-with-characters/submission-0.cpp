class Solution {
public:
    string minWindow(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        vector<int>freq(128,0);

        for(auto it:t){
            freq[it]++;
        }

        int left=0;
        int start=0;
        int minilen=INT_MAX;

        for(int right=0;right<n1;right++){
            if(freq[s[right]]>0)
                n2--;

                freq[s[right]]--;

                while(n2==0){
                    if(right-left+1<minilen){
                        minilen=right-left+1;
                        start=left;
                    }
                    freq[s[left]]++;
                    if(freq[s[left]]>0)
                    n2++;

                    left++;
                }
            
        }
        if(minilen==INT_MAX)
        return "";

        else
        return s.substr(start,minilen);

        
    }
};
