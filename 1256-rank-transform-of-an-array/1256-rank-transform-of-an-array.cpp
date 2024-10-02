class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map <int,int> m;
        set <int> s;
        for(int i=0;i<arr.size();i++){
            s.insert(arr[i]);
        }
        int i=1;
        for(auto &val :s){
            m[val]=i;
            i++;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=m[arr[i]];
        }
        return arr;
    }
};