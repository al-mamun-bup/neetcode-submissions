class Solution {
public:
    vector<int>dp;
    int climbStairs(int n) {
        dp.resize(n, -1);
        return solve(n, 0);
    }

    int solve(int n,int i){
        if(i >= n){
            return (i==n);
        }
        if(dp[i] != -1){
            return dp[i];
        }

        return dp[i] = solve(n, i+1) + solve(n, i+2);
       
    }
};
