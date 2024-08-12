class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map <string,int> m;
        vector <string> ans;
        if(s.size()<10) return ans;
        for(int i=0;i<=s.size()-10;i++){
            string curr="";
            for(int j=i;j<i+10;j++){
                curr+=s[j];
            }
            if(m.find(curr)==m.end()){
                m[curr]++;
            }
            else if(m[curr]==1){
                ans.push_back(curr);
                m[curr]++;
            }
        }
        return ans;
    }
};