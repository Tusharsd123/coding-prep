class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k >= n/2)
        {
            int sum = 0;
            for(int i = 1;i<n;i++)
                if(prices[i] > prices[i-1])
                     sum += prices[i] - prices[i-1];
            return sum;
        }
        vector<int> buy(k+1,INT_MIN),sell(k+1,0);
        for(int i = 0;i<n;i++)
        {
            for(int j = 1;j<=k;j++)
            {
                buy[j] = max(buy[j],sell[j-1]-prices[i]);
                sell[j] = max(sell[j],buy[j]+prices[i]);
            }
        }
        return sell[k];
    }
};
