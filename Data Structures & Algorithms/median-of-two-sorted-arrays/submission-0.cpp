class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        int n3=nums1.size();
        sort(nums1.begin(),nums1.end());

        if(n3%2==0){
            return (nums1[n3/2-1]+nums1[n3/2])/2.0;
        }
        else{
            return nums1[n3/2];
        }
        
    }
};
