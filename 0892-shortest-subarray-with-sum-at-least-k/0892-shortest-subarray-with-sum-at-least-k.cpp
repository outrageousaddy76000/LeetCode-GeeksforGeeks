class Solution {
private:
    int min(int a, int b){
        if(a<b) return a;
        return b;
    }
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int ans=INT_MAX;
        int sum=0;
        int start=-1;
        for(int i=0;i<nums.size();i++){
            if(start!=-1){
                if(nums[i]>0){
                    sum+=nums[i];
                    if(sum>=k){
                        ans=min(ans,i-start+1);
                        while(start<i){
                            sum-=nums[start];
                            start++;
                            while(nums[start]<0){
                                sum-=nums[start];
                                start++;
                            }
                            if(sum>=k){
                                ans=min(ans,i-start+1);
                            }
                            else{
                                //saara pseudo drop krke check krke break
                                int start2=i-1;
                                int sum2=nums[i];
                                while(start2>start){
                                    sum2+=nums[start2];
                                    if(sum2>=k){
                                        ans=min(ans,i-start2+1);
                                        break;
                                    }
                                    start2--;
                                }
                                break;
                            }
                        }
                    }
                }
                else{
                    sum+=nums[i];
                    if(sum<=0){
                        start=-1;
                        sum=0;
                    }
                }
            }
            else{
                if(nums[i]>0){
                    start=i;
                    sum=nums[i];
                    if(sum>=k) return 1;
                }
            }
            // cout<<sum<<" ";
        }
        return ans==INT_MAX?-1:ans;
    }
};