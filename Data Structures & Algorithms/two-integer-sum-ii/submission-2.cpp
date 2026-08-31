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
};
