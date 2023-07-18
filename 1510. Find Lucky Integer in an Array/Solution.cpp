class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector <int> v(501);
        for(int i=0;i<arr.size();i++){
            v[arr[i]]++;
        }
        int ans=-1;
        for(int i=v.size()-1;i>0;i--){
            if(v[i]==i) return i;
        }
        return ans;
    }
};