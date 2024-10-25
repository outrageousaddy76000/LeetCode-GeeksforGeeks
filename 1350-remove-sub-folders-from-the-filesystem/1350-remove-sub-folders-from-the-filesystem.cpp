class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        map <string,int> m;
        for(int i=0;i<folder.size();i++) m[folder[i]]++;
        vector <string> ans;
        for(string s:folder){
            bool flag=true;
            for(int i=1;i<s.size();i++){
                if(s[i]=='/'){
                    if(m.find(s.substr(0,i))!=m.end()){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag) ans.push_back(s);
        }
        return ans;
    }
};