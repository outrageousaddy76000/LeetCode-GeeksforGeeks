class Solution {
public:
    void bt(unordered_map<char, vector<char>> &m,string s,vector <string> &ans,int ind,string curr){
        cout<<curr<<" ";
        if(ind==s.size()){
            ans.push_back(curr);
            return;
        }
        string a = curr;
        for(int i=0;i<m[s[ind]].size();i++){
            a+=m[s[ind]][i];
            bt(m,s,ans,ind+1,a);
            a=curr;
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> m;
        m['2'] = {'a', 'b', 'c'};
        m['3'] = {'d', 'e', 'f'};
        m['4'] = {'g', 'h', 'i'};
        m['5'] = {'j', 'k', 'l'};
        m['6'] = {'m', 'n', 'o'};
        m['7'] = {'p', 'q', 'r', 's'};
        m['8'] = {'t', 'u', 'v'};
        m['9'] = {'w', 'x', 'y', 'z'};
        vector <string> ans;
        string curr="";
        if(digits.size()==0) return ans;
        bt(m,digits,ans,0,curr);
        return ans;
    }
};