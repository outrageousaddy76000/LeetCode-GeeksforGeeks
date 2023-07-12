class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set <string> s;
        for(int i=0;i<emails.size();i++){
            string a="";
            int check=0;
            int checkplus=0;
            for(int j=0;j<emails[i].size();j++){
                if(check){
                    //dont ignore anything
                    a+=emails[i][j];
                }
                else{
                    if(emails[i][j]=='@'){
                        a+=emails[i][j];
                        check=1;
                        continue;
                    }
                    if(checkplus) continue;
                    if(emails[i][j]=='.') continue;
                    if(emails[i][j]=='+'){
                        checkplus=1;
                        continue;
                    }
                    a+=emails[i][j];
                }
            }
            s.insert(a);
        }
        return s.size();
    }
};