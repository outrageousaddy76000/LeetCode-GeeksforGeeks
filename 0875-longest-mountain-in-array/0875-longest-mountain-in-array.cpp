class Solution {
public:
    int longestMountain(vector<int>& arr) {
        //consider every point as mountain start unless previous mountain is continuing
        if(arr.size()<3) return 0;
        bool start=false,peak=false;
        int size=0,ans=0;
        for(int i=0;i<arr.size();i++){
            if(start){
                if(arr[i]==arr[i-1]){
                    if(peak)
                    ans=max(size,ans);
                    size=1;
                    peak=false;
                    continue;
                }
                if(peak){
                    if(i+1==arr.size()){
                        size++;
                        continue;
                    }
                    if(arr[i+1]>arr[i]){
                        //mountain finished
                        size++;
                        ans = max(ans,size);
                        start = true;
                        peak=false;
                        size=1;
                    }
                    else size++;
                }
                else{
                    if(i+1==arr.size()){
                        //mountain invalid
                        size=0;
                        continue;
                    }
                    if(arr[i]>arr[i-1] && arr[i+1]<arr[i]){
                        peak=true;
                        size++;
                    }
                    else if(arr[i]<arr[i-1]){
                        start=true;
                        size=1;
                    }
                    else{
                        size++;
                    }
                }
            }
            else{
                start=true;
                size++;
            }
        }
        ans = max(size,ans);
        return ans>=3?ans:0;
    }
};