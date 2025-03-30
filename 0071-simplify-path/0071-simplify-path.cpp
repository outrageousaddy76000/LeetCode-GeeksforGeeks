class Solution {
public:
    string simplifyPath(string path) {
        vector <string> ans;
        stringstream ss(path);
        string temp;
        while (getline(ss, temp, '/')) {
            if(temp=="." || temp=="") continue;
            else if(temp=="..") {if(ans.size()) ans.pop_back();}
            else ans.push_back(temp);
        }
        string res="/";
        for(int i=0;i<ans.size();i++){
            res+=ans[i];
            res+="/";
            if(i==ans.size()-1) res.pop_back();
        }
        return res;
    }
};