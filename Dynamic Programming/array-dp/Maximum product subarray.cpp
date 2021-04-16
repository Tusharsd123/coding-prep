class Solution {
public:
    int maxProduct(vector<int>& a) {
        if (a.size() == 0) return 0;
        int ans = INT_MIN, minNeg = 1, maxPos = 1;

        for (int i : a) {
            int mp = maxPos;
            maxPos = max({i, minNeg * i, maxPos * i});
            minNeg = min({i, mp * i, minNeg * i});
            ans = max(ans, maxPos);
        }

        return ans;
        
    }
};
