class Solution {
public:
    string multiply(string num1, string num2) {
            int n1=num1.size();
        int n2=num2.size();

        vector<int>ans(n1+n2,0);
        string temp="";

        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                int l1=num1[i]-'0';
                int l2=num2[j]-'0';

                int multiplyinglast=l1*l2;
                int sum=multiplyinglast+ans[i+j+1];

                ans[i+j+1]=sum%10;
                ans[i+j]+=sum/10;
            }
        }
        
        // idhar hum leading zeroes chck kr rhe hh
        for(auto it:ans){
            if(temp.empty()&& it==0)
            continue;

            temp+=to_string(it);
        }
        if(temp.empty())
        return "0";

        return temp;
        
        
    
        
    }
};
