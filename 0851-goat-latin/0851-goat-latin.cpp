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
        int cnt=1;
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
            for(int i=0;i<cnt;i++){
                word+='a';
            }
            cnt++;
            ans+=word;
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};