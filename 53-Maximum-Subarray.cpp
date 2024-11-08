class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxSum = INT_MIN, i=0;
    
        while(i<nums.size()){
            currSum+=nums[i];
            maxSum=max(maxSum, currSum);
            if(currSum < 0){
                currSum = 0;
            }
            i++;
        }
        return maxSum;
    }
};