class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        vector <int> sum1,sum2,sum3;
        for(int i=0;i<firstWord.size();i++){
            sum1.push_back(firstWord[i]-'a');
        }
        for(int i=0;i<secondWord.size();i++){
            sum2.push_back(secondWord[i]-'a');
        }
        for(int i=0;i<targetWord.size();i++){
            sum3.push_back(targetWord[i]-'a');
        }
        //directly convert to int
        int a=0,b=0,c=0;
        int cnt=0;
        for(int i=sum1.size()-1;i>=0;i--){
            a+=sum1[i]*pow(10,cnt);
            cnt++;
        }
        cnt=0;
        for(int i=sum2.size()-1;i>=0;i--){
            b+=sum2[i]*pow(10,cnt);
            cnt++;
        }
        cnt=0;
        for(int i=sum3.size()-1;i>=0;i--){
            c+=sum3[i]*pow(10,cnt);
            cnt++;
        }
        return a+b==c;
    }
};