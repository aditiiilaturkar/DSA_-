class Solution {
public:
    int solve(vector<int>& prices, int i, int buy, vector<vector<int>>&dp){
        if(i>=prices.size()) return 0;  
        if(dp[i][buy]!=-1) return dp[i][buy]; 

        int profit=0;
        if(buy){
            int buying = solve(prices, i+1, 0, dp) - prices[i];
            int dont_buy = solve(prices, i+1, 1, dp);
            profit = max(buying, dont_buy); 
        }else{
            int sell = prices[i];
            int dont_sell = solve(prices, i+1, 0, dp);
             profit = max(sell, dont_sell); 
        }
        dp[i][buy] = profit;
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(), vector<int>(2, -1));
        return solve(prices, 0, 1, dp); 
    }
};