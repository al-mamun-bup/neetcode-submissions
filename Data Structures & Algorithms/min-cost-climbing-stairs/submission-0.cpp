class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);

        return min(solve(n-1,dp,cost),solve(n-2,dp,cost));
    }

    int solve(int i, vector<int>&dp, vector<int>&cost){
        // base case
        if(i==0 or i==1) return cost[i];
        // already calculated?
        if(dp[i] != -1){
            return dp[i];
        }

        dp[i] = cost[i] + min(solve(i-1,dp,cost),solve(i-2,dp,cost));

        return dp[i];
    }
};

