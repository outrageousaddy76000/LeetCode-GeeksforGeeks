class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        //upper is number of 1s in 1st row
        //lower is number of 1s in 2nd row
        int n = colsum.size();
        vector <vector<int>> ans(2,vector <int> (n));
        for(int i=0;i<n;i++){
            if(colsum[i]==2){
                lower--;
                upper--;
                ans[1][i]=1;
                ans[0][i]=1;
            }
            else if(colsum[i]==0){
                ans[0][i]=0;
                ans[1][i]=0;
            }
        }
        for(int i=0;i<n;i++){
            if(colsum[i]==1){
                if(upper>0){
                    upper--;
                    ans[0][i]=1;
                }
                else{
                    lower--;
                    ans[1][i]=1;
                }
            }
        }
        // for(auto v:ans){
        //     for(auto &val:v) cout<<val<<" ";
        //     cout<<endl;
        // }
        if(lower!=0 || upper!=0){
            ans.clear();
        }
        return ans;
    }
};