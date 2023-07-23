class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        unordered_map <int,int> m1,m2;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            int x = count(mat[i].begin(),mat[i].end(),1);
            m1[i]=x;
        }
        for(int j=0;j<m;j++){
            int x =0;
            for(int i=0;i<n;i++){
                if(mat[i][j]==1) x++;
            }
            m2[j]=x;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    if(m1[i]==1 && m2[j]==1) ans++;
                }
            }
        }
        return ans;
    }
};