class Solution {
private:
    int dp[500][500];
    int helper(int start,int end,vector <int> &stones,vector <int> &pre){
        if(end-start<1) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int ans=0;
        for(int i=start;i<end;i++){
            int curr;
            //take from start to i in one side, i+1 to end on the other and recurse
            int sf,sl;
            if(start==0) sf=pre[i];
            else sf=pre[i]-pre[start-1];
            sl=pre[end]-pre[i];
            if(sl==sf){
                curr=sl+max(helper(start,i,stones,pre),helper(i+1,end,stones,pre));
            }
            else if(sf<sl){
                curr=sf+helper(start,i,stones,pre);
            }
            else{
                curr=sl+helper(i+1,end,stones,pre);
            }
            // cout<<start<<" "<<end<<" "<<ans<<endl;
            ans=max(ans,curr);
        }
        return dp[start][end]=ans;
    }
public:
    int stoneGameV(vector<int>& stones){
        vector <int> pre(stones.size());
        for(int i=0;i<stones.size();i++){
            if(i) pre[i]=pre[i-1]+stones[i];
            else pre[i]=stones[i];
        }
        memset(dp,-1,sizeof(dp));
        return helper(0,stones.size()-1,stones,pre);
    }
};