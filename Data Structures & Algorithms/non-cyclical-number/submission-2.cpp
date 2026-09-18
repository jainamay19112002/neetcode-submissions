class Solution {
public:
    int newnumberagain(int n){
        int naya=0;
        while(n>0){
            int lastdigit=n%10;
            n=n/10;
            naya+=lastdigit*lastdigit;
        }
        return naya;
    }
    bool isHappy(int n) {
        unordered_set<int>st;

        while(n!=1){
            if(st.count(n))
            return false;
            
            else
            st.insert(n);
            n=newnumberagain(n);
        }
        return true;
        
    }
};
