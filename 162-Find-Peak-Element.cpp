class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i=0, j= nums.size()-1;

        while(i<=j){
            int mid = i+(j-i)/2;
            if((mid==nums.size()-1 || nums[mid] > nums[mid+1]) && (mid == 0 || nums[mid]>nums[mid-1])){
                return mid;
            }else if(nums[mid] < nums[mid+1]){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }   
        return 0;
    }
};