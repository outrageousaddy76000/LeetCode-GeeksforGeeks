class Solution {
public:
    int solve(int curr_index, set <int> st, int &n){
        if(curr_index==n+1) return 1;
        int ans=0;
        vector <int> canbe;
        for(auto val:st){
            if(curr_index%val==0 || val%curr_index==0){
                canbe.push_back(val);
            }
        }
        for(auto &val:canbe){
            st.erase(val);
            ans+=solve(curr_index+1,st,n);
            st.insert(val);
        }
        return ans;
    }
    int countArrangement(int n) {
        set <int> st;
        for(int i=1;i<=n;i++) st.insert(i);
        return solve(1,st,n);
    }
};