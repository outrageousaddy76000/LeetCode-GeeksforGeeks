class Solution {
public:
    int pivotIndex(vector<int>& a) {
        int n = a.size();
        vector <long long int> pre(n);
        vector <long long int> post(n);
        pre[0]=a[0];
        post[n-1]=a[n-1];
        int index=-1;
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+a[i];
        }
        if(post[n-1]==pre[n-1]) index=n-1;
        for(int i=n-2;i>=0;i--){
            post[i]=post[i+1]+a[i];
            if(post[i]==pre[i]) index=i;
        }
        //find equal element in pre and post
        return index;        
    }
};