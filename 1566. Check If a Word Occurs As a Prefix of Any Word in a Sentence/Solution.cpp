class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int ind=1;
        int siz = searchWord.size();
        while(ss>>word){
            if(word.size()>=siz){
                if(word.substr(0,siz)==searchWord) return ind;
            }
            ind++;
        }
        return -1;
    }
};