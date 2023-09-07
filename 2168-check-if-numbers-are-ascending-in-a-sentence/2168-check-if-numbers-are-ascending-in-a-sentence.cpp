class Solution {
public:
    bool areNumbersAscending(string s) {
        vector <int> ans;
        stringstream ss(s);
        string word;
        while(ss>>word){
            if(word[0]<95){
                //its a number
                ans.push_back(stoi(word,0,10));
            }
        }
        for(int i=1;i<ans.size();i++){
            if(ans[i]<=ans[i-1]) return false;
        }
        return true;
    }
};