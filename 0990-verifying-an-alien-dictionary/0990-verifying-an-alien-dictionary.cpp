class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector <string> v = words;
        unordered_map <char,int> m;
        for(int i=0;i<order.size();i++){
            m[order[i]]=i;
        }
        sort(v.begin(),v.end(),[&m](string a,string b){
            for(int i=0;i<a.size();i++){
                if(a[i]!=b[i]) return m[a[i]]<m[b[i]];
            }
            return a<b;
        });
        if(words==v) return true;
        return false;
    }
};