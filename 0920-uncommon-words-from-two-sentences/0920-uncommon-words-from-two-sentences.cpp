class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map <string,int> m;
        stringstream ss(s1+" "+s2);
        string word;
        while(ss>>word){
            m[word]++;
        }
        vector <string> ans;
        for(auto &pr:m){
            if(pr.second==1) ans.push_back(pr.first);
        }
        return ans;
    }
};