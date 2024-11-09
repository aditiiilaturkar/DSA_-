class Solution {
public:
    int solve(vector<int>& nums, int s, int e) { 
        if(s>e) return INT_MIN;
        int mid = s+(e-s)/2;
        int left =0, right = 0, curr =0;
        for(int i=mid-1; i>=s; i--){
            curr+= nums[i];
            left =max(left, curr);
        }
        curr = 0;
        for(int i=mid+1; i<=e; i++){
            curr+= nums[i];
            right = max(right, curr);
        }

        return max({solve(nums, s, mid-1), solve(nums, mid+1, e), left+nums[mid]+right});
    }
    int maxSubArray(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};