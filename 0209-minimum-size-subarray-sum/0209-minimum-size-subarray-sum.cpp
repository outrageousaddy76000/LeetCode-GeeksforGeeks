class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector <int> pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        map <int,int> m;
        for(int i=1;i<n;i++){
            m[pre[i]-target]=i;
        }
        for(auto &val:pre){
            cout<<val<<" ";
        }
        cout<<endl;
        int ans=INT_MAX;
        auto it1 = lower_bound(pre.begin(),pre.end(),target);
        if(it1!=pre.end()){
            int len = it1-pre.begin()+1;
            ans=min(len,ans);
        }
        for(int i=0;i<n-1;i++){
            auto it = m.lower_bound(pre[i]);
            if(it==m.end()) continue;
            cout<<it->first<<" "<<it->second<<endl;
            ans=min(ans,(int)(it->second-i));
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};