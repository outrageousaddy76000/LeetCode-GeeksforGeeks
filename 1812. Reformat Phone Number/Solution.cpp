class Solution {
public:
    string reformatNumber(string number) {
        string ans="";
        for(int i=0;i<number.size();i++){
            if(number[i]==' ' || number[i]=='-') continue;
            ans+=number[i];
        }
        string final="";
        if(ans.size()%3==1){
            int cnt=0;
            for(int i=0;i<ans.size()-4;i++){
                cnt++;
                final+=ans[i];
                if(cnt==3){
                    cnt=0;
                    final+='-';
                }
            }
            for(int i=ans.size()-4;i<ans.size();i++){
                cnt++;
                final+=ans[i];
                if(cnt==2 && i!=ans.size()-1){
                    cnt=0;
                    final+='-';
                }
            }
            
        }
        else if(ans.size()%3==2){
            int cnt=0;
            for(int i=0;i<ans.size()-2;i++){
                cnt++;
                final+=ans[i];
                if(cnt==3){
                    cnt=0;
                    final+='-';
                }
            }
            final+=ans.substr(ans.size()-2,2);
        }
        else{
            int cnt=0;
            for(int i=0;i<ans.size();i++){
                cnt++;
                final+=ans[i];
                if(cnt==3 && i!=ans.size()-1){
                    cnt=0;
                    final+='-';
                }
            }
        }
        return final;
    }
};