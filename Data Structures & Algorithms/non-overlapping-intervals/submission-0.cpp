class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      int n=intervals.size();

        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
        return a[1]<b[1];
        });

        int cntthatnotoverlap=1;
        int lasttaken=intervals[0][1];

        for(int i=1;i<n;i++){
            if(lasttaken<=intervals[i][0]){
            cntthatnotoverlap++;
            lasttaken=intervals[i][1];
            }
        }
        return n-cntthatnotoverlap;
        
    }
};
