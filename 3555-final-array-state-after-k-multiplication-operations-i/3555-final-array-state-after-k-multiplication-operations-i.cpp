class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
      vector <int> ans(nums.size());
      priority_queue <pair<int,int>,vector <pair<int,int>>, greater<pair<int,int>>> pq;
      for(int i=0;i<nums.size();i++){
        pq.push(make_pair(nums[i],i));
      }
      while(k--){
        pair <int,int> x = pq.top();
        pq.pop();
        x.first*=multiplier;
        pq.push(x);
      }
      while(!pq.empty()){
        ans[pq.top().second]=pq.top().first;
        pq.pop();
      }
      return ans;
    }
};