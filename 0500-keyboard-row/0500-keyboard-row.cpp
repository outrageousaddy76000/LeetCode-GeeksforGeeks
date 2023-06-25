class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map <char,int> m1;
        unordered_map <char,int> m2;
        unordered_map <char,int> m3;
        vector <string> ans;
        string s1 = "qwertyuiop";
        string s2 = "asdfghjkl";
        string s3 = "zxcvbnm";
        for(int i=0;i<s1.size();i++){
            m1[s1[i]]++;
        }
        for(int i=0;i<s2.size();i++){
            m2[s2[i]]++;            
        }
        for(int i=0;i<s3.size();i++){
            m3[s3[i]]++;            
        }
        for(int i=0;i<words.size();i++){
            int check=1,loop1=0,loop2=0;
            if(m1[tolower(words[i][0])]>0) loop1++;
            else if(m2[tolower(words[i][0])]>0) loop2++;
            if(loop1){
                for(int j=0;j<words[i].size();j++){
                    //check if all words[i][j] has m1[words[i][j]]>0
                    if(m1[tolower(words[i][j])]==0) check=0;
                }
            }
            else if(loop2){
                for(int j=0;j<words[i].size();j++){
                    if(m2[tolower(words[i][j])]==0) check=0;
                }
            }
            else{
                for(int j=0;j<words[i].size();j++){
                    if(m3[tolower(words[i][j])]==0) check=0;                    
                }
            }
            if(check) ans.push_back(words[i]);
        }
        return ans;
    }
};