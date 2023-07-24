class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector <int> v(26);
        for(int i=0;i<allowed.size();i++){
            v[allowed[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<words.size();i++){
            int check=1;
            for(int j=0;j<words[i].size();j++){
                if(!v[words[i][j]-'a']) check=0;
            }
            if(check) ans++;
        }
        return ans;
    }
};