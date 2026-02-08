class Solution {
public:
    void reverse(vector <int> &arr, int pos){
        for(int i=0;i<pos/2;i++){
            swap(arr[i],arr[pos-1-i]);
        }
    }

    int findPos(vector <int> arr, int elem){
        for(int i=0;i<arr.size();i++){
            if(arr[i]==elem) return i+1;
        }
        return -1;
    }

    vector<int> pancakeSort(vector<int>& arr) {
        vector <int> ans;
        for(int i=arr.size();i>0;i--){
            int pos = findPos(arr,i);
            if(pos != i){
                ans.push_back(pos);
                reverse(arr,pos);
                ans.push_back(i);
                reverse(arr,i);
            }
        }
        return ans;
    }
};