class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int i=0;
        int j=n-1;
        int maxiarea=0;

        while(i<j){
            maxiarea=max(maxiarea,(j-i)*min(heights[i],heights[j]));
            if(heights[i]<heights[j]){
            i++;
            }
            else{
            j--;
            }
        }
        return maxiarea;
        
    }
};
