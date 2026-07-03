class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        dp[0]=cost[0];
        cost.push_back(0);
        for(int i=1;i<cost.size();i++){
            int fs=dp[i-1]+cost[i];
            int ss=cost[i];
            if(i>1) ss=dp[i-2]+cost[i];
            dp[i]=min(ss,fs);

        }
        return dp[cost.size()-1];
        
    }
};
