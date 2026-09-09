/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
       int n=intervals.size();
        
     
        sort(intervals.begin(),intervals.end(),[](Interval&a,Interval&b){
        return a.start<b.start;
        });

        int lasttaken=intervals[0].end;
        for(int i=1;i<n;i++){
            if(lasttaken>intervals[i].start)
             return false;

             lasttaken=intervals[i].end;
            }
            return true;
        
       
    }
};
