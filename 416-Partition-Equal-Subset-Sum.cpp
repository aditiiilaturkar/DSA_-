class Solution {
public:
    bool solve(vector<int>& nums, int target, int i, vector<vector<int>>&dp){
        if(i>=nums.size()) return false;
        if(target<0) return false;
        if(target == 0) return true;
        if(dp[i][target] != -1) return dp[i][target];

        bool take = solve(nums, target-nums[i], i+1, dp);
        bool dont_take = solve(nums, target, i+1, dp);

        return dp[i][target]  = take || dont_take;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int i=0; i<nums.size(); i++){
            total+= nums[i];
        }
        if(total%2==1) return false;
        int half = total / 2;
        vector<vector<int>>dp(nums.size()+1, vector<int>(half+1, -1));
        return solve(nums, half, 0, dp);
    }
};