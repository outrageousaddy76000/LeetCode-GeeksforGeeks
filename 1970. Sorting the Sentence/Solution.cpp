class Solution {
public:
    string sortSentence(string s) {
        vector <string> v(10);
        stringstream ss(s);
        string word;
        while(ss>>word){
            int x = word[word.size()-1]-'1';
            word.pop_back();
            v[x]=word;
        }
        string ans="";
        for(auto &val:v)
            if(val.size())
                ans+=val+" ";
        ans.pop_back();
        return ans;
    }
};