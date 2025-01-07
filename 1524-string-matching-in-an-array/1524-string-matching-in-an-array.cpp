class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector <string> ans;
        set <string> s;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                string s1 = words[i];
                string s2 = words[j];
                if(s1.find(s2)!=-1) s.insert(s2);
                if(s2.find(s1)!=-1) s.insert(s1);
            }
        }
        for(auto &val:s) ans.push_back(val);
        return ans;
    }
};