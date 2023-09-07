class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map <string,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(m[arr[i]]==1){
                if(k==1) return arr[i];
                else k--;
            }
        }
        return "";
    }
};