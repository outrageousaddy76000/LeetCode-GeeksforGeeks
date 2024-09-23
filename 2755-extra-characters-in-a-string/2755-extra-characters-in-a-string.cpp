class Solution {
private:
    unordered_map <string,int> dp;
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        if(s.size()==0) return 0;
        if(dp.find(s)!=dp.end()) return dp[s];
        char c = s[0];
        vector <int> ans;
        for(auto &str:dictionary){
            int l = str.size();
            if(s.size()>=l){
                string check = s.substr(0,l);
                if(check==str){
                    ans.push_back(minExtraChar(s.substr(l,s.size()-l),dictionary));
                }
            }
        }
        int res;
        if(ans.size())
            res= min(1+minExtraChar(s.substr(1,s.size()-1), dictionary),*min_element(ans.begin(),ans.end()));
        else res= 1+minExtraChar(s.substr(1,s.size()-1),dictionary);
        return dp[s]=res;
    }
};