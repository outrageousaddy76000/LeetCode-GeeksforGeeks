class Solution {
public:
    bool containsall(string s){
        map <char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        return m['a'] && m['e'] && m['i'] && m['o'] && m['u'] && m.size()==5;
    }
    int countVowelSubstrings(string word) {
        int ans=0;
        int n = word.size();
        for(int i=0;i<n;i++){
            for(int j=i+4;j<n;j++){
                string s= word.substr(i,j-i+1);
                if(containsall(s)) ans++; 
            }
        }
        return ans;
    }
};