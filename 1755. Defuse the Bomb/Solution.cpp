class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n =code.size();
        if(k==0){
            code.clear();
            code.resize(n);
            return code;
        }
        if(k>0){
            vector <int> pre(n);
            pre[0]=code[0];
            for(int i=1;i<n;i++){
                pre[i]=pre[i-1]+code[i];
            }
            for(int i=0;i<n;i++){
                if(i+k<n){
                    code[i]=pre[i+k]-pre[i];
                }
                else{
                    int x = (i+k)-n;
                    code[i]=pre[n-1]-pre[i]+pre[x];
                }
            }
        }
        else{
            k=abs(k);
            reverse(code.begin(),code.end());
            vector <int> pre(n);
            pre[0]=code[0];
            for(int i=1;i<n;i++){
                pre[i]=pre[i-1]+code[i];
            }
            for(int i=0;i<n;i++){
                if(i+k<n){
                    code[i]=pre[i+k]-pre[i];
                }
                else{
                    int x = (i+k)-n;
                    code[i]=pre[n-1]-pre[i]+pre[x];
                }
            }
            reverse(code.begin(),code.end());
        }
        return code;
    }
};