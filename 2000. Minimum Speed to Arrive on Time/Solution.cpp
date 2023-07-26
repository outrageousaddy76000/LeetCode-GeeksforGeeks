class Solution {
public:
    bool can(double &hour,int x,vector <int> &dist){
        double sum=0.0;
        for(int i=0;i<dist.size();i++){
            if(i==dist.size()-1) {
                sum+=1.0*dist[i]/(1.0*x);
                break;    
            }
            int a = ceil(1.0*dist[i]/(1.0*x));
            sum+= a;
        }
        return sum<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low =1,high=1e7;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(can(hour,mid,dist)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(can(hour,low,dist)) return low;
        return -1;
    }
};