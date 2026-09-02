class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        vector<int>nextsmaller(n);
        vector<int>prevsmaller(n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty())
            nextsmaller[i]=n;
            else
            nextsmaller[i]=st.top();

            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty())
            prevsmaller[i]=-1;
            else
            prevsmaller[i]=st.top();

            st.push(i);
        }
        
        int maxiarea=0;
        for(int i=0;i<n;i++){
            int width=nextsmaller[i]-prevsmaller[i]-1;
            int height=heights[i];
            int currarea=width*height;
            maxiarea=max(maxiarea,currarea);

        }
        return maxiarea;

        
    }
};
