class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int i, int j, bool toLeft) {
       
        int ind = -1;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(nums[mid] == target){
                ind = mid;
                if(toLeft){
                    j=mid-1;
                }else{
                    i=mid+1;
                }
            }else if(nums[mid]>target){
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return ind;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int>ans(2, -1);
       ans[0] = binarySearch(nums, target, 0, nums.size()-1, true);
       ans[1] = binarySearch(nums, target, 0, nums.size()-1, false);    
       return ans;
    }
};