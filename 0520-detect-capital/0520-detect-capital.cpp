class Solution {
public:
    bool detectCapitalUse(string word) {
        vector <int> v;
        for(int i=0;i<word.size();i++){
            v.push_back(word[i]);
        }
        for(auto &val:v){
            cout<<val<<" ";
        }
        if(*max_element(v.begin(),v.end())<91){
            //all capital 
            return true;
        }
        else if (*min_element(v.begin(),v.end())>96){
            //all small
            return true;
        }
        else{
            if(v[0]<91 && *min_element(v.begin()+1,v.end())>96) return true;
        }
        return false;
    }
};