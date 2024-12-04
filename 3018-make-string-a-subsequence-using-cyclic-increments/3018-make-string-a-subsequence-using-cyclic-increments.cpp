class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0;
        for(int ind=0;ind<str1.size();ind++){
            if(str1[ind]==str2[i] || str1[ind]+1==str2[i] || (str1[ind]=='z' && str2[i]=='a')) i++;
            if(i==str2.size()) return true;
        }
        cout<<i<<endl;
        return false;
    }
};