class Solution {
private:
    bool f(int val,int n, vector <int> &v){
        //at most val
        for(auto &x:v){
            if(x%val==0){
                n-=x/val;
            }
            else{
                n-=x/val;
                n--;
            }
            if(n<0) return false;
        }
        return true;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        //binary search on answer
        int low = 1, high =*max_element(quantities.begin(),quantities.end());
        int ans=0;
        while(high>=low){
            int mid = low + (high-low)/2;
            if(f(mid,n,quantities)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};