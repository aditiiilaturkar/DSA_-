class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int i = 1;
        if(nums.size()>1 && nums[1]<nums[0]) return 0;
        while(i<nums.size()-1){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                return i;
            }
            i++;
        }
        if(nums.size()>1 && nums[i]>nums[i-1]) return i;
        return 0;
    }
};