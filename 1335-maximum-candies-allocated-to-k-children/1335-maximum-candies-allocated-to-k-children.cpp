class Solution {
private:
    bool f(vector <int> &candies, int mid, long long int k){
        for(int i=0;i<candies.size();i++){
            k-=candies[i]/mid;
        }
        return k<=0;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        int high = 1e9;
        int ans=0;
        while(high>=low){
            int mid = low + (high-low)/2;
            if(f(candies,mid,k)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};