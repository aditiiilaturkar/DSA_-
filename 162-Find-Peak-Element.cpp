class Solution {
public:
    int bs(vector<int>& nums, int i, int j){
      
        
        while(i<=j){
            int mid = i+(j-i)/2;
            if((mid==0 || nums[mid] > nums[mid-1]) && (mid==nums.size()-1 || nums[mid] > nums[mid+1])){
                return mid;
            }
            else if(nums[mid] < nums[mid+1]){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return 0;
    }
    int findPeakElement(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        return bs(nums, i, j);
    }
};