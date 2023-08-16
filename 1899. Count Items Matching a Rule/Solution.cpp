class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans=0;
        for(int i=0;i<items.size();i++){
            string a = items[i][0];
            string b = items[i][1];
            string c = items[i][2];
            if(ruleKey=="color"){
                if(b==ruleValue) ans++;
            }
            if(ruleKey=="type"){
                if(a==ruleValue) ans++;
            }
            if(ruleKey=="name"){
                if(c==ruleValue) ans++;
            }
        }
        return ans;
    }
};