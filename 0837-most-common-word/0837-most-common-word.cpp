class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map <string,int> m2;
        stringstream ss(paragraph);
        string word;
        while(ss>>word){
            string actual="";
            for(int i=0;i<word.size();i++){
                if(word[i]=='!' || word[i]=='?' || word[i]=='\'' || word[i]==',' || word[i]==';'|| word[i]=='.'){
                if(actual.size()>0){
                m2[actual]++;
                actual="";
            }  
                }
                else actual+=tolower(word[i]);
            }
            if(actual.size()>0){
                m2[actual]++;
            }
        }
        int maxi=INT_MIN;
        string ans="";
        for(auto s:banned){
            m2.erase(s);
        }
        for(auto &pr:m2){
            if(pr.second>maxi){
                maxi=pr.second;
                ans=pr.first;
            }
        }
        return ans;
    }
};