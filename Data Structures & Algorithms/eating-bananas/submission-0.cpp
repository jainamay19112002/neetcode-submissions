class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int res=high;

        while(low<=high){
            int mid=(low+high)/2;

            long long totaltimeneeded=0;
            for(auto it:piles){
                totaltimeneeded+=ceil(it+mid-1)/mid;
            }
            if(totaltimeneeded<=h){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
        
    }
};
