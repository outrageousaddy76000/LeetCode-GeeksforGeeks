class Solution {
public:
    string reorderSpaces(string text) {
        int cnt=0;
        for(int i=0;i<text.size();i++){
            if(text[i]==' ') cnt++;
        }

        stringstream ss(text);
        string word;
        int n=0;
        while(ss>>word){
            n++;
        }        
        string ans="";
        if(n==1){
            stringstream a(text);
            while(a>>word){
                ans+=word;
            }
            for(int i=0;i<cnt;i++) ans+=' ';
            return ans;
        }
        int x = cnt/(n-1);
        int y = cnt%(n-1);
        stringstream a(text);
        while(n-- && a>>word){
            ans+=word;
            if(n)
            for(int i=0;i<x;i++){
                ans+=' ';
            }
        }
        for(int i=0;i<y;i++){
            ans+=' ';
        }
        return ans;
    }
};