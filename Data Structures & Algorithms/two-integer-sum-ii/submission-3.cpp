class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        /* this gives tle...bcoz it goes upto O(n^2)
        int n=numbers.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(numbers[i]+numbers[j]==target){
                return {i+1,j+1};
                }
            }
        }
        return {};      
    }
    */
    /* 2nd approach using binary search (array sorted diya h)
    int n=numbers.size();
    for(int i=0;i<n;i++){
        int left=i+1;
        int right=n-1;
        int findingnew=target-numbers[i];

        while(left<=right){
            int mid=(left+right)/2;

            if(findingnew==numbers[mid]){
                return{i+1,mid+1};
            }
            else if(numbers[mid]<findingnew){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
    }
    return {};
    }
    */

    int left=0;
     int right=numbers.size()-1;

        while (left<right) {
            int currsum=numbers[left]+numbers[right];

            if(currsum>target) {
            right--;
            } 
            else if(currsum<target) {
            left++;
            } 
            else{
            return {left+1,right+1};
            }
        }
        return {};
    }
};
