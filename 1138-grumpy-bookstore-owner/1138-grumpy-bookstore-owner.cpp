class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans=0;
        int n = customers.size();
        vector <int> pre(n);
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                ans+=customers[i];
                customers[i]=0;
            }
            if(i) pre[i]=pre[i-1]+customers[i];
            else pre[i]=customers[i];
        }
        //find a window of size minutes and add all inside the window to ans
        int first=0;
        int last=minutes-1;
        int maxi = 0;
        while(last<n){
            int curr = pre[last++]+customers[first]-pre[first++];
            maxi = max(maxi,curr);
        }
        ans+=maxi;
        return ans;
    }
};