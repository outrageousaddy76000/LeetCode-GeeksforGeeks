class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack <char> st;
        bool ans;
        for(int i=0;i<expression.size();i++){
            if(expression[i]=='(' || expression[i]==',') continue;
            else if(expression[i]!=')') st.push(expression[i]);
            else{
                bool hast=false,hasf=false;
                while(st.top()=='f' || st.top()=='t'){
                    if(st.top()=='t') hast=true;
                    else hasf=true;
                    st.pop();
                }
                if(st.top()=='|'){
                    if(hast) ans=true;
                    else ans=false;
                }
                else if(st.top()=='&'){
                    if(hasf) ans=false;
                    else ans=true;
                }
                else{
                    if(hast) ans=false;
                    else ans=true;
                }
                st.pop();
                if(st.empty()) break;
                if(ans) st.push('t');
                else st.push('f');
            }
        }
        return ans;
    }
};