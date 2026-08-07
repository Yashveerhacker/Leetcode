class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n);
        dp[0]=1;
        int i = 0;
        int j = 0;
        int k = 0;
        for(int l = 1; l < n; l++)
        {
            int a = dp[i]*2;
            int b = dp[j]*3;
            int c = dp[k]*5;

            dp[l]=min(a,min(b,c));

            if(dp[l]==a)
            {
                i++;
            }
            if(dp[l]==b)
            {
                j++;
            }
            if(dp[l]==c)
            {
                k++;
            }
        }
        return dp[n-1];
    }
};