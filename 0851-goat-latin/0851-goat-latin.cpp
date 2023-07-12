class Solution {
public:
    bool isVowel(char c){
        c=tolower(c);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
    string toGoatLatin(string sentence) {
        string ans="";
        stringstream ss(sentence);
        string word;
        string add="a";
        while(ss>>word){
            if(isVowel(word[0])){
                word+="ma";
            }
            else{
                char c = word[0];
                word.erase(0, 1);
                word+=c;
                word+="ma";
            }
            word+=add;
            add+='a';
            ans+=word;
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};