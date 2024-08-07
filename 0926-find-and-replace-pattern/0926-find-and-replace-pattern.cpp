class Solution {
public:
    bool check(string word, string &pattern){
        if(word.size()!=pattern.size()) return false;
        map <char,char> m;
        vector <bool> v(26);
        for(int i=0;i<pattern.size();i++){
            if(m.find(word[i])==m.end()){
                //if pattern[i] is marked return false
                if(v[pattern[i]-'a']) return false;
                m[word[i]]=pattern[i];
                v[pattern[i]-'a']=true;
            }
            word[i]=m[word[i]];
        }
        return word==pattern;

    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector <string> ans;
        for(auto &word:words){
            if(check(word,pattern)) ans.push_back(word);
        }
        return ans;
    }
};