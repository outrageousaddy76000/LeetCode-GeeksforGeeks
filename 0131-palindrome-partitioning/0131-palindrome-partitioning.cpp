class Solution {
private:
    bool isPal(string s){
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-1-i]) return false;
        }
        return true;
    }
public:
    unordered_map <int,vector<vector<string>>> m;
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        if(m.find(s.size())!=m.end()) return m[s.size()];
        for(int i=0;i<s.size();i++){
            string curr = s.substr(0,i+1);
            if(isPal(curr)){
                vector<vector<string>> next;
                if(i!=s.size()-1){
                    next = partition(s.substr(i+1,s.size()-i-1));
                    for(auto &val:next){
                        val.insert(val.begin(),curr);
                    }
                    for(auto &val:next){
                        ans.push_back(val);
                    }
                }
                else{
                    vector<string> temp;
                    temp.push_back(curr);
                    ans.push_back(temp);
                }
            }
        }
        return m[s.size()]=ans;
    }
};