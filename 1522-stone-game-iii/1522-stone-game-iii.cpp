class Solution {
private:
    int dp[2][50001];
    int helper(int index,vector <int> &stones,int turn){
        if(index==stones.size()) return 0;
        if(dp[turn][index]!=-1) return dp[turn][index];
        int ans;
        if(turn==0){
            //alice's turn
            ans=INT_MIN;
            int result=0;
            for(int i=0;i<3;i++){
                if(index+i>=stones.size()) break;
                result+=stones[index+i];
                ans=max(ans,result+ helper(index+i+1,stones,1));
            }
        }
        else{
            //bob's turn
            ans=INT_MAX;
            for(int i=0;i<3;i++){
                if(index+i>=stones.size()) break;
                ans=min(ans,helper(index+i+1,stones,0));
            }
        }
        return dp[turn][index]=ans;
    }
public:
    string stoneGameIII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        int alice = helper(0,stones,0);
        int bob = accumulate(stones.begin(),stones.end(),0)-alice;
        if(alice>bob) return "Alice";
        else if(bob>alice) return "Bob";
        return "Tie";
    }
};