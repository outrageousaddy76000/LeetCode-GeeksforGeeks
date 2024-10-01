class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map <int,int> m;
        for(auto &val:arr){
            m[((val%k)+k)%k]++;
        }
        for(auto &pr:m){
            // cout<<pr.first<<" "<<pr.second<<endl;
            if(pr.first==0){
                if(pr.second&1) return false;
            }
            else if(m[k-pr.first]!=pr.second) return false;
        }
        return true;
    }
};