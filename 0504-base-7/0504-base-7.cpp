class Solution {
public:
    string convertToBase7(int num) {
        string ans="";
        if(num==0){
            ans+='0';
            return ans;
        }
        int x =num;
        num=abs(num);
        while(num>0){
            int a = num/7;
            int b = num%7;
            ans+=to_string(b);
            num=a;
        }
        if(x<0) ans+='-';    
        reverse(ans.begin(),ans.end());
        return ans;
    }
};