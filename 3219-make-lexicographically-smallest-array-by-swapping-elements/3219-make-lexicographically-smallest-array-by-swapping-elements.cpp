class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector <pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int start=0;
        for(int i=0;i<v.size();i++){
            if(i==v.size()-1 || v[i+1].first-v[i].first>limit){
                //component break
                //start to i
                priority_queue <int,vector <int>, greater<int>> numbers,indexes;
                for(int j=start;j<=i;j++){
                    numbers.push(v[j].first);
                    indexes.push(v[j].second);
                }
                for(int j=start;j<=i;j++){
                    nums[indexes.top()]=numbers.top();
                    indexes.pop();
                    numbers.pop();
                }
                start=i+1;
            }
        }
        return nums;
    }
};