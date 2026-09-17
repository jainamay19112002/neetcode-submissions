class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
          int n=hand.size();

        if(n%groupSize!=0)
        return false;

        map<int,int>mp;
        for(auto it:hand){
            mp[it]++;
        }

        while(!mp.empty()){
            int start=mp.begin()->first;
            for(int i=0;i<groupSize;i++){
                int j=start+i;
                if(mp.find(j)==mp.end())
                return false;

                mp[j]--;

                if(mp[j]==0)
                mp.erase(j);
                
            }
        }
        return true;
        
    
        
    }
};
