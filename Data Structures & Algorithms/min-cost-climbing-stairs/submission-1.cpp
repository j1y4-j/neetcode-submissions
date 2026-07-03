class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1);
        // dp initialises all to 0
        // base case: dp[0]=0,dp[1]=0; min cost to reach idx i
        for(int i=2;i<=n;i++){
            int fs=dp[i-1]+cost[i-1];
            int ss=cost[i];
            if(i>1) ss=dp[i-2]+cost[i-2];
            dp[i]=min(ss,fs);

        }
        return dp[n];
        
    }
};
