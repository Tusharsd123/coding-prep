//We use a boolean vector dp[]. dp[i] is set to true if a valid word (word sequence) ends there. 
//The optimization is to look from current position i back and only substring and do dictionary 
//look up in case the preceding position j with dp[j] == true is found.



class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        unordered_set<string> dicts;
        for(auto i : dict)
            dicts.insert(i);
        if(dicts.size()==0)
            return false;
        vector<bool> dp(s.size()+1,false);
        dp[0] = true;
        for(int i = 1;i<=s.size();i++)
        {
            for(int j = i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(dicts.find(word)!=dicts.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
