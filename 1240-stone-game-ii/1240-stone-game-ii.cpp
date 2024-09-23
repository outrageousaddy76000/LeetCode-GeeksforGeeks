class Solution {
private:
    int min(int a,int b){
        if(a<b) return a;
        return b;
    }
    int dp[2][10001][101];
    int helper(int index, vector <int> &piles, int m,int turn){
        if(index==piles.size()) return 0;
        if(dp[turn][index][m]!=-1) return dp[turn][index][m];
        int ans;
        if(turn==0){
            //alice's turn
            ans=0;
            int result = 0;
            for(int i=index;i<min(piles.size(),index+2*m);i++){
                result+=piles[i];
                //recursion
                ans=max(ans,result+helper(i+1,piles,max(m,i-index+1),1));
            }
        }
        else{
            //bob's turn
            ans=INT_MAX;
            for(int i=index;i<min(piles.size(),index+2*m);i++){
                //recursion
                ans=min(ans,helper(i+1,piles,max(m,i-index+1),0));
            }
        }
        return dp[turn][index][m]=ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        //alice will try to maximise its score, bob will try to minimise alice's score
        memset(dp,-1,sizeof(dp));
        return helper(0,piles,1,0);
    }
};