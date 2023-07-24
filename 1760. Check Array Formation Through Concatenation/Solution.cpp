class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        //check if all integers in arr are present in pieces
        vector <int> v(100);
        vector <int> index(101);
        for(int i=0;i<arr.size();i++){
            v[arr[i]-1]++;
            index[arr[i]]=i;
        }
        for(int i=0;i<pieces.size();i++){
            for(int j=0;j<pieces[i].size();j++){
                v[pieces[i][j]-1]--;
            }
        }
        for(int i=0;i<100;i++){
            if(v[i]!=0) return false;
        }
        //now check if relative ordering is same in arr as it is in pieces
        for(int i=0;i<pieces.size();i++){
            for(int j=1;j<pieces[i].size();j++){
                if(index[pieces[i][j]]-index[pieces[i][j-1]]!=1) return false;
            }
        }
        return true;
    }
};