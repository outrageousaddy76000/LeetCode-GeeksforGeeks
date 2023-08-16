class Solution {
public:
    int numDifferentIntegers(string word) {
        set <string> s;
        int first=-1;
        for(int i=0;i<word.size();i++){
            if(word[i]>58 && first!=-1){
                string a = word.substr(first,i-first);
                //remove leading zeroes and insert in s
                int j=0;
                while(a[j]=='0'){
                    j++;
                }
                s.insert(a.substr(j,a.size()-j));
                first=-1;
            }
            else if(word[i]>58){
                continue;
            }
            else{
                if(first==-1) first=i;
            }
        }
        if(first!=-1){
            string a = word.substr(first,word.size()-first);
            int j=0;
            while(a[j]=='0'){
                j++;
            }
            s.insert(a.substr(j,a.size()-j));
        }
        return s.size();
    }
};