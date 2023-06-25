class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector <int> ans(2);
        ans[0]=INT_MAX;
        ans[1]=0;
        if(area == 1){
            ans[0]=1;
            ans[1]=1;
            return ans;
        }
        for(int i=area/2;i>=1;i--){
            if(area%i==0){
                if(abs(1LL*(area/i)-1LL*i)<abs(1LL*ans[0]-1LL*ans[1])){
                    ans[0]=area/i;
                    ans[1]=i;
                }
            }
            else continue;
        }
        if(ans[0]<ans[1]) swap(ans[0],ans[1]);
        return ans;
    }
};