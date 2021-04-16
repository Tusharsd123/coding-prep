class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximum = 0;
        int minimum = INT_MAX;
        int n = prices.size();
        for(int i = 0;i<n;i++)
        {
            if(minimum>prices[i])
            {
               minimum = prices[i]; 
             }
            else
            {
                maximum = max(maximum,prices[i]-minimum);
            }
        }
        return maximum;
    }
};
