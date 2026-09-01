class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
        int leftmaxi=0,rightmaxi=0;
        int maxwaterstored=0;

        while(left<=right){
            leftmaxi=max(leftmaxi,height[left]);
            rightmaxi=max(rightmaxi,height[right]);

            if(leftmaxi<=rightmaxi){
                maxwaterstored+=leftmaxi-height[left];
                left++;
            }
            else{
                maxwaterstored+=rightmaxi-height[right];
                right--;
            }
        }
        return maxwaterstored;
        
    }
};
