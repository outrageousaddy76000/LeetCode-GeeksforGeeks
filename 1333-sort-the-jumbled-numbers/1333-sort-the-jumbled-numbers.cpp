class Solution {
public:
    int mapped(int x, vector <int> &mapping){
        if(x==0) return mapping[0];
        int ans=0;
        int cnt=0;
        while(x>0){
            int curr = x%10;
            x/=10;
            ans+=pow(10,cnt)*mapping[curr];
            cnt++;
        }
        return ans;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        //map -  put in pair - sort
        vector <pair<int,pair<int,int>>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back(make_pair(i,make_pair(nums[i],mapped(nums[i],mapping))));
            cout<<mapped(nums[i],mapping)<<endl;
        }
        sort(v.begin(),v.end(),[](const pair<int,pair<int,int>> &a, const pair <int,pair<int,int>> &b){
            if(a.second.second==b.second.second){
                return a.first<b.first;
            }
            else return a.second.second<b.second.second;
        });
        vector <int> ans;
        for(auto &val:v) ans.push_back(val.second.first);
        return ans;
    }
};