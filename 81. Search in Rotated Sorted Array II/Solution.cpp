class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot=-1;
        int low = 0,high=n-1;
        //find pivot
        for(int i=0;i<n-1;i++){
            if(nums[i+1]<nums[i]){
                pivot=i;
                break;
            }
        }
        if(pivot==-1){
            //sorted
            low = 0 ;
            high=n-1;
            while(high>=low){
                int mid = low +(high-low)/2;
                if(nums[mid]<target){
                    low=mid+1;
                }
                else if(nums[mid]>target){
                    high=mid-1;
                }
                else return true;
            }
        }
        else{
            if(nums[0]<=target){
                //search in 0 to pivot
                low = 0 ;
                high=pivot;
                while(high>=low){
                    int mid = low +(high-low)/2;
                    if(nums[mid]<target){
                        low=mid+1;
                    }
                    else if(nums[mid]>target){
                        high=mid-1;
                    }
                    else return true;
                }
            }
            else{
                //serch in pivot to n-1
                low = pivot+1 ;
                high=n-1;
                while(high>=low){
                    int mid = low +(high-low)/2;
                    if(nums[mid]<target){
                        low=mid+1;
                    }
                    else if(nums[mid]>target){
                        high=mid-1;
                    }
                    else return true;
                }
            }
        }
        return false;
    }
};