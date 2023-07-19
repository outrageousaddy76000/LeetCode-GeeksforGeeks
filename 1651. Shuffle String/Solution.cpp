class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string x =s;
        for(int i=0;i<indices.size();i++){
            x[indices[i]]=s[i];
        }
        return x;
    }
};