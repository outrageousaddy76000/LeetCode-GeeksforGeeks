class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map <int,int> m;
        for(int i=0;i<arr2.size();i++){
            m[arr2[i]]=i;
        }
        sort(arr1.begin(),arr1.end(),[&m](int &a,int &b){
            if(m.find(a)==m.end() && m.find(b)==m.end()){
                return a<b;
            }
            if(m.find(a)==m.end()){
                return false;
            }
            else if(m.find(b)==m.end()){
                return true;
            }
            return m[a]<m[b];
        });
        return arr1;
    }
};