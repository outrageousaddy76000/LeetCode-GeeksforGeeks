class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        //prefix sum partial sum
        vector <int> ans(n);
        for(int i=0;i<rounds.size()-1;i++){
            if(i){
                //dont mark the beginning
                if(rounds[i+1]>rounds[i]){
                    if(rounds[i]==n)
                        ans[0]+=1;
                    else ans[rounds[i]]+=1;
                    if(rounds[i+1]!=n)
                        ans[rounds[i+1]]-=1;
                }
                else{
                    if(rounds[i]==n)
                        ans[0]+=1;
                    else ans[rounds[i]]+=1;
                    if(rounds[i+1]!=n)
                        ans[rounds[i+1]]-=1;
                }
            }
            else{
                if(rounds[i+1]>rounds[i]){
                    ans[rounds[i]-1]+=1;
                    ans[0]+=1;
                    if(rounds[i+1]!=n)
                        ans[rounds[i+1]]-=1;
                }
                else{
                    ans[rounds[i]-1]+=1;
                    if(rounds[i+1]!=n)
                        ans[rounds[i+1]]-=1;
                }
            }
        }
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]+ans[i];
        }
        int x = *max_element(ans.begin(),ans.end());
        vector <int> final;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==x) final.push_back(i+1);
        }
        return final;
    }
};