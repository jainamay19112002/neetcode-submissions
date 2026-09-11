class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

    vector<vector<int>> dp(n, vector<int>(3, 0));

    // day 0
    dp[0][0] = -prices[0];  // holding
    dp[0][1] = 0;           // sold
    dp[0][2] = 0;           // rest

    for(int i = 1; i < n; i++) {

        // holding
        dp[i][0] = max(dp[i-1][0],
                       dp[i-1][2] - prices[i]);

        // sold today
        dp[i][1] = dp[i-1][0] + prices[i];

        // resting / can buy
        dp[i][2] = max(dp[i-1][2],
                       dp[i-1][1]);
    }

    return max(dp[n-1][1], dp[n-1][2]);
        
    }
};
