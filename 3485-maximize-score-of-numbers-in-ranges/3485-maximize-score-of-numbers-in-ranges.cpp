class Solution {
private:
    bool f(long long int mid,vector <int> &start,int d){
        long long int curr = start[0];
        for(int i=1;i<start.size();i++){
            if(curr+mid<start[i]) curr=start[i];
            else if(curr+mid>start[i]+d) return false;
            else curr+=mid;
        }
        return true;
    }
public:
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(),start.end());
        //minimum ko bdhana h
        long long int low = 0;
        long long int high = start[start.size()-1]+d - start[0];
        long long int ans=low;
        while(high>=low){
            long long int mid = low + (high-low)/2;
            if(f(mid,start,d)){
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